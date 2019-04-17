#include <Servo.h>

#define S0 A0
#define S1 A1
#define S2 A2
#define S3 A3
#define S4 A4
#define S5 A5
//int ns0=40,ns1=40,ns2=40,ns3=40,ns4=40,ns5=40;// truk 1
int ns0 = 40, ns1 = 40, ns2 = 40, ns3 = 70, ns4 = 70, ns5 = 70; // truk 1
//int ns0=50,ns1=40,ns2=40,ns3=40,ns4=40,ns5=50;// truk 2
//int ns0=40,ns1=40,ns2=40,ns3=40,ns4=40,ns5=40; //--> 180-0// truk 3
//int ns0=140,ns1=45,ns2=45,ns3=45,ns4=45,ns5=45; //--> 180-0// truk 4

byte sensor = 0;
int kode;
int steer;
int rr;
int motor = 3;

int sudut_max = 179;
int sudut_min = 0;

Servo servosteer;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servosteer.attach(6);
  pinMode(motor, 1);
  
  for (rr = 0; rr <= 2; rr++)
  {
    baca_sensor();
    calibra();
    while (sensor != 0b000000)
    {
      baca_sensor();
      calibra();
      trace();
    }
    berhenti();
    delay(5000);
  }
  berhenti();
  delay(5000);
}

void loop() {
  //for(rr=0;rr<=5;rr++){Serial.print(analogRead(rr));Serial.write('\t');}Serial.write('\n');
  // baca_sensor();
  //Serial.println(sensor,BIN);
  //steer=map(kode,-6,6,180,0);
  //servosteer.write(steer);
  /*
  if(kode==-6)
  {
    while(1)
    {
      servosteer.write(180);
      analogWrite(motor,125);
      baca_sensor();
      if(sensor==0b111110 || sensor==0b111100)
      break;
      }
    }

  Serial.print(kode);Serial.write('\t');
  Serial.print(steer);Serial.write('\n');

  analogWrite(motor,125);

  */
}


