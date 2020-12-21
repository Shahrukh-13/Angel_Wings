

#include <Servo.h>
int count =0;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;  
int pos1 = 0;    
int pos2 = 180;

int pos3 = 0;
int pos4 =180;

void setup() 
{
  myservo1.attach(11);     // Right wing Lower servo
  myservo2.attach(10);     // Right wing upper servo
  myservo3.attach(9);      // Left wing lower servo
  myservo4.attach(8);      // Left wing upper servo
  
  pinMode(7, OUTPUT);   // Servo relay
  digitalWrite(7, LOW);  
  
  pinMode(6, INPUT);    //button
  digitalWrite(6, LOW);

  myservo1.write(pos2);
  myservo2.write(pos1);
  myservo3.write(pos3);
  myservo4.write(pos4);

  delay(1000);
  digitalWrite(7,HIGH);
  delay(1000);
}

void loop() 
{
  

  //myservo2.write(100);
 

  //myservo1.write(70);


  if (digitalRead(6)==HIGH)
  {
    //delay(1000);
    if (count==0)
    {
    while(pos2>=50 && pos3<=130)
    {
       pos2=pos2-1;
       pos3=pos3+1;
       myservo1.write(pos2);
       myservo3.write(pos3);
       delay(20);

       

      if(pos1<=100 && pos4>=80)
      {
       pos1=pos1+1;
       pos4=pos4-1;
       myservo2.write(pos1);
       myservo4.write(pos4);
       delay(20);
      }
      //count=1;
    }
     count=1;
    }

    else if(count==1)
    {
    while(pos2<=180 && pos3>=0)
    {
       pos2=pos2+1;
       pos3=pos3-1;
       myservo1.write(pos2);
       myservo3.write(pos3);
       delay(20);

       

      if(pos1>=0 && pos4<=180)
      {
       pos1=pos1-1;
       pos4=pos4+1;
       myservo2.write(pos1);
       myservo4.write(pos4);
       delay(20);
      }
      //count=1;
    }
     count=0;
    }
  }
}

