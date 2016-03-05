void setup() {
  setupMotors();

}


void loop() {
  delay(1000);
  fd(100);
  delay(1000);
  bk(100);
  delay(1000);
  lt(100);
  delay(1000);
  rt(100);
  delay(1000);
  stop();

}
