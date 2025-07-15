speed detector coreect code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define IR sensor pins
const int irSensor1 = 2;  // First IR sensor
const int irSensor2 = 3;  // Second IR sensor

// Constants
const float distance_m = 0.2;  // 20 cm = 0.2 meters

// Variables to store time
unsigned long startTime = 0;
unsigned long endTime = 0;

bool timingActive = false;
int startSensor = 0; // 1 for IR1 start, 2 for IR2 start

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);

  lcd.init();
  lcd.backlight();

  // Show welcome message once
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Speed Detector");
  delay(2000);      // Display for 2 seconds
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Waiting...      ");

  int ir1State = digitalRead(irSensor1);
  int ir2State = digitalRead(irSensor2);

  // Assuming LOW means sensor triggered (object present)
  if (!timingActive) {
    if (ir1State == LOW) {
      startTime = millis();
      timingActive = true;
      startSensor = 1;
      Serial.println("Timing started at IR1");
      delay(50);  // small debounce
    } else if (ir2State == LOW) {
      startTime = millis();
      timingActive = true;
      startSensor = 2;
      Serial.println("Timing started at IR2");
      delay(50);
    }
  } else {
    // Wait for the object to trigger the opposite sensor
    if (startSensor == 1 && ir2State == LOW) {
      endTime = millis();
      float timeSeconds = (endTime - startTime) / 1000.0;
      float speed_mps = distance_m / timeSeconds;
      float speed_kmph = speed_mps * 3.6;

      Serial.print("Speed from IR1 to IR2: ");
      Serial.print(speed_kmph);
      Serial.println(" km/h");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Speed IR1->IR2:");
      lcd.setCursor(0, 1);
      lcd.print(speed_kmph, 2);
      lcd.print(" km/h");

      timingActive = false;
      delay(3000);
      lcd.clear();
    } 
    else if (startSensor == 2 && ir1State == LOW) {
      endTime = millis();
      float timeSeconds = (endTime - startTime) / 1000.0;
      float speed_mps = distance_m / timeSeconds;
      float speed_kmph = speed_mps * 3.6;

      Serial.print("Speed from IR2 to IR1: ");
      Serial.print(speed_kmph);
      Serial.println(" km/h");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Speed IR2->IR1:");
      lcd.setCursor(0, 1);
      lcd.print(speed_kmph, 2);
      lcd.print(" km/h");

      timingActive = false;
      delay(3000);
      lcd.clear();
    }
  }
}

