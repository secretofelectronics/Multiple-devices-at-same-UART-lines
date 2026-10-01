void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');

    command.trim();

    // Nano address = 1

    if (command == "@1:LED:ON") {

      digitalWrite(LED_BUILTIN, HIGH);
    }

    else if (command == "@1:LED:OFF") {

      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}