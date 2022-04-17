#include <Arduino.h>
#line 1 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
int ledPin = 2;

int sensor[] = {5, 6, 8, 10, 12};
int input[] = {0, 0, 0, 0, 0};

static float tiempoInicial = 0;

static float tiempo[] = {0, 0, 0, 0, 0};
static boolean tiempoMarcado[] = {false, false, false, false, false};


/*
int s0 = 5;
int s1 = 6;
int s2 = 8;
int s3 = 10;
int s4 = 12;

int inputS0 = 0;
int inputS1 = 0;
int inputS2 = 0;
int inputS3 = 0;
int inputS4 = 0;
*/



#line 28 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
void setup();
#line 43 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
void loop();
#line 61 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
void iniciarContador();
#line 75 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
void tomarTiempo(int i);
#line 87 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
boolean verificarRecorrido(int i);
#line 97 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\speed_sensor.ino"
boolean hayAlgunSensorPrendido();
#line 107 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\speed_sensor.ino"
void prenderLed(int led);
#line 28 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\functional_speed_sensor.ino"
void setup() {

    Serial.begin (9600);
    pinMode (ledPin, OUTPUT);
    pinMode (sensor[0], INPUT); //El pin 0 es que revisa cuando empieza a moverse el carro. 
    pinMode (sensor[1], INPUT);
    pinMode (sensor[2], INPUT);
    pinMode (sensor[3], INPUT);
    pinMode (sensor[0], INPUT);   

   
}



void loop() {
   input[0]= !digitalRead (sensor[0]);
   input[1]= !digitalRead (sensor[1]);
   input[2]= !digitalRead (sensor[2]);
   input[3]= !digitalRead (sensor[3]);
   input[4]= !digitalRead (sensor[4]);
   

  iniciarContador();

  tomarTiempo (1);
  tomarTiempo (2);
  tomarTiempo (3);
  tomarTiempo (4);
  
  
}

   void iniciarContador (){

  if (tiempoInicial == 0 &&  input[0]== HIGH){
    tiempoInicial= (float)millis();
    tiempo [0] = (float)millis();
    tiempoMarcado[0] = true;
    float divider = 1000;

  Serial.print ("El tiempo inicial es :  ");
  Serial.println (tiempo[0] / divider);
    }
  }


  void tomarTiempo (int i){ //donde i indica el orden de los sensores. 

    if (tiempo[i]==0 && verificarRecorrido(i)==true && input [i] == HIGH){
      tiempo[i] = millis() - tiempoInicial;
      tiempoMarcado[i] = true; 
      Serial.print ("El tiempo marcado en la posición "); Serial.print (i); Serial.print(" es:..."); 
      Serial.println (tiempo[i]);
    }
  }

  // Metodo que verifica si los sensores anteriores al sensor[i] ya han sido utilizados, revisandolos uno por uno en un ciclo For.
  // La finalidad de este método es que no se inicie el sensor 4 cuando el 1 aún no se prende. 
  boolean verificarRecorrido (int i){
    for (int j=0; j<i; j++){
      if (tiempoMarcado[j] == false){
        return false; //False si algun sensor antes que el de la pos i no se ha prendido ya. 
      }
    }
    return true; //Retorna true si todos los sensores están prendidos.
  }


 





#line 1 "c:\\Users\\Esteban\\Desktop\\VS_Arduino\\speed_sensor.ino"
int ledPin = 2;

int sensor[] = {5, 6, 8, 10, 12};
int input[] = {0, 0, 0, 0, 0};

static float tiempoInicial = 0;

static float tiempo[] = {0, 0, 0, 0, 0};
static boolean tiempoMarcado[] = {false, false, false, false, false};


/*
int s0 = 5;
int s1 = 6;
int s2 = 8;
int s3 = 10;
int s4 = 12;

int inputS0 = 0;
int inputS1 = 0;
int inputS2 = 0;
int inputS3 = 0;
int inputS4 = 0;
*/



void setup() {

    Serial.begin (9600);
    pinMode (ledPin, OUTPUT);
    pinMode (sensor[0], INPUT); //El pin 0 es que revisa cuando empieza a moverse el carro. 
    pinMode (sensor[1], INPUT);
    pinMode (sensor[2], INPUT);
    pinMode (sensor[3], INPUT);
    pinMode (sensor[0], INPUT);   

   
}



void loop() {
   input[0]= !digitalRead (sensor[0]);
   input[1]= !digitalRead (sensor[1]);
   input[2]= !digitalRead (sensor[2]);
   input[3]= !digitalRead (sensor[3]);
   input[4]= !digitalRead (sensor[4]);
   
  prenderLed(ledPin);
  iniciarContador();

  tomarTiempo (1);
  tomarTiempo (2);
  tomarTiempo (3);
  tomarTiempo (4);
  
  
}

   void iniciarContador (){

  if (tiempoInicial == 0 &&  input[0]== HIGH){
    tiempoInicial= (float)millis();
    tiempo [0] = (float)millis();
    tiempoMarcado[0] = true;
    float divider = 1000;

  Serial.print ("El tiempo inicial es :  ");
  Serial.println (tiempo[0] / divider);
    }
  }


  void tomarTiempo (int i){ //donde i indica el orden de los sensores. 

    if (tiempo[i]==0 && verificarRecorrido(i)==true && input [i] == HIGH){
      tiempo[i] = millis() - tiempoInicial;
      tiempoMarcado[i] = true; 
      Serial.print ("El tiempo marcado en la posición "); Serial.print (i); Serial.print(" es:..."); 
      Serial.println (tiempo[i]);
    }
  }

  // Metodo que verifica si los sensores anteriores al sensor[i] ya han sido utilizados, revisandolos uno por uno en un ciclo For.
  // La finalidad de este método es que no se inicie el sensor 4 cuando el 1 aún no se prende. 
  boolean verificarRecorrido (int i){
    for (int j=0; j<i; j++){
      if (tiempoMarcado[j] == false){
        return false; //False si algun sensor antes que el de la pos i no se ha prendido ya. 
      }
    }
    return true; //Retorna true si todos los sensores están prendidos.
  }


  boolean hayAlgunSensorPrendido (){

  for (int i=0; i<6; i++){
    if (input[i] == HIGH){
      return true; 
    }
  }
  return false;
  }

  void prenderLed (int led){
    while (hayAlgunSensorPrendido() == true){
      digitalWrite (led, HIGH);
    }
    while (hayAlgunSensorPrendido ()== false){
      digitalWrite (led, LOW);
    }
    
  }





