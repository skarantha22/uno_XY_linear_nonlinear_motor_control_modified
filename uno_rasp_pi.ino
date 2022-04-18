int motor1DriverPulsePinNumber = 12;    // motor1 Pulse pin
int motor1DriverDirectionPinNumber = 11;    // motor1 Direection pin

int motor2DriverPulsePinNumber = 10;    // motor2 Pulse pin
int motor2DriverDirectionPinNumber = 9;    // motor2 Direection pin

char _commandRotateMotor1ClockWise='A';
char _commandRotateMotor1CounterClockWise='B';
char _commandRotateMotor2ClockWise='C';
char _commandRotateMotor2CounterClockWise='D';
char _commandRotateMotor1Motor2ClockWise='E';
char _commandRotateMotor1CounterClockWiseMotor2ClockWise='F';
char _commandRotate1CounterClockWiseMotor2ClockWiseMotor='G';
char _commandRotateMotor1Motor2CounterClockWise='H';
char _commandStopMotor1Motor2='I';

char c;
int i,j,k,l;
int full_cycle=400;
int half_cycle=200;
int stepsPerTurn = 200;
int RPM = 160;
float stepsPerSecond = (stepsPerTurn*RPM)/60;
float waitInMilliseconds = (1/stepsPerSecond)*1000;

void setup() {
  Serial.begin(9600);
  pinMode (motor1DriverPulsePinNumber, OUTPUT);
  pinMode (motor1DriverDirectionPinNumber, OUTPUT);
  pinMode (motor2DriverPulsePinNumber, OUTPUT);
  pinMode (motor1DriverDirectionPinNumber, OUTPUT);
  Serial.println("motor state:initialize");
  delay(200);
  
}
/////////////Funtion 1 defination/////////////////////////////////////////
void turnMotorClockWise(int pulsepinnumber, int directionpinnumber)
{
      Serial.println("motor1 clkwise");
      digitalWrite(directionpinnumber,LOW);
      for(i=0;i<full_cycle;i++)
        {
        digitalWrite(pulsepinnumber,HIGH);
        delay(waitInMilliseconds);
        digitalWrite(pulsepinnumber,LOW);
        delay(waitInMilliseconds);
        }
}
/////////////////Funtion1 defination ends/////////////////////////////////////

/////////////////Funtion 2 defination/////////////////////////////////////////
void turnMotorCounterClockWise(int pulsepinnumber, int directionpinnumber)
{
      Serial.println("motor anticlkwise");
      digitalWrite(directionpinnumber,HIGH);
      for(i=0;i<full_cycle;i++)
        {
        digitalWrite(pulsepinnumber,HIGH);
        delay(waitInMilliseconds);
        digitalWrite(pulsepinnumber,LOW);
        delay(waitInMilliseconds);
        }
}
/////////////Funtion 2 defination ends///////////////////////////////////////

