/*
FlyBox2_encoder_module an additional encoder control for FlyBox2 project

Copyright (C) 2020  Andrea Mancini

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <Arduino.h>
#include <setmicro.h>
#include <Encoders.h>
#include <portsetup.h>
#include <Timer.h>



int ENC_delay = 0;
int ENC_click_delay = 100;
int dir_delay = 100; 
int dir = 0;

Encoders_ Enc1(ENC1_CLK,ENC1_DT,ENC1_SW);
Timer_ DirTimer;

void setup() {
  setLed();
  setPort();
}

void loop() {

  if(DirTimer.expired(dir_delay)){
    dir = Enc1.direction(ENC_delay);
    DirTimer.update();
  }
  
  if(dir == 1){
    digitalWrite(ENC1_left,LOW);
    digitalWrite(ENC1_right,HIGH);
    /*Serial.print("ENC1 right = ");
    Serial.print("HIGH");
    Serial.println();*/
  }else if(dir == -1){
    digitalWrite(ENC1_left,HIGH);
    digitalWrite(ENC1_right,LOW);
    /*Serial.print(" ENC1 left = ");
    Serial.println("HIGH");*/
  }else {
    digitalWrite(ENC1_left,LOW);
    digitalWrite(ENC1_right,LOW);
    //Serial.println("stop");
  }

  //Serial.println(digitalRead(ENC1_right));
  
  if(Enc1.click(ENC_click_delay) == LOW){
    digitalWrite(ENC1_SW_OUT, LOW);
    //Serial.println(" ENC1 click");
  }else{
    digitalWrite(ENC1_SW_OUT, HIGH);
    //Serial.println(" ENC1 No click");
  }
    
}

  