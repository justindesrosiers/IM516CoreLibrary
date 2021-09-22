// Example use of blink without delay to prevent code being blocked by the delay function.

// Set up constants for the pins we will use
int const GREEN_LED = 10;
int const YELLOW_LED = 9;
int const RED_LED = 8;

// Set up variables to hold our state
int greenState = LOW;
int yellowState = LOW;
int redState = LOW;

// Establish intervals for the given LEDs
int const GREEN_INTERVAL = 1000;
int const YELLOW_INTERVAL = 750;
int const RED_INTERVAL = 1500;

// Store the previous time in a variabl for each LED
unsigned long previousRedMillis = 0; 
unsigned long previousYellowMillis = 0; 
unsigned long previousGreenMillis = 0; 

void setup()
{
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop()
{
  // Store the value returned from the blinkWithoutDelay function into a state for a given LED
  greenState = blinkWithoutDelay(GREEN_INTERVAL, previousGreenMillis);
  redState = blinkWithoutDelay(RED_INTERVAL, previousRedMillis);
  yellowState = blinkWithoutDelay(YELLOW_INTERVAL, previousYellowMillis);
  
  // Supply the state to the digitalWrite function to turn the LED either on, or off.
  digitalWrite(YELLOW_LED, yellowState);
  digitalWrite(GREEN_LED, greenState);
  digitalWrite(RED_LED, redState);
}

/**
* blinkWithoutDelay
* This function takes in an interval and a previousMillis parameter to check that the interval has elapsed.
* When the interval has elapsed against the previousMillis time, the function will return either a true or false value which can be used to execute a block of code
* at the set interval without interrupting the execution of other code in the sketch.
*/
bool blinkWithoutDelay(int interval, unsigned long& previousMillis)
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    return true;
  }
  return false;
}