/////////////////Funtion 3 defination/////////////////////////////////////////
void turnMotor12ClockWise(int pulsepinnumber1, int directionpinnumber1,int pulsepinnumber2, int directionpinnumber2)
{
                          Serial.println("motorxyfirst");
                          digitalWrite(directionpinnumber1,LOW);
                          digitalWrite(directionpinnumber2,LOW);
                          for(k=0;k<full_cycle;k++)
                            {
                            digitalWrite(pulsepinnumber1,HIGH);
                            digitalWrite(pulsepinnumber2,HIGH);
                            delay(waitInMilliseconds);
                            digitalWrite(pulsepinnumber1,LOW);
                            digitalWrite(pulsepinnumber2,LOW);
                            delay(waitInMilliseconds);
                            }
}
//////////////////////////////////////////Funtion 3 defination ends///////////////////////////////////////
//////////////////////////////////////////Funtion 4 defination////////////////////////////////////////////
void turnMotor1ClockWiseMotor2AntiClockwise(int pulsepinnumber1, int directionpinnumber1,int pulsepinnumber2, int directionpinnumber2)
{
                          Serial.println("motorxysecond");
                          digitalWrite(directionpinnumber1,HIGH);
                          digitalWrite(directionpinnumber2,LOW);
                          for(k=0;k<full_cycle;k++)
                            {
                            digitalWrite(pulsepinnumber1,HIGH);
                            digitalWrite(pulsepinnumber2,HIGH);
                            delay(waitInMilliseconds);
                            digitalWrite(pulsepinnumber1,LOW);
                            digitalWrite(pulsepinnumber2,LOW);
                            delay(waitInMilliseconds);
                            }
                              
}
////////////////////////////////////////Funtion 4 defination ends///////////////////////////////////////
//////////////////////////////////////////Funtion 5 defination////////////////////////////////////////////
void turnMotor1AntiClockwiseMotor2Clockwise(int pulsepinnumber1, int directionpinnumber1,int pulsepinnumber2, int directionpinnumber2)
{
                          Serial.println("motorxythird");
                          digitalWrite(directionpinnumber1,LOW);
                          digitalWrite(directionpinnumber2,HIGH);
                          for(k=0;k<full_cycle;k++)
                            {
                            digitalWrite(pulsepinnumber1,HIGH);
                            digitalWrite(pulsepinnumber2,HIGH);
                            delay(waitInMilliseconds);
                            digitalWrite(pulsepinnumber1,LOW);
                            digitalWrite(pulsepinnumber2,LOW);
                            delay(waitInMilliseconds);
                            }
                              
}
////////////////////////////////////////Funtion 5 defination ends///////////////////////////////////////
//////////////////////////////////////////Funtion 6 defination////////////////////////////////////////////
void turnMotor1Motor2AntiClockwise(int pulsepinnumber1, int directionpinnumber1,int pulsepinnumber2, int directionpinnumber2)
{
                          Serial.println("motorxyfourth");
                          digitalWrite(directionpinnumber1,LOW);
                          digitalWrite(directionpinnumber2,LOW);
                          for(k=0;k<full_cycle;k++)
                            {
                            digitalWrite(pulsepinnumber1,HIGH);
                            digitalWrite(pulsepinnumber2,HIGH);
                            delay(waitInMilliseconds);
                            digitalWrite(pulsepinnumber1,LOW);
                            digitalWrite(pulsepinnumber2,LOW);
                            delay(waitInMilliseconds);
                            }
                              
}
////////////////////////////////////////Funtion 6 defination ends///////////////////////////////////////
//////////////////////////////////////////Funtion 6 defination////////////////////////////////////////////
void turnMotor1Motor2stop(int pulsepinnumber1,int pulsepinnumber2)
{
                          Serial.println("motorstop");
                          digitalWrite(pulsepinnumber1,LOW);
                          digitalWrite(pulsepinnumber2,LOW);
}
////////////////////////////////////////Funtion 6 defination ends///////////////////////////////////////




void loop() {
   while (Serial.available() > 0)
  c = Serial.read();
  {
    if (c==_commandRotateMotor1ClockWise)
      {
        turnMotorClockWise(motor1DriverPulsePinNumber,motor1DriverDirectionPinNumber);

      }
        else if (c==_commandRotateMotor1CounterClockWise)
          {
          turnMotorCounterClockWise(motor1DriverPulsePinNumber,motor1DriverDirectionPinNumber);
              }
           
            else if (c==_commandRotateMotor2ClockWise)
                { 
                 turnMotorClockWise(motor2DriverPulsePinNumber,motor2DriverDirectionPinNumber); 
                 }   
                  else if (c==_commandRotateMotor2CounterClockWise)
                    { 
                      turnMotorCounterClockWise(motor2DriverPulsePinNumber,motor2DriverDirectionPinNumber);
                    }   

                      else if (c==_commandRotateMotor1Motor2ClockWise)
                        { 
                          turnMotor12ClockWise(motor1DriverPulsePinNumber,motor1DriverDirectionPinNumber,motor2DriverPulsePinNumber,motor2DriverDirectionPinNumber);
                        }   
                          else if (c==_commandRotateMotor1CounterClockWiseMotor2ClockWise)
                            { 
                              turnMotor1ClockWiseMotor2AntiClockwise(motor1DriverPulsePinNumber,motor1DriverDirectionPinNumber,motor2DriverPulsePinNumber,motor2DriverDirectionPinNumber);
                              }   

                              else if (c==_commandRotate1CounterClockWiseMotor2ClockWiseMotor)
                                { 
                                  turnMotor1AntiClockwiseMotor2Clockwise(motor1DriverPulsePinNumber,motor1DriverDirectionPinNumber,motor2DriverPulsePinNumber,motor2DriverDirectionPinNumber);
                                }   
                                  else if (c==_commandRotateMotor1Motor2CounterClockWise)
                                    { 
                                      turnMotor1Motor2AntiClockwise(motor1DriverPulsePinNumber,motor1DriverDirectionPinNumber,motor2DriverPulsePinNumber,motor2DriverDirectionPinNumber);
                                      }  
                                        else if (c==_commandStopMotor1Motor2)
                                                   {
                                                    turnMotor1Motor2stop(motor1DriverPulsePinNumber,motor2DriverPulsePinNumber);
                                                   }
}

}
