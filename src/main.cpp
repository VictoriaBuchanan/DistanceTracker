#include <Arduino.h>
#include <SR04.h>

// Defines the pins for the LEDs
#define RED1 7
#define GREEN1 6
#define BLUE1 5
#define RED2 4
#define GREEN2 3
#define BLUE2 2

// Defines the pins for the HC-SR04
#define ECHO_PIN 13
#define TRIG_PIN 11

// Stores the distance value
float distance;

// Creates the object for the ultrasonic module
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

//Setups the sonar object using the NewPing library

void setBothBlue(bool on){
  if(on == true){
    digitalWrite(BLUE1, HIGH);
    digitalWrite(BLUE2, HIGH);
  } else {
    digitalWrite(BLUE1, LOW);
    digitalWrite(BLUE2, LOW);
  }
}

void setBothGreen(bool on){
  if(on == true){
    digitalWrite(GREEN1, HIGH);
    digitalWrite(GREEN2, HIGH);
  } else {
    digitalWrite(GREEN1, LOW);
    digitalWrite(GREEN2, LOW);
  }
}

void setBothRed(bool on){
  if(on == true){
    digitalWrite(RED1, HIGH);
    digitalWrite(RED2, HIGH);
  } else {
    digitalWrite(RED1, LOW);
    digitalWrite(RED2, LOW);
  }
}

void setup() {
  // Starts the serial monitor
  Serial.begin(9600);

  //Setup for the lights
  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(BLUE1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(BLUE2, OUTPUT);

}

void loop() {

}