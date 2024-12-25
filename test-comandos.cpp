// Código para Arduino Mega
const int leds[6] = {2, 3, 4, 5, 6, 7}; // Portas para os LEDs
const int inputs[7] = {8, 9, 10, 11, 12, 13, 14}; // Portas de entrada

void setup() {
  // Configuração das portas dos LEDs como saída
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW); // Inicia os LEDs desligados
  }
  
  // Configuração das portas de entrada
  for (int i = 0; i < 7; i++) {
    pinMode(inputs[i], INPUT_PULLUP); // Usa resistores pull-up
  }
  
  // Configuração da comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê comandos da porta serial
  if (Serial.available() > 0) {
    char command = Serial.read();
    handleCommand(command);
  }
}

void handleCommand(char command) {
  switch (command) {
    case 'U': // Seta para cima
      digitalWrite(leds[0], HIGH);
      break;
    case 'D': // Seta para baixo
      digitalWrite(leds[1], HIGH);
      break;
    case 'L': // Seta para esquerda
      digitalWrite(leds[2], HIGH);
      break;
    case 'R': // Seta para direita
      digitalWrite(leds[3], HIGH);
      break;
    case 'P': // Página para cima (saltar)
      digitalWrite(leds[4], HIGH);
      break;
    case 'N': // Página para baixo (abaixar)
      digitalWrite(leds[5], HIGH);
      break;
    default:
      // Apaga todos os LEDs para outros comandos
      for (int i = 0; i < 6; i++) {
        digitalWrite(leds[i], LOW);
      }
      break;
  }
}
