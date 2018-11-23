float seno;
int frequencia;
 
void setup() {
  pinMode(32, OUTPUT);
}

void loop() {
  for(int x = 0; x < 180; x++) {
    seno = (sin(x*3.1416/180));
    frequencia = 2000 + (int(seno*1000));
    tone(32, frequencia);
    delay(2);
  }
}
