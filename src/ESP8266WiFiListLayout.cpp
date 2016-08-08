/*
  ESP8266WiFiListLayout.cpp - Library for show a great layout to wifi list.
  Created by Douglas R Camargo, November 27, 2015.
  Released into the public domain.
*/

#include "arduino.h"
#include "ESP8266WiFiListLayout.h"

ESP8266WiFiListLayout::ESP8266WiFiListLayout()
{
}

String ESP8266WiFiListLayout::resetCss()
{
  String css = "body,html{height:100%}a,abbr,acronym,address,applet,b,big,blockquote,body,caption,center,cite,code,dd,del,dfn,div,dl,dt,em,fieldset,font,form,html,i,iframe,img,ins,kbd,label,legend,li,object,ol,p,pre,q,s,samp,small,span,strike,strong,sub,sup,table,tbody,td,tfoot,th,thead,tr,tt,u,ul,var{margin:0;padding:0;border:0;outline:0;font-size:100%;vertical-align:baseline;background:0 0}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:after,blockquote:before,q:after,q:before{content:'';content:none}:focus{outline:0}del{text-decoration:line-through}table{border-spacing:0}";
  return css;
}

String ESP8266WiFiListLayout::baseCss()
{
  String css;
  css += "body {";
  css += "  font-family:Arial, Helvetica, sans-serif;";
  css += "  background-color: #f9f9f9;";
  css += "  margin:0 auto;";
  css += "  width:540px;";
  css += "  font-size:12px;";
  css += "}";
  css += ".center {";
  css += "  text-align: center !important;";
  css += "}";
  css += ".wifi_form {";
  css += "  width: 100%;";
  css += "  margin: 0px;";
  css += "}";
  return css;
}

String ESP8266WiFiListLayout::tableCss()
{
  String css;
 css += "table {";
 css += "  color:#666;";
 css += "  width: 500px;";
 css += "  text-shadow: 1px 1px 0px #fff;";
 css += "  background:#eaebec;";
 css += "  margin:10px;";
 css += "  border:#ccc 1px solid;";
 css += "  -moz-border-radius:3px;";
 css += "  -webkit-border-radius:3px;";
 css += "  border-radius:3px;";
 css += "  -moz-box-shadow: 0 1px 2px #d1d1d1;";
 css += "  -webkit-box-shadow: 0 1px 2px #d1d1d1;";
 css += "  box-shadow: 0 1px 2px #d1d1d1;";
 css += "}";
 css += "table th {";
 css += "  padding: 8px;";
 css += "  border-top:1px solid #fafafa;";
 css += "  border-bottom:1px solid #e0e0e0;";
 css += "  background: #dff0FF;";
 css += "  background: -webkit-gradient(linear, left top, left bottom, from(#ffffff), to(#dff0FF));";
 css += "  background: -moz-linear-gradient(top,  #ffffff,  #dff0FF);";
 css += "}";
 css += "table th:first-child{";
 css += "  text-align: left;";
 css += "  padding-left:20px;";
 css += "}";
 css += "table tr:first-child th:first-child{";
 css += "  -moz-border-radius-topleft:3px;";
 css += "  -webkit-border-top-left-radius:3px;";
 css += "  border-top-left-radius:3px;";
 css += "}";
 css += "table tr:first-child th:last-child{";
 css += "  -moz-border-radius-topright:3px;";
 css += "  -webkit-border-top-right-radius:3px;";
 css += "  border-top-right-radius:3px;";
 css += "}";
 css += "table tr{";
 css += "  text-align: center;";
 css += "  padding-left:20px;";
 css += "}";
 css += "table tr td:first-child{";
 css += "  text-align: left;";
 css += "  padding-left:20px;";
 css += "  border-left: 0;";
 css += "}";
 css += "table tr td {";
 css += "  padding: 8px;";
 css += "  border-top: 1px solid #ffffff;";
 css += "  border-bottom:1px solid #e0e0e0;";
 css += "  border-left: 1px solid #e0e0e0;";
 css += "  background: #fafafa;";
 css += "  background: -webkit-gradient(linear, left top, left bottom, from(#fbfbfb), to(#fafafa));";
 css += "  background: -moz-linear-gradient(top,  #fbfbfb,  #fafafa);";
 css += "}";
 css += "table tr.even td{";
 css += "  background: #f6f6f6;";
 css += "  background: -webkit-gradient(linear, left top, left bottom, from(#f8f8f8), to(#f6f6f6));";
 css += "  background: -moz-linear-gradient(top,  #f8f8f8,  #f6f6f6);";
 css += "}";
 css += "table tr:last-child td{";
 css += "  border-bottom:0;";
 css += "}";
 css += "table tr:last-child td:first-child{";
 css += "  -moz-border-radius-bottomleft:3px;";
 css += "  -webkit-border-bottom-left-radius:3px;";
 css += "  border-bottom-left-radius:3px;";
 css += "}";
 css += "table tr:last-child td:last-child{";
 css += "  -moz-border-radius-bottomright:3px;";
 css += "  -webkit-border-bottom-right-radius:3px;";
 css += "  border-bottom-right-radius:3px;";
 css += "}";
 css += "table tr:hover td{";
 css += "  background: #f2f2f2;";
 css += "  background: -webkit-gradient(linear, left top, left bottom, from(#f2f2f2), to(#f0f0f0));";
 css += "  background: -moz-linear-gradient(top,  #f2f2f2,  #f0f0f0);";
 css += "}";
  return css;
}

