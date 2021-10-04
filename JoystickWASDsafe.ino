#include<Keyboard.h>

// Analog input of the horizontal joystick position
const int JoystickX = A0;
// Analog input of the vertical joystick position
const int JoystickY = A1;
//joystick press
const int SW_pin = 2;
//joystick num 2
const int SW_pin2 = 4;

void setup()
{
  Serial.begin(9600);
  pinMode(SW_pin, INPUT_PULLUP);
  pinMode(SW_pin2, INPUT_PULLUP);
}

void loop()
{
  // Process horizontal joystick position
  int x = analogRead(JoystickX);
  Serial.print("xaxis value : ");
  Serial.println(x);
  if (1023 == x)
  {
    Keyboard.press('d');
    Serial.print("xaxis left");
  }
  else if (0 == x)
  {
    Keyboard.press('a');
    Serial.print("eaezae");
  }
  else
  {
    Keyboard.release('d');
    Keyboard.release('a');
    delay(5);
  }

  // Process vertical joystick position
  int y = analogRead(JoystickY);
  if (0 == y)
  {
    Keyboard.press('w');
    Serial.print("eaezae");
  }
  else if (1023 == y)
  {
    Keyboard.press('s');
    Serial.print("eaezae");
  }
  else
  {
      Keyboard.release('w');
    Keyboard.release('s');
    delay(5);
  }
  //button press
  int z = digitalRead(SW_pin);
  Serial.print(z);

  if(0==z)
  {
  Keyboard.press('e');  
  }
  else
  {
    Keyboard.release('e');
  }
  int z2 = digitalRead(SW_pin2);
  if(0==z2)
  {
  Keyboard.press('x');  
  }
  else
  {
    Keyboard.release('x');
  }
}
