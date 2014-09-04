const int buttonPin = PUSH2;    // Button
const int ledPin =  GREEN_LED;  // LED
const int timestep = 25;        // Loop delay

int buttonState = 0;
int buttonPressedFor = 0;  // Таймер времени нажатия кнопки

void setup()
{
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {      // Кнопка отжата, следовательно:
    buttonPressedFor = 0;         //   сбрасываем счётчик времени нажатия
    digitalWrite(ledPin, LOW);    //   и выключаем диод
  }
  else {                          // Кнопка нажата, следовательно:
    buttonPressedFor += timestep; //   увеличиваем счётчик времени нажатия
    digitalWrite(ledPin, HIGH);   //   и включаем диод
  }
  
  if (buttonPressedFor >= 5000) { // Если кнопка была нажата более 5 секунд:
    buttonPressedFor = 0;         //   Сбрасываем счётчик нажатия
    // Здесь вставляем любой код который хотим выполнить
    // Или какие delay нам надо
    // например:
    //   delay(15000);
  }
  delay(timestep);
}
