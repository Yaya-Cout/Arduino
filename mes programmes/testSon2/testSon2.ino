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
int ABS=120;
int MAX_VIT1=150;
int NOR_VIT1=110;
int MIN_VIT1=90;
int MAX_VIT2=132;
int NOR_VIT2=92;
int MIN_VIT2=72;
int VIT1=110;
int VIT2=92;
int BUZZER=10;
unsigned long RED;
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

#define TOUCHE_2_ROBOT 2538093563 // bouton 2 de la télécommande du robot
#define TOUCHE_3_ROBOT 4039382595 // bouton 3 de la télécommande du robot
#define TOUCHE_4_ROBOT 2534850111 // bouton 4 de la télécommande du robot
#define TOUCHE_5_ROBOT 1033561079 // bouton 5 de la télécommande du robot
#define TOUCHE_6_ROBOT 1635910171 // bouton 6 de la télécommande du robot
#define TOUCHE_7_ROBOT 2351064443 // bouton 7 de la télécommande du robot
#define TOUCHE_8_ROBOT 1217346747 // bouton 8 de la télécommande du robot
#define TOUCHE_9_ROBOT 71952287 // bouton 9 de la télécommande du robot
#define TOUCHE_0_ROBOT 465573243 // bouton 0 de la télécommande du robot0
#define TOUCHE_DIESE_ROBOT 1053031451 // bouton # de la télécommande du robot
#define TOUCHE_ETOILE_ROBOT  851901943

#define DO_3    261.626
#define DO_D_3  277.183
#define RE_3    293.665
#define RE_D_3  311.127
#define MI_3    329.628
#define FA_3    349.228
#define FA_D_3  369.994
#define SOL_3   391.995
#define SOL_D_3 415.305
#define LA_3    440.000
#define LA_D_3  466.164
#define SI_3    493.883
#define DO_4    523.251
#define DO_D_4  554.365
#define RE_4    587.330
#define RE_D_4  622.254
#define MI_4    659.456
#define FA_4    698.456
#define FA_D_4  739.989
#define SOL_4   783.991
#define SOL_D_4 830.609
#define LA_4    880.000
#define LA_D_4  932.328
#define SI_4    987.767
#define DO_5    1046.50

#define TEMPO    400

IRrecv irrecv(receiverpin);
decode_results results;


void _mForward() // Avancer
{
//  digitalWrite(ENA,HIGH);
//  digitalWrite(ENB,HIGH);
  analogWrite(ENA,VIT1);
  analogWrite(ENB,VIT2);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(BUZZER, LOW);
  Serial.println("go forward!");
}
void _mBack() // Reculer
{
//  digitalWrite(ENA,HIGH);
//  digitalWrite(ENB,HIGH);
  analogWrite(ENA,VIT1);
  analogWrite(ENB,VIT2);
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
//  digitalWrite(ENA,LOW);
//  digitalWrite(ENB,LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
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

  //digitalWrite(BUZZER,LOW);
  tone(BUZZER, 880, 1000);
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
//    if(RED==AVANT_HIFI || RED==AVANT_ROBOT)redeiverpin = 12;
//int LED=13;                //define LED pinvolat
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
       VIT1=MIN_VIT1;
       VIT2=MIN_VIT2;
   }

  //else if(RED==TOUCHE_2_HIFI || RED==TOUCHE_2_ROBOT)
  else if(RED==TOUCHE_2_ROBOT)
  {
       tone(BUZZER, DO_3, 1000);
       VIT1=NOR_VIT1;
       VIT2=NOR_VIT2;
  }

  //else if(RED==TOUCHE_3_HIFI || RED==TOUCHE_3_ROBOT)
  else if(RED==TOUCHE_3_ROBOT)
  {
       tone(BUZZER, RE_3, 1000);
       VIT1=MAX_VIT1;
       VIT2=MAX_VIT2;
  }

  //else if(RED==TOUCHE_4_HIFI || RED==TOUCHE_4_ROBOT)
  else if(RED==TOUCHE_4_ROBOT)
  {
       tone(BUZZER, MI_3, 1000);
  }

  //else if(RED==TOUCHE_5_HIFI || RED==TOUCHE_5_ROBOT)
  else if(RED==TOUCHE_5_ROBOT)
  {
       tone(BUZZER, FA_3, 1000);
  }

  //else if(RED==TOUCHE_6_HIFI || RED==TOUCHE_6_ROBOT)
  else if(RED==TOUCHE_6_ROBOT)
  {
       tone(BUZZER, SOL_3, 1000);
  }

  //else if(RED==TOUCHE_7_HIFI || RED==TOUCHE_7_ROBOT)
  else if(RED==TOUCHE_7_ROBOT)
  {
       tone(BUZZER, LA_3, 1000);
  }

  //else if(RED==TOUCHE_8_HIFI || RED==TOUCHE_8_ROBOT)
  else if(RED==TOUCHE_8_ROBOT)
  {
       tone(BUZZER, SI_3, 1000);
  }

  //else if(RED==TOUCHE_9_HIFI || RED==TOUCHE_9_ROBOT)
  else if(RED==TOUCHE_9_ROBOT)
  {
       tone(BUZZER, DO_4, 1000);
  }


  //else if(RED==TOUCHE_0_HIFI || RED==TOUCHE_0_ROBOT)
  else if(RED==TOUCHE_0_ROBOT)
  {
       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);

       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       delay(TEMPO/4);

       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, FA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);

       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
       delay(TEMPO/4);

       tone(BUZZER, FA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);

       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
       delay(TEMPO/4);

       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);

       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
  }

 //else if(RED==TOUCHE_DIESE_HIFI || RED==TOUCHE_DIESE_ROBOT)
  else if(RED==TOUCHE_DIESE_ROBOT)
  {
       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, FA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);

       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_4, TEMPO); delay(TEMPO);
       tone(BUZZER, FA_4, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_4, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_4, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_4, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_5, TEMPO); delay(TEMPO);
  }

   //else if(RED==TOUCHE_0_HIFI || RED==TOUCHE_0_ROBOT)
     else if(RED==TOUCHE_ETOILE_ROBOT)
 {
       tone(BUZZER, MI_4, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_4, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_4, TEMPO); delay(TEMPO);
       tone(BUZZER, MI_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_4, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);

       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
       tone(BUZZER, RE_4, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_4, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
       tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
//       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
//       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
//
//       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
//       tone(BUZZER, DO_4, TEMPO); delay(TEMPO);
//       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
//       tone(BUZZER, SOL_4, TEMPO); delay(TEMPO);
//       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
//       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
//       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SI_3, TEMPO); delay(TEMPO);
       tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
       tone(BUZZER, LA_3, TEMPO); delay(TEMPO);
 }
}
}
