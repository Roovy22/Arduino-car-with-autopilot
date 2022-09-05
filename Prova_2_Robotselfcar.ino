#include <Servo.h>
#include <HCSR04.h>


#define trig 3 //Trigger Ultrasuoni
#define echo 2 //Echo Ultrasuoni

//Motore Destro
const int mad  = 5;  // Pin 14 of L293
const int mbd  = 6;  // Pin 10 of L293
//Motor Sinistro
const int mas  = 10; // Pin  7 of L293
const int mbs  = 9;  // Pin  2 of L293

HCSR04 hc = HCSR04(trig, echo);
long a;
Servo myservo;

int i;

void setup() {
  myservo.attach(11);
  myservo.write(90);

  pinMode(mad, OUTPUT) ;
  pinMode(mbd, OUTPUT) ;
  pinMode(mas, OUTPUT) ;
  pinMode(mbs, OUTPUT) ;
  Serial.begin(9600);
  delay(60);
}

void loop() {

  a = hc.dist();
  Serial.println(a);

  myservo.write(90);

  delay(500);

  if (a > 10) {
    drive_forward();
  } else if (a < 10) {
    motor_stop();
    myservo.write(0);
    a = hc.dist();
    Serial.println(a);
    delay(200);
    a = hc.dist();
    Serial.println(a);
    delay(200);
    a = hc.dist();
    Serial.println(a);
    delay(200);
    a = hc.dist();
    Serial.println(a);
    delay(200);
    if (a > 10) {
        turn_right();
        delay(1000);
      drive_forward();
    } else if (a < 10) {
      motor_stop();
      myservo.write(180);
      a = hc.dist();
      Serial.println(a);
      delay(200);
      a = hc.dist();
      Serial.println(a);
      delay(200);
      a = hc.dist();
      Serial.println(a);
      delay(200);
      a = hc.dist();
      Serial.println(a);
      delay(200);
      if (a > 10) {
        
          turn_left();
          delay(1000);
         drive_forward();
      }
    }

  }
}
//-------------------------//||\\-------------------------\\

void motor_stop() {
  digitalWrite(mas, LOW);
  digitalWrite(mbs, LOW);
  digitalWrite(mad, LOW);
  digitalWrite(mbd, LOW);
  delay(25);
}
void drive_forward() {
  digitalWrite(mas, HIGH);
  digitalWrite(mbs, LOW);
  digitalWrite(mad, HIGH);
  digitalWrite(mbd, LOW);
}
void drive_backward() {
  digitalWrite(mas, LOW);
  digitalWrite(mbs, HIGH);
  digitalWrite(mad, LOW);
  digitalWrite(mbd, HIGH);
}
void turn_left() {
  digitalWrite(mas, LOW);
  digitalWrite(mbs, HIGH);
  digitalWrite(mad, HIGH);
  digitalWrite(mbd, LOW);
}
void turn_right() {
  digitalWrite(mas, HIGH);
  digitalWrite(mbs, LOW);
  digitalWrite(mad, LOW);
  digitalWrite(mbd, HIGH);
}
