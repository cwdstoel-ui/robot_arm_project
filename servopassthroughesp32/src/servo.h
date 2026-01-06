#ifndef SERVO_H
#define SERVO_H
#include <Arduino.h>
#include "SCSCL.h"
#include "SCS.h"
#include "INST.h"
#include <SCServo.h>

 

 
constexpr int MAX_ID = 6;
constexpr int MAX_VALUES = 6; 
extern const int MAX_listID;
extern const int MAX_posRead;
extern const int MAX_speedRead; 
extern float EMA_old_Pos[MAX_VALUES];
extern float EMA_old_Speed[MAX_VALUES];
 
 
void check_Servo();
void ReadPos_Servo();
void ReadSpeed_Servo();
 

typedef struct struct_message {
byte listID[MAX_ID];
s16 posRead[MAX_VALUES];
s16 speedRead[MAX_VALUES];
} struct_message;

// Create a struct_message called myData
extern struct_message myData;

#endif
