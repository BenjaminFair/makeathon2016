#define FINAL_THRESH 80
#define DIFF_THRESH 6

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
}

void loop() {
  int front, back;
  sp();
  while(Serial1.available()) Serial1.read();
  while(Serial2.available()) Serial2.read();
  do {
    while(!Serial1.available()) {
      delay(10);
    }
    front = Serial1.read();
  } while(front == 0 || front >= 128);

  do {
    while(!Serial2.available()) {
      delay(10);
    }
    back = Serial2.read();
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
    fd(100);
    Serial.println("It's straight ahead!");
  } else {
    lt(100);
    Serial.println("Searching...");
  }
  delay(500);
}
