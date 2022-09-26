// Example sketch using blink without delay to blink leds in sequence

#define RED 8
#define YELLOW 12
#define GREEN 13

// Use a struct to contain data for a single led
typedef struct {
  int pin;
  bool state;
  bool priority;
  unsigned long previousMillis;
  int passTo;
} LED;

// Initialize leds
LED redLed = {RED, LOW, false, 0, YELLOW};
LED yellowLed = {YELLOW, LOW, false, 0, GREEN};
LED greenLed = {GREEN, LOW, false, 0, RED};

const unsigned long interval = 1000;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  redLed.priority = true;
  Serial.begin(9600);
}

void loop() {
  // If an led has priority, then it will call blinkWithoutDelay
  if(redLed.priority) blinkWithoutDelay(&redLed, interval);
  if(yellowLed.priority) blinkWithoutDelay(&yellowLed, interval);
  if(greenLed.priority) blinkWithoutDelay(&greenLed, interval);
}

void blinkWithoutDelay(LED *led, unsigned long interval){
  unsigned long currentMillis = millis();
  if(currentMillis - led->previousMillis >= interval){
    led->previousMillis = currentMillis;
    led->state = !led->state;
    digitalWrite(led->pin, led->state);
    led->priority = led->state;
    switch(led->passTo){
      case GREEN:
        greenLed.priority = !led->priority;
        break;
      case RED:
        redLed.priority = !led->priority;
        break;
      case YELLOW:
        yellowLed.priority = !led->priority;
        break;
      default:
        redLed.priority = !led->priority;
    }
  }
}
