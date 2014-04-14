int SER_Pin = 3;   //pin 14 on the 75HC595
int RCLK_Pin = 1;  //pin 12 on the 75HC595
int SRCLK_Pin = 4; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 2 


//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

#define delayTime 100

boolean registers[numOfRegisterPins];

void setup(){
  analogReference(INTERNAL);
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  //reset all register pins
  clearRegisters();
  writeRegisters();
  
  standby(1);
  standby(1);
  standby(1);
  dispNumber(getTemp());
}  


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;  
   }
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}



void set0(int reg){
  //HIGH, LOW
  setRegisterPin(0 + reg*8, LOW);
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(3 + reg*8, LOW);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(7 + reg*8, HIGH);
  
  writeRegisters();
}

void set1(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, HIGH);
  setRegisterPin(3 + reg*8, HIGH);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, HIGH);
  setRegisterPin(6 + reg*8, HIGH);
  setRegisterPin(7 + reg*8, HIGH);
  
  writeRegisters();
}
void set2(int reg){
  //HIGH, LOW
  
  setRegisterPin(1 + reg*8, HIGH);
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(3 + reg*8, LOW);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, HIGH);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}
void set3(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(3 + reg*8, HIGH);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, HIGH);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}
void set4(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, HIGH);
  setRegisterPin(3 + reg*8, HIGH);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, HIGH);
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}
void set5(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(3 + reg*8, HIGH);
  setRegisterPin(4 + reg*8, HIGH);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}
void set6(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(3 + reg*8, LOW);
  setRegisterPin(4 + reg*8, HIGH);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}
void set7(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, HIGH);
  setRegisterPin(3 + reg*8, HIGH);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, HIGH);
  setRegisterPin(7 + reg*8, HIGH);
  
  writeRegisters();
}
void set8(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(3 + reg*8, LOW);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}
void set9(int reg){
  //HIGH, LOW
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(2 + reg*8, HIGH);
  setRegisterPin(3 + reg*8, HIGH);
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(7 + reg*8, LOW);
  
  writeRegisters();
}

void standby(int reg){
  clearRegisters();
  setRegisterPin(1 + reg*8, LOW);
  setRegisterPin(1,LOW);
  writeRegisters();
  delay(delayTime);  
  clearRegisters();
  setRegisterPin(4 + reg*8, LOW);
  setRegisterPin(4,LOW);
  writeRegisters();
  delay(delayTime); 
  clearRegisters();
  setRegisterPin(5 + reg*8, LOW);
  setRegisterPin(5,LOW);
  writeRegisters();
  delay(delayTime); 
  clearRegisters();
  setRegisterPin(6 + reg*8, LOW);
  setRegisterPin(6,LOW);
  writeRegisters();
  delay(delayTime); 
  clearRegisters();
  setRegisterPin(3 + reg*8, LOW);
  setRegisterPin(3,LOW);
  writeRegisters();
  delay(delayTime); 
  clearRegisters();
  setRegisterPin(2 + reg*8, LOW);
  setRegisterPin(2,LOW);
  writeRegisters();
  delay(delayTime); 
}

void dispNumber(int num){
  if(num >= 0 && num < 100);
    if(num < 10){
      setNumber(0,0);
      setNumber(num,1);
    }else{
      int digit1 = num % 10;
      setNumber(digit1,1);
      int digit2 = (num - digit1)/10;
      setNumber(digit2,0);
    }
}

void setNumber(int num, int reg){
  switch (num) {
    case 0:
      set0(reg);
      break;
    case 1:
      set1(reg);
      break;
    case 2:
      set2(reg);
      break;
    case 3:
      set3(reg);
      break;
    case 4:
      set4(reg);
      break;
    case 5:
      set5(reg);
      break;
    case 6:
      set6(reg);
      break;
    case 7:
      set7(reg);
      break;
    case 8:
      set8(reg);
      break;
    case 9:
      set9(reg);
      break;
  }
  
}

int getTemp(){

 /*
 int reading = analogRead(1);  
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 float temperatureC = (voltage - 0.5) * 100 ; 
 */
 
 int tempReading = analogRead(1); // Get the reading from the sensor

 double voltage = tempReading * (1100/1024); // Convert reading from sensor into millivolts

 double temperatureC = ((voltage - 500)/10); // Convert to temperature in degrees C.
 int temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 
 return temperatureF;
 
}

void loop(){
  /*
  for(int i=1; i <8; i++){
    clearRegisters();
    setRegisterPin(i, LOW);
    writeRegisters();
    delay(1000);
    Serial.println(i);
    Serial.println();
  }
  set0(1);
  delay(delayTime); 
  set1(1);
  delay(delayTime); 
  set2(1);
  delay(delayTime); 
  set3(1);
  delay(delayTime); 
  set4(1);
  delay(delayTime); 
  set5(1);
  delay(delayTime); 
  set6(1);
  delay(delayTime); 
  set7(1);
  delay(delayTime); 
  set8(1);
  delay(delayTime); 
  set9(1);
  delay(delayTime); 
  
  for(int i = 0; i<100; i++){
    dispNumber(i);
    delay(150);
  }  
  
  
  */
 // Serial.println(getTemp());
  int sum = 0;
  int p = 25;
  for(int i = 0; i <p; i++){
    sum += getTemp();
    delay(1000/p);
  }
  dispNumber(sum/p);
  //delay(delayTime);
}
