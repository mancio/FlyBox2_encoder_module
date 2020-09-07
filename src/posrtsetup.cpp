#include <portsetup.h>
#include <Arduino.h>
//#include <main.cpp>


// keep off for better performance
/*void activeSerial(){
    Serial.begin(9600);
}*/

void setPort(){
    pinMode(ENC1_CLK, INPUT);
    pinMode(ENC1_DT, INPUT);
    pinMode(ENC1_SW, INPUT);
    pinMode(ENC1_right, OUTPUT);
    pinMode(ENC1_left, OUTPUT);
    pinMode(ENC1_SW_OUT, OUTPUT);
}

void resetEnc(){
    digitalWrite(ENC1_left, LOW);
    digitalWrite(ENC1_right, LOW);
}