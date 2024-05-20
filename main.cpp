#include <Arduino.h> // Library untuk mengontrol Arduino
#include <Servo.h> // Library untuk mengontrol servo

// Definisikan pin untuk LED dan servo
const int redLEDPin = 10;
const int greenLEDPin = 11;
const int servoPin = 9;

// Buat objek servo
Servo myServo;

// Variabel untuk melacak status LED
bool isRedLEDOn = true;
unsigned long previousMillis = 0; // Untuk melacak waktu

// Interval waktu untuk mengganti LED (5 detik = 5000 milidetik)
const long interval = 5000;

void setup() {
  // Set pin LED sebagai output
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  
  // Mulai dengan menyalakan LED merah
  digitalWrite(redLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);
  
  // Attach servo ke pin yang telah ditentukan
  myServo.attach(servoPin);
  
  // Set posisi awal servo ke 0 derajat
  myServo.write(0);
}

void loop() {
  // Dapatkan waktu sekarang
  unsigned long currentMillis = millis();
  
  // Cek apakah interval waktu telah berlalu
  if (currentMillis - previousMillis >= interval) {
    // Simpan waktu sekarang
    previousMillis = currentMillis;
    
    // Ganti status LED
    if (isRedLEDOn) {
      // Matikan LED merah, nyalakan LED hijau
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);
      
      // Gerakkan servo ke posisi 90 derajat
      myServo.write(90);
    } else {
      // Nyalakan LED merah, matikan LED hijau
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(greenLEDPin, LOW);
      
      // Gerakkan servo kembali ke posisi 0 derajat
      myServo.write(0);
    }
    
    // Balik status LED
    isRedLEDOn = !isRedLEDOn;
  }
}
