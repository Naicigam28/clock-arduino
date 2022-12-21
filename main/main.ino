#include <LiquidCrystal.h>

const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Booting Up");
  Serial.begin(9600);
  lcd.clear();
  lcd.print("00:00:00");
}

int hours=0;
int minutes=0;
int seconds=0;

void handleKeyPad(){
 int x;
  x = analogRead (0); 
  if (x < 100) {
    lcd.print ("Right ");
  }
  else if (x < 300) {
    lcd.print ("Up    ");
    
  }
  else if (x < 500){
    lcd.print ("Down  ");
    
  }
  else if (x < 700){
    lcd.print ("Left  ");
  }
  else if (x < 900){
    lcd.print ("Select  ");
  }
}



void updateClock(){

int first_row=0;
int seconds_pos=7;
int minutes_pos=4;
int hours_pos=1;


seconds++;

if(seconds>=10){
  seconds_pos=6;
}

if(minutes>=10){
  minutes_pos=3;
}

if(hours>=10){
  hours_pos=0;
}

if(minutes>=10){
  minutes_pos=3;
}


if(minutes>=10){
  minutes_pos=3;
}
if(seconds>=10){
  seconds_pos=6;
}
if(seconds>60){
  minutes++;
  seconds=0;
  seconds_pos=7;
}

if(minutes>60){
  hours++;
   minutes=0;
}
if(hours>24){
  hours=0;
    seconds=0;
   minutes=0;
}


lcd.setCursor(hours_pos,first_row);
lcd.print(hours);
lcd.setCursor(minutes_pos,first_row);
lcd.print(minutes);
lcd.setCursor(seconds_pos,first_row);
lcd.print(seconds);
delay(1000);
};


void loop() {
  
  
 
  
  updateClock();
  
 
  

}