void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
}

void loop() {
  int front, back;
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
}
