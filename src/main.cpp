#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(10, 11, 12, 13, 14, 15); // rs,en,data pins d4 -d7

int motorPort = 16; // Motor Pin
int motorSpeed = 0; // Motor Value- Initially Zero

String encodedVal = "";

const int incPort = 3; // increment switch
int SW1INC = 1;
const int decPort = 2; // Decrement Switch
int SW2DEC = 1;

// Encoder input ports
const int S1E = 6;
const int S2E = 7;
const int S3E = 8;
const int S4E = 9;

// Initial Encoded val
int S11E = 1;
int S12E = 1;
int S13E = 1;
int S14E = 1;
int speed = 0;
int speedLimit = 100;

void setup()
{

  lcd.begin(16, 2);
  analogWrite(motorPort, motorSpeed); // setting motor speed to zero
  // Declaring switches
  pinMode(incPort, INPUT_PULLUP);
  pinMode(decPort, INPUT_PULLUP);
  // setting input port for encoder
  pinMode(S1E, INPUT);
  pinMode(S2E, INPUT);
  pinMode(S3E, INPUT);
  pinMode(S4E, INPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vehicle Speed");
  lcd.setCursor(0, 1);
  lcd.print("Limit Controller");
  delay(5000);
  lcd.clear();
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Speed: " + String(speed) + "       "); // printing speed on display
  lcd.setCursor(0, 1);
  lcd.print("Road Limit: " + String(speedLimit) + "       "); // displayinng speed limit

  // giving voltage to motor
  analogWrite(16, speed * 255 / 100);

  // increasing speed
  if (digitalRead(incPort))
  {
    // checking for speed is lessthan 100
    if (speed <= 100)
    {
      speed += 10; // increasing by 10
    }
  }
  // decreasing speed on button press and speed is greater than 0
  if (digitalRead(decPort) && speed > 0)
  {
    speed -= 10; // decreasing by 10
  }
  // port S1E Status- HIGH/LOW
  S11E = digitalRead(S1E);
  // port S2E Status- HIGH/LOW
  S12E = digitalRead(S2E);
  // port S3E Status- HIGH/LOW
  S13E = digitalRead(S3E);
  // port S4E Status- HIGH/LOW
  S14E = digitalRead(S4E);
  // asigning the encoded binary to variable
  encodedVal = String(S11E) + String(S12E) + String(S13E) + String(S14E);
  if (encodedVal == "1111")
  {
    { // speed 100
      speedLimit = 100;
    }
  };
  if (encodedVal == "1110")
  { // speed 20
    speedLimit = 20;
  }
  if (encodedVal == "1101")
  { // speed 40
    speedLimit = 40;
  }
  if (encodedVal == "1011")
  { // speed 60
    speedLimit = 60;
  }
  if (encodedVal == "0111")
  { // speed 80
    speedLimit = 80;
  }

  // speed limiting condition checking
  if (speed > speedLimit)
  {
    // Overspeed displaying
    lcd.setCursor(0, 0);
    lcd.print("OVERSPEED       ");
    lcd.setCursor(0, 1);
    lcd.print("Road Limit: " + String(speedLimit) + "       "); // displayinng speed limit
    delay(500);

    // for loop for gradual decrease of speed
    for (int i = speed; i > speedLimit; i--)
    {
      analogWrite(16, i * 255 / 100);
      delay(30);
    }
    // assigning limited speed to speed
    speed = speedLimit;
  }

  delay(300);
  lcd.clear(); // clearing display
}