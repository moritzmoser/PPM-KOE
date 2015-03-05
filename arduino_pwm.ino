#define led1 3
#define led2 4
#define right 5
#define left 6
#define s1 A1
#define s2 A2
#define s3 A3
#define s4 A4

int drehzahl1 = 0;
int drehzahl2 = 0;
int arr1[4];
int arr2[4];
int arr3[4];
int arr4[4];

int x1 = 0;
int x2 = 0;
int x3 = 0;
int x4 = 0;

void setup() //S5 &S6 wird als OUTPUT definiert und auf LOW gesetzt.
{
  pinMode(left, OUTPUT);
  pinMode(left, LOW);
  pinMode(right, OUTPUT);
  pinMode(right, LOW);
  
  pinMode(led1, OUTPUT);
  pinMode(led1, LOW);
  pinMode(led2, OUTPUT);
  pinMode(led2, LOW);
  /*Serial.begin(9600);
  startroutine();*/
}


void startroutine() //wird einmal aufgerufen, wenn das Fahrzeug startet
{
  for (int z=0; z<3; z++) //signalisiert dem Benutzer, dass er ab jetzt 3 Sekunden Zeit hat, bis er das Fahrzeug auf dem Kurs platziert haben muss (mittels Blinken der Scheinwerfer)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(500);
  }
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  for (int i=0; i<5; i++) //eigentliche Startroutine: die 4 Arrays (jeweils 1 pro Sensor) werden an die bestehenden Bedingungen angepasst, indem 5 Mal der jetzige Zustand eingespeichert wird
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
    delay(250);
  }
  
  for (int z=0; z<4; z++) //signalisiert dem Benutzer, dass der Synchronisationsvorgang jetzt abgeschlossen ist
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(250);
  }
  x1 = x1/5;  //Mittelwerte der Arrays werden aktualisiert
  x2 = x2/5;
  x3 = x3/5;
  x4 = x4/5;
}

int getX(int * mat) //retourniert den Mittelwert des Arrays
{
  int x = 0;
  for (int i = 0; i < 5; i++)
    x = x + mat[i];
  x = x/5;
  return x;
}


void setArr(int * mat, int messwert) //Aktualisiert das Array, indem es alte Einträge nach hinten verschiebt und den neuen Messwert auf Position 0 ablegt.
{
  for (int i = 4; i > 0; i--)
    mat[i] = mat[i-1];
  mat[0] = messwert;
}

boolean abweichung(int * mat, int messwert) //retourniert, ob der momentane Messwert vom Mittelwert abweicht => ob das Fahrzeug agieren muss
{
  if (messwert > (getX(mat)*1,3))  //Koeffizient für gültige Abweichung = 1,3
    return false;
  else if (messwert < (getX(mat)/1,3))  //Koeffizient für gültige Abweichung = 1,3
    return false;
  else
  {
    setArr(mat, messwert);
    return true;
  }
    
}

int testroutine()  //testroutine erzeugt testdaten
{
  if (random(0, 1) > 0,1)
  {
    int i = (int)random(500, 600);
    return i;
  }
  else
    return 0; 
}




void loop()
{
  analogWrite(left, 255);
  analogWrite(right, 255);
  
  /*int se1 = analogRead(s1);
  int se2 = analogRead(s2);
  int se3 = analogRead(s3);
  int se4 = analogRead(s4);
  
  int se1 = testroutine();
  int se2 = testroutine();
  int se3 = testroutine();
  int se4 = testroutine();
  
  if (abweichung(arr1, se1) && abweichung(arr2, se2) && abweichung(arr3, se3) && abweichung(arr4, se4))
  {
    analogWrite(left, 255);
    analogWrite(right, 255);
  }
  
  else if (abweichung(arr1, se1) && !abweichung(arr2, se2) && abweichung(arr3, se3) && abweichung(arr4, se4))
  {
    analogWrite(left, 180);
    analogWrite(right, 255);
  }
  
  else if (abweichung(arr1, se1) && abweichung(arr2, se2) && !abweichung(arr3, se3) && abweichung(arr4, se4))
  {
    analogWrite(left, 255);
    analogWrite(right, 180);
  }
  
  
  else if (!abweichung(arr1, se1))
  {
    analogWrite(left, 0);
    analogWrite(right, 255);
  }
  
  else if (!abweichung(arr4, se4))
  {
    analogWrite(left, 255);
    analogWrite(right, 0);
  }
  
  
  
  
  Serial.println(se1);
  //Serial.print("\t\t");
  delay(2000);
  */
  
}

