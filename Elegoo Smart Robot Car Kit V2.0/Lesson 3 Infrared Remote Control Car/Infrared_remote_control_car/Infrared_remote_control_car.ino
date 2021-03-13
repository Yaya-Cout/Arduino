//www.elegoo.com
//2016.09.23

#include <IRremote.h>
int receiverpin = 12;
int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int ABS=150;
unsigned long RED;
//#define A 16736925
//#define A 5316027 // avant de la télécommande du robot
#define A 2327580833 // avant de la télécommande de la chaine

//#define B 16754775
//#define B 2747854299 // arriere de la télécommande du robot
#define B 2685719143 // arriere de la télécommande de la chaine

//#define X 16712445
//#define X 3622325019 // OK de la télécommande du robot
#define X 1815043745 // stop de la télécommande de la chaine

//#define C 16720605
//#define C 1386468383 // gauche de la télécommande du robot
#define C 641543941 // gauche de la télécommande de la chaine


//#define D 16761405
//#define D 553536955 // droite de la télécommande du robot
#define D 3841588867 // droite de la télécommande de la chaine


IRrecv irrecv(receiverpin);
decode_results results;

void _mForward()
{ 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}
void _mBack()
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}
void _mleft()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  Serial.println("go left!");
}
void _mright()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go right!");
}
void _mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("STOP!");  
}
void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(receiverpin,INPUT);
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
    if(RED==A)
  {  
     _mForward();
  }

  else if(RED==B)
  {
        _mBack();
  }

  else if(RED==C)
  {
        _mleft();
  }

  else if(RED==D)
  {
        _mright();
   }

  else if(RED==X)
  { 
         _mStop();
   }
}
} 

