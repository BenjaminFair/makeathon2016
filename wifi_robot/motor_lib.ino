//Motors
#define NUM_MOTORS 4
const int pwm[NUM_MOTORS] = {4, 9, 10, 7};
const int dir[NUM_MOTORS] = {45, 42, 44, 43};

void setupMotors() {
  for(int i = 0; i < NUM_MOTORS; i++) {
    pinMode(pwm[i], OUTPUT);
  }
  for(int i = 0; i < NUM_MOTORS; i++) {
    pinMode(dir[i], OUTPUT);
  }
}

void fd(int speed) {
  digitalWrite(dir[0], HIGH);
  digitalWrite(dir[1], HIGH);
  digitalWrite(dir[2], LOW);
  digitalWrite(dir[3], LOW);
  for(int i = 0; i < NUM_MOTORS; i++) {
    analogWrite(pwm[i], speed);
  }
}

void bk(int speed) {
  digitalWrite(dir[0], LOW);
  digitalWrite(dir[1], LOW);
  digitalWrite(dir[2], HIGH);
  digitalWrite(dir[3], HIGH);
  for(int i = 0; i < NUM_MOTORS; i++) {
    analogWrite(pwm[i], speed);
  }
}

void sp() {
  for(int i = 0; i < NUM_MOTORS; i++) {
    analogWrite(pwm[i], 0);
  }
}

void lt(int speed) {
  digitalWrite(dir[0], HIGH);
  digitalWrite(dir[1], LOW);
  digitalWrite(dir[2], LOW);
  digitalWrite(dir[3], HIGH);
  for(int i = 0; i < NUM_MOTORS; i++) {
    analogWrite(pwm[i], speed);
  }
}

void rt(int speed) {
  digitalWrite(dir[0], LOW);
  digitalWrite(dir[1], HIGH);
  digitalWrite(dir[2], HIGH);
  digitalWrite(dir[3], LOW);
  for(int i = 0; i < NUM_MOTORS; i++) {
    analogWrite(pwm[i], speed);
  }
}
