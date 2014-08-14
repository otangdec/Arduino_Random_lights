/*

*/


int switchState = 0;
int count = 0;
int DELAYED = 150;
void setup()
{
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(2,INPUT);
    randomSeed(analogRead(0));
}

void loop()
{ 
  int result = 0;
  int cycles = 0;
  //light();
  
  switchState = digitalRead(2);
  
  if( switchState == HIGH) {
    
    for(int i = 0; i < 15; i++){      
      if(i >= 0 && i<= 5) light(100);
      else if (i > 5 && i < 12) light(150);
      else if(i == 12) light(200);
      else if(i == 13) light(250);
      else if(i == 14) light(350);
      else light(450); 
    }

    result = random(1,6);  // get random number from 1 - 6
    switch(result){
      case 1:
        red1On();
        delay(1500);
        break;
      case 2:
        red1On();
        delay(500);
        blueOn();
        delay(1500);
        break;
      case 3:
        red1On();
        delay(500);
        blueOn();
        delay(500);
        yellowOn();
        delay(1500);
        break;
      case 4:
        red1On();
        delay(500);
        blueOn();
        delay(500);
        yellowOn();
        delay(500);
        red2On();
        delay(1500);
        break;
      case 5: 
        red1On();
        delay(500);
        blueOn();
        delay(500);
        yellowOn();
        delay(500);
        red2On();
        delay(500);
        greenOn();
        delay(1500);
        break;
    } 
  }
  resetLight();
}

void resetLight(){
  count = 0;
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
}
void light(int delayed)
{ 
     red1On();
     delay(delayed);
     blueOn();
     delay(delayed);
     yellowOn();
     delay(delayed);
     red2On();
     delay(delayed);
     greenOn();
     delay(delayed);
}
   
void red1On(){
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

void blueOn(){
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}

void yellowOn(){
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

void red2On(){
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

void greenOn(){
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
