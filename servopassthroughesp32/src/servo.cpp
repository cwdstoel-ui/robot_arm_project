#include <Arduino.h>
#include "servo.h"
#include "STSCTRL.h"
#include "SCS.h"
#include <SCServo.h>
#include "SMS_STS.h"
 
 
//SMS_STS st;
 
byte activeNumInList = 0;
 
int const MAX_listID = MAX_VALUES;
int const MAX_posRead = MAX_VALUES;
int const MAX_speedRead = MAX_VALUES; 
float EMA_old_Pos[MAX_VALUES];
float EMA_old_Speed[MAX_VALUES];
struct_message myData;

 
void check_Servo(){

  int j = 0; 
  activeNumInList = 0; 
  for(int i = 1; i <= MAX_ID; i++){
    
    int result_ping = st.Ping(i);
    
    int feedback = st.FeedBack(i);
    
    if(result_ping != -1 && feedback != -1){
    
      myData.listID[j] = i;
      j++; 
      
      activeNumInList = j; 
      // activeNumList = j;
    }
    
  }
    
}

 
void ReadPos_Servo(){

  for(int i = 0; i < activeNumInList; i++){
    int id = myData.listID[i];         
    int Pos = st.ReadPos(id);
    
         
      if(Pos != -1){
       
        float EMA_calc = 0.3 * Pos +(1 - 0.3) * EMA_old_Pos[i];
        myData.posRead[i] = EMA_calc;
        EMA_old_Pos[i] = EMA_calc;   
         
      }
  }
}

void ReadSpeed_Servo(){

  for(int i = 0; i < activeNumInList; i++){
    int id = myData.listID[i];
    int Speed = st.ReadSpeed(id);   
      if(Speed != -1){
    
        float EMA_calc = 0.3 * Speed +(1 - 0.3) * EMA_old_Speed[i];
        myData.speedRead[i] = EMA_calc;
        EMA_old_Speed[i] = EMA_calc;       
        
           
      }
  }
}
  
    
    
  
  
  
  
