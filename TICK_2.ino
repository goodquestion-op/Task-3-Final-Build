unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
unsigned long previousTick = 0;     // stores previous time we triggered the function for Tick
unsigned long previousHeart = 0;     // stores previous time we triggered the function for Heart
unsigned long previousLED = 0;  // stores previous time we triggered the function for the LED
            

int HeartInterval = 60;  // stores the interval between triggering the Heart
int TickInterval = 1000;        // stores the interval between triggering the Tick
int LEDInterval = 60;


const int tick = 4000;


int rawTick;
int rawHeart;
int mapTick;
int mapHeart;
int average;


const int HALL_PIN = A0;
const int TICK_PIN = 11;
const int LED = 13;
const int HEART_PIN = A1;

const int delayMsec = 60;

void setup() {
  pinMode(TICK_PIN,OUTPUT);
  for(int i = 0;i < 5; i++){
    tone(TICK_PIN,tick,5);
    delay(1000);
  }
  pinMode(A0,INPUT);

  Serial.begin(9600);


  pinMode(LED,OUTPUT);
  Serial.print(9600);
}


void loop() {
  
  Heart();
  Tick();
  Average(mapTick);
  currentMillis = millis();
  If_state();
  




}
void Heart() {
  static int beatMsec = 0;
  int heartRateBPM = 0;
  rawHeart = analogRead(HEART_PIN);
  //Serial.println(rawHeart);
  mapHeart = map(rawHeart,0,1023,0,150);
  //Serial.println(mapHeart);
}
void Tick(){
     rawTick = analogRead(HALL_PIN);
    mapTick = map(rawTick, 0, 1023, 0, 700);
    //Serial.println(mapTick*1.5);  
   // TickInterval = mapTick*1.5;
}
void Average(float maped){
  average = 0;  
 for (int i=0; i < 10; i++) {
 average = average + maped*1.5;
 }
 average = average/10;
 Serial.println(average);
 TickInterval = average;
}
void If_state(){
  
    if (currentMillis - previousTick >= TickInterval){
      tone(TICK_PIN,tick,5);
      digitalWrite(LED,HIGH);
      previousTick = currentMillis; 
      if (currentMillis - previousLED >= LEDInterval){
        digitalWrite(LED,LOW);
        previousLED = currentMillis;
    }    
   }  
    
    if (currentMillis - previousLED >= LEDInterval){
    digitalWrite(LED,LOW);
    previousLED = currentMillis;
    }

}

