
int A = 11, B = 10, C = 9, D = 8;
int Paso = 1500;
int boton2 = 3;
int no_pasos = 0;
void setup() 
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(boton2, INPUT);
}

void izquierda()
{
  //paso 1
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delayMicroseconds(Paso);
  //paso 2
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delayMicroseconds(Paso);
  //paso 3
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  delayMicroseconds(Paso);
  //paso 4
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delayMicroseconds(Paso);
}

void derecha()
{
  //paso 1
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delayMicroseconds(Paso);
  //paso 2
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delayMicroseconds(Paso);
  //paso 3
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  delayMicroseconds(Paso);
  //paso 4
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  delayMicroseconds(Paso);
}

void loop() 
{
  if(no_pasos == 6)
  {   
    for(int i = 0; i < (5 * (no_pasos - 1)); i++) 
      derecha();
    
      delay (1000);
      no_pasos = 0;
  }
  
  if(digitalRead(boton2) == HIGH)
  {
    no_pasos = no_pasos + 1;
    if(no_pasos <= 5)
    {
      for(int i = 0; i < 5; i++)
        izquierda();

      delay(1000);
    }
  }
}