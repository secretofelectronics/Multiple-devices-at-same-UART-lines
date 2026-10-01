void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  // ESP8266 onboard LED is normally active LOW
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {

  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');

    command.trim();

    // ESP8266 address = 2

    if (command == "@2:LED:ON") {

      digitalWrite(LED_BUILTIN, LOW);
    }

    else if (command == "@2:LED:OFF") {

      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}