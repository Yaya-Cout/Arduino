#include <IRremote.h>


int BUZZER=10;


//#define D 16761405
#define DROITE_ROBOT 553536955 // droite de la télécommande du robot
#define DROITE_HIFI 3841588867 // droite de la télécommande de la chaine

#define LED_ROBOT 3238126971 // bouton 1 de la télécommande du robot
#define USB_REC_HIFI 2555128611 // USB/REC de la télécommande de la chaine



IRrecv irrecv(receiverpin);
decode_results results;


void _mForward() // Avancer
{ 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(BUZZER, LOW);
  Serial.println("go forward!");
}
void _mBack() // Reculer
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(BUZZER, HIGH);
  Serial.println("go back!");
}
void _mleft() // A Gauche
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  digitalWrite(BUZZER, LOW);
  Serial.println("go left!");
}
void _mright() // A Dtroite
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(BUZZER, LOW);
  Serial.println("go right!");
}
void _mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  digitalWrite(BUZZER, LOW);
  Serial.println("STOP!");  
}

void stateChange()      
{
  state = !state;          
  digitalWrite(LED, state);
  digitalWrite(BUZZER, state);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);     //initialize LED as an output
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(receiverpin,INPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,LOW);
  //tone(BUZZER, 440, 1000);
  noTone(BUZZER);
  Serial.begin(9600);
  _mStop();
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
    { 

      RED=results.value;
       Serial.println(RED);
       irrecv.resume();
    delay(150);
    if(RED==AVANT_HIFI || RED==AVANT_ROBOT)
  {  
     _mForward();
  }

  else if(RED==ARRIERE_HIFI || RED==ARRIERE_ROBOT)
  {
        _mBack();
  }

  else if(RED==GAUCHE_HIFI || RED==GAUCHE_ROBOT)
  {
        _mleft();
  }

  else if(RED==DROITE_HIFI || RED==DROITE_ROBOT)
  {
        _mright();
   }

  else if(RED==STOP_HIFI || RED==STOP_ROBOT)
  { 
         _mStop();
   }

  else if(RED==USB_REC_HIFI || RED==LED_ROBOT)
  { 
       stateChange();
   }
   

}
} 

