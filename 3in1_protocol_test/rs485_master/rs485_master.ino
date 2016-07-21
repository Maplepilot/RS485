
#define RS485Transmit    HIGH
#define RS485Receive     LOW 
#define SLAVE   8 //up to 8 slaves
#define LOOPTIME 1

void setup() {

  pinMode(8, OUTPUT);
  digitalWrite(8, RS485Receive); //DE,RE=LOW, RX enabled

  Serial.begin(115200);     // Console 
  Serial1.begin(1000000);  // TO MAX485
  Serial2.begin(1000000);  // TO Logic
}

int recv;
int i;
unsigned long lastMilli = 0;                    // loop timing 

void loop() 
{
  if((millis()-lastMilli) >= LOOPTIME)  
  {                                    // enter tmed loop
    lastMilli = millis();
    for (int slave_id = 1; slave_id <= SLAVE; slave_id++)
    {
      Serial.print("ID"); Serial.print(slave_id, HEX); 
      Serial.print(" Sent: "); Serial.print(i, HEX);
      sendCmd(i, slave_id);
      recv = read_slave(slave_id);
      Serial.print("  ID"); Serial.print(slave_id,HEX); 
      Serial.print(" Got: ");  Serial.println(recv, HEX);
    }
    Serial.println();
    i++;
    if (i>100) i = 0;
  }

}

int read_slave(int slave)
{
  if (Serial1.available() >= 4) 
  {
    char rT = (char)Serial1.read(); //read target speed from mega
          if(rT == '{') //start byte
          {
              char commandArray[3];
              Serial1.readBytes(commandArray,3);
              byte rA=commandArray[0]; //device address
              byte rH=commandArray[1]; //high byte
              char rP=commandArray[2]; //stop byte
              if(rP=='}' && rA==slave)         
              {             
                  return rH;
              } 
          }
  }
  else  return 0;
}

void sendCmd(int cmd,int slave)
{
  digitalWrite(8, RS485Transmit); //DE,RE=HIGH, TX enabled
  char sT='{';  //send start byte
  byte sA = slave;
  byte sH = lowByte(cmd);
  char sP='}';  //send stop byte
  Serial1.write(sT); Serial1.write(sA); Serial1.write(sH); Serial1.write(sP);
  delayMicroseconds(10);
  digitalWrite(8, RS485Receive); //DE,RE=LOW, RX enabled
  delayMicroseconds(100);
  //delay(1);  // delay 1ms
}

