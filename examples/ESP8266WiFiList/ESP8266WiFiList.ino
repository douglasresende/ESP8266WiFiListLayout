#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <ESP8266WiFiListLayout.h>

const char *ssid = "ESP8266-01";
const char *password = "12345678";

ESP8266WebServer server(80);
ESP8266WiFiListLayout layout;

void getResetCss() {
  String temp = layout.resetCss();
  server.send ( 200, "text/css", temp );
}

void getBaseCss() {
  String temp = layout.baseCss();
  server.send ( 200, "text/css", temp );
}

void getTableCss() {
  String temp = layout.tableCss();
  server.send ( 200, "text/css", temp );
}

void getModalCss() {
  String temp = layout.modalCss();
  server.send ( 200, "text/css", temp );
}

void getButtonCss(){
  String temp = layout.buttonCss();
  server.send ( 200, "text/css", temp );
}

void getInputCss(){
  String temp = layout.inputCss();
  server.send ( 200, "text/css", temp );
}

void getBaseJs() {
  String temp = layout.baseJs();
  server.send ( 200, "text/css", temp );
}

void getModalJs() {
  String temp = layout.modalJs();
  server.send ( 200, "text/css", temp );
}

void getPageRoot() {
  String temp = layout.pageRootHtml();
  server.send ( 200, "text/html", temp );
}

bool eepromClear(void) {
  for (int i = 0; i < 96; ++i) { EEPROM.write(i, 0); }
  EEPROM.commit();
  return true;
}

void getLostWifi(){
  eepromClear();
  WiFi.disconnect();
  server.send ( 200, "text/json", "{\"status\": \"Desconectado\"}" );
}

void eepromSaveWifi(String id, String pass){
  eepromClear();
  for (int i = 0; i < id.length(); ++i)  { EEPROM.write(i, id[i]);      }
  for (int i = 0; i < pass.length(); ++i){ EEPROM.write(32+i, pass[i]); }
  EEPROM.commit();
}

void printArgs(){
  int total = server.args();
  int i = 0;
  while(i <= total){
    Serial.println();
    Serial.print(server.arg(i));
    i += 1;
  }
}

void postSaveWifi() {
  printArgs();
  String id = server.arg("id");
  String pass = server.arg("pass");
  eepromSaveWifi(id, pass);
  server.send ( 200, "text/json", "{status: 'Wifi Salvo'}" );
}

void getRefreshWiFi() {
  int n = WiFi.scanNetworks();
  String msg = "[{";
  msg += "\"wifi\": [";
  msg += "{\"totals\": \""; msg += n; msg += "\"}";
  for (int i = 0; i < n; ++i)
  {
    msg += ",{";
    msg += "   \"id\": \""; msg += (i+1); msg += "\"";
    msg += "  ,\"ssid\": \""; msg += WiFi.SSID(i); msg += "\"";
    msg += "  ,\"rssi\": \""; msg += WiFi.RSSI(i); msg += "\"";
    msg += "  ,\"need_password\": "; msg += ((WiFi.encryptionType(i) == ENC_TYPE_NONE)?"false":"true");
    msg += "}";
    delay(10);
  }
  msg += "]}]";
  server.send(200, "text/json", msg);
}

bool testWifi(void) {
  int c = 0;
  while ( c < 20 ) {
    if (WiFi.status() == WL_CONNECTED) { return true; }
    delay(500);
    c++;
  }
  return false;
}

String eepromGetId(void){
  String eeprom_id;
  for (int i = 0; i < 32; ++i){
    eeprom_id += char(EEPROM.read(i));
  }
  return eeprom_id;
}

String eepromGetPass(void){
  String eeprom_pass = "";
  for (int i = 32; i < 96; ++i){
    eeprom_pass += char(EEPROM.read(i));
  }
  return eeprom_pass;
}

void eepromWifiConnect(void){
  String eeprom_id   = eepromGetId();
  String eeprom_pass = eepromGetPass();
  if ( eeprom_id.length() > 1 ) {
    WiFi.begin(eeprom_id.c_str(), eeprom_pass.c_str());
    if (testWifi()) {
      return;
    }
  }
}

String getLocalIP(void){
  IPAddress myAddr = WiFi.localIP();
  byte first_octet = myAddr[0];
  byte second_octet = myAddr[1];
  byte third_octet = myAddr[2];
  byte fourth_octet = myAddr[3];
  String  myIP;
  myIP += first_octet;  myIP += ".";
  myIP += second_octet; myIP += ".";
  myIP += third_octet;  myIP += ".";
  myIP += fourth_octet;
  return myIP;
}

void getConnectWiFi(void) {
  eepromWifiConnect();
  String status = "Desconectado";
  String ip;
  String ssid;
  if (testWifi()) {
    status = "Conectado";
    ip     = getLocalIP();
    ssid   = eepromGetId();
  }
  String msg;
  msg += "{";
  msg += " \"status\": \""; msg += status; msg += "\"";
  msg += ",\"ip\": \""; msg += ip; msg += "\"";
  msg += ",\"ssid\": \""; msg += ssid; msg += "\"";
  msg += "}";
  server.send(200, "text/json", msg);
}

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(10);
  WiFi.mode(WIFI_AP_STA);
  delay(100);

  WiFi.softAP(ssid, password);

  eepromWifiConnect();

  // DEFAULT ROUTE
  server.on("/",             HTTP_GET,  getPageRoot);
  // FILES
  server.on("/reset.css",    HTTP_GET,  getResetCss);
  server.on("/base.css",     HTTP_GET,  getBaseCss);
  server.on("/table.css",    HTTP_GET,  getTableCss);
  server.on("/modal.css",    HTTP_GET,  getModalCss);
  server.on("/button.css",   HTTP_GET,  getButtonCss);
  server.on("/input.css",    HTTP_GET,  getInputCss);
  server.on("/base.js",      HTTP_GET,  getBaseJs);
  server.on("/modal.js",     HTTP_GET,  getModalJs);
  // AJAX FUNCTIONS
  server.on("/connect_wifi", HTTP_GET,  getConnectWiFi);
  server.on("/lost_wifi",    HTTP_GET,  getLostWifi);
  server.on("/refresh_wifi", HTTP_GET,  getRefreshWiFi);
  server.on("/save_wifi",    HTTP_POST, postSaveWifi);
  server.begin();
}

void loop() {
  server.handleClient();
}
