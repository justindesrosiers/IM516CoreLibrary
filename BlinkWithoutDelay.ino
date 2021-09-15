// C++ code
//
int const GREEN_LED = 10;
int const YELLOW_LED = 9;
int const RED_LED = 8;

int greenState = LOW;
int yellowState = LOW;
int redState = LOW;

int const GREEN_INTERVAL = 1000;
int const YELLOW_INTERVAL = 750;
int const RED_INTERVAL = 1500;

unsigned long previousRedMillis = 0; 
unsigned long previousYellowMillis = 0; 
unsigned long previousGreenMillis = 0; 

void setup()
{
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  greenState = blinkWithoutDelay(GREEN_INTERVAL, greenState, previousGreenMillis);
  redState = blinkWithoutDelay(RED_INTERVAL, redState, previousRedMillis);
  yellowState = blinkWithoutDelay(YELLOW_INTERVAL, yellowState, previousYellowMillis);
  digitalWrite(YELLOW_LED, yellowState);
  digitalWrite(GREEN_LED, greenState);
  digitalWrite(RED_LED, redState);
}


bool blinkWithoutDelay(int interval, int previousState, unsigned long& previousMillis)
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    return !previousState;
  }
  return previousState;
}

void blinkLed(int led, int interval)
{
  digitalWrite(led, HIGH);
  delay(interval);
  digitalWrite(led, LOW);
  delay(interval); 
}
