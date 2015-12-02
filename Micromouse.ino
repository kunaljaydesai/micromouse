#define right_wheel_1 A0
#define right_wheel_2 A1
#define left_wheel_1 A2
#define left_wheel_2 A3

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

boolean forward_left = true;
boolean forward_right = true;

//speed(1-100)
void right_forward(float speed){ 
    analogWrite(right_wheel_1, 0);
    analogWrite(right_wheel_2, speed/100*255);
    forward_right = true;
    //Serial.println("right forward");
  }
void left_forward(int speed){
    analogWrite(left_wheel_1, 0);
    analogWrite(left_wheel_2, speed/100*255);
    forward_left = true;
    //Serial.println("left forward");
  }

void right_backward(int speed){
  analogWrite(right_wheel_1, speed/100*255);
  analogWrite(right_wheel_2, 0);
  forward_right = false;
  //Serial.println("right backward");
  }
void left_backward(int speed){
  analogWrite(left_wheel_1, speed/100*255);
  analogWrite(left_wheel_2, 0);
  forward_left = false;
  //Serial.println("left backward");
  }

void turn_left(){
  right_forward(100);
  left_backward(100);
  }

void turn_right(){
    right_backward(100);
    left_forward(100);
  }

void move_forward(){
  right_forward(100);
  left_forward(100);
  }

void move_backward(){
  right_backward(100);
  left_backward(100);
  }
  
int left_tick = 0;
int right_tick = 0;

int right1 = digitalRead(0);
int right2 = digitalRead(1);
int left1 = digitalRead(2);
int left2 = digitalRead(3);

void encoderUpdate() {
  int newRight1 = digitalRead(0);
  int newRight2 = digitalRead(1);
  int newLeft1 = digitalRead(2);
  int newLeft2 = digitalRead(3);
  if (right1 != newRight1 || right2 != newRight2){
    right1 = newRight1;
    right2 = newRight2;
    right_tick += 1;
    Serial.print("RIGHT TICK " );
    Serial.println(right_tick, DEC); 
  }
  if (left1 != newLeft1 || left2 != newLeft2){
    left1 = newLeft1;
    left2 = newLeft2;
    left_tick += 1;
    Serial.print("LEFT  TICK ");
    Serial.println(left_tick, DEC); 
  }
}

float Kp = -1;
float Kd = -100;
float error = 0;
float preError = 0;
float pidOutput;
float deltaError;

void striaghtPID() {
  error = left_tick - right_tick;
  deltaError = error - preError;
  pidOutput = Kp * error + Kd *deltaError;
  right_forward(75 - 25 * pidOutput);
  left_forward(75 + 25 * pidOutput);
  preError = error;
}

void distancePID() {
  
}

void loop() {
  encoderUpdate();
  striaghtPID();
}


