int led = 13; //pin to use for the LED
int DIT_DELAY = 300; //time to leave light on for dit
int DASH_DELAY = 600; //time to leave light on for dash
int SYMBOL_DELAY = 600; //time to wait between dits and dash
int WORD_DELAY = 900; //time to wait between words

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
      delay(SYMBOL_DELAY);
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