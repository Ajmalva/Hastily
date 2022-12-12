
int sen1=A0;
int sen2=A3;
int ledRed=9;
int ledGreen=10;
unsigned long t1=0;
unsigned long t2=0; 
float velocity;
float limit = 20.0;
void setup()
{
  Serial.begin(9600);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
}
  void loop()
  {
    while(digitalRead(sen1));
    while(digitalRead(sen1)==0);
    t1=millis();
    while(digitalRead(sen2));
    t2=millis();
    velocity=t2-t1;
    velocity=velocity/1000;//convert millisecond to second
    velocity=(5.0/velocity);//v=d/t
    velocity=velocity*3600;//multiply by seconds per hr
    velocity=velocity/1000;//division by meters per Km
    Serial.println(velocity);
    if(velocity > limit)
    {
      digitalWrite(ledRed,HIGH);
      delay(2000);
      digitalWrite(ledRed,LOW);
      }
      else
      {
        digitalWrite(ledGreen,HIGH);
        delay(2000);
        digitalWrite(ledGreen,LOW);
      }
  }
