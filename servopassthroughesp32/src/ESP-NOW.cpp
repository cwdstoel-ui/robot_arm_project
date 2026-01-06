#include "ESP-NOW.h"
#include "servo.h"


uint8_t broadcastaddress[6] = {0x30, 0xC9, 0x22, 0xB0, 0xA6, 0xFC}; 
void Data_send(const uint8_t *mac_addr, esp_now_send_status_t status);

esp_now_peer_info_t peerinfo = {}; 

void ESP_NOW_WiFi_init(){  

//WiFi.mode(WIFI_STA);
 

esp_err_t ESP_init = esp_now_init();
    
    if(ESP_init != ESP_OK){

        Serial.printf(" failed %d",ESP_init);
    }
}


void ESP_add_peer(){
    
peerinfo;
memcpy( peerinfo.peer_addr,broadcastaddress,6);
peerinfo.channel = 0;
peerinfo.ifidx = WIFI_IF_STA;
peerinfo.encrypt = false;
peerinfo.priv = NULL;

esp_err_t add_peer = esp_now_add_peer(&peerinfo);
    
    if(add_peer == ESP_OK){
        Serial.printf("added");
    }

    if(add_peer != ESP_OK){
       Serial.printf("add peer failed %d: ",add_peer);
    }


}

void ESP_Send(){

   esp_err_t result_send = esp_now_send(peerinfo.peer_addr,(uint8_t *) &myData,sizeof(myData));
    


    if(result_send != ESP_OK){
        
        Serial.printf(" Send failed %d ",result_send);
    }

     
} 

void ESP_Callbacksetup(const uint8_t *mac_addr, esp_now_send_status_t status){

    

    if(mac_addr == NULL){
        
        Serial.printf("mac_addr not found");
    }

    esp_now_send_status_t status_check = status; 

    if(status_check != ESP_NOW_SEND_SUCCESS){

        Serial.printf("error %d", status_check);
    }

    
}

void ESP_callback(){
    
    esp_err_t callback = esp_now_register_send_cb(ESP_Callbacksetup);

    if(callback != ESP_OK){

        Serial.printf("callback failed: %d",callback);

    }

    
}
    

     


