const int Bomba = 2;
const int LED_Tanque_Lleno = 3;
const int LED_Tanque_PocaAgua = 4;
const int LED_Tanque_SinAgua = 5;
const int LED_Reserva_Lleno = 6;
const int LED_Reserva_PocaAgua = 7;
const int LED_Reserva_SinAgua = 8;

int Tanque_PocaAgua;
int Tanque_Lleno;
int Reserva_PocaAgua;
int Reserva_Lleno;

void setup() {
  Serial.begin(9600);   
  pinMode(Bomba,OUTPUT);  
  pinMode(LED_Tanque_Lleno,OUTPUT); 
  pinMode(LED_Tanque_PocaAgua,OUTPUT); 
  pinMode(LED_Tanque_SinAgua,OUTPUT); 
  pinMode(LED_Reserva_Lleno,OUTPUT); 
  pinMode(LED_Reserva_PocaAgua,OUTPUT); 
  pinMode(LED_Reserva_SinAgua,OUTPUT); 
  pinMode(9,INPUT);   
  pinMode(10,INPUT);
  pinMode(11,INPUT);   
  pinMode(12,INPUT);      
}

void loop() {
  Tanque_PocaAgua = digitalRead(9);
  Tanque_Lleno = digitalRead(10);
  Reserva_PocaAgua = digitalRead(11);
  Reserva_Lleno = digitalRead(12);

  if (Tanque_Lleno == 1 && Tanque_PocaAgua == 1)
  {
    Serial.println("Tanque Lleno");
    digitalWrite(LED_Tanque_Lleno, HIGH);
    digitalWrite(LED_Tanque_PocaAgua, LOW);
    digitalWrite(LED_Tanque_SinAgua, LOW);
    digitalWrite(Bomba, LOW);
   // delay(1000);
  }

    if (Tanque_Lleno == 0 && Tanque_PocaAgua == 1)
  {
    Serial.println("Tanque Poca Agua");
    digitalWrite(LED_Tanque_PocaAgua, HIGH);
    digitalWrite(LED_Tanque_Lleno, LOW);
    digitalWrite(LED_Tanque_SinAgua, LOW);

   // delay(1000);
  }

    if (Tanque_Lleno == 0 && Tanque_PocaAgua == 0)
  {
    Serial.println("Tanque Sin Agua");
    digitalWrite(LED_Tanque_SinAgua, HIGH);
    digitalWrite(LED_Tanque_Lleno, LOW);
    digitalWrite(LED_Tanque_PocaAgua, LOW);
        
      if (Reserva_PocaAgua == 1 || Reserva_Lleno == 1)
      {
        digitalWrite(Bomba, HIGH);  
      }
      else
      {
        digitalWrite(Bomba, LOW);
      }
   // delay(1000);
  }




    if (Reserva_Lleno == 1 && Reserva_PocaAgua == 1)
  {
    Serial.println("Reserva Lleno");
    digitalWrite(LED_Reserva_Lleno, HIGH);
    digitalWrite(LED_Reserva_PocaAgua, LOW);
    digitalWrite(LED_Reserva_SinAgua, LOW);
    //delay(1000);
  }

      if (Reserva_Lleno == 0 && Reserva_PocaAgua == 1)
  {
    Serial.println("Reserva Poca Agua");
    digitalWrite(LED_Reserva_PocaAgua, HIGH);
    digitalWrite(LED_Reserva_Lleno, LOW);
    digitalWrite(LED_Reserva_SinAgua, LOW);
    //delay(1000);
  }

        if (Reserva_Lleno == 0 && Reserva_PocaAgua == 0)
  {
    Serial.println("Reserva Sin Agua");
    digitalWrite(LED_Reserva_SinAgua, HIGH);
    digitalWrite(LED_Reserva_Lleno, LOW);
    digitalWrite(LED_Reserva_PocaAgua, LOW);
   // delay(1000);
  }

  
Serial.println(Tanque_PocaAgua);
Serial.println(Tanque_Lleno);
}
