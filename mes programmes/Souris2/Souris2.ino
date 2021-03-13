// #include <Mouse.h>
#include <Yann.h>

// set pin numbers for the five buttons:
// const int upButton = 2;
// const int downButton = 3;
// const int leftButton = 4;
// const int rightButton = 5;
// const int mouseButton = 6;
int upState;
int downState;
int rightState;
int leftState;
int clickState;
int clickStateSend;
int receiverpin = 12;
unsigned long RED;
IRrecv irrecv(receiverpin);
decode_results results;

int range = 5;              // output range of X or Y movement; affects movement speed
int responseDelay = 10;     // response delay of the mouse, in ms


void setup() {
  // initialize the buttons' inputs:
  // pinMode(upButton, INPUT);
  // pinMode(downButton, INPUT);
  // pinMode(leftButton, INPUT);
  // pinMode(rightButton, INPUT);
  // pinMode(mouseButton, INPUT);
  Serial.begin(9600); // Pour afficher sur le moniteur série, écrire Serial.println(""); écrire le texte entre les gillemets.
  pinMode(receiverpin,INPUT);
  // initialize mouse control:
  // Mouse.begin();
  irrecv.enableIRIn();
}

void loop() {
  // read the buttons:
  // int upState = digitalRead(upButton);
  // int downState = digitalRead(downButton);
  // int rightState = digitalRead(rightButton);
  // int leftState = digitalRead(leftButton);
  // int clickState = digitalRead(mouseButton);
  upState = LOW;
  downState = LOW;
  rightState = LOW;
  leftState = LOW;
  clickState = LOW;
  if (irrecv.decode(&results))
  {

    RED = results.value;
    Serial.println(RED);
    irrecv.resume();
    delay(150);
    if (RED == AVANT_HIFI || RED == AVANT_ROBOT)
    {
      upState = HIGH;
      Serial.println("UP");
    }
    if (RED == ARRIERE_HIFI || RED == ARRIERE_ROBOT)
    {
      downState = HIGH;
      Serial.println("DOWN");
    }
    if (RED == DROITE_HIFI || RED == DROITE_ROBOT)
    {
      rightState = HIGH;
      Serial.println("RIGHT");
    }
    if (RED == GAUCHE_HIFI || RED == GAUCHE_ROBOT)
    {
      leftState = HIGH;
      Serial.println("LEFT");
    }
    if (RED == STOP_HIFI || RED == STOP_ROBOT)
    {
      clickState = HIGH;
      Serial.println("CLICK");
    }
    if (RED == VOLUME_UP_HIFI)
    {
      clickState = HIGH;
      Serial.println("SCROLL_UP");
    }
    if (RED == VOLUME_DOWN_HIFI)
    {
      clickState = HIGH;
      Serial.println("SCROLL_DOWN");
    }
    if (RED == USB_REC_HIFI)
    {
      clickState = HIGH;
      Serial.println("RIGHT_CLICK");
    }
    if (RED == OFF_HIFI)
    {
      clickState = HIGH;
      Serial.println("OFF");
    }

    // // calculate the movement distance based on the button states:
    // int  xDistance = (leftState - rightState) * range;
    // int  yDistance = (upState - downState) * range;

    // if X or Y is non-zero, move:
    // if ((xDistance != 0) || (yDistance != 0)) {
    //   // Mouse.move(xDistance, yDistance, 0);
    //   Serial.println(xDistance + yDistance);
    // }
    // a delay so the mouse doesn't move too fast:
    // delay(responseDelay);
  }
}
