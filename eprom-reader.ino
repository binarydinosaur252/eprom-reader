//Morris's 8bit (E(E(P)))ROM dumper, written in C++ with Arduino.h 

void setup(){
Serial.begin(115200); //creating a 115200 baud serial connection

while(!Serial){} //waiting for serial connection

  int pincounter = 22;
  //define pins 22 through 30 as input pins
  while(pincounter < 30){
    pinMode(pincounter,INPUT);
    pincounter++;
  }
  while(pincounter < 38){
    pinMode(pincounter, OUTPUT);
    pincounter++;
  }
}

void put_address()
{
  uint8_t i = 30;
  while(i < 38){
    bitRead(i, i-30);
    if(i == 1){
    digitalWrite(i, HIGH);
    }
    i++;
  }
}


void receive_byte(){ //receives 1 bit of data from each pin and creates a byte
  
  uint8_t incoming_byte;
  int i = 22;
  
while(i < 30){
  if(digitalRead(i) == HIGH){
    bitSet(incoming_byte, i-22);
    delay(50);
  }
i++;
}
Serial.print(incoming_byte,HEX);//prints incoming byte over serial
Serial.print(" ");
}


void loop() {
  put_address();
  receive_byte(); //currently trys to receive data forever
  delay(75);
}

