#include <Notes et télécommandes.h>
int TEMPO = 1;
int receiverpin = 12;
int LED = 13;              //define LED pin
volatile int state = LOW;  //define default input mode
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 120;
int MAX_VIT1 = 150;
int NOR_VIT1 = 110;
int MIN_VIT1 = 90;
int BOOST1 = 255;
int MAX_VIT2 = 150;
int NOR_VIT2 = 110;
int MIN_VIT2 = 90;
int BOOST2 = 255;
int VIT1 = 110;
int VIT2 = 110;
int BUZZER = 10;
unsigned long RED;
IRrecv irrecv(receiverpin);
decode_results results;


void _mForward() // Avancer
{
  //  digitalWrite(ENA,HIGH);
  //  digitalWrite(ENB,HIGH);
  analogWrite(ENA, VIT1);
  analogWrite(ENB, VIT2);
  digitalWrite(in1, HIGH); //digital output
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(BUZZER, LOW);
  Serial.println("go forward!");
}
void _mBack() // Reculer
{
  //  digitalWrite(ENA,HIGH);
  //  digitalWrite(ENB,HIGH);
  analogWrite(ENA, VIT1);
  analogWrite(ENB, VIT2);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(BUZZER, HIGH);
  Serial.println("go back!");
}
void _mleft() // A Gauche
{
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(BUZZER, LOW);
  Serial.println("go left!");
}
void _mright() // A Dtroite
{
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
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
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(receiverpin, INPUT);
  pinMode(BUZZER, OUTPUT);

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

    RED = results.value;
    Serial.println(RED);
    irrecv.resume();
    delay(150);
    //    if(RED==AVANT_HIFI || RED==AVANT_ROBOT)redeiverpin = 12;
    //int LED=13;                //define LED pinvolat
    if (RED == AVANT_HIFI || RED == AVANT_ROBOT)
    {
      _mForward();
    }

    else if (RED == ARRIERE_HIFI || RED == ARRIERE_ROBOT)
    {
      _mBack();
    }

    else if (RED == GAUCHE_HIFI || RED == GAUCHE_ROBOT)
    {
      _mleft();
    }

    else if (RED == DROITE_HIFI || RED == DROITE_ROBOT)
    {
      _mright();
    }

    else if (RED == STOP_HIFI || RED == STOP_ROBOT)
    {
      _mStop();
    }

    else if (RED == USB_REC_HIFI || RED == LED_ROBOT)
    {
      stateChange();
      VIT1 = MIN_VIT1;
      VIT2 = MIN_VIT2;
    }

    //else if(RED==TOUCHE_2_HIFI || RED==TOUCHE_2_ROBOT)
    else if (RED == TOUCHE_2_ROBOT)
    {
      tone(BUZZER, DO_3, 1000);
      VIT1 = NOR_VIT1;
      VIT2 = NOR_VIT2;
    }

    //else if(RED==TOUCHE_3_HIFI || RED==TOUCHE_3_ROBOT)
    else if (RED == TOUCHE_3_ROBOT)
    {
      tone(BUZZER, RE_3, 1000);
      VIT1 = MAX_VIT1;
      VIT2 = MAX_VIT2;
    }

    //else if(RED==TOUCHE_4_HIFI || RED==TOUCHE_4_ROBOT)
    else if (RED == TOUCHE_4_ROBOT)
    {
      tone(BUZZER, MI_3, 1000);
      VIT1 = BOOST1;
      VIT2 = BOOST2;
    }

    //else if(RED==TOUCHE_5_HIFI || RED==TOUCHE_5_ROBOT)
    else if (RED == TOUCHE_5_ROBOT)
    {
      tone(BUZZER, FA_3, 1000);
    }

    //else if(RED==TOUCHE_6_HIFI || RED==TOUCHE_6_ROBOT)
    else if (RED == TOUCHE_6_ROBOT)
    {
      tone(BUZZER, SOL_3, 1000);
    }

    //else if(RED==TOUCHE_7_HIFI || RED==TOUCHE_7_ROBOT)
    else if (RED == TOUCHE_7_ROBOT)
    {
      tone(BUZZER, LA_3, 1000);
    }

    //else if(RED==TOUCHE_8_HIFI || RED==TOUCHE_8_ROBOT)
    else if (RED == TOUCHE_8_ROBOT)
    {
      tone(BUZZER, SI_3, 1000);
    }

    //else if(RED==TOUCHE_9_HIFI || RED==TOUCHE_9_ROBOT)
    else if (RED == TOUCHE_9_ROBOT)
    {
      tone(BUZZER, DO_4, 1000);
    }


    //else if(RED==TOUCHE_0_HIFI || RED==TOUCHE_0_ROBOT)
    else if (RED == TOUCHE_0_ROBOT)
    {
      tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);

      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      delay(TEMPO / 4);

      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      tone(BUZZER, FA_3, TEMPO); delay(TEMPO);
      tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);

      tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
      tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
      tone(BUZZER, SOL_3, TEMPO); delay(TEMPO);
      delay(TEMPO / 4);

      tone(BUZZER, FA_3, TEMPO); delay(TEMPO);
      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);

      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
      delay(TEMPO / 4);

      tone(BUZZER, MI_3, TEMPO); delay(TEMPO);
      tone(BUZZER, RE_3, TEMPO); delay(TEMPO);
      tone(BUZZER, DO_3, TEMPO); delay(TEMPO);

      tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
      tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
      tone(BUZZER, DO_3, TEMPO); delay(TEMPO);
    }

    //else if(RED==TOUCHE_DIESE_HIFI || RED==TOUCHE_DIESE_ROBOT)
    else if (RED == TOUCHE_DIESE_ROBOT)
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
    else if (RED == TOUCHE_ETOILE_ROBOT)
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
