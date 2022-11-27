#include <Servo.h>
#define PI 3.1415926535897932384626433832795
#include <math.h>

Servo myservo;
double open = 142;
double close = 15;
double rangeDeg = (open - close);
double rangeRad = rangeDeg * PI / 180;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(2);
  myservo.write(open);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    String val = Serial.readString(); //move, grip, home,

    if(val.indexOf("grip") == 0)
      sendGrip(val.substring(4).toInt());
  }
}

int getGrip() {
  double trueTheta = myservo.read();
  double mappedTheta = (trueTheta - open) * (-1) * PI / 180.0;
  double gripOpen = 16.5 * cos(0) + 29.25 * cos(asin((16.5 * sin(0) / 29.25)));
  double gripClose = 16.5 * cos(rangeRad) + 29.25 * cos(asin((16.5 * sin(rangeRad) / 29.25)));
  double gripRaw = 16.5 * cos(mappedTheta) + 29.25 * cos(asin((16.5 * sin(mappedTheta) / 29.25)));
  int gripMapped = (int)map(gripRaw, gripOpen, gripClose, 0, 100);
  return gripMapped;
}

void sendGrip(int perGrip) {
  double mapped = mapp(perGrip, 0, 100, (16.5 * cos(rangeRad) + 29.25 * cos(asin((16.5 * sin(rangeRad) / 29.25)))), (16.5 * cos(0) + 29.25 * cos(asin((16.5 * sin(0) / 29.25)))));
  double thetaRaw = acos((pow(mapped, 2) + pow(16.5, 2) - pow(29.25, 2)) / (2 * mapped * 16.5));
  int theta = (thetaRaw * 180 / PI) + 15;
  myservo.write(theta);
}

double mapp(double start, double fromLow, double fromHigh, double toLow, double toHigh) {
  return ((start - fromLow)/(fromHigh - fromLow)) * (toHigh - toLow) + toLow;
}