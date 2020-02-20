#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int RXPin = 10;
const int TXPin = 11;
const int PRPin = A0;
boolean isPlaying = false;
boolean isStopped = true;

SoftwareSerial mp3Serial(RXPin, TXPin);
DFRobotDFPlayerMini mp3Player;

void setup()
{
  mp3Serial.begin(9600);
  Serial.begin(9600);

  Serial.println(F("Arrancando MusicBox para Arduino."));

  if (!mp3Player.begin(mp3Serial)) {
    Serial.println(F("Imposible inicializar: revisa la conexión o la tarjeta SD."));
  }

  pinMode(PRPin, INPUT);
  mp3Player.volume(5);
  Serial.println(F("MusicBox online!."));
}

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
