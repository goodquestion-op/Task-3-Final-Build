#include <Keypad.h>

const int LED_green = 11;
const byte ROWS = 4; // four rows
const byte COLS = 4; //four columns  

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A'},
  { '4', '5', '6', 'B'},
  { '7','8','9','C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  Serial.begin(9600);
  pinMode(LED_green, OUTPUT);
}

void loop() {   
  char key = keypad.getKey();
  
  if(key){
    Serial.print(Data[data_count]);
    digitalWrite(LED_green,HIGH);
     Serial.print("key : ");
     Serial.println(key);   
    delay(100);
  }
 


  }
  digitalWrite(LED_green,LOW);
}