void setup() {
    Serial.begin(9600);
}

void loop() {
    int resultado = 0;                        // Resultado
    int opA = (int) random(1, 100);                 // Operando A recebe um número aleatório
    int opB = (int) random(1, 100);                 // Operando B recebe um número aleatório
    int op = (int) random(1,3);                    // Operador recebe 0 ou 1
    char strOp;
    if (strOp == 1) {
        strOp = '*';
        resultado = opA * opB;
    } else {
        strOp = '+';
        resultado = opA + opB;
    }
    

    Serial.print(opA);
    Serial.print(strOp);
    Serial.print(opB);
    Serial.print(resultado);
    delay(1000);
}
