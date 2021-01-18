//Sketch for Controlling GPIO Pins 18,19,22 and 23 of ESP32 Via Serial Blutooth Terminal Application.



#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int received;// received value will be stored in this variable
char receivedChar;// received value will be stored as CHAR in this variable

const char led1on ='a';
const char led1off ='b';
const char led2on ='c';
const char led2off ='d';
const char led3on ='e';
const char led3off ='f';
const char led4on ='g';
const char led4off ='h';
const char led5on ='i';
const char led5off ='j';
const int ledpin1 = 18;
const int ledpin2 = 19;
const int ledpin3 = 22;
const int ledpin4 = 23;
const int ledpin5 = 21;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32 BluetootIOT"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("To turn ON send: a");//print on serial monitor  
  Serial.println("To turn OFF send: b"); //print on serial monitor 
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
}

void loop() {
    receivedChar =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    SerialBT.print("Received:");// write on BT app
    SerialBT.println(receivedChar);// write on BT app      
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor    
    //SerialBT.println(receivedChar);//print on the app    
    //SerialBT.write(receivedChar); //print on serial monitor
    
if(receivedChar == led1on)
    {
     SerialBT.println("LED1 ON:");// write on BT app
     Serial.println("LED1 ON:");//write on serial monitor
     digitalWrite(ledpin1, HIGH);// turn the LED ON
       
    }
    if(receivedChar == led1off)
    {
     SerialBT.println("LED1 OFF:");// write on BT app
     Serial.println("LED1 OFF:");//write on serial monitor
      digitalWrite(ledpin1, LOW);// turn the LED off 
    }    
     if(receivedChar == led2on)
    {
     SerialBT.println("LED2 ON:");// write on BT app
     Serial.println("LED2 ON:");//write on serial monitor
     digitalWrite(ledpin2, HIGH);// turn the LED ON
       
    }
    if(receivedChar == led2off)
    {
     SerialBT.println("LED2 OFF:");// write on BT app
     Serial.println("LED2 OFF:");//write on serial monitor
      digitalWrite(ledpin2, LOW);// turn the LED off 
    }
 if(receivedChar == led3on)
    {
     SerialBT.println("LED3 ON:");// write on BT app
     Serial.println("LED3 ON:");//write on serial monitor
     digitalWrite(ledpin3, HIGH);// turn the LED ON
       
    }
    if(receivedChar == led3off)
    {
     SerialBT.println("LED3 OFF:");// write on BT app
     Serial.println("LED3 OFF:");//write on serial monitor
      digitalWrite(ledpin3, LOW);// turn the LED off 
    } 
if(receivedChar == led4on)
    {
     SerialBT.println("LED4 ON:");// write on BT app
     Serial.println("LED4 ON:");//write on serial monitor
     digitalWrite(ledpin4, HIGH);// turn the LED ON
       
    }
    if(receivedChar == led4off)
    {
     SerialBT.println("LED4 OFF:");// write on BT app
     Serial.println("LED4 OFF:");//write on serial monitor
      digitalWrite(ledpin4, LOW);// turn the LED off 
    } 
    if(receivedChar == led5on)
    {
     SerialBT.println("LED5 ON:");// write on BT app
     Serial.println("LED5 ON:");//write on serial monitor
     digitalWrite(ledpin5, HIGH);// turn the LED ON
       
    }
    if(receivedChar == led5off)
    {
     SerialBT.println("LED5 OFF:");// write on BT app
     Serial.println("LED5 OFF:");//write on serial monitor
      digitalWrite(ledpin5, LOW);// turn the LED off 
    } 
  }
  delay(20);
}
