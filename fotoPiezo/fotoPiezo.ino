int speaker=12;
int foto=0;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  int lect=analogRead(A0);
  Serial.println(lect);
  int pitch=200+lect/4;
  tone(speaker,pitch);
}
