#include<Keyboard.h>

// Analog input of the horizontal joystick position
const int JoystickX = A0;
// Analog input of the vertical joystick position
const int JoystickY = A1;
//joystick press
const int SW_pin = 2;
//keybinds declare choose
const char up = 'w' ;
const char down= 's' ;
const char left= 'a'  ;
const char right = 'd' ;
const char Aclick = 'b';

void setup()
{
  Serial.begin(9600);
  pinMode(SW_pin, INPUT_PULLUP);
}

void loop()
{
  // Process horizontal joystick position
  int x = analogRead(JoystickX);
  Serial.print("xaxis value : ");
  Serial.println(x);
  if (1023 == x)
  {
    Keyboard.press(left);
    Serial.print("xaxis left");
  }
  else if (0 == x)
  {
    Keyboard.press(right);
    Serial.print("eaezae");
  }
  else
  {
    Keyboard.release(left);
    Keyboard.release(right);
    delay(5);
  }

  // Process vertical joystick position
  int y = analogRead(JoystickY);
  if (0 == y)
  {
    Keyboard.press(down);
    Serial.print("eaezae");
  }
  else if (1023 == y)
  {
    Keyboard.press(up);
    Serial.print("eaezae");
  }
  else
  {
      Keyboard.release(down);
    Keyboard.release(up);
    delay(5);
  }
  //button press
  int z = digitalRead(SW_pin);
  Serial.print(z);

  if(0==z)
  {
  Keyboard.press(Aclick);  
  }
  else
  {
    Keyboard.release(Aclick);
  }
}
