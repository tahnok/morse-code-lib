#include <WProgram.h>

int led = 13; //pin to use for the LED
int DIT_DELAY = 300; //time to leave light on for dit
int DASH_DELAY = DIT_DELAY * 3; //time to leave light on for dash
int SYMBOL_DELAY = DIT_DELAY; //time to wait between dits and dash
int CHARACTER_DELAY = DIT_DELAY * 3;
int WORD_DELAY = DIT_DELAY * 7; //time to wait between words

int morse_seq(char input);
void morse_char(char input);
void write_morse(String in);
void dit(void);
void dash(void);

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);    
}

void loop() {
  write_morse("SOS");
}

void write_morse(String input){
  for(int i = 0; i < input.length(); i++){
    if(input[i] != ' '){
      morse_char(input[i]);
      delay(CHAR_DELAY);
    } else {
      delay(WORD_DELAY);
    }
  } 
}

void morse_char(char morse){
  int sequence = morse_seq(morse);
  //while we haven't hit 0
  while(sequence != 0){
    //if the last digit is a 2 then then we need a dash
    if(sequence % 2){
      dash();
    } else { // otherwise it's a dit
      dit();
    } //this essentially shifts the number over
    sequence = sequence / 10;
    delay(SYMBOL_DELAY);
  }
}

int morse_seq(char inp){
  //turns the input character into a number
  //morse sequence is stored as an int
  //2 means dash, 1 means dit
  //the seuqence is stored backwards because it's easier to parse
  int ascii = atoi(&inp);
  switch(ascii) {
  case 97:
  case 65:
    //A = -.
    return 21;
  case 98:
  case 66:
    //B = .---
    return 1112;
  case 99:
  case 67:
    //C = -.-.
    return 1212;
  case 100:
  case 68:
    //D = -..
    return 112;
  case 101:
  case 69:
    //E = .
    return 1;
  case 102:
  case 70:
    //F = ..-.
    return 1211;
  case 103:
  case 71:
    //G = --.
    return 122;
  case 104:
  case 72:
    //H = ....
    return 1111;
  case 105:
  case 73:
    //I = ..
    return 11;
  case 106:
  case 74:
    //J = .---
    return 2221;
  case 107:
  case 75:
    //K = -.-.
    return 1212;
  case 108:
  case 76:
    //L = .-..
    return 1121;
  case 109:
  case 77:
    //M = --
    return 22;
  case 110:
  case 78:
    //N = -.
    return 12;
  case 111:
  case 79:
    //O = ---
    return 111;
  case 112:
  case 80:
    //P = .--.
    return 1221;
  case 113:
  case 81:
    //Q = --.-
    return 2122;
  case 114:
  case 82:
    //R = .-.
    return 121;
  case 115:
  case 83:
    //S = ...
    return 111;
  case 116:
  case 84:
    //T = -
    return 2;
  case 117:
  case 85:
    //U = ..-
    return 211;
  case 118:
  case 86:
    //V = ...-
    return 2111;
  case 119:
  case 87:
    //U = ..-
    return 211;
  case 120:
  case 88:
    //W = .--
    return 221;
  case 121:
  case 89:
    //X = -..-
    return 2112;
  case 122:
  case 90:
    //Y = -.--
    return 2212;
  case 123:
  case 91:
    //Z = --..
    return 1122;
  case 49:
    //0 = -----
    return 22222;
  case 50:
    //1 = .----
    return 22221;
  case 51:
    //2 = ..---
    return 22211;
  case 52:
    //3 = ...--
    return 22111;
  case 53:
    //4 = ....-
    return 21111;
  case 54:
    //5 = .....
    return 11111;
  case 55:
    //6 = -....
    return 11112;
  case 56:\
    //7 = --...
    return 11122;
  case 57:
    //8 = ---..
    return 11222;
  case 58:
    //9 = ----.
    return 12222;

  }
}

void dit(void){
  digitalWrite(led, HIGH);
  delay(DIT_DELAY);
  digitalWrite(led, LOW);
}

void dash(void){
  digitalWrite(led, HIGH);
  delay(DASH_DELAY);
  digitalWrite(led, LOW);
}