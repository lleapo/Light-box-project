int ledPin= 9;
int buttonPin= 3; 
int buttonval=0;
int mode=0;
float currtime = 0;
unsigned long lastinterrupttime =0;
unsigned long ledtime = 0; //use for blinking LED
int diffState = LOW; //blinking pin state
bool buttonpushed=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buttonPin, INPUT);
pinMode(ledPin,OUTPUT); 
attachInterrupt(digitalPinToInterrupt(buttonPin), modeset , FALLING);
}
void modeset(){
if (millis()-lastinterrupttime >100){ //debouncing
 mode=mode+1;
lastinterrupttime=millis();
}
}

void loop() {
// put your main code here, to run repeatedly:

switch(mode){
  case 0:
  analogWrite(ledPin,0);
  break;
  
  case 1:
  analogWrite(ledPin, 64);
  break;

  case 2:
  analogWrite(ledPin, 127);
  break;
  
  case 3: 
  analogWrite(ledPin, 255);
  break;
  case 4:
    flash_light();
    break;
}

if (mode>= 5){
 mode=0; 
}

}

void flash_light(){
 unsigned long currtime = millis();
    if (currtime - ledtime >= 500) { //500 millisecond delay
      ledtime = currtime;
      if (diffState == LOW) {
        diffState = HIGH;
      } else {
        diffState = LOW;
      }
      digitalWrite (ledPin, diffState);
}
}

