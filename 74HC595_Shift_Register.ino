int latchPin = 5;  // Latch pin of 74HC595 is connected to  pin 5
int clockPin = 6; // Clock pin of 74HC595 is connected to pin 6
int dataPin = 4;  // Data pin of 74HC595 is connected to pin 4
int ledAmount = 5; //amount of LEDs used in this project

byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off


void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}


void loop() 
{
  leds = 0; // turn leds off
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < ledAmount; i++) //incrementally display the LEDs
  {
    bitSet(leds, i);    // Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds); //shifts data to the left starting at the right most bit 
   digitalWrite(latchPin, HIGH); //copies values of shift register over to the storage register
}
