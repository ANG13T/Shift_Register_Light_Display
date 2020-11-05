# 74HC595 Shift Register Light Display

This projects utilizes a 74HC595 shift register to make a display with LEDS!

## Materials
- 20 - 30 jumper wires
- 74HC595 shift register
- 5 x 220ohm resistors
- 5 LEDs
- Arduino Uno
- Breadboard

## Schematic

![design image](https://github.com/angelina-tsuboi/Shift_Register_Light_Display/blob/master/images/design.png)


## How It Work

This project utilizes a 74HC595 shift register to make a quick display with five LEDs.

### Why should you use a shift register
Shift registers provide extra I/O pins for a microcontroller with a limited amount of I/O pins. The 74HC595 shift register is a SIPO (Serial-In-Parallel-Out) chip which is utilized when there is a demand for a many outputs such as LEDs. 

### How does a shift register work?

The 74HC595 includes two registers (memory containers) which holds up to 8 bits of data. The first one is called the shift register. When we apply a pulse through the clock pin, the values in the shift register move one step to the left and the shift register also accepts the value from the DATA pin. If the pulse if HIGH, 1 will get pushed onto the shift register otherwise 0. When the latch pin is activated, the values inside the shift register are copied onto the storage register. Every bit on the storage register is connected to one of the outpin pins of the 74HC595 (Qa - Qh), therefore when a value inside the storage register changes so does the output.


### How does the code work?

The *leds* variable will contain the byte for each of our output pins (1 for HIGH and 0 for LOW)

```
byte leds = 0;
```

We set the output pins of the arduino for the latch, data, and clock pins.

```
 pinMode(latchPin, OUTPUT);
 pinMode(dataPin, OUTPUT);  
 pinMode(clockPin, OUTPUT);
```

The first part of the loop sets all the values of *leds* to 0 and updates the shift registers with thoses values. This will set all output pins to LOW so all the LEDs would turn off.
```
 leds = 0; // turn leds off
 updateShiftRegister();
 delay(500);
```

The second part of the *loop()* loops through all the leds and sets the value of the corresponding index of the shift register to HIGH which is followed by a short delay. This will cause the LEDS to light up incrementally.
```
for (int i = 0; i < ledAmount; i++)
{
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
}
```

The *updateShiftRegister()* function sets the latch pin to LOW then it shifts the values of the shift register to the left by using *shiftOut()*. *shiftOut()* takes in the data and clock pin. The third parameter it takes is which end of the data to begin with. We use the LSBFIRST variable in order to set the starting point to the right most bit. For the final parameter, the constructor takes in the data that will be shifted onto the shift register. Finally, the code sets the latchPin to HIGH which copies over the contents of the shift register to the storage register which shows up as the output.

```
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
```


## Completed Project

![project photo](https://github.com/angelina-tsuboi/Shift_Register_Light_Display/blob/master/images/final.jpg)


