#ifndef WIFI_SERVER_H
#define WIFI_SERVER_H

#include<Arduino.h>
#include<WiFi.h>
#include<wifiserver.h>

extern const char* ssdi;
extern const char* password;
extern const int port;
extern wl_status_t wifi_status_check;
extern IPAddress local_IP;
extern WiFiServer Server;

int wifi_init();
//void client_init();
void get_client_data();

#endif 