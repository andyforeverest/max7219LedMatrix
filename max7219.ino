const uint8_t clk = 7;
const uint8_t cs = 6;
const uint8_t din = 5;

uint8_t caracter1[8] = {0b00111100, 0b00001000, 0b00011000, 0b00000100, 0b00001000, 0b00001000, 0b00001000, 0b00001000};
void setup() {
  digitalWrite(cs, HIGH);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  initializare();
}
void output(byte address, byte data)
{
  digitalWrite(cs, LOW);
  shiftOut(din, clk, MSBFIRST, address);
  shiftOut(din, clk, MSBFIRST, data);
  digitalWrite(cs, HIGH);
}

void initializare(){
  output(0x0f, 0x00); //display test register - test mode off
  output(0x0c, 0x01); //shutdown register - normal operation
  output(0x0b, 0x07); //scan limit register - control all columns
  output(0x0a, 0x00); //intensity register - min brightness = 0x00, max = 0x0f
  output(0x09, 0x00); //no decoding
}

void writeLed(uint8_t row, uint8_t col){
  for(uint8_t i = 1; i<9; i++){
    if(i == row){
      output(i, col);
    }//i == row
    else{
      output(i, 0x00);
    }//else
  }
}
  
void loop() {
  uint8_t row = random(1, 9);
  uint8_t col = random(0, 8);
    output(row, 0x01<<col);
    delay(100);
    output(row, (0x01<<col)&(~(0x01<<col)));
}
