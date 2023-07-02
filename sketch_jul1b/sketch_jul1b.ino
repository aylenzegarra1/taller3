/*
 PRUEBA INTENSIDAD
 */

// constants won't change
const int TRIG_PIN = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 3; // Arduino pin connected to LED's pin
const int DISTANCE_THRESHOLD = 50; // centimeters

//INTENSIDAD VARIABLES

// variables will change:
long duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode. LED control pin is 3, a PWM capable pin
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  //distance_cm = 0.017 * duration_us;
  distance_cm = duration_us * 0.034 / 2; // CHAT GPT
  //distance_cm = duration_us / 2 / 29.1; //FER'S VERSION

  if(distance_cm < DISTANCE_THRESHOLD){
    digitalWrite(LED_PIN, LOW); // turn on LED
  }else{
    digitalWrite(LED_PIN, HIGH);  // turn off LED
  }



// aca probamos INTENSIDAD

   // Mapea la distancia a un rango adecuado para el brillo del LED (0-255)
  int brightness = map(distance_cm, 5, 100, 0, 255);

  // Limita los valores del brillo dentro del rango 0-255
  brightness = constrain(brightness, 0, 255);

  // Establece el brillo del LED
  analogWrite(LED_PIN, brightness);



  
  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(300);
}
