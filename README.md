# 아두이노를 이용하여 초음파 거리 센서를 활용한 주차장 만차 시 우회 알림 로봇
- 주차장에 만차로 인해서 주차가 불가능하여 우회하는 것을 알리기 위해 로봇이 90도로 몸을 회전  


## 🔸 설계 구성요소
- 목표설정 : 주차장에 만차로 인해서 주차가 불가능하여 우회하는 것을 알리기 위해 로봇이 90도로 몸을 회전하는 것 
- 제작 : 대표적으로 아두이노, 브레드 보드, 초음파 거리센서,  LCD(16X2), 서보모터를 사용하여 Tinkercad로 구현
- 시험 : 전방에 탐지되는 차량이 1.5M(150CM) 이내로 들어왔을 때, 알림 로봇이 90도로 몸을 회전하여 우회를 알리는 것
- 결과 도출 : 미리 LCD판으로 ‘Parking Full’이라는 문구로 만차 상황을 알리고, 차량이 일정 거리(1.5M) 내에 진입했을 때, 몸을 90도로 회전하여 우회를 알림
<br>

 ## 🔶 설계 제한적 / 기능적 요구조건
 - 환경 : Tinkercad 소스코드로 초음파 거리탐지 센서와 서보모터의 상호작용을 구현해내기가 어려워서 코드를 문자가 아닌 블록으로 알고리즘을 만든 뒤 만들어진 코드와 LCD 소스코드와 합침
 - 윤리 : 유사제품을 참고하되 기존 제품에 차별성을 두어 만들고, 작품 제작으로 얻은 데이터의 유출을 방지
 - 안전 : Tinkcercad로 가상의 시뮬레이션으로 로봇의 동작을 확인하고, 실험해볼 수 있기에 안전하게 설계 가능
 - 생산성 : 하드웨어적으로 부품들을 주문해 제작하는 것이 아니기 때문에 비용을 들지 않고, Tinkercad로 설계
 - 실효성 : LCD 판과 로봇의 움직임으로 상황을 알려 불필요한 인적배치와 인건비를 절감하는 효과
<br>

 ## 🔶 전체 아두이노 연결도
 ![전체 아두이노 연결도](https://user-images.githubusercontent.com/79084294/147312161-eabe7702-afdc-458a-8558-c09ba386f3af.png)
 
 <br>
 
  ## 🔶 1.5m 밖에 차량이 있을 시
![1 5m 밖에 차량이 있을때](https://user-images.githubusercontent.com/79084294/147312471-ceb0d1b8-86d7-41cf-ab33-c6af501da223.png)
 
 <br>
 
  ## 🔶 1.5m 안으로 차량이 진입 시
![1 5m 안으로 차량이 진입할 때](https://user-images.githubusercontent.com/79084294/147312502-920f859d-0327-4ef1-8f83-d0286cbd340b.png)
 
 <br>
 
  ## 🔶 문제점 / 해결과정
  - 문제점
    - LCD 판에 문구를 지속적으로 띄우고, 초음파 센서로부터 탐지되는 거리에 따라 서보모터가 작동하고, 회전하는 각도를 설정하는데 어려움 발생
    - 초음파 거리 센서를 활용해 물체를 탐지하는 것을 소스 코드로 구현해내기가 어려웠음

  - 해결과정
    - 아두이노 Tinkercad '초음파 센서 피에조 부저' 활용 예제를 참조하여 블록코딩을 학습하고, 서보모터의 알고리즘을 블록으로 만든 뒤 코드로 형성
    - 초음파 거리센서를 활용하여 물체가 탐지되는 것을 정상적으로 잘 작동할 때까지 시뮬레이션을 반복
