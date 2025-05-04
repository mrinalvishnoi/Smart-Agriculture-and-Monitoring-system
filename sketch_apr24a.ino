#include <Servo.h>

Servo servo;  // Create a servo object

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;



void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT); // Set echo pin as input
  pinMode(buzzer, OUTPUT); // Set buzzer pin as output
  pinMode(ledPin, OUTPUT);// Set led pin as output
 
  servo.attach(8);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); // Ensure trigger pin is low
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // Send a 10 microsecond pulse to trigger pin
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Read the echo pin, calculate duration
  distance = (duration / 2) / 29.1; // Calculate distance based on speed of sound
  Serial.print("Distance: ");
  Serial.println(distance);
 
  
 
  
  if (distance < 20 && distance > 0) { // Adjust threshold according to your setup
    // If someone is close enough (within 50cm), trigger the buzzer
    digitalWrite(buzzer, HIGH); // Turn on the buzzer
    digitalWrite(ledPin, HIGH); // Turn on the buzzer
    servo.write(90);
    

  }
  else{
    digitalWrite(buzzer, LOW); // Turn off the buzzer
    digitalWrite(ledPin, LOW); // Turn on the buzzer
    servo.write(0);

  }
  
}