String ESP8266WiFiListLayout::modalCss()
{
  String css;
  css += ".modalDialog {";
  css += "  position: fixed;";
  css += "  font-family: Arial, Helvetica, sans-serif;";
  css += "  top: 0;";
  css += "  right: 0;";
  css += "  bottom: 0;";
  css += "  left: 0;";
  css += "  background: rgba(0, 0, 0, 0.6);";
  css += "  z-index: 99999;";
  css += "  opacity:0;";
  css += "  -webkit-transition: opacity 200ms ease-in;";
  css += "  -moz-transition: opacity 200ms ease-in;";
  css += "  transition: opacity 200ms ease-in;";
  css += "  pointer-events: none;";
  css += "}";
  css += ".showModalDialog {";
  css += "  opacity:1;";
  css += "  pointer-events: auto;";
  css += "}";
  css += ".modalDialog > div {";
  css += "  width: 260px;";
  css += "  position: relative;";
  css += "  margin: 10% auto;";
  css += "  padding: 10px;";
  css += "  border-radius: 6px;";
  css += "  background: #fff;";
  css += "}";
  return css;
}

String ESP8266WiFiListLayout::buttonCss()
{
  String css;
  css += ".btn {";
  css += "  padding: 1px 5px;";
  css += "  font-size: 12px;";
  css += "  line-height: 1.5;";
  css += "  border-radius: 3px;";
  css += "  border: #357ebd solid 1px;";
  css += "  display: inline-block;";
  css += "  text-decoration: none;";
  css += "  text-align: center;";
  css += "  min-width: 60px;";
  css += "  position: relative;";
  css += "  cursor: pointer;";
  css += "  color: rgb(51, 51, 51);";
  css += "  text-shadow: rgb(255, 255, 255) 0px 1px 0px;";
  css += "  background-image: linear-gradient(rgb(255, 255, 255) 0%, rgb(234, 234, 234) 100%);";
  css += "  background-repeat: repeat-x;";
  css += "  border-color: rgb(204, 204, 204);";
  css += "  box-shadow: rgba(255, 255, 255, 0.14902) 0px 1px 0px inset, rgba(0, 0, 0, 0.0745098) 0px 1px 1px;";
  css += "}";
  css += ".btn:hover {";
  css += "  color: #333333;";
  css += "  background-image: linear-gradient(rgb(255, 255, 255) 0%, rgb(244, 244, 244) 100%);";
  css += "  border-color: #adadad;";
  css += "}";
  css += "[role=\"button\"] {";
  css += "  cursor: pointer;";
  css += "}";
  return css;
}

