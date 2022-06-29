#define ldr1 =6;
#define ldr2 =7;
#define ldr3 =8;

void setup() {
//LDR pins
  pinMode(ldr1,INPUT);
    pinMode(ldr2,INPUT); 
    pinMode(ldr3,INPUT);
//    LED pins
    pinMode(2,OUTPUT);
     pinMode(3,OUTPUT);
      pinMode(4,OUTPUT);
    

}

void loop() {
  int a =digitalRead(6);
    int b =digitalRead(7);
      int c =digitalRead(8);

     if (a == LOW){
      digitalWrite(2,HIGH);
     }
       if (b == LOW){
      digitalWrite(3,HIGH);
     }

    if (c == LOW){
      digitalWrite(4,HIGH);
     }
  
  
}
