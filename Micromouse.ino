#define right_wheel_1 A9
#define right_wheel_2 A7
#define left_wheel_1 A8
#define left_wheel_2 A6

int encoder_right_1 = 0;
int encoder_right_2 = 0;
int encoder_left_1 = 0;
int encoder_left_2 = 0;

int pin0 = 0;
int pin1 = 1;
int pin2 = 2;
int pin3 = 3;

int left_tick = 0;
int right_tick = 0;

boolean forward_left = true;
boolean forward_right = true;

void right_forward(){
    analogWrite(right_wheel_1, 0);
    analogWrite(right_wheel_2, 255);
    //Serial.println("right forward");
  }
void left_forward(){
    analogWrite(left_wheel_1, 0);
    analogWrite(left_wheel_2, 255);
    //Serial.println("left forward");
  }

void right_backward(){
  analogWrite(right_wheel_1, 255);
  analogWrite(right_wheel_2, 0);
  //Serial.println("right backward");
  }
void left_backward(){
  analogWrite(left_wheel_1, 255);
  analogWrite(left_wheel_2, 0);
  //Serial.println("left backward");
  }

void turn_left(){
  right_forward();
  left_backward();
  }

void turn_right(){
    right_backward();
    left_forward();
  }

void move_forward(){
  right_forward();
  left_forward();
  forward_left, forward_right = true, true;
  }

void move_backward(){
  right_backward();
  left_backward();
  forward_left, forward_right = false, false;
  }
void setup() {
  encoder_right_1 = digitalRead(0);
  encoder_right_2 = digitalRead(1);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  int right_encoder1 = digitalRead(pin0);
  int right_encoder2 = digitalRead(pin1);
  int left_encoder1 = digitalRead(pin2);
  int left_encoder2 = digitalRead(pin3);
  //Serial.println(new_encoder);
  //Serial.println(newer_encoder);
  //delay(2000);
  //turn_right();
  if (right_encoder1 != encoder_right_1 || right_encoder2 != encoder_right_2){
      encoder_right_1 = right_encoder1;
      encoder_right_2 = right_encoder2;
      
      right_tick += 1;
      Serial.println("RIGHT TICK" + right_tick);
    }
    if (left_encoder1 != encoder_left_1 || left_encoder2 != encoder_left_2){
      encoder_left_1 = left_encoder1;
      encoder_left_2 = left_encoder2;
      left_tick += 1;
      Serial.println("LEFT TICK" + left_tick);
      }
  left_backward();
 
}


