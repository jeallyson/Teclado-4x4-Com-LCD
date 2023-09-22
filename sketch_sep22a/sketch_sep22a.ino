#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

#define linhas  4
#define colunas 4


char mapaTeclas[linhas][colunas] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
String digitada;      // Senha digitada
byte pinos_linhas[linhas] = {A0, A1, A2, A3};
byte pinos_colunas[colunas] = {2, 3, 4, 5};

Keypad teclado = Keypad(makeKeymap(mapaTeclas), pinos_linhas, pinos_colunas, linhas, colunas);

void setup() {
    // Iniciar comunicação serial
    Serial.begin(9600);

    // Inicializar o LCD
    lcd.begin(16, 2);
    lcd.print("Aguardando...");
}

void loop() {
    char tecla = teclado.getKey(); // Lê a tecla pressionada

    if (tecla) {
        digitada += tecla; // Adiciona a tecla à string digitada
        Serial.print("Tecla pressionada: ");
        Serial.println(tecla); // Exibe a tecla no monitor serial

        // Exibe o que foi digitado no LCD
        lcd.clear(); // Limpa o LCD
        lcd.setCursor(0, 0); // Define a posição do cursor no LCD
        lcd.print("Tecla Digitada");
        lcd.setCursor(0, 1); // Define a segunda linha do LCD
        lcd.print(digitada);
    }

    // Aqui você pode adicionar lógica para verificar a senha, se necessário

    delay(100); // Pequeno atraso para evitar leituras rápidas de teclas
}
