#include <LiquidCrystal.h>
#include <Servo.h>
#include <Wire.h>

int time=0;
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_11;

//회로에 연결된 핀 번호를 사용하여 lcd 객체 인스턴스 생성
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  servo_11.attach(11);
  
  //LCD의 행과 열을 16행 2열로 설정
  lcd.begin(16, 2);
  //LCD에 문자열 출력
  lcd.print("Parking Full");
  Wire.begin(1); //슬레이브 주소                
  Wire.onRequest(requestEvent); //요청시 requestEvent함수 호출
  Wire.onReceive(receiveEvent); //데이터 전송 받을 때 receiveEvent함수 호출

  Serial.begin(9600);  
}

void loop()
{
   distance = 0.01723 * readUltrasonicDistance(9, 9);
  if (distance < 150) {
    servo_11.write(90);
  } else {
    servo_11.write(0);
  }
  delay(10); // Delay a little bit to improve simulation performance
  
  //커서를 2열 1행으로 이동
  lcd.setCursor(0, 1);
  //1초간 대기
  delay(1000);
}

void receiveEvent(int howMany) { //전송 데이터 읽기
  while (Wire.available()>1) { 
    char ch = Wire.read(); 
    Serial.print(ch);         
  }
  int x = Wire.read();    
  Serial.println(x);      
}
void requestEvent() { //요청 시 수행 함수
  Wire.write("ok!\n");   
}