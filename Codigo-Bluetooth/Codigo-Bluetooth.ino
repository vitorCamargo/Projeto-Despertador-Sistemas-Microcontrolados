int led = 13;
 
boolean status1 = false;
 
 
void setup() {
 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
 
void loop() {
  char comando = Serial.read();
 
 
  if(comando == 'a') {
    if (status1) {
      digitalWrite(led, LOW);
      status1 = false;
    } else {
      digitalWrite(led, HIGH);
      status1 = true;
    }
  }
 
}
