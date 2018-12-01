#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Keypad.h>
#include <DS1307.h>

#define TAM_HORA 5

boolean statusIntervalo = false;
int addr = 0, frequencia;
float seno;

unsigned long int intervalo = 0;

byte value;
char comando;
String horaArmazenada, horaAtual;

const byte linhas = 4, colunas = 4;
char matrizteclado[linhas][colunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinoslinhas[linhas] = {9,8,7,6};
byte pinoscolunas[colunas] = {5,4,3,2};

int led = 13;
int buzzer = 32;
LiquidCrystal lcd(12, 11, 28, 29, 30, 31);
Keypad teclado = Keypad(makeKeymap(matrizteclado), pinoslinhas, pinoscolunas, linhas, colunas);
DS1307 rtc(A4, A5);

void limpa_eeprom() {
  for (int i = 0; i < EEPROM.length(); i++) { EEPROM.write(i, 0); }
}

void recebe_horas() {
  for (int i = 0; i < TAM_HORA; i++) {
    if (i == 0) { horaArmazenada = ""; }
    
    value = EEPROM.read(i);
    horaArmazenada += (char) value;
  }
}

void bluetooth_eeprom() {  
  comando = Serial.read();
  EEPROM.write(addr, comando);
  addr++;

  if (addr == EEPROM.length()) { addr = 0; }
}

void despertar() {
  Serial.println("ACORDA MENINO");
}

void setup() {
  rtc.halt(false);
  rtc.setDOW(FRIDAY);
  rtc.setTime(22, 05, 0);
  rtc.setDate(30, 11, 2018);
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}
 
void loop() {
   recebe_horas();

   if (Serial.available() != 0) { bluetooth_eeprom(); }
   else { addr = 0; }

  if ((millis() - intervalo) >= 30000) {
    if (horaArmazenada == "") {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
  
      horaAtual = rtc.getTimeStr();
      horaAtual.remove(5, 3);
      
      if (horaArmazenada == horaAtual) {
        despertar();
      }
    }
    intervalo = millis();
  }
}
