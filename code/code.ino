#define IR_Left 7
#define IR_Middle 6
#define IR_Right 5
//define motorRight
#define IN1 4 //forward
#define IN2 5
#define ENA 3
//define motorLeft
#define IN3 10 //forward
#define IN4 9
#define ENB 11

byte leftRead , middleRead , rightRead;

void forward(int Speed);
void right(int Speed);
void left(int Speed);
void Stop();

void setup() {
  pinMode(IR_Left,INPUT);
  pinMode(IR_Middle,INPUT);
  pinMode(IR_Right,INPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  forward(150);
}

void loop() {
 leftRead = digitalRead(IR_Left);
 middleRead = digitalRead(IR_Middle);
 rightRead = digitalRead(IR_Right); 
 if(leftRead == 1 && rightRead == 1 && middleRead == 0){
    forward(150);
   }
 else if(leftRead == 1 && rightRead == 0 && middleRead == 0){
   right(150);
   }
 else if(leftRead == 0 && rightRead == 1 && middleRead == 0){
   left(150);
   }
 else if(leftRead == 0 && rightRead == 0 && middleRead == 0){
   forward(150);
   }
 else{
   Stop();
  }
}

void forward(int Speed){
    analogWrite(ENA , Speed/2);
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , LOW);
    
    analogWrite(ENB , Speed);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
  }
  void right(int Speed) {
    analogWrite(ENA , Speed/2);
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , LOW);
    
    analogWrite(ENB , Speed);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
  }
  void left(int Speed) {
    analogWrite(ENA , Speed);
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , LOW);
    
    analogWrite(ENB , Speed/2);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
    }
    void Stop()
{
    analogWrite(ENA , 0);
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , LOW);
    
    analogWrite(ENB , 0);
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , LOW);
}
