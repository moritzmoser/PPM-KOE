#define right 5
#define left 6
#define s1 A1
#define s2 A2
#define s3 A3
#define s4 A4

int drehzahl1 = 0;
int drehzahl2 = 0;
int arr1 [4];
int arr2 [4];
int arr3 [4];
int arr4 [4];

int x1 = 0;
int x2 = 0;
int x3 = 0;
int x4 = 0;

//long lastprint;

void setup() //S5 &S6 wird als OUTPUT definiert und auf LOW gesetzt.
{
  pinMode(left, OUTPUT);
  pinMode(left, LOW);
  pinMode(right, OUTPUT);
  pinMode(right, LOW);
  //Serial.begin(9600);
  //lastprint = millis();
  startroutine();
}


void startroutine()
{
  for (int i=0; i<5; i++)
  {
    int se1 = analogRead(s1);
    arr1 [i] = se1;
    x1 = x1 + se1;
    int se2 = analogRead(s2);
    arr2 [i] = se2;
    x2 = x1 + se2;
    int se3 = analogRead(s3);
    arr3 [i] = se3;
    x3 = x1 + se3;
    int se4 = analogRead(s4);
    arr4 [i] = se4;
    x4 = x1 + se4;
  }
  x1 = x1/5;
  x2 = x2/5;
  x3 = x3/5;
  x4 = x4/5;
}

int berechneX(int mat [])
{
  int x = 0;
  for (int i = 0; i < 5; i++)
  {
    x = x + mat[i];
  }
  x = x/5;
  return x;
}


void aktualisiereArr(int * mat, int messwert)
{
  for (int i = 0; i < 5; i++)
  {
  mat [1] = 1;
  }
}


void loop()
{
  int se1 = analogRead(s1);
  int se2 = analogRead(s2);
  int se3 = analogRead(s3);
  int se4 = analogRead(s4);
  
  
  
  /*
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
  }*/
}

