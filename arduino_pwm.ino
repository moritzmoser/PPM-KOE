#define rightmotor 5 //Der Pin Nummer 5 wird als S5 definiert. Zu beachten ist, dass es Pin 5 oder 6 sein muss, da nur diese PWM-Signale ausgeben können.
#define leftmotor 6
int sensor1 = A0;
int sensor2 = A1;
int drehzahl1 = 0;
int drehzahl2 = 0;
long lastprint;

void setup() //S5 &S6 wird als OUTPUT definiert und auf LOW gesetzt.
{
  pinMode(leftmotor, OUTPUT);
  pinMode(leftmotor, LOW);
  pinMode(rightmotor, OUTPUT);
  pinMode(rightmotor, LOW);
  Serial.begin(9600);
  lastprint = millis();
}


void loop()
{
  drehzahl1 = (analogRead(sensor1)/1023.0)*255.0+100.0;
  drehzahl2 = (analogRead(sensor2)/1023.0)*255.0+100.0;
  if (drehzahl1 > 200 && drehzahl2 < 200)
  {
     analogWrite(leftmotor, 0 ); //0-255 benötigten Schritte passend zu schalten
     analogWrite(rightmotor, 255 ); //0-255 benötigten Schritte passend zu schalten
  }
  else if (drehzahl1 < 200 && drehzahl2 > 200)
  {
     analogWrite(leftmotor, 255 ); //0-255 benötigten Schritte passend zu schalten
     analogWrite(rightmotor, 0 ); //0-255 benötigten Schritte passend zu schalten
  }
  else
    {
     analogWrite(leftmotor, 0 ); //0-255 benötigten Schritte passend zu schalten
     analogWrite(rightmotor, 0 ); //0-255 benötigten Schritte passend zu schalten
  }
  if (millis()-lastprint>2000)
  {
    Serial.print("n1: ");
    Serial.print(drehzahl1);
    Serial.print(" ,");
    Serial.print("n2: ");
    Serial.print(drehzahl2);
    Serial.print(";    ");
    lastprint = millis();
  }
}
