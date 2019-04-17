void berhenti()
{
  analogWrite(motor, 0);

}

void trace()
{
  baca_sensor();
  calibra();
  steer = map(kode, -6, 6, sudut_max, sudut_min);
  if (kode == -6)
  {
    while (1)
    {
      servosteer.write(sudut_max);
      analogWrite(motor, 50);
      baca_sensor();
      if (sensor == 0b111110 || sensor == 0b111100)
        break;
    }
  }
 
  servosteer.write(steer);
  analogWrite(motor, 70);
}

void baca_sensor() {
  if (analogRead(S0) < ns0) {
    sensor |= B00000001;
  }
  else {
    sensor &= B11111110;
  }
  if (analogRead(S1) < ns1) {
    sensor |= B00000010;
  }
  else {

    sensor &= B11111101;
  }
  if (analogRead(S2) < ns2) {

    sensor |= B00000100;
  }
  else {

    sensor &= B11111011;
  }
  if (analogRead(S3) < ns3) {

    sensor |= B00001000;
  }
  else {

    sensor &= B11110111;
  }
  if (analogRead(S4) < ns4) {

    sensor |= B00010000;
  }
  else {

    sensor &= B11101111;
  }
  if (analogRead(S5) < ns5) {

    sensor |= B00100000;
  }
  else {

    sensor &= B11011111;
  }
}

void calibra()
{
  switch (sensor)
  { 
    case 0b011111: kode = 5; break;
    case 0b001111: kode = 4; break;
    case 0b101111: kode = 3; break;
    case 0b100111: kode = 2; break;
    case 0b110111: kode = 1; break;
    case 0b110011: kode = 0; break;
    case 0b111011: kode = -1; break;
    case 0b111001: kode = -2; break;
    case 0b111101: kode = -3; break;
    case 0b111100: kode = -4; break;
    case 0b111110: kode = -5; break;
    case 0b111111:
      if    (kode < 0) {
        kode = -6;
      }
      else  {
        kode = 6;
      }
      break;
  }
}

