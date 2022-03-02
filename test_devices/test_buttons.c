//
//
//
//
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(34,INPUT);
 pinMode(35,INPUT);
 pinMode(32,INPUT);
 pinMode(33,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(F("BOTON 1"));
  Serial.println(digitalRead(14));
  Serial.println(F("BOTON 2"));
  Serial.println(digitalRead(12));
  Serial.println(F("BOTON 3"));
  Serial.println(digitalRead(13));
  Serial.println(F("BOTON 4"));
  Serial.println(digitalRead(15));

}