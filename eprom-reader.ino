//Morris's 8bit (E(E(P)))ROM dumper, written in C++ with Arduino.h 

void setup(){
Serial.begin(115200); //creating a 115200 baud serial connection

while(!Serial){} //waiting for serial connection

  int pincounter = 22;
  //define pins 22 through 30 as input pins
  while(pincounter <= 30){
    pinMode(pincounter,INPUT);
    pincounter++;
  }
  while(pincounter <= 38){
    pinMode(pincounter, OUTPUT);
    pincounter++;
  }
}

void put_address(uint8_t j)
{
  digitalWrite(30, HIGH && (j & B10000000));
  digitalWrite(31, HIGH && (j & B01000000));
  digitalWrite(32, HIGH && (j & B00100000));
  digitalWrite(33, HIGH && (j & B00010000));
  digitalWrite(34, HIGH && (j & B00001000));
  digitalWrite(35, HIGH && (j & B00000100));
  digitalWrite(36, HIGH && (j & B00000010));
  digitalWrite(37, HIGH && (j & B00000001));
}


void receive_byte(){ //receives 1 bit of data from each pin and creates a byte
  
  uint8_t incoming_byte;
  int i = 22;
  
while(i < 11){
  if(digitalRead(i) == HIGH){
    bitSet(incoming_byte, i-22);
    delay(50);
  }
i++;
}
Serial.println(incoming_byte,HEX);//prints incoming byte over serial
}


void loop() {
  int addr = 0x00;
  put_address(addr);
  receive_byte(); //currently trys to receive data forever
  delay(50);
  addr++;
}

