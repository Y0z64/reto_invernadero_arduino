// Pin del CH1
int PIN = 3;
int wait = 2000;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, LOW);
}

void loop() {
  Serial.println("SSR is ON");
  digitalWrite(PIN, HIGH);
  delay(wait);
  digitalWrite(PIN, LOW);
  Serial.println("SSR is OFF");
  delay(wait);  
}
