# Description

The simpliest project with a photoresistor and a DFPlayer Mini. When the photoresistor receives light, starts the first mp3 of the SD card. Therefore, in the dark the mp3 stops.

## Library dependencies

This sketch has the following dependencies:

* [SoftwareSerial.h](https://www.arduino.cc/en/Reference/SoftwareSerial): for the serial communication with the DFPlayer. Already installed with the Arduino IDE.
* [DFRobotDFPlayerMini.h](https://github.com/DFRobot/DFRobotDFPlayerMini): to interact with the DFPlayer. You will need to download and install it in your Arduino libraries folder.

## Requisites and parts

* 1 x Arduino Uno
* 1 x Photoresistor
* 1 x 10K Ohm resistor
* 1 x 1K Ohm resistor
* 1 x DFPlayer Mini
* 1 x SD card formatted as fat16 or fat32
* 1 x mp3 file on the SD card

## Diagram

![Wiring diagram](images/wiring-diagram.png)

## The code

```c
// Initializing
boolean isPlaying = false;
boolean isStopped = true;

SoftwareSerial mp3Serial(RXPin, TXPin);
DFRobotDFPlayerMini mp3Player;
```

```c
// Logic
void loop()
{
  int PRValue = digitalRead(PRPin);

  if ((PRValue == HIGH) && !(isPlaying) ){
    Serial.println(F("Photoresistor high, play."));
    isPlaying = !isPlaying;
    isStopped = !isStopped;
    mp3Player.play(1);
  } else if ((PRValue == LOW) && !(isStopped)) {
    Serial.println(F("Photoresistor low, stop."));
    isPlaying = !isPlaying;
    isStopped = !isStopped;
    mp3Player.stop();
  }
  delay(500);
}
```
