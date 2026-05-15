// Piano com buzzer e 4 botões

const int buzzerPin = 8; // Pino do buzzer
const int buttonPins[] = {2, 3, 4, 5}; // Pinos dos botões
const int notes[] = {262, 294, 330, 349}; // Dó, Ré, Mi, Fá

void setup() {
  // Configura os botões com pull-up interno
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {

  bool playing = false;

  // Verifica os botões
  for (int i = 0; i < 4; i++) {

    if (digitalRead(buttonPins[i]) == LOW) {
      tone(buzzerPin, notes[i]);
      playing = true;
      break; // toca apenas uma nota por vez
    }
  }

  // Se nenhum botão estiver pressionado
  if (!playing) {
    noTone(buzzerPin);
  }
}