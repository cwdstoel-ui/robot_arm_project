#ifndef ESP_NOW_H
#define ESP_NOW_H
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

extern int WiFi_init;
extern int ESP_init;
extern int ESP_peer;

extern uint8_t broadcastaddress[6]; //= {0x30, 0xC9, 0x22, 0xB0, 0xA6, 0xFC};  
extern esp_now_peer_info_t peerinfo; 
//esp_now_send_status_t status;              


 

void ESP_NOW_WiFi_init();
void ESP_add_peer();
void ESP_Send();
void ESP_Callbacksetup();
void ESP_callback();
//void Esp_Send_callback();

#endif