String ESP8266WiFiListLayout::inputCss()
{
  String css;
  css += ".form-control {";
  css += "  display: inline-block;";
  css += "  width: auto;";
  css += "  vertical-align: middle;";
  css += "  height: 30px;";
  css += "  padding: 0px 6px;";
  css += "  font-size: 12px;";
  css += "  line-height: 1.42857143;";
  css += "  color: #555;";
  css += "  background-color: #fff;";
  css += "  background-image: none;";
  css += "  border: 1px solid #ccc;";
  css += "  border-radius: 4px;";
  css += "  -webkit-box-shadow: inset 0 1px 1px rgba(0,0,0,.075);";
  css += "  box-shadow: inset 0 1px 1px rgba(0,0,0,.075);";
  css += "  -webkit-transition: border-color ease-in-out .15s,-webkit-box-shadow ease-in-out .15s;";
  css += "  -o-transition: border-color ease-in-out .15s,box-shadow ease-in-out .15s;";
  css += "  transition: border-color ease-in-out .15s,box-shadow ease-in-out .15s;";
  css += "}";
  css += ".form-control[disabled] {";
  css += "  background-color: #eee;";
  css += "  opacity: 1;";
  css += "}";
  return css;
}

String ESP8266WiFiListLayout::baseJs()
{
  String js;
  js += "function get(url) {";
  js += "  var xhReq = new XMLHttpRequest();";
  js += "  xhReq.open('GET', url, false);";
  js += "  xhReq.send(null);";
  js += "  return xhReq.responseText;";
  js += "}";
  js += "function connectWifi(){";
  js += "  data = JSON.parse( get('/connect_wifi') );";
  js += "  loadWifiStatus( data );";
  js += "}";
  js += "function lostWifi(){";
  js += "  data = JSON.parse( get('/lost_wifi') );";
  js += "  loadWifiStatus( data );";
  js += "}";
  js += "function loadWifiStatus(data){";
  js += "  var list = document.getElementById('wifi_status');";
  js += "  list.innerHTML = '';";
  js += "  var tr = document.createElement('tr');";
  js += "  if(data.status == 'Conectado'){";
  js += "    tr.innerHTML = '<td><center>'+data.status+'</center></td><td>'+data.ssid+'</td><td>'+data.ip+'</td>';";
  js += "  } else {";
  js += "    tr.innerHTML = '<td colspan=\"3\"><center>'+data.status+'</center></td>';";
  js += "  }";
  js += "  list.appendChild(tr);";
  js += "}";
  js += "function refreshWiFi() {";
  js += "  data = JSON.parse( get('/refresh_wifi') );";
  js += "  loadWifi( data );";
  js += "}";
  js += "function post(url,params) {";
  js += "  var xhReq = new XMLHttpRequest();";
  js += "  xhReq.open('POST', url, false);";
  js += "  xhReq.send(params);";
  js += "}";
  js += "function loadWifi(data){";
  js += "  var item;";
  js += "  var list = document.getElementById('wifi_list');";
  js += "  list.innerHTML = '';";
  js += "  var colors = false;";
  js += "  var wifi = data[0].wifi;";
  js += "  wifi.shift();";
  js += "  wifi.sort(function(a,b){ return parseInt(b.rssi) - parseInt(a.rssi); }).map(function(el){";
  js += "    var tr = document.createElement('tr');";
  js += "    if(colors){ tr.className = 'even'; }";
  js += "    colors = !colors;";
  js += "    item  = '';";
  js += "    item += '<td>'+el.ssid+'</td>';";
  js += "    item += '<td>'+(parseInt(el.rssi)+100)+'%</td>';";
  js += "    item += '<td>'+el.need_password+'</td>';";
  js += "    item += '<td><button onclick=\"showModal(\\''+el.ssid+'\\')\" class=\"btn\">Conectar</button></td>';";
  js += "    tr.innerHTML = item;";
  js += "    list.appendChild(tr);";
  js += "  });";
  js += "}";
  js += "function start_app(){";
  js += "  connectWifi();";
  js += "}";
  return js;
}

