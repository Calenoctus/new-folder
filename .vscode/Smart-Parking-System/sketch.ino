#include"HX711.h"

//sensors pins
#define LDR_PIN A0
#define DT_PIN 2
#define SCK_PIN 3

//LED pins
#define RED_LED 8
#define GREEN_LED 9

//create load cell object
HX711 scale;

//detection thresholds
int light_threshold =700;
float weightthreshold =1000;

//varaibles
int lightValue;
float weightValue;

void setup(){
  Serial.begin(9600);

  //set LED pins
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);

  //initialise load cell
  scale.begin(DT_PIN,SCK_PIN);

  //set initial scale factor
  scale.set_scale(1.0);

  //reset weight reading to zero
  scale.tare();

  Serial.println("System initialized");
  delay(1000);
}

void loop(){

  //Read light sensor
  lightValue=analogRead(LDR_PIN);

  //Read weight sensor
  weightValue=scale.get_value(5);

  //Display sensor readings
  Serial.print("Light Level:");
  Serial.println(lightValue);

  Serial.print("Weight Reading:");
  Serial.println(weightValue);

  //checK parking space status
  if(lightValue > light_threshold&&
     weightValue > weightthreshold){

      //Parking space occupied
      digitalWrite(RED_LED,HIGH);
      digitalWrite(GREEN_LED,LOW);

      Serial.println("STATUS:PARKING SPACE OCCUPIED");
     }else{
      //parking space vacant
      digitalWrite(RED_LED,LOW);
      digitalWrite(GREEN_LED,HIGH);

      Serial.println("STATUS:PARING SPACE VACANT");
     }

     Serial.println("-------------------");

     delay(1000);
 }
     
