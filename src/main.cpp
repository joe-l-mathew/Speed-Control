#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(10, 11, 12, 13, 14, 15); // rs,en,data pins d4 -d7

int motorPort = 16; // Motor Pin
int motorSpeed = 0; // Motor Value- Initially Zero

int a = 0;
int b = 0;
int c = 0;
int d = 0;

int ac = 0;
int aa = 0;
int bb = 0;
int cc = 0;
int dd = 0;
int ee = 0;

const int incPort = 2; // increment switch
int SW1INC = 1;
const int decPort = 3; // Decrement Switch
int SW2DEC = 1;

// Encoder input ports
const int S1E = 6;
const int S2E = 7;
const int S3E = 8;
const int S4E = 9;

int S11E = 0;
int S12E = 0;
int S13E = 0;
int S14E = 0;

int S1Ealert = 1;
int S2Ealert = 1;
int S3Ealert = 1;
int S4Ealert = 1;

void setup()
{

  lcd.begin(16, 2);
  // setting motor speed to zero
  analogWrite(motorPort, motorSpeed);
  // Declaring switches
  pinMode(incPort, INPUT);
  pinMode(decPort, INPUT);
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
}

void loop()
{

  S11E = digitalRead(S1E);
  if (S1Ealert == LOW)
  {
    S11E = 0;
  }
  else
  {
    S11E = 1;
  }
  S2Ealert = digitalRead(S2E);
  if (S2Ealert == LOW)
  {
    S12E = 0;
  }
  else
  {
    S12E = 1;
  }
  S3Ealert = digitalRead(S3E);
  if (S3Ealert == LOW)
  {
    S13E = 0;
  }
  else
  {
    S13E = 1;
  }
  S4Ealert = digitalRead(S4E);
  if (S4Ealert == LOW)
  {
    S14E = 0;
  }
  else
  {
    S14E = 1;
  }

  /////////////////////////////////////////NORMAL NO AMBULANCE//////////////////////////////////////////////////////////////////////////////////
  if ((S11E == 1) & (S12E == 1) & (S13E == 1) & (S14E == 1))
  {
    SW1INC = digitalRead(incPort);
    if (SW1INC == LOW)
    {
      ac = ac + 1;
      delay(500);
      if (ac > 10)
      {
        ac = 10;
        delay(500);
      }
    }

    SW2DEC = digitalRead(decPort);
    if (SW2DEC == LOW)
    {
      if (ac > 0)
      {
        ac = ac - 1;
        delay(500);
      }
    }
    //-------------------------------Input-------------------------------------
    if (ac == 0)
    {
      motorSpeed = 0;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 0 mph   ");
      a = 0;
      b = 0;
      c = 0;
      d = 0;
    }
    if (ac == 1)
    {
      motorSpeed = 100;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 10 mph   ");
      a = 0;
      b = 0;
      c = 0;
      d = 0;
    }
    if (ac == 2)
    {
      motorSpeed = 120;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 20 mph   ");
      dd = 0;
      a = 0;
      b = 0;
      c = 0;
      d = 0;
    }
    if (ac == 3)
    {
      motorSpeed = 140;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 30 mph   ");
      a = 1;
      b = 0;
      c = 0;
      d = 0;
    }
    if (ac == 4)
    {
      motorSpeed = 160;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 40 mph   ");
      cc = 0;
      a = 1;
      b = 0;
      c = 0;
      d = 0;
    }
    if (ac == 5)
    {
      motorSpeed = 180;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 50 mph   ");
      a = 1;
      b = 1;
      c = 0;
      d = 0;
    }
    if (ac == 6)
    {
      motorSpeed = 200;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 60 mph   ");
      bb = 0;
      a = 1;
      b = 1;
      c = 0;
      d = 0;
    }
    if (ac == 7)
    {
      motorSpeed = 225;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 70 mph   ");
      a = 1;
      b = 1;
      c = 1;
      d = 0;
    }
    if (ac == 8)
    {
      motorSpeed = 235;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 80 mph   ");
      ee = 0;
      aa = 0;
      a = 1;
      b = 1;
      c = 1;
      d = 0;
    }
    if (ac == 9)
    {
      motorSpeed = 245;
      analogWrite(motorPort, motorSpeed);
      delay(500);
      lcd.setCursor(0, 0);
      lcd.print("Speed: 90 mph   ");
      a = 1;
      b = 1;
      c = 1;
      d = 1;
    }
    if (ac == 10)
    {
      ee = ee + 1;
      if (ee == 1)
      {
        motorSpeed = 255;
        analogWrite(motorPort, motorSpeed);
        lcd.setCursor(0, 0);
        lcd.print("Speed: 100 mph  ");
        lcd.setCursor(0, 1);
        lcd.print("Max speed       ");
        delay(2000);
        lcd.clear();
      }

      if (ee == 2)
      {
        motorSpeed = 255;
        analogWrite(motorPort, motorSpeed);
        lcd.setCursor(0, 0);
        lcd.print("Speed: 100 mph  ");
      }
      if (ee == 3)
      {
        ee = 2;
        a = 1;
        b = 1;
        c = 1;
        d = 1;
        goto st;
      }
    }
  }
st:
  //////////////////////////////////////////vehicle speed 80mph/////////////////////////////////////////////////////////
  if (d == 1)
  {
    if ((S11E == 0) & (S12E == 1) & (S13E == 1) & (S14E == 1))
    {
      aa = aa + 1;
      if (aa == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Over Speeding   ");
        lcd.setCursor(0, 1);
        lcd.print("   Detected!!   ");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Capping Speed   ");
        lcd.setCursor(0, 1);
        lcd.print("   to 80mph     ");
        delay(5000);
        lcd.clear();
      }
      if (aa >= 2)
      {
        lcd.setCursor(0, 0);
        lcd.print("SpeedLimit:80mph");
        lcd.setCursor(0, 1);
        lcd.print("Speed: 80 mph   ");
        motorSpeed = 235;
        analogWrite(motorPort, motorSpeed);
        delay(500);
        delay(3000);
        lcd.clear();
        ac = 8;
      }
    }
  }
  //////////////////////////////////////////vehicle speed 60mph/////////////////////////////////////////////////////////
  if (c == 1)
  {
    if ((S11E == 1) & (S12E == 0) & (S13E == 1) & (S14E == 1))
    {
      bb = bb + 1;
      if (bb == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Over Speeding   ");
        lcd.setCursor(0, 1);
        lcd.print("   Detected!!   ");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Capping Speed   ");
        lcd.setCursor(0, 1);
        lcd.print("   to 60mph     ");
        delay(5000);
        lcd.clear();
      }
      if (bb >= 2)
      {
        lcd.setCursor(0, 0);
        lcd.print("SpeedLimit:60mph");
        lcd.setCursor(0, 1);
        lcd.print("Speed: 60 mph   ");
        motorSpeed = 200;
        analogWrite(motorPort, motorSpeed);
        delay(500);
        delay(3000);
        lcd.clear();
        ac = 6;
      }
    }
  }
  //////////////////////////////////////////vehicle speed 40mph/////////////////////////////////////////////////////////
  if (b == 1)
  {
    if ((S11E == 1) & (S12E == 1) & (S13E == 0) & (S14E == 1))
    {
      cc = cc + 1;
      if (cc == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Over Speeding   ");
        lcd.setCursor(0, 1);
        lcd.print("   Detected!!   ");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Capping Speed   ");
        lcd.setCursor(0, 1);
        lcd.print("   to 40mph     ");
        delay(5000);
        lcd.clear();
      }
      if (cc >= 2)
      {
        lcd.setCursor(0, 0);
        lcd.print("SpeedLimit:40mph");
        lcd.setCursor(0, 1);
        lcd.print("Speed: 40 mph   ");
        motorSpeed = 160;
        analogWrite(motorPort, motorSpeed);
        delay(500);
        delay(3000);
        lcd.clear();
        ac = 4;
      }
    }
  }
  //////////////////////////////////////////vehicle speed 20mph////////////////////////////////////////////////////////
  if (a == 1)
  {
    if ((S11E == 1) & (S12E == 1) & (S13E == 1) & (S14E == 0))
    {
      dd = dd + 1;
      if (dd == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Over Speeding   ");
        lcd.setCursor(0, 1);
        lcd.print("   Detected!!   ");
        delay(5000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Capping Speed   ");
        lcd.setCursor(0, 1);
        lcd.print("   to 20mph     ");
        delay(5000);
        lcd.clear();
      }
      if (dd >= 2)
      {
        lcd.setCursor(0, 0);
        lcd.print("SpeedLimit:20mph");
        lcd.setCursor(0, 1);
        lcd.print("Speed: 20 mph   ");
        motorSpeed = 120;
        analogWrite(motorPort, motorSpeed);
        delay(500);
        delay(3000);
        lcd.clear();
        ac = 2;
      }
    }
  }
}