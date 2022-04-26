int redLed=13;
int blueLed=12;
int yellowLed=11;
int greenLed=10;
int sensorPin=7;
int switchPin=6;

int lightMode = 0; // will change LEDs blinking pattern. 
int count = 0; // will increase with every clap.
unsigned long previousMillis = 0;    // will store last time LED was updated. Unsigned means no negative values.
long interval; //LEDs blinking speed.

void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin (9600);
}
  
void loop (){

  if(digitalRead(switchPin) == LOW){   //switch to Clapping mode.

    boolean clap = digitalRead(sensorPin);
    interval = analogRead(A0); //Interval depends on the potenciometer position.
  
    if(clap == true){
        count++; //every clap will increase count changing the LEDs pattern
        lightMode = 0;
        delay(200);   
    }  

    if(count == 1){
        digitalWrite(redLed, HIGH);
        digitalWrite(blueLed, HIGH);
        digitalWrite(yellowLed, HIGH);
        digitalWrite(greenLed, HIGH);
      
    }else if(count == 2){ 
      // check to see if it's time to blink the LED; that is, if the difference
      // between the current time and last time you blinked the LED is bigger than
      // the interval at which you want to blink the LED.
        unsigned long currentMillis = millis();
         
        if(currentMillis - previousMillis >= interval){
        
         previousMillis = currentMillis; // save the last time you blinked the LED

          switch(lightMode){
            case 0:
              digitalWrite(redLed, LOW);
              digitalWrite(blueLed, HIGH);
              digitalWrite(yellowLed, LOW);
              digitalWrite(greenLed, HIGH);
              lightMode = 1;  //Change light blinking mode for next loop.
            break;
            case 1:
              digitalWrite(redLed, HIGH);
              digitalWrite(blueLed, LOW);
              digitalWrite(yellowLed, HIGH);
              digitalWrite(greenLed, LOW);
              lightMode = 0;
            break;
          }
        }
    }else if(count == 3){     

        unsigned long currentMillis = millis();
         
        if(currentMillis - previousMillis >= interval){
        
          previousMillis = currentMillis;

          switch(lightMode){
            case 0:
              digitalWrite(redLed, HIGH);
              digitalWrite(blueLed, LOW);
              digitalWrite(yellowLed, LOW);
              digitalWrite(greenLed, LOW);
            break;
            case 1:  
              digitalWrite(redLed, LOW);
              digitalWrite(blueLed, HIGH);
              digitalWrite(yellowLed, LOW);
              digitalWrite(greenLed, LOW);
            break;
            case 2:
              digitalWrite(redLed, LOW);
              digitalWrite(blueLed, LOW);
              digitalWrite(yellowLed, HIGH);
              digitalWrite(greenLed, LOW);
            break;
            case 3:
              digitalWrite(redLed, LOW);
              digitalWrite(blueLed, LOW);
              digitalWrite(yellowLed, LOW);
              digitalWrite(greenLed, HIGH);
              lightMode = -1;
            break;           
         }    
         lightMode++; //Change light blinking mode for next loop.
       }     
   }else if(count == 4){
        digitalWrite(redLed, LOW);
        digitalWrite(blueLed, LOW);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, LOW);
       
        count = 0; // the fourth clap resets count value to 0. 
    }
    
  }else{  //Switch to Music mode.
      boolean clap = digitalRead(sensorPin);
      if(clap == true){
        digitalWrite(redLed, HIGH);
        digitalWrite(blueLed, HIGH);
        digitalWrite(yellowLed, HIGH);
        digitalWrite(greenLed, HIGH); 
      }else{
        digitalWrite(redLed, LOW);
        digitalWrite(blueLed, LOW);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, LOW);
      }
    } 
}
