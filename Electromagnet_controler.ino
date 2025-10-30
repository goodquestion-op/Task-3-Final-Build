const int relay = 13;
const int therm = A0;
int read;
int average;
int tester;


void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  pinMode(therm, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  read = analogRead(therm);
  Serial.println(tester);
  Average();
  if (tester > 370){
  digitalWrite(relay, HIGH);
  }else{
    digitalWrite(relay, LOW); 
  }


}

void Average(){
  average = 0;  
 for (int i=0; i < 10; i++) {
 average = average + read;
 }
 average = average/10;
 Serial.println(average);
 tester = average;
}