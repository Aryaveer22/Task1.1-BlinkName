int ledPin = 13; // The built-in LED on most Arduino boards
int dotDelay = 1000; // Duration of a dot (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT); // Initialize the digital pin as an output
}

void loop() {
  String message = "ARYAVEER"; 
  morseBlink(message);
  delay(3000); 
}

void morseBlink(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message.charAt(i);
    switch (c) {
      case 'A':
        blinkDot();
        blinkDash();
        break;
      case 'R':
        blinkDot();
        blinkDash();
        blinkDot();
        break;
      case 'Y':
        blinkDash();
        blinkDot();
        blinkDash();
        blinkDash();
        break;
      case 'V':
        blinkDot();
        blinkDot();
        blinkDot();
        blinkDash();
        break;
      case 'E':
        blinkDot();
        break;
      case ' ':
        delay(dotDelay * 3); // Space between words
        break;
    }
    delay(dotDelay); // Space between characters within a word
  }
}

void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
  delay(dotDelay); // Dot duration
  digitalWrite(ledPin, LOW); // Turn off LED
  delay(dotDelay); // Space between dots and dashes
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
  delay(dotDelay * 3); // Dash duration (3 times the dot duration)
  digitalWrite(LED_BUILTIN, LOW); // Turn off LED
  delay(dotDelay); // Space between dots and dashes
}
