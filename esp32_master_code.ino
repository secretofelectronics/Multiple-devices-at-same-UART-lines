HardwareSerial Bus(2);

#define BUTTON_NANO 25
#define BUTTON_ESP8266 26

bool lastNanoState = HIGH;
bool lastESP8266State = HIGH;

void setup() {

  Serial.begin(115200);

  // UART2
  // RX = GPIO16
  // TX = GPIO17
  Bus.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(BUTTON_NANO, INPUT_PULLUP);
  pinMode(BUTTON_ESP8266, INPUT_PULLUP);

  Serial.println("ESP32 MASTER STARTED");
}

void loop() {

  bool nanoButton = digitalRead(BUTTON_NANO);
  bool esp8266Button = digitalRead(BUTTON_ESP8266);

  // Button 1 controls Nano
  if (nanoButton != lastNanoState) {

    if (nanoButton == LOW) {
      Bus.println("@1:LED:ON");
      Serial.println("Nano LED ON");
    }
    else {
      Bus.println("@1:LED:OFF");
      Serial.println("Nano LED OFF");
    }

    lastNanoState = nanoButton;
  }

  // Button 2 controls ESP8266
  if (esp8266Button != lastESP8266State) {

    if (esp8266Button == LOW) {
      Bus.println("@2:LED:ON");
      Serial.println("ESP8266 LED ON");
    }
    else {
      Bus.println("@2:LED:OFF");
      Serial.println("ESP8266 LED OFF");
    }

    lastESP8266State = esp8266Button;
  }
}