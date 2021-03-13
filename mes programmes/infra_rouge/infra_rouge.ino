
#include <IRremote.h>
int receiverpin = 12;
int LED=13;                //define LED pin
volatile int state = LOW;  //define default input mode
int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int ABS=150;
unsigned long RED;
int BUZZER=10;
//#define A 16736925
#define AVANT_ROBOT 5316027 // avant de la télécommande du robot
#define AVANT_HIFI 2327580833 // avant de la télécommande de la chaine

//#define B 16754775
#define ARRIERE_ROBOT 2747854299 // arriere de la télécommande du robot
#define ARRIERE_HIFI 2685719143 // arriere de la télécommande de la chaine

//#define X 16712445
#define STOP_ROBOT 3622325019 // OK de la télécommande du robot
#define STOP_HIFI 1815043745 // stop de la télécommande de la chaine

//#define C 16720605
#define GAUCHE_ROBOT 1386468383 // gauche de la télécommande du robot
#define GAUCHE_HIFI 641543941 // gauche de la télécommande de la chaine


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
  //noTone(BUZZER);
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

