int sensorValue = 0;

#define SENSOR A0 //voice sensor
#define LED 6 //light bulb or led
#define THRESHOLD 200 //sensor value thershold, to detect a calp

void setup() {
pinMode(LED, OUTPUT);
pinMode(SENSOR, INPUT);
Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(SENSOR); //Read Sensor Value
  
  if (sensorValue < THRESHOLD){ //If sensor value below the threshold, we detect a clap
    delay(300); //wait 300ms for the second clap
    long start = millis();
    while(millis()-start < 100){ //listen for the second clap
      sensorValue = analogRead(SENSOR);
      if(sensorValue < THRESHOLD){ 
        switchLed(LED); //if we detect a calp, switch on/off the led or light bulb
        break;
      }
    }
  }
}

void switchLed(const int pin){
  if(digitalRead(pin) == HIGH) digitalWrite(pin, LOW);
  else digitalWrite(pin, HIGH);
}