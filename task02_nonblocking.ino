/*
  Task 02 - Timers and Non-Blocking Code
  Embedded Systems & IoT

  Requirements:
  - No delay() in the main loop
  - Use a timer correctly
  - Two things happen at different rates

  LED 1 toggles every 500 ms.
  LED 2 toggles every 2000 ms.
  millis() is used so the loop never blocks.
*/

const int LED_FAST = 8;
const int LED_SLOW = 9;

const unsigned long FAST_INTERVAL = 500;
const unsigned long SLOW_INTERVAL = 2000;

unsigned long previousFast = 0;
unsigned long previousSlow = 0;

bool fastState = LOW;
bool slowState = LOW;

void setup() {
  pinMode(LED_FAST, OUTPUT);
  pinMode(LED_SLOW, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  // Fast task: toggle LED 1 every 500 ms
  if (currentMillis - previousFast >= FAST_INTERVAL) {
    previousFast = currentMillis;
    fastState = !fastState;
    digitalWrite(LED_FAST, fastState);
    Serial.println("Fast task: 500 ms");
  }

  // Slow task: toggle LED 2 every 2000 ms
  if (currentMillis - previousSlow >= SLOW_INTERVAL) {
    previousSlow = currentMillis;
    slowState = !slowState;
    digitalWrite(LED_SLOW, slowState);
    Serial.println("Slow task: 2000 ms");
  }

  // No delay(): the loop remains free for other work.
}
