# Projeto Despertador

## Ata da Reunião para Decisões de Projeto (14/11/2018 - 15h50min)

### Ideia Geral
A ideia geral do projeto é desenvolver um despertador utilizando a plataforma Arduino, que trabalhará em conjunto com um aplicativo desenvolvido utilizando React Native. 

![Imagem da Ideia](https://github.com/lucasvribeiro/Projeto-Despertador-Sistemas-Microcontrolados/blob/master/ata.jpg)

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
