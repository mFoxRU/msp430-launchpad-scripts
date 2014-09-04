//     Simple script for timed light
// Turns the light on when button is pressed
// Keeps the light on while button is pressed
// Keeps the light on for 'timeout' when button is released
// Timer restarts on new button press

//       CONFIG
// Timeout 
const int timeout = 2000;
//    END OF CONFIG


const int button = PUSH2;
const int light = GREEN_LED;
const int time_step = 100;

int remaining = 0;

void setup()
{
  pinMode(button, INPUT_PULLUP);     
  pinMode(light, OUTPUT);      
}

void loop() {
  if (digitalRead(button) == LOW)
    remaining = timeout;
  if (remaining > 0) 
    digitalWrite(light, HIGH);
  else {
    digitalWrite(light, LOW);
    remaining = 0;
  }
  remaining -= time_step;
  delay(time_step);
}
