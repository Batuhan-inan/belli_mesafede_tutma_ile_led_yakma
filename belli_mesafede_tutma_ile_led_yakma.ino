int led=4;
int trig=2;
int echo=3;
float sure;
float mesafe;
unsigned long ilksure=0;
bool icindemi=false;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  sure=pulseIn(echo,HIGH);
  mesafe=0.034*sure/2;
  Serial.print("mesafe=");
  Serial.println(mesafe);
  Serial.print("durdugu sure");
  Serial.println(millis() - ilksure);
  delay(1000);

if(mesafe>15&& mesafe<25){
  if(!icindemi){
icindemi=true;
  ilksure=millis();
  }
  if(millis()-ilksure>=500){
  digitalWrite(led,HIGH);

  }
}  
else {
digitalWrite(led,LOW);
  icindemi = false;
}
  

}
