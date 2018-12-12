#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Keypad.h>
#include <DS1307.h>
#include <stdlib.h>

#define TAM_HORA 5

boolean statusIntervalo = false;
int addr = 0, frequencia;
float seno;

unsigned long int intervalo = 0;

byte value;
char comando;
String horaArmazenada, horaAtual;

String StrConta;
String StrResult = "    ";
int Resultado = 0;
String ResultIncorreto = "ERRRROOOOUUU!";
String BomDia = "Bom dia!";
int Acertos = 0;

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

void geraConta() {
    int opA = (int) random(1, 100);
    int opB = (int) random(1, 100);
    int op = (int) random(1, 3);
    char strOp;
    
    if (op == 1) {
        strOp = '*';
        Resultado = opA * opB;
    } else {
        strOp = '+';
        Resultado = opA + opB;
    }

    StrConta = (String(opA) + strOp + String(opB) + '=');
    Serial.print(StrConta);
}

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
  tone(buzzer, 150);
  geraConta();
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(StrConta);

  char apertatecla = '0';
  int posTela = 0;
  int resultUsuario = 0;
  StrResult = "    ";
  while (apertatecla != '*' && apertatecla != '#' && apertatecla != 'A' && apertatecla != 'B' && apertatecla != 'B' && apertatecla != 'C' && apertatecla != 'D') {
      apertatecla = teclado.getKey();

      if (apertatecla != '*' && apertatecla != '#' && apertatecla != 'A' && apertatecla != 'B' && apertatecla != 'B' && apertatecla != 'C' && apertatecla != 'D') {
        if (apertatecla) {
          lcd.setCursor(0, 1);
          StrResult[posTela] = apertatecla;
          lcd.print(StrResult);
          resultUsuario = (resultUsuario * (10)) + atoi(&apertatecla);
          posTela++;
        }
      }
    }

    Serial.println(resultUsuario);
    
    if (Resultado == resultUsuario) {
      Acertos++;
    } else {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(ResultIncorreto);
      delay(5000);
      despertar();
    }

    if (Acertos == 3) {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(BomDia);
      noTone(buzzer);
      delay(3000);
      lcd.clear();
      return ;
    } else {
      despertar();
    }
}

void setup () {
  rtc.halt(false);
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}
 
void loop () {
   recebe_horas();

   if (Serial.available() != 0) { bluetooth_eeprom(); }
   else { addr = 0; }

  if ((millis() - intervalo) >= 35000 || intervalo == 0) {
    Serial.print("Hora Atual: ");
    Serial.println(horaAtual);
    Serial.print("Hora Despertador: ");
    Serial.println(horaArmazenada);
    
    if (horaArmazenada == "") {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
  
      horaAtual = rtc.getTimeStr();
      horaAtual.remove(5, 3);
      
      if (horaArmazenada == horaAtual) {
        despertar();
        Acertos = 0;
      }
    }
    intervalo = millis();
  }
}
