#include<RH_ASK.h>
#include<SPI.h>
#define BLUE_LED 5
#define GREEN_LED 6
#define RED_LED 7
#define YELLOW_LED 4


RH_ASK driver;

//volatile bool tooglestage = false;
  

void reciever(){
 uint8_t buf[2];
 uint8_t buflen = sizeof(buf);
   if(driver.recv(buf, &buflen))
   { 
      Serial.println((char*)buf);

    if(strncmp((char*)buf,"B1", buflen) == 0)
    {
      digitalWrite(BLUE_LED,HIGH);
    }
    else if(strncmp((char*)buf,"B0", buflen) == 0)
    {
      digitalWrite(BLUE_LED,LOW);
      }
    else if(strncmp((char*)buf,"G1", buflen) == 0)
    {
      digitalWrite(GREEN_LED,HIGH);  
    }
    else if(strncmp((char*)buf,"G0", buflen) == 0)
    {
      digitalWrite(GREEN_LED,LOW);
      }
    else if(strncmp((char*)buf,"R1", buflen) == 0)
    {
      digitalWrite(RED_LED,HIGH);
    }
    else if(strncmp((char*)buf,"R0", buflen) == 0)
    {
      digitalWrite(RED_LED,LOW);
      }
    else if(strncmp((char*)buf,"Y1", buflen) == 0)
    {
    digitalWrite(YELLOW_LED,HIGH);  
    }
    else if(strncmp((char*)buf,"Y0", buflen) == 0)
    {
      digitalWrite(YELLOW_LED,LOW);
      }
    }
  }

void setup() {
  Serial.begin(9600);
  //Serial.println("seting up...");
  pinMode(BLUE_LED,OUTPUT);
  digitalWrite(BLUE_LED,LOW);
  pinMode(GREEN_LED,OUTPUT);
  digitalWrite(GREEN_LED,LOW);
  pinMode(RED_LED,OUTPUT);
  digitalWrite(RED_LED,LOW);
  pinMode(YELLOW_LED,OUTPUT);
  digitalWrite(YELLOW_LED,LOW);
  driver.init();  
}

void loop() {
     
reciever();//run function"reciever"
}
