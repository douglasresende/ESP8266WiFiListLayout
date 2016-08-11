/*
  ESP8266WiFiListLayout.h - Library for show a great layout to wifi list.
  Created by Douglas R Camargo, November 27, 2015.
  Released into the public domain.
*/

#ifndef ESP8266WiFiListLayout_h
#define ESP8266WiFiListLayout_h

// #include "arduino.h"

class ESP8266WiFiListLayout
{
  public:
    ESP8266WiFiListLayout();
    String resetCss();
    String baseCss();
    String tableCss();
    String modalCss();
    String buttonCss();
    String inputCss();
    String baseJs();
    String modalJs();
    String pageRootHtml();
  private:
};

#endif

