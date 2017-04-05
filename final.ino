#include <Servo.h>

Servo servo;
int angle = 10;
int Lm35Pin= A1;

void setup() {
 Serial.begin(9600);
 pinMode(8, OUTPUT);
 servo.attach(10);
 servo.write(angle);
}

void loop() {
 int avalue;
 float temp;
 avalue=analogRead(Lm35Pin);
 temp=float(avalue)/1023;
 temp=temp*500;
 Serial.print("Temperature is: ");
 Serial.print(temp);
 Serial.println(" C");
 delay(500);
 if(temp>=29)
 digitalWrite(8, HIGH);
 if(temp>=30)
  { 
   for(angle = 0; angle < 140; angle++)  
    { servo.write(angle); 
       delay(5); 
    } 
  // delay(4000);
  }
 if(temp<29)
  { digitalWrite(8,LOW);
    for(angle = 140; angle >0; angle--)    
     { servo.write(angle);
       delay(5);
     } 
   delay(4000);
  } 
}
