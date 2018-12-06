#include <EEPROM.h>

int addr = 0;
byte value;
char eeprom, comando;
int control = 0;


void limpa_eeprom(){
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
    Serial.println(i);
  }
}

void bluetooth_eeprom(){
  while(Serial.available() == 0){
    addr = 0;  
  }
  
  comando = Serial.read();
  EEPROM.write(addr, comando);
  value = EEPROM.read(addr);
  eeprom = (char) value; 

  Serial.print("EEPROM: ");
  Serial.print(addr);
  Serial.print("\t");
  Serial.print(eeprom);
  Serial.println();

  addr++;

  if (addr == EEPROM.length()) {
    addr = 0;
  }
}

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  bluetooth_eeprom();
}
