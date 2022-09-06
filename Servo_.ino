/*
  Based on Tom Igoe's code
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
#include <Servo.h>

Servo myServo;

const int buzzerPin = 10;
const int buttonPin = 2;     // the number of the pushbutton pin
static int white =  3;
static int green = 4; // the number of the LED pin
static int blue = 5;
static int red = 6;
static int yellow = 7;


// notes in the melody:
// use 0 for a rest
// put each measure on its own line
// NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 
  //NOTE_G5, 0, NOTE_G4, 0,
  //NOTE_C5, NOTE_G4, 0, NOTE_E4,
  //NOTE_A5, NOTE_B5, NOTE_AS5, NOTE_A5,
int buttonState = 0;   
int melody[] = {
// NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 
//  NOTE_G5, 0, NOTE_G4, 0,
//  NOTE_C5, NOTE_G4, 0, NOTE_E4,
//  NOTE_A5, NOTE_B5, NOTE_AS5, NOTE_A5,
  
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 0,
  NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B5, NOTE_C5
  
};

// note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
// be sure each note or rest in the melody above has a corresponding duration below
// put each measure on its own line
// cccccc
// ecdbc
// 8, 8, 8, 8, 8, 8, 
 // 4, 4, 4, 4,
 // 6, 8, 4, 6,
 // 4, 4, 8, 4
int noteDurations[] = {
// 8, 8, 8, 8, 8, 8, 
//  4, 4, 4, 4,
//  6, 8, 4, 6,
//  4, 4, 8, 4

  
  4, 4, 2, 4, 4, 4, 2,
  4, 4, 4, 4, 4
};

// set the tempo
// a tempo of 60 is one beat per second
// a tempo of 120 would be twice as fast
int beatsPerMinute = 100;

void setup() {
// initialize the LED pin as an output:
  myServo.attach(12);
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
     myServo.write(180);
  delay(1000);
  myServo.write(0);
  delay(1000);
   playSong();
    // turn LED on:
    digitalWrite(white, HIGH);  // make the white led light up 
  digitalWrite(green, LOW); // white (high) all others (low)
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(500);                       
  digitalWrite(white, LOW); // make the green led light up    
  digitalWrite(green, HIGH); // green (high) all others (low) 
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(500);   // wait for a second
  digitalWrite(white, LOW); // make the blue led light up     
  digitalWrite(green, LOW); // blue (high) all others (low)
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(500);
  digitalWrite(white, LOW);   //make the red led light up 
  digitalWrite(green, LOW);   //red (high) all others (low)
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  delay(500);
  digitalWrite(white, LOW);   // make the yellow led light up  
  digitalWrite(green, LOW); // yellow (high) all others (low)
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(white, LOW);   
  digitalWrite(green, LOW); 
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  delay(500);
  digitalWrite(white, LOW);   
  digitalWrite(green, LOW); 
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(500);
  digitalWrite(white, LOW);   
  digitalWrite(green, HIGH); 
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(500);
  } else {
    // turn LED off:
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
  }
}

void playSong(){
 // iterate over the notes of the melody:
  int len = sizeof(melody)/sizeof(melody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
}
