int upbutton1 = 10;
int downbutton1 = 11;
int leftbutton1 = 12;
int app = 9;
int app1 = 8; 
int up = 0;
int down = 0;

void setup() {
pinMode(upbutton1, INPUT);
pinMode(downbutton1,INPUT);
pinMode(app,OUTPUT);
pinMode(app1,OUTPUT);
digitalWrite(upbutton1,HIGH);
digitalWrite(downbutton1,HIGH);
digitalWrite(app1,HIGH);
Serial.begin(9600);
}

void loop() {
  upbutton();
  downbutton();
}

void upbutton(){
  int upvalue = digitalRead(upbutton1);
  if(upvalue == LOW){
    up++;
    delay(200);
  }
  if(up == 1){
    digitalWrite(app,HIGH);
    Serial.print("ON");
  }
  if(up>=2){
    digitalWrite(app,LOW);
    up = 0;
  }
}
void downbutton(){
  int downvalue = digitalRead(downbutton1);
  if(downvalue == LOW){
    down++;
    delay(200);
  }
  if(down == 1){
    digitalWrite(app1,HIGH);
  }
  if(down>=2){
    digitalWrite(app1,LOW);
    down = 0;
  }
}
