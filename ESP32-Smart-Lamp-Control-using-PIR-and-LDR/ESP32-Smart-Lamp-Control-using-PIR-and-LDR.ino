/*
 * ESP32 Smart Lamp Control using PIR and LDR
 * ------------------------------------------
 * This program controls a relay based on motion detection (PIR sensor) 
 * and ambient light level (LDR sensor). The relay remains ON for a 
 * specified duration when motion is detected in the dark.
 * 
 * Developed by: Yodha Ardiansyah
 * Website: https://arunovasi.my.id
 */

// Pin Configuration
#define PIR_PIN 25       // PIR sensor connected to GPIO25
#define LDR_PIN 12       // LDR sensor (Digital)
#define RELAY_PIN 13     // Relay module control pin

// Timing Variables
unsigned long lastMotionTime = 0;          // Last motion detection timestamp
const unsigned long relayActiveTime = 5000; // Relay stays ON for 5 seconds

void setup() {
  // Initialize pins
  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Ensure relay is OFF at startup
  digitalWrite(RELAY_PIN, LOW);

  // Serial monitor for debugging
  Serial.begin(115200);
  Serial.println("Starting ESP32 program for LDR, PIR, and Relay control...");
}

void loop() {
  // Read LDR status (HIGH = bright, LOW = dark)
  int ldrStatus = digitalRead(LDR_PIN);
  // Read PIR status (HIGH = motion detected, LOW = no motion)
  int motionDetected = digitalRead(PIR_PIN);

  // Get current time
  unsigned long currentTime = millis();

  // Relay control logic
  if (ldrStatus == HIGH) { // Dark condition
    if (motionDetected == HIGH) {
      // If motion is detected
      digitalWrite(RELAY_PIN, HIGH);  // Turn ON relay
      lastMotionTime = currentTime;   // Reset timer
      Serial.println("Motion detected! Relay ON");
    } else if (currentTime - lastMotionTime < relayActiveTime) {
      // If no new motion but within the active duration
      digitalWrite(RELAY_PIN, HIGH);  // Keep relay ON
      Serial.println("Relay remains ON");
    } else {
      // If no motion for the specified duration
      digitalWrite(RELAY_PIN, LOW);   // Turn OFF relay
      Serial.println("No motion detected. Relay OFF");
    }
  } else {
    // Bright condition
    digitalWrite(RELAY_PIN, LOW);     // Ensure relay is OFF
    Serial.println("Bright condition. Relay OFF");
  }

  // Delay before the next loop iteration
  delay(100);
}
