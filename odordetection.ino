#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ----- I2C LCD -----
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ----- Pin Definitions -----
#define trig1 5      // Ultrasonic 1 (object detection)
#define echo1 6
#define trig2 7      // Ultrasonic 2 (trash level)
#define echo2 8
#define servoPin 9   // Servo motor
#define gasSensor A1 // MQ135 Gas Sensor Analog Output

Servo servo;

long distance1, distance2;
int gasValue;

// Function to measure distance
long measureDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;
  return distance;
}

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Smart Dustbin");
  delay(1500);
  lcd.clear();

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  servo.attach(servoPin);
  servo.write(0);
  delay(500);
  servo.detach();
}

void loop()
{
  distance1 = measureDistance(trig1, echo1);  // Object detection
  distance2 = measureDistance(trig2, echo2);  // Trash level
  gasValue = analogRead(gasSensor);           // Gas level reading (0–1023)

  Serial.print("Object: ");
  Serial.println(distance1);
  Serial.print("Trash: ");
  Serial.println(distance2);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  lcd.clear();

  // ----- Gas / Odor Detection -----
  if (gasValue > 200)   // change sensitivity (300–500)
  {
    lcd.setCursor(0,0);
    lcd.print("Odor Detected!");
    lcd.setCursor(0,1);
    lcd.print("Clean Dustbin");
    delay(2000);
    return;
  }

  // ----- Check if bin is full -----
  if (distance2 <= 5)
  {
    lcd.setCursor(0,0);
    lcd.print("The bin is full");
    lcd.setCursor(0,1);
    lcd.print("Please empty it");
    delay(2000);
    return;
  }

  // ----- Object Detection for Lid Opening -----
  if (distance1 <= 10)
  {
    lcd.setCursor(0,0);
    lcd.print("Opening lid...");

    servo.attach(servoPin);
    servo.write(90);
    delay(4000);
    servo.write(0);
    delay(1000);
    servo.detach();

    lcd.clear();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Waiting...");
  }

  delay(300);
}
