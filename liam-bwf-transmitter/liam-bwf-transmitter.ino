/* Liam BWF Transmitter
   --------------------
   
   This program will send out a +/- signal of 100µs, then delay 10ms.
 
   
   100µs
    __                           
   |  |                           
   |  |        10ms                
   |  |   ______________
      |  |             
      |  |              
      |__|                       
  
   The signal will be recieved differently by the cutter depending on
   if it is inside or outside of the BWF
   For this reason, it is important to connect the BWF ends the right
   way. Should the cutter think it is outside, try switching the ends.
  
   There are serveral different versions of this shield

   1. A standalone shield connected to an aruduino through a cable
      - A standalone shield can be run on higher voltage and has a
        built in voltage converter for the arduino
        This is perfect for larger lawns which requires a strong signal
   2. A normal L298 motor shield on an Arduino
      - Easy to put together. Same as for the Liam reciever but max 12V
   3. A L293 motor shield on an Arduino
      - A very low cost shield but limited in voltage (12V) and speed
   4. A MegaMoto shield on an Arduino
      - Higher cost but very powerful and strong signal with little heat generation

*/

// Select which transmitter type you have by uncommenting that line

//#define __1_L298_Standalone__

// To set registers
//#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
//#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

/*
   Connector usage
   ---------------
   The BWF should be connected to motor A or motor 0 on all shields

   For the standalone shield (nr 1), pins A0 and A1 should be connected to input pins
   for motor 1 on the shield (In1 and In2)
*/


//--------------- End of definition --------------------------

// Arduino pins and timing for the PWM signals.
	#define PIN1_PWM A0
	#define PIN2_PWM A1
	#define PIN3_PWM A2
	#define PIN4_PWM A3
//	#define LONG_DELAY_1  8000
	#define SHORT_DELAY 250
  #define LONG_DELAY_1  6300
  #define LONG_DELAY_2  1200
  #define LONG_DELAY_3  4600
  #define LONG_DELAY_4  2900



void setup()
{
  Serial.begin(115200);
  Serial.println("Liam BWF Transmitter");

  pinMode(PIN1_PWM,OUTPUT);
  pinMode(PIN2_PWM,OUTPUT);
  pinMode(PIN3_PWM,OUTPUT);
  pinMode(PIN4_PWM,OUTPUT);
}


void loop()
{
  _high(1);
  delayMicroseconds(SHORT_DELAY);
  _low(1);
  delayMicroseconds(SHORT_DELAY);
  _none(1);
  delayMicroseconds(LONG_DELAY_1);

  _high(3);
  delayMicroseconds(SHORT_DELAY);
  _low(3);
  delayMicroseconds(SHORT_DELAY);
  _none(3);
  delayMicroseconds(LONG_DELAY_2);

  _high(2);
  delayMicroseconds(SHORT_DELAY);
  _low(2);
  delayMicroseconds(SHORT_DELAY);
  _none(2);
  delayMicroseconds(LONG_DELAY_3);

  _high(3);
  delayMicroseconds(SHORT_DELAY);
  _low(3);
  delayMicroseconds(SHORT_DELAY);
  _none(3);
  delayMicroseconds(LONG_DELAY_4);

  _high(2);
  delayMicroseconds(SHORT_DELAY);
  _low(2);
  delayMicroseconds(SHORT_DELAY);
  _none(2);
  delayMicroseconds(LONG_DELAY_4);

  _high(3);
  delayMicroseconds(SHORT_DELAY);
  _low(3);
  delayMicroseconds(SHORT_DELAY);
  _none(3);
  delayMicroseconds(LONG_DELAY_3);

  _high(2);
  delayMicroseconds(SHORT_DELAY);
  _low(2);
  delayMicroseconds(SHORT_DELAY);
  _none(2);
  delayMicroseconds(LONG_DELAY_2);

  _high(3);
  delayMicroseconds(SHORT_DELAY);
  _low(3);
  delayMicroseconds(SHORT_DELAY);
  _none(3);
  delayMicroseconds(LONG_DELAY_1);
}

void high() {
  digitalWrite(PIN1_PWM, HIGH);
  digitalWrite(PIN2_PWM, LOW);
  digitalWrite(PIN3_PWM, HIGH);
  digitalWrite(PIN4_PWM, LOW);
}

void none() {
  digitalWrite(PIN1_PWM, LOW);
  digitalWrite(PIN2_PWM, LOW);
  digitalWrite(PIN3_PWM, LOW);
  digitalWrite(PIN4_PWM, LOW);
}

void low() {
  digitalWrite(PIN1_PWM, LOW);
  digitalWrite(PIN2_PWM, HIGH);
  digitalWrite(PIN3_PWM, LOW);
  digitalWrite(PIN4_PWM, HIGH);
}


void _high(int i) {
  switch(i) {
    case 1:
      digitalWrite(PIN1_PWM, HIGH);
      digitalWrite(PIN2_PWM, LOW);
      digitalWrite(PIN3_PWM, HIGH);
		  digitalWrite(PIN4_PWM, LOW);
      break;
    case 2:
      digitalWrite(PIN1_PWM, HIGH);
      digitalWrite(PIN2_PWM, LOW);
      break;
    case 3:
      digitalWrite(PIN3_PWM, HIGH);
      digitalWrite(PIN4_PWM, LOW);
      break;
    }
}

void _none(int i) {
  switch(i) {
    case 1:
      digitalWrite(PIN1_PWM, LOW);
      digitalWrite(PIN2_PWM, LOW);
      digitalWrite(PIN3_PWM, LOW);
      digitalWrite(PIN4_PWM, LOW);
      break;
    case 2:
      digitalWrite(PIN1_PWM, LOW);
      digitalWrite(PIN2_PWM, LOW);
      break;
    case 3:
      digitalWrite(PIN3_PWM, LOW);
      digitalWrite(PIN4_PWM, LOW);
      break;
    }
}

void _low(int i) {
    switch(i) {
    case 1:
      digitalWrite(PIN1_PWM, LOW);
      digitalWrite(PIN2_PWM, HIGH);
      digitalWrite(PIN3_PWM, LOW);
      digitalWrite(PIN4_PWM, HIGH);
      break;
    case 2:
      digitalWrite(PIN1_PWM, LOW);
      digitalWrite(PIN2_PWM, HIGH);
      break;
    case 3:
      digitalWrite(PIN3_PWM, LOW);
      digitalWrite(PIN4_PWM, HIGH);
      break;
    }
}
