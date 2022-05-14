// Amount to divide current fan rpm with, compare your fan spec sheets to figure this out.
float rpmDivider = 3.375;

// Pins
int fanInputPin = 2; // Read rpm from fan
int analogOutputPin = 3; // Adjust then output pwm to this pin

// Initialize variables 
bool pinStatus; // Whether pin is outputting high or low
int pulseLoopDelay = 0; // Delay between pulses

void setup() {
  Serial.begin(115200);
};

// Starts counting time for loops
long microValuePulse, microValueLoop = micros(); // Sets variable to the current time
long microsPassedPulse, microsPassedLoop;

void loop() {
  // Checks how much time has passed since last loop
  microsPassedPulse = micros() - microValuePulse;
  microsPassedLoop = micros() - microValueLoop;

  // Catch overflow
  if (microValuePulse > micros()) {
    microValuePulse = micros();
    microsPassedPulse = 0;
  }
  if (microValueLoop > micros()) {
    microValueLoop = micros();
    microsPassedLoop = 0;
  }

  // Quick check incase pulseLoopDelay decided to be 0
  if (pulseLoopDelay != 0) {
    // Check if time to toggle pin
    if (microsPassedPulse >= pulseLoopDelay) {
      // If pinStatus says that the pin is off then turn it on
      if (!pinStatus) {
        digitalWrite(analogOutputPin, HIGH);
        pinStatus = true;
      }
      // Otherwise turn it off
      else {
        digitalWrite(analogOutputPin, LOW);
        pinStatus = false;
      }

      // Resets timer
      microValuePulse = micros();
    }
  }

  // Attempts to read pulse length
  int fanInputVal = pulseIn(fanInputPin, HIGH);

  // Changes delay between pulses to adjusted value from the fan input
  pulseLoopDelay = fanInputVal / rpmDivider;
};