String ESP8266WiFiListLayout::modalJs()
{
  String js;
  js += "function showModal(ssid){";
  js += "  document.getElementById('ssid').value = ssid;";
  js += "  document.getElementById('pass').value = '';";
  js += "  document.getElementById('openModal').classList.add('showModalDialog');";
  js += "}";
  js += "function closeModal(){";
  js += "  document.getElementById('openModal').classList.remove('showModalDialog');";
  js += "}";
  js += "function saveAndConnectWifi() {";
  js += "  var params = new FormData();";
  js += "  var ssid = document.getElementById('ssid').value;";
  js += "  var pass = document.getElementById('pass').value;";
  js += "  params.append('id', ssid);";
  js += "  params.append('pass', pass);";
  js += "  post('/save_wifi',params);";
  js += "  connectWifi();";
  js += "  closeModal();";
  js += "}";
  return js;
}

String ESP8266WiFiListLayout::pageRootHtml()
{
  String html;
  html += "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">";
  html += "<html xmlns='http://www.w3.org/1999/xhtml'>";
  html += "<head>";
  html += "  <meta http-equiv='Content-Type' content='text/html; charset=utf-8' />";
  html += "  <title>ESP8266</title>";
  html += "  <link rel='stylesheet' href='reset.css'>";
  html += "  <link rel='stylesheet' href='base.css'>";
  html += "  <link rel='stylesheet' href='table.css'>";
  html += "  <link rel='stylesheet' href='modal.css'>";
  html += "  <link rel='stylesheet' href='button.css'>";
  html += "  <link rel='stylesheet' href='input.css'>";
  html += "  <script type='text/javascript' src='base.js'></script>";
  html += "  <script type='text/javascript' src='modal.js'></script>";
  html += "</head>";
  html += "<body onload='start_app()'>";
  html += "  <table cellspacing='0'>";
  html += "    <thead>";
  html += "      <tr>";
  html += "        <th>";
  html += "          Status";
  html += "          <button class='btn' onclick='connectWifi()'>Refresh</button>";
  html += "          <button class='btn' onclick='lostWifi()'>Lost WiFi</button>";
  html += "        </th>";
  html += "        <th>Wifi</th>";
  html += "        <th>IP</th>";
  html += "      </tr>";
  html += "    </thead>";
  html += "    <tbody id='wifi_status'>";
  html += "      <tr>";
  html += "        <td colspan='3'>";
  html += "          <center>Disconnected</center>";
  html += "        </td>";
  html += "      </tr>";
  html += "    </tbody>";
  html += "  </table>";
  html += "  <table cellspacing='0'>";
  html += "    <thead>";
  html += "      <tr>";
  html += "        <th>";
  html += "          WiFi";
  html += "          <button class='btn' onclick='refreshWiFi()'>Refresh</button>";
  html += "        </th>";
  html += "        <th>Power</th>";
  html += "        <th>Pass?</th>";
  html += "        <th>Connect?</th>";
  html += "      </tr>";
  html += "    </thead>";
  html += "    <tbody id='wifi_list'>";
  html += "      <tr>";
  html += "        <td colspan='4'>";
  html += "          <center>Wifi not found</center>";
  html += "        </td>";
  html += "      </tr>";
  html += "    </tbody>";
  html += "  </table>";
  html += "  <div id='openModal' class='modalDialog'>";
  html += "    <div>";
  html += "      <table class='wifi_form'>";
  html += "        <thead>";
  html += "          <tr>";
  html += "            <th colspan='2'>Please enter password:</th>";
  html += "          </tr>";
  html += "        </thead>";
  html += "        <tr>";
  html += "          <td><strong>SSID:</strong></td>";
  html += "          <td><input type='text' id='ssid' class='form-control' disabled='disabled'/></td>";
  html += "        </tr>";
  html += "        <tr>";
  html += "          <td><strong>Pass:</strong></td>";
  html += "          <td><input type='password' id='pass' class='form-control'/></td>";
  html += "        </tr>";
  html += "        <tr class='even'>";
  html += "          <td colspan='2' class='center'>";
  html += "            <button class='btn' onclick='saveAndConnectWifi()'>Connect</button>";
  html += "            <button class='btn' onclick='closeModal()'>Cancel</button>";
  html += "          </td>";
  html += "        </tr>";
  html += "      </table>";
  html += "    </div>";
  html += "  </div>";
  html += "</body>";
  html += "</html>";
  return html;
}
