// REMOVE IT
function seed(){
  data = [{"wifi": [{"totals": "25"},{   "id": "1"  ,"ssid": "GVT-D6C3"  ,"rssi": "-54"  ,"need_password": true},{   "id": "2"  ,"ssid": "AD"  ,"rssi": "-63"  ,"need_password": true},{   "id": "3"  ,"ssid": "Mariza"  ,"rssi": "-60"  ,"need_password": true},{   "id": "4"  ,"ssid": "Maria Eugenia"  ,"rssi": "-77"  ,"need_password": true},{   "id": "5"  ,"ssid": "MC"  ,"rssi": "-79"  ,"need_password": true},{   "id": "6"  ,"ssid": "GVT-9DB7"  ,"rssi": "-83"  ,"need_password": true},{   "id": "7"  ,"ssid": "imunologia"  ,"rssi": "-92"  ,"need_password": true},{   "id": "8"  ,"ssid": "GVT-2C63"  ,"rssi": "-76"  ,"need_password": true},{   "id": "9"  ,"ssid": "GVT-9EA2"  ,"rssi": "-72"  ,"need_password": true},{   "id": "10"  ,"ssid": "FONO "  ,"rssi": "-78"  ,"need_password": true},{   "id": "11"  ,"ssid": "LiderSA"  ,"rssi": "-85"  ,"need_password": true},{   "id": "12"  ,"ssid": "Lucas"  ,"rssi": "-80"  ,"need_password": true},{   "id": "13"  ,"ssid": "RMS-GO"  ,"rssi": "-64"  ,"need_password": true},{   "id": "14"  ,"ssid": "UmaNovaOrdem"  ,"rssi": "-93"  ,"need_password": true},{   "id": "15"  ,"ssid": "GVT-4B97"  ,"rssi": "-86"  ,"need_password": true},{   "id": "16"  ,"ssid": "GVT-E7E4"  ,"rssi": "-76"  ,"need_password": true},{   "id": "17"  ,"ssid": "BEZERRA"  ,"rssi": "-93"  ,"need_password": true},{   "id": "18"  ,"ssid": "GVT-817B"  ,"rssi": "-74"  ,"need_password": true},{   "id": "19"  ,"ssid": "RCA-Interna"  ,"rssi": "-88"  ,"need_password": true},{   "id": "20"  ,"ssid": "APFA 2.4"  ,"rssi": "-75"  ,"need_password": true},{   "id": "21"  ,"ssid": "CILIA"  ,"rssi": "-61"  ,"need_password": true},{   "id": "22"  ,"ssid": "Office"  ,"rssi": "-82"  ,"need_password": true},{   "id": "23"  ,"ssid": "Machado"  ,"rssi": "-92"  ,"need_password": true},{   "id": "24"  ,"ssid": "GVT-E47A"  ,"rssi": "-80"  ,"need_password": true},{   "id": "25"  ,"ssid": "Rodrigues "  ,"rssi": "-82"  ,"need_password": true}]}]
  loadWifi(data);
}
function seedWifiStatus(){
  data = {"status": "Conectado", "ip": "192.168.255.255", "ssid":"BIGGSONNO"};
  loadWifiStatus(data);
}
function seedWifiStatusDisconnect(){
  data = {"status": "Desconectado"};
  loadWifiStatus(data);
}
// END - REMOVE IT
function connectWifi(){
  // loadWifiStatus( get('/connect_wifi') );
  seedWifiStatus();
}
function lostWifi(){
  // loadWifiStatus( get('/lost_wifi') );
  seedWifiStatusDisconnect();
}
function loadWifi(data){
  var item;
  var list = document.getElementById('wifi_list');
  list.innerHTML = '';

  var colors = false;
  var wifi = data[0].wifi;
  wifi.shift();
  wifi.sort(function(a,b){ return parseInt(b.rssi) - parseInt(a.rssi); }).map(function(el){
    var tr = document.createElement('tr');
    if(colors){ tr.className = 'even'; }
    colors = !colors;
    item  = '';
    item += '<td>'+el.ssid+'</td>';
    item += '<td>'+(parseInt(el.rssi)+100)+'%</td>';
    item += '<td>'+el.need_password+'</td>';
    item += '<td><button onclick="showModal(\''+el.ssid+'\')" class="btn">Conectar</button></td>';
    tr.innerHTML = item;
    list.appendChild(tr);
  });
}
function loadWifiStatus(data){
  var list = document.getElementById('wifi_status');
  list.innerHTML = '';
  var tr = document.createElement('tr');
  if(data.status == "Conectado"){
    tr.innerHTML = '<td><center>'+data.status+'</center></td><td>'+data.ssid+'</td><td>'+data.ip+'</td>';
  } else {
    tr.innerHTML = '<td colspan=\'3\'><center>'+data.status+'</center></td>';
  }
  list.appendChild(tr);
}
function get(url) {
  var xhReq = new XMLHttpRequest();
  xhReq.open('GET', url, false);
  xhReq.send(null);
  return xhReq.responseText;
}
function refreshWiFi() {
  // data = JSON.parse( get('/refresh_wifi') );
  // loadWifi( data );
  seed();
}
function lostWifi(){
  data = JSON.parse( get('/lost_wifi') );
  console.log( data );
}
function post(url, params) {
  var xhReq = new XMLHttpRequest();
  xhReq.open('POST', url, false);
  xhReq.send(params);
}
function start_app(){
  connectWifi();
}
