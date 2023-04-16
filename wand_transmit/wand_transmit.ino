#include <RH_ASK.h> 
#include <SPI.h>

#define BLUE_SWITCH 4
#define GREEN_SWITCH 5
#define RED_SWITCH 6
#define YELLOW_SWITCH 7

RH_ASK driver;
volatile bool togglestate = false;
volatile char *msg;
volatile bool BLUE_state = false;
volatile bool GREEN_state = false;
volatile bool YELLOW_state = false;
volatile bool RED_state = false; 
  
void transmiter(){
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
} 


void setup() {
  PCICR |= B00000100; // port D is enabled
  PCMSK2 |= B11110000; // to enable pin 4,5,6,7
  pinMode(BLUE_SWITCH,INPUT_PULLUP);
  pinMode(GREEN_SWITCH,INPUT_PULLUP);
  pinMode(RED_SWITCH,INPUT_PULLUP);
  pinMode(YELLOW_SWITCH,INPUT_PULLUP);
  //driver.init;
  //ISR(PCINT2_vect);
  driver.init();
  //Serial.begin(9600);
  //Serial.println("seting up...");
  //attachInterrupt(digitalPinToInterrupt(PRESS_SWICH),transmiter,FALLING);
}

ISR (PCINT2_vect)
{
  if(!togglestate)
  {
    if(digitalRead(BLUE_SWITCH) == LOW){
      msg = BLUE_state ? "B0" : "B1";
      BLUE_state = !BLUE_state;
    }
    else if(digitalRead(GREEN_SWITCH) == LOW){
      msg = GREEN_state ? "G0" : "G1" ;
      GREEN_state = !GREEN_state;
    }
    else if(digitalRead(RED_SWITCH) == LOW){
      msg = RED_state ? "R0" : "R1";
      RED_state = !RED_state;
    }
    else if(digitalRead(YELLOW_SWITCH) == LOW){
      msg = YELLOW_state ? "Y0" : "Y1";
      YELLOW_state = !YELLOW_state;
    }
    togglestate = true;
  }
}


void loop() {
  delay(500);
  /*if(digitalRead(BLUE_SWITCH) == LOW){
      msg = BLUE_state ? "B0" : "B1";
      BLUE_state = !BLUE_state;
    }
    else if(digitalRead(GREEN_SWITCH) == LOW){
      msg = GREEN_state ? "G0" : "G1" ;
      GREEN_state = !GREEN_state;
    }
    else if(digitalRead(RED_SWITCH) == LOW){
      msg = RED_state ? "R0" : "R1";
      RED_state = !RED_state;
    }
    else if(digitalRead(YELLOW_SWITCH) == LOW){
      msg = YELLOW_state ? "Y0" : "Y1";
      YELLOW_state = !YELLOW_state;
    }
    transmiter();*/
  if(togglestate)
  {
    transmiter();
    togglestate = false;
  }
}
