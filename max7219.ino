const int clk = 7;
const int cs = 6;
const int din = 5;
void setup() {
  digitalWrite(cs, HIGH);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
output(0x0f, 0x00); //display test register - test mode off
  output(0x0c, 0x01); //shutdown register - normal operation
  output(0x0b, 0x07); //scan limit register - display digits 0 thru 7
  output(0x0a, 0x00); //intensity register - max brightness
  output(0x01, 0x01); //
  output(0x02, 0x02); //
  output(0x03, 0x04); // 
}
void output(byte address, byte data)
{
  digitalWrite(cs, LOW);
  shiftOut(din, clk, MSBFIRST, address);
  shiftOut(din, clk, MSBFIRST, data);
  digitalWrite(cs, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}