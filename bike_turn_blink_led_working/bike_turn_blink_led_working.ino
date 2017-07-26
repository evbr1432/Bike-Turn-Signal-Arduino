//Evan Brookens
//Arduino bike turn signal project
//7/25/2017

//Hardware location on board:
const int buttonPin = 2;     //Number of the pushbutton pin on the board
const int ledPin1 =  13;     //Pin on the board of LED1
const int ledPin2 =  6;      //Pin on the board of LED2

//Flash variables to custimize flash:
int flash_count = 10;         //Number of times light flashes
int flash_speed = 500;        //Milliseconds inbetween flashes

//General Use Global Variables
int buttonState = 0;         //Variable for reading the pushbutton status
int button_hold_time = 0;    //Arbitrrary counter for length of time the button is held down
int x = 0;                   //x value for flashing for loops (could be const)


//Setup Values:
void setup() {
  //Initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  //Initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  //Required for printing to serial monitor
  Serial.begin(9600);
}

void loop() {
  //Read the state of the button value:
  //Check if the pushbutton is pressed.
  //LOW == Pressed 
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    //Call hold_time to check the amount of time the button was pressed
    hold_time();
    if (button_hold_time >= 2) {
      //If button pressed and button_hold_time(arbitrary) added up to at least 2 (about 600 miliseconds).
      for (x = 0; x < flash_count; x++) {
        //Flash led pin 1 every ~flash_speed Miliseconds
        digitalWrite(ledPin1, HIGH);
        delay (flash_speed);
        digitalWrite(ledPin1, LOW);
        delay (flash_speed);     
      }
    }  
    else {
      for (x = 0; x < flash_count; x++) {
        //Flash led pin 2 every ~flash_speed Miliseconds
        digitalWrite(ledPin2, HIGH);
        delay (flash_speed);
        digitalWrite(ledPin2, LOW);
        delay (flash_speed);
      }
    }
    //Reset count
    button_hold_time = 0;
  }

  //If button is not pressed, turn off both LED's
  else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  
}

//Caluculates amount of time the button was pressed
//Every iteration of while loop is ~300 miliseconds of button hold time

int hold_time() {
  while (buttonState == LOW) {
    button_hold_time++;
    delay(300);
    //INFO for serial monitor to test correct return values.
    Serial.print("Hold_time while counter: ");
    Serial.print(button_hold_time);
    Serial.print("\n");
    //Read state so it can leave
    buttonState = digitalRead(buttonPin);
    }
  //Return time the button was held while in this function
  return button_hold_time;
}


