//-----------------------------------------------------------------
// LIBARIES & HEADERS
//-----------------------------------------------------------------
#include <Arduino.h>
#include <SR04.h>

//-----------------------------------------------------------------
// LEDS
//-----------------------------------------------------------------
// Defines the pins for the LEDs
#define RED1 7
#define GREEN1 6
#define BLUE1 5
#define RED2 4
#define GREEN2 3
#define BLUE2 2

//-----------------------------------------------------------------
// ULTRASONIC DEVICE (SR04)
//-----------------------------------------------------------------
// Defines the pins for the HC-SR04
#define ECHO_PIN 13
#define TRIG_PIN 11

// Stores the distance value
float distance;

// Creates the object for the ultrasonic module
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

// Variables for the various distance thresholds
// The SR04 cannot determine distances past 400cm so the scale caps there
float t1 = 52.00;
float t2 = 102.00;
float t3 = 152.00;
float t4 = 202.00;
float t5 = 252.00;
float t6 = 302.00;
float t7 = 352.00;
float t8 = 400.00;

//-----------------------------------------------------------------
// FUNCTIONS
//-----------------------------------------------------------------
/*
Sets the R, G and B values of the two four pin RGB LEDs.
@param red is true when both red lights should be lit up, otherwise it is false
@param green is true when both green lights should be lit up, otherwise it is false
@param blue is true when both blue lights should be lit up, otherwise it is false
*/
void setAllColors(bool red, bool green, bool blue)
{
  setBothRed(red);
  setBothGreen(green);
  setBothBlue(blue);
}

/*
Sets the blue value for the two RGB LEDs to HIGH if the functions parameter is true, otherwise it sets it to LOW.
@param on is true when both blue lights should be on, otherwise it is false
*/
void setBothBlue(bool on)
{
  if (on == true)
  {
    digitalWrite(BLUE1, HIGH);
    digitalWrite(BLUE2, HIGH);
  }
  else
  {
    digitalWrite(BLUE1, LOW);
    digitalWrite(BLUE2, LOW);
  }
}

/*
Sets the green value for the two RGB LEDs to HIGH if the functions parameter is true, otherwise it sets it to LOW.
@param on is true when both green lights should be on, otherwise it is false
*/
void setBothGreen(bool on)
{
  if (on == true)
  {
    digitalWrite(GREEN1, HIGH);
    digitalWrite(GREEN2, HIGH);
  }
  else
  {
    digitalWrite(GREEN1, LOW);
    digitalWrite(GREEN2, LOW);
  }
}

/*
Sets the red value for the two RGB LEDs to HIGH if the functions parameter is true, otherwise it sets it to LOW.
@param on is true when both reds lights should be on, otherwise it is false
*/
void setBothRed(bool on)
{
  if (on == true)
  {
    digitalWrite(RED1, HIGH);
    digitalWrite(RED2, HIGH);
  }
  else
  {
    digitalWrite(RED1, LOW);
    digitalWrite(RED2, LOW);
  }
}

//-----------------------------------------------------------------
// MAIN PROGRAM
//-----------------------------------------------------------------

void setup()
{
  //Pin setup for the two RGB LEDS
  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(BLUE1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(BLUE2, OUTPUT);
}

void loop()
{
  // Gets the distance from the SR04
  distance = sr04.Distance();

  // Determines which LED should light up (and in what color) based on the distance an object is from the sensor
  if (distance <= t1)
  {
    setAllColors(true, false, false);
  }
  else if (distance > t1 && distance <= t2)
  {
    setAllColors(false, false, false);
    digitalWrite(RED1, HIGH);
  }
  else if (distance > t2 && distance <= t3)
  {
    setAllColors(false, false, false);
    digitalWrite(BLUE1, HIGH);
  }
  else if (distance > t3 && distance <= t4)
  {
    setAllColors(false, false, true);
  }
  else if (distance > t4 && distance <= t5)
  {
    setAllColors(false, false, false);
    digitalWrite(GREEN1, HIGH);
  }
  else if (distance > t5 && distance <= t6)
  {
    setAllColors(false, true, false);
  }
  else if (distance > t6 && distance <= t7)
  {
    digitalWrite(RED1, HIGH);
    digitalWrite(RED2, LOW);
    digitalWrite(GREEN1, HIGH);
    digitalWrite(GREEN2, LOW);
    digitalWrite(BLUE1, HIGH);
    digitalWrite(BLUE2, LOW);
  }
  else if (distance <= t8)
  {
    setAllColors(true, true, true);
  }
  else
  {
    setAllColors(false, false, false);
  }
  //Creates a 2s delay between when the ultrasonic pings from the SR04
  delay(2000);
}