function get(url) {
  var xhReq = new XMLHttpRequest();
  xhReq.open('GET', url, false);
  xhReq.send(null);
  return xhReq.responseText;
}
function connectWifi(){
  data = JSON.parse( get('/connect_wifi') );
  loadWifiStatus( data );
}
function lostWifi(){
  data = JSON.parse( get('/lost_wifi') );
  loadWifiStatus( data );
}
function loadWifiStatus(data){
  var list = document.getElementById('wifi_status');
  list.innerHTML = '';
  var tr = document.createElement('tr');
  if(data.status == 'Conectado'){
    tr.innerHTML = '<td><center>'+data.status+'</center></td><td>'+data.ssid+'</td><td>'+data.ip+'</td>';
  } else {
    tr.innerHTML = '<td colspan=\"3\"><center>'+data.status+'</center></td>';
  }
  list.appendChild(tr);
}
function refreshWiFi() {
  data = JSON.parse( get('/refresh_wifi') );
  loadWifi( data );
}
function post(url,params) {
  var xhReq = new XMLHttpRequest();
  xhReq.open('POST', url, false);
  xhReq.send(params);
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
    item += '<td><button onclick=\"showModal(\\''+el.ssid+'\\')\" class=\"btn\">Conectar</button></td>';
    tr.innerHTML = item;
    list.appendChild(tr);
  });
}
function start_app(){
  connectWifi();
}
