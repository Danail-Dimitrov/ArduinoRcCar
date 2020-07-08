const int m11 = 2;
const int m12 = 3;
const int m21 = 4;
const int m22 = 5;
const int led = 24;
String wheelState = "Center";
float speed = 204;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    char command = Serial.read();
    switch(command)
    {
      case 'F' : ForwardButtonPressed(); break; 
      case 'B' : BackwardsButtonPressed(); break; 
      case 'G' : ForwardLeft(); break; 
      case 'I' : ForwardRight(); break; 
      case 'H' : BackwardsLeft(); break; 
      case 'J' : BackwardsRight(); break; 
      case 'L' : Left(); break; 
      case 'R' : Right(); break; 
      case 'W' : FrontLightsOn(); break; 
      case 'w' : FrontLightsOff(); break;
      case '0' : speed = 0; break;       
      case '1' : speed = 25.5; break; 
      case '2' : speed = 51; break; 
      case '3' : speed = 76.5; break; 
      case '4' : speed = 102; break; 
      case '5' : speed = 127.5; break; 
      case '6' : speed = 153; break; 
      case '7' : speed = 178.5; break; 
      case '8' : speed = 204; break; 
      case '9' : speed = 229.5; break; 
      case 'q' : speed = 255; break; 
      default : Stop(); break; 
    }    
  }
  delay(10);
}

void Stop()
{
  analogWrite(m12, 0);
  analogWrite(m11, 0);
  CenterFrontWheels();
}

void ForwardButtonPressed()
{
  CenterFrontWheels();
  Forward();
}

void BackwardsButtonPressed()
{
  CenterFrontWheels();
  Backwards();
}

void ForwardLeft()
{
  Forward();
  Left();
}

void ForwardRight()
{
   Forward();
   Right();
}

void BackwardsLeft()
{
   Backwards();
   Left();
}

void BackwardsRight()
{
   Backwards();
   Right();
}

void Forward()
{
  analogWrite(m11, speed);
}


void Backwards()
{
  analogWrite(m12, speed);
}

void Left()
{
  if(wheelState != "Left")
  {
      analogWrite(m22, 150);
      if(wheelState == "Right")
      {
        delay(35);
      }
      delay(35);
      analogWrite(m22, 0);
      wheelState = "Left";
  }
}


void Right()
{
  if(wheelState != "Rigt") 
  {
      analogWrite(m21, 150);      
      if(wheelState == "Left")
      {
        delay(35);
      }
      delay(35);
      analogWrite(m21, 0);
      wheelState = "Rigt";
  }
}

void CenterFrontWheels()
{
  if(wheelState == "Left")
  {
      analogWrite(m21, 150);    
      delay(25);
      analogWrite(m21, 0);
      wheelState = "Center"; 
  }
  else if(wheelState == "Rigt")
  {
      analogWrite(m22, 150);
      delay(25 );
      analogWrite(m22, 0);
      wheelState = "Center"; 
  }
}

void FrontLightsOn()
{
  digitalWrite(led, HIGH);
}

void FrontLightsOff()
{
  digitalWrite(led, LOW);
}
