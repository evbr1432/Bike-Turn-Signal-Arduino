
//Pins that the Led's and Buttons are connected too
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 =  6;      // the number of the LED pin

//Variables
int light_hold = 0;          //counter for keeping the light on (for loops etc...)
int buttonState = 0;         // variable for reading the pushbutton status
int count = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

//Main loop
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  //LOW == Pressed 
  if (buttonState == LOW) {
    //if pressed, add one to count and wait 400 miliseconds
    count++;
    delay(400);
  }

  
  if (buttonState == LOW) {
    if (count >= 2) {
      //if button pressed 
      for (light_hold = 0; light_hold < 10; light_hold++){
        digitalWrite(ledPin1, HIGH);
        delay (500);
        digitalWrite(ledPin1, LOW);
        delay (500);
        count = 0;
      }
      Serial.println("count loop 1:");
      Serial.println(count);
    }    
    else{
      for (light_hold = 0; light_hold < 10; light_hold++){
        digitalWrite(ledPin2, HIGH);
        delay (500);
        digitalWrite(ledPin2, LOW);
        delay (500);
      }
      Serial.println("count loop 2:");
      Serial.println(count);
    }
  }
  
  else{
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  
}


