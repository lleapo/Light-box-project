//this currently works, code needs to be reorganized 

int ledPin= 11;
int buttonPin= 2; 
int buttonval=0;
int mode=0;
float currtime = 0;
unsigned long ledtime = 0; //use for blinking LED
int diffState = LOW; //blinking pin state

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(ledPin,OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
buttonval= digitalRead(buttonPin);

if (buttonval==HIGH && mode==0) {
mode=1;
digitalWrite(ledPin, 64);
}

if (buttonval==HIGH && mode==1){
mode=2 ;
digitalWrite(ledPin, 127);
}

if (buttonval==HIGH && mode==2){
  mode=3;
digitalWrite(ledPin, 255);
}

if (buttonval==HIGH && mode==3){
mode=4;
unsigned long currtime = millis();
  if (mode==4) {
 
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
 
}

if (buttonval==HIGH && mode==4){
  mode=5;
  digitalWrite (ledPin, LOW);
}

}
