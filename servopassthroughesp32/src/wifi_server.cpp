#include"wifi_server.h"

const char* ssdi = "iotroam";
const char* password = "Pu43yVUPO6";
const int port = 5000;
wl_status_t wifi_status_check = WL_IDLE_STATUS;
IPAddress local_IP;
WiFiServer Server(port);




int wifi_init(){

bool wifi_mode_check = WiFi.mode(WIFI_STA);

    if(wifi_mode_check != true){

        Serial.printf("wifi mode init: %d\n", wifi_mode_check);

        return 0;
    }

    else{

        Serial.printf("wifi mode init: %d\n", wifi_mode_check);

        

    }

wifi_mode_t wifi_get_mode_check = WiFi.getMode();

    if(wifi_get_mode_check != WIFI_STA){

        Serial.printf("wifi mode: %d\n", wifi_get_mode_check);

        return 0;
    }


    else{

        Serial.printf("wifi mode: %d\n", wifi_get_mode_check);

        

    }


WiFi.begin(ssdi,password);


while(wifi_status_check != WL_CONNECTED){ 

    wifi_status_check = WiFi.status();


    Serial.printf("wifi status is: %d\n",wifi_status_check);


}

  
Serial.println(WiFi.localIP());

Server.begin();

return 1;

}

WiFiClient client; 


void get_client_data(){

  

    if(!client){


        client =  Server.available();

        Serial.printf("no client detected");
       

    }


    if(client.available()){
       
        int message =  client.read();


       Serial.printf("message is %d\n",message);
    }
}




