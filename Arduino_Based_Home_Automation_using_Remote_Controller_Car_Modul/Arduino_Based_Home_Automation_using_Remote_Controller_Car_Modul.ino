const int timebomb = 10;
const int trigger = 9;
int timer = 10;
bool bombstatus = true;
bool initializing = true;
void setup() 
{
pinMode(timebomb, INPUT);
pinMode(trigger,OUTPUT);
digitalWrite(timebomb,HIGH);
Serial.begin(9600);
Serial.println("Waiting for trigger...");
}

void loop() 
{
  Bomba();
}
void Bomba()
{
  int switchvalue = digitalRead(timebomb);
    if (switchvalue == LOW)
        {
          if(initializing)
          {
            Serial.println("initiating Time Bomb.............");
            delay(1000);
            initializing = false;
          }
          else
          {
            if(timer<=0)
            {
              if(bombstatus)
                {
                  digitalWrite(trigger,LOW);
                  Serial.println("The Bomb Explode!");
                  delay(1000);
                  bombstatus = false;
                }
            }
              else
              { 
                Serial.print("The Bomb will Explode in ");
                Serial.print(timer);
                Serial.println(" second/s");
                timer--;
                delay(1000);
              }
           }
        }
    else{
        bombstatus = true;
        if(!initializing)
        { 
          Serial.println("Initiation Canceled!");
          digitalWrite(trigger,HIGH);  
          delay(3000);
          Serial.println("Waiting for trigger...");
        }
         initializing = true;
         timer = 10;
         digitalWrite(trigger,HIGH);          
        }
}
