#include <DS3231.h>
#include <Servo.h>
 

Servo myservo;
DS3231  rtc(SDA, SCL);
Time t;

int pos = 0;
//coment out any section of the day which is not required.
const int OnHourM = 8;//set the time at wish the food has tobe dispensed in the morning(Hour and Minutes respecively.)
const int OnMinM = 15;

const int OnHourA = 13;//set the time at wish the food has tobe dispensed in the afternoon(Hour and Minutes respecively.)
const int OnMinA = 15;

const int OnHourN = 21;//set the time at wish the food has tobe dispensed in the night(Hour and Minutes respecively.)
 int OnMinN = 30;
boolean state = false;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  myservo.write(30);
  myservo.attach(8);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  delay (1000);

  if (t.hour == OnHourM && t.min == OnMinM && state == false) {
    servo();
    Serial.println("Morning");
    state = true;
    delay(60000);
    state = false;
  }

  if (t.hour == OnHourA && t.min == OnMinA && state == false) {
    servo();
        Serial.println("afternoon");
    state = true;
     delay(60000);
    state = false;
  }

  if (t.hour == OnHourN && t.min == OnMinN && state == false) {
    servo();
        Serial.println("night");
    state = true;
     delay(60000);
    state = false;
  }



}

void servo() {
  for (pos = 25; pos >= 0; pos -= 1) { // goes from 25 degrees to 0 degrees
    // in steps of 1 degree
    Serial.println("Servo on");
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 0; pos <= 25; pos += 1) { // goes from 0 degrees to 25 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);

  }
}
