function showModal(ssid){
  document.getElementById('ssid').value = ssid;
  document.getElementById('pass').value = '';
  document.getElementById('openModal').classList.add('showModalDialog');
}
function closeModal(){
  document.getElementById('openModal').classList.remove('showModalDialog');
}
function saveAndConnectWifi() {
  var params = new FormData();
  var ssid = document.getElementById('ssid').value;
  var pass = document.getElementById('pass').value;
  params.append('id', ssid);
  params.append('pass', pass);
  post('/save_wifi',params);
  connectWifi();
  closeModal();
}
