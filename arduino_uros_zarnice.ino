int b1 = 2;
int b2 = 3;
int b3 = 4;
int b4 = 11;

int LED_1 = 6;
int LED_2 = 7;

int b1_stanje = 0;
int b2_stanje = 0;
int b3_stanje = 0;
int b4_stanje = 0;

const char Buttons [50];

void setup() {
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);

  Serial.begin(9600);





}

void loop() {
  // put your main code here, to run repeatedly:
  b1_stanje = digitalRead(b1);
  b2_stanje = digitalRead(b2);
  b3_stanje = digitalRead(b3);
  b4_stanje = digitalRead(b4);
 


  if (b1_stanje == HIGH && digitalRead(LED_2) == LOW){
    digitalWrite(LED_1, HIGH);
  }
  if (b2_stanje == HIGH && digitalRead(LED_1) == LOW){
    digitalWrite(LED_2, HIGH);
  }
  if (b3_stanje == HIGH){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
  }
  if (b4_stanje == HIGH){
    if (digitalRead(LED_2) == HIGH  && digitalRead(LED_1) == HIGH){
      if (b3_stanje == HIGH){
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_1, LOW);
        delay(100);
      }
    }
    else if(digitalRead(LED_2) == HIGH  ||  digitalRead(LED_1) == LOW){
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_1, HIGH);
      delay(250);
    }
    else if (digitalRead(LED_1) == HIGH || digitalRead(LED_2) == LOW){
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_1, LOW);
      delay(250);
    }
  }


}

