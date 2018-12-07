//Carrega a biblioteca LiquidCrystal
#include <stdlib.h>
#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

// VARIAVEIS GLOBAIS
String StrConta;                          // Guarda string com a conta
String StrResult = "    ";                // Guarda string com o resultado
int Resultado = 0;                        // Guarda resultado da conta
String ResultIncorreto = "ERRRROOOOUUU!"; // Mensagem de erro
String BomDia = "Bom dia!";               // Mensagem de acerto
int Acertos = 0;                          // Contabiliza acertos
const byte linhas = 4;                    //4 linhas
const byte colunas = 4;                   //4 colunas

char matrizteclado[linhas][colunas] = { //teclado matricial
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinoslinhas[linhas] = {9,8,7,6}; //pinos utilizados nas linhas
byte pinoscolunas[colunas] = {5,4,3,2}; //pinos utilizados nas colunas
 
//inicializando o teclado
Keypad teclado = Keypad( makeKeymap(matrizteclado), pinoslinhas, pinoscolunas, linhas, colunas );
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 28, 29, 30, 31);

void geraConta() {
    int opA = (int) random(1, 100);                       // Operando A recebe um número aleatório
    int opB = (int) random(1, 100);                       // Operando B recebe um número aleatório
    int op = (int) random(1,3);                           // Operador recebe 1 ou 2
    char strOp;
    if (op == 1) {                                        // Se op é 1, será uma multiplicação
        strOp = '*';
        Resultado = opA * opB;
    } else {                                              // Se op é diferente de 1, será uma adição
        strOp = '+';
        Resultado = opA + opB;
    }

    StrConta = (String(opA) + strOp + String(opB) + '=');
    Serial.print(StrConta);
    
}

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
}
 
void loop()
{
  geraConta();                                        // Gera conta aleatoria
  lcd.clear();                                        // Limpa a tela
  lcd.setCursor(3, 0);                                // Posiciona o cursor na coluna 3, linha 0
  lcd.print(StrConta);                                // Envia a conta para o LCD

  char apertatecla = '0';                             // Guarda tecla que foi pressionada
  int posTela = 0;                                    // Guarda posição do digito a ser preenchido
  int resultUsuario = 0;                              // Guarda resultado dado pelo usuário
  while (apertatecla != '*') {
      apertatecla = teclado.getKey();                 // Verifica se alguma tecla foi pressionada

      if (apertatecla != '*') {
        if (apertatecla) {                            // Se alguma tecla foi pressionada
          //Serial.print("Tecla Pressionada: ");
          //Serial.println(apertatecla);
          lcd.setCursor(0, 1);                        // Posiciona o cursor na coluna 0, linha 1
          StrResult[posTela] = apertatecla;           // Monta string com o resultado do usuário
          lcd.print(StrResult);                       // Envia número digitado pelo usuário para o LCD
          resultUsuario = (resultUsuario * (10)) + atoi(&apertatecla);      // Guarda resultado do usuário
          //Serial.println("Resultado: ");
          //Serial.println(resultUsuario);
          posTela++;                                  // Incrementa posição do digito a ser preenchido
        }
      }
    }

    if (Resultado == resultUsuario) {                 // Se usuário acertou a conta
      Acertos++;                                      // Incrementa acertos
    } else {                                          // Se usuário errou a conta
      lcd.clear();                                    // Limpa a tela
      lcd.setCursor(2, 0);                            // Posiciona o cursor na coluna 2, linha 0
      lcd.print(ResultIncorreto);                     // Indica erro na conta
      delay(10000);
    }

    StrResult = "    ";                               // Limpa a string do resultado

    if (Acertos == 3) {                               // Se usuário acertou 3 contas
      lcd.clear();                                    // Limpa a tela
      lcd.setCursor(2, 0);                            // Posiciona o cursor na coluna 2, linha 0
      lcd.print(BomDia);                              // Deseja bom dia ao usuário
      delay(10000);
      while(true);
    }

    
   
//  //Rolagem para a esquerda
//  for (int posicao = 0; posicao < 3; posicao++)
//  {
//    lcd.scrollDisplayLeft();
//    delay(300);
//  }
//   
//  //Rolagem para a direita
//  for (int posicao = 0; posicao < 6; posicao++)
//  {
//    lcd.scrollDisplayRight();
//    delay(300);
//  }
}
