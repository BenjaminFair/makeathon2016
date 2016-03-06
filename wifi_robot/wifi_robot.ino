#define FINAL_THRESH 83
#define DIFF_THRESH 1080

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial.println("Hello! I look for WiFi");
}

void loop() {
  long front, back;
  sp();
  delay(2000);
  Serial.println("Clearing buffers...");
  while(Serial1.available()) Serial1.read();
  while(Serial2.available()) Serial2.read();
  do {
    Serial.println("Waiting for front sensor...");
    while(!Serial1.available()) {
//      delay(10);
    }
    Serial.print("Reading from front sensor...");
    front = Serial1.read();
    Serial.write(front);
    Serial.print(" (");
    Serial.print(front, DEC);
    Serial.println(")");
  } while(front == 0 || front >= 128);

  do {
    Serial.println("Waiting for back sensor...");
    while(!Serial2.available()) {
//      delay(10);
    }
    Serial.print("Reading from back sensor... ");
    back = Serial2.read();
    Serial.write(back);
    Serial.print(" (");
    Serial.print(back, DEC);
    Serial.println(")");
  } while(back == 0 || back >= 128);

  Serial.print(front, DEC);
  Serial.print(" / ");
  Serial.print(back, DEC);
  Serial.print(" = ");
  Serial.println(front*1000 / back);

  if(front > FINAL_THRESH) {
    sp();
    Serial.println("WiFi found!");
    digitalWrite(13, HIGH);
    delay(1000);
  } else if((front*1000) / back > DIFF_THRESH) {
    fd(100);
    Serial.println("It's straight ahead!");
    digitalWrite(13, LOW);
    delay(1500);
  } else {
    lt(85);
    Serial.println("Searching...");
    digitalWrite(13, LOW);
    delay(500);
  }
}
