int xpin1=0;
int ypin1=1;

int xpin2=2;
int ypin2=3;

int botonpin=2;
int xposi1=0;
int yposi1=0;
int xposi2=0;
int yposi2=0;

int estadoboton=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xpin1,INPUT);
  pinMode(xpin2,INPUT);
  pinMode(ypin1,INPUT);
  pinMode(ypin2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  xposi1=analogRead(xpin1);
  yposi1=analogRead(ypin1);
  xposi2=analogRead(xpin2);
  yposi2=analogRead(ypin2);

  Serial.print("Joystick 1");
  Serial.print("x:");
  Serial.print(xposi1);
  Serial.print("y:");
  Serial.print(yposi1);
  Serial.print("     ");
  Serial.print("Joystick 2");
  Serial.print("x:");
  Serial.print(xposi2);
  Serial.print("y:");
  Serial.println(yposi2);
  delay(1000);
}
