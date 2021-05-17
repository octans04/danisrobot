
int enA = 5;
int in1 = 7;
int in2 = 8;
int enB = 11;
int in3 = 9;
int in4 = 10;

int ir1 = 3;
int ir2 = 2;

int grados;

bool estadoir2;
bool estadoir1;

void setup() {
   Serial.begin(9600);
  // Declaraciones de los pines
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  //pinMode(ir3, INPUT);
  //pinMode(ir4, INPUT); 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  estadoir1 = digitalRead(ir1);
  estadoir2 = digitalRead(ir2);
 
 
}

void loop() {
  
  //potencia de los motores
  analogWrite(enA, 200);
  analogWrite(enB, 200);

  Serial.println(digitalRead(ir1));
  Serial.println(digitalRead(ir2));
  
  if(digitalRead(ir1)==0 && digitalRead(ir2)==1){
    analogWrite(enA,250);
    analogWrite(enB,180);
    m1avanza();
    m2para();
  }
  if(digitalRead(ir1)==1 && digitalRead(ir2)==0){
    analogWrite(enB,250);
    analogWrite(enA,180);
    m1para();
    m2avanza();
}
  if(digitalRead(ir1)==1 && digitalRead(ir2)==1){
    analogWrite(enB,250);
    analogWrite(enA,250);
    m1avanza();
    m2avanza();
}
}

void m1avanza() {
  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  }

void m2avanza() {
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  }

void m1para() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }

void m2para() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  }
