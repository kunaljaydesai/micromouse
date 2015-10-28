#define right_wheel_1 A9
#define right_wheel_2 A7
#define left_wheel_1 A8
#define left_wheel_2 A6


void right_forward(){
    analogWrite(right_wheel_1, 0);
    analogWrite(right_wheel_2, 255);
    Serial.println("right forward");
  }
void left_forward(){
    analogWrite(left_wheel_1, 0);
    analogWrite(left_wheel_2, 255);
    Serial.println("left forward");
  }

void right_backward(){
  analogWrite(right_wheel_1, 255);
  analogWrite(right_wheel_2, 0);
  Serial.println("right backward");
  }
void left_backward(){
  analogWrite(left_wheel_1, 255);
  analogWrite(left_wheel_2, 0);
  Serial.println("left backward");
  }

void turn_left(){
  right_forward();
  left_backward();
  }

void turn_right(){
    right_backward();
    left_forward();
  }
void setup() {

}

void loop() {
  /*right_backward();
  left_backward();
  delay(5000);
  right_forward();
  left_forward();
  delay(5000);*/
  turn_right();
  delay(5000);
  turn_left();
  delay(5000);
}


