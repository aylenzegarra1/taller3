//NUEVO PERO DE CHAT GPT SOLO

#define TRIGGER_PIN 6   // Pin del sensor de ultrasonido conectado al pin TRIGGER
#define ECHO_PIN 7      // Pin del sensor de ultrasonido conectado al pin ECHO
#define LED_PIN 3       // Pin del LED conectado al pin 3

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  long duration, distance;
  
  // Envía un pulso de 10μs al sensor de ultrasonido
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Lee el tiempo que tarda el eco en regresar
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calcula la distancia en centímetros
  distance = duration * 0.034 / 2;
  
  // Mapea la distancia a un rango adecuado para el brillo del LED (0-255)
  int brightness = map(distance, 5, 100, 0, 255); // Intercambiamos los valores máximo y mínimo
  
  // Limita los valores del brillo dentro del rango 0-255
  brightness = constrain(brightness, 0, 255);
  
  // Establece el brillo del LED
  analogWrite(LED_PIN, brightness);
  
  delay(100); // Pequeño retraso para estabilizar las lecturas del sensor
}
