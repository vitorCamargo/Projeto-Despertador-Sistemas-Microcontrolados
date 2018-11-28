# Projeto Despertador

## Ata da Reunião para Decisões de Projeto (14/11/2018 - 15h50min)

### Ideia Geral
A ideia geral do projeto é desenvolver um despertador utilizando a plataforma Arduino, que trabalhará em conjunto com um aplicativo desenvolvido utilizando React Native. 

![Imagem da Ideia](https://github.com/lucasvribeiro/Projeto-Despertador-Sistemas-Microcontrolados/blob/master/ata.png)

### Materiais e Métodos
Para projetar o circuito serão utilizados os seguintes materiais:
- 1 Arduino Mega 2560
- 1 LCD 16x2
- 1 Módulo Buzzer
- 1 Módulo Bluetooth HC-06
- 1 Módulo RTC (Real Time Clock)
- 1 LED 5mm
- 1 Teclado Matricial
- 3 Resistores
- Vários Jumpers

O código do programa será feito em C++ utilizando o Arduino IDE.

Para o desenvolvimento do aplicativo serão utilizadas as tecnologias Node.JS e React Native.

### Como funciona
Ao final do projeto, será possível estabelecer uma conexão via Bluetooth, entre o celular e o projeto, utilizando o aplicativo desenvolvido. Desta forma, ainda no aplicativo, será possível escolher um horário para o despertador. Ao fazê-lo, um sinal será enviado para o Módulo Bluetooth do projeto, indicando o horário selecionado. Este horário será salvo na EEPROM do Arduino e, quando o horário selecionado for igual ao horário atual indicado pelo Módulo RTC, o Módulo Buzzer  e o celular começarão a emitir sons de alarme.
Além disso, uma operação randômica de soma ou multiplicação será exibida no Display LCD 16x2, e os alarmes ***só*** irão parar de soar quando o usuário inserir o resultado, no Display LCD, utilizando o Teclado Matricial.

### Pré Requisitos (Rúbrica)
Para a realização deste projeto, foram necessários cumprir os seguintes pré-requisitos:
1. O projeto deve usar um display (7 segmentos, LCD texto, LCD gráfico), ***o qual é utilizado para mostrar mostrar a conta para que o despertador pare de tocar***;
2. O projeto deve controlar pelo menos um LED, ***utilizado para mostrar se já existe algum valor armazendo na memória EEPROM (algum horário para despertar)*** ;
3. O projeto deve fazer beep com um buzer ou um autofalante, ***o projeto fica apitando pelo buzzer quando der a hora de despertar***;
4. O projeto deve ter uma modalidade de entrada do tipo botão ou teclado, ***utilizamos a matriz de botões para que seja possível digitar o resultado da conta para desligar o despertador***;
5. O projeto deve se comunicar com algum dispositivo (protocolos USART, SPI, e/ou
I2C), ***será utilizado o módulo de tempo real, que utiliza o protocolo I2C***;
6. O projeto deve logar alguma variável de maneira permanente (EEPROM, MMC
Card), ***é armazedo na EEPROM o horário que o despertador deve ser ligado***;
7. O projeto deve permitir entradas via porta serial (computador controlando o
dispositivo), ***utilizamos o módulo de bluetooth para enviar para o dispositivo o horário a ser gravado na EEPROM e consequentemente, será o horário para despertar***.

# [Divisão das Tarefas](https://github.com/lucasvribeiro/Projeto-Despertador-Sistemas-Microcontrolados/blob/master/Divisao-de-Tarefas.md)
