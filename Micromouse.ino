#define right_wheel_1 A6
#define right_wheel_2 A7
#define left_wheel_1 A8
#define left_wheel_2 A9


void right_forward(){
    analogWrite(right_wheel_1, 0);
    analogWrite(right_wheel_2, 255);
    Serial.println("right forward");
  }
void left_forward(){
    analogWrite(left_wheel_1, 0);
    analogWrite(right_wheel_2, 255);
    Serial.println("left forward");
  }
void setup() {

}

void loop() {
  right_forward();
  left_forward();
}


