#define FINAL_THRESH 80
#define DIFF_THRESH 7

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial.println("Hello! I look for WiFi");
}

void loop() {
  int front, back;
  sp();
  Serial.println("Clearing buffers...");
  while(Serial1.available()) Serial1.read();
  while(Serial2.available()) Serial2.read();
  do {
    Serial.println("Waiting for front sensor...");
    while(!Serial1.available()) {
      delay(10);
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
      delay(10);
    }
    Serial.print("Reading from back sensor... ");
    back = Serial2.read();
    Serial.write(back);
    Serial.print(" (");
    Serial.print(back, DEC);
    Serial.println(")");
  } while(back == 0 || back >= 128);

  Serial.print(front, DEC);
  Serial.print(" - ");
  Serial.print(back, DEC);
  Serial.print(" = ");
  Serial.println(front - back);

  if(front > FINAL_THRESH) {
    sp();
    Serial.println("WiFi found!");
  } else if(front - back > DIFF_THRESH) {
//    fd(100);
    Serial.println("It's straight ahead!");
  } else {
//    lt(100);
    Serial.println("Searching...");
  }
  delay(500);
}
