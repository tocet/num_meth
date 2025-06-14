#define BAUDRATE 115200
#define TriggerPin 31
#define EchoPin 33
#define MAX_RANGE 280

long distance;

void setup() {
 pinMode(TriggerPin,OUTPUT);
 pinMode(EchoPin,INPUT_PULLUP);
 Serial.begin(BAUDRATE);
}
void loop() {
  long avg = 0;

  for(int i=0; i<4; ) {
   distance = hcsr04_measurement(TriggerPin,EchoPin);
   if(distance < MAX_RANGE) { 
     i++;
     avg+=distance; }
   delay(100); 
  }
   Serial.print("Distance to the target: ");
   Serial.println(avg/4);
}

long hcsr04_measurement(int T_Pin, int E_Pin) {
 digitalWrite(T_Pin,LOW);
 delayMicroseconds(2);
 digitalWrite(T_Pin,HIGH);
 delayMicroseconds(10);
 digitalWrite(T_Pin,LOW);
 return pulseIn(E_Pin,HIGH)/58.2;
}
