#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Hex table
// 00 01 => 1
// 00 10 => 2
// 01 01 => 5
// 01 10 => 6
// 10 01 => 9
// 10 10 => A

// a 0x09 .-  => 10 01
// b 0x56 -... => 01 01 01 10
// c 0x66 -.-. => 01 10 01 10
// o 0x2A --- 00 10 10 10
// s 0x15 ... 00 01 01 01

int morse[26] = {
  //hex, letter, morse, binary, inverted binary
  0x09, //a => .-   => 00 00 10 01 => 00 00 10 01
  0x56, //b => -... => 10 01 01 01 => 01 01 01 10
  0x66, //c => -.-. => 10 01 10 01 => 01 10 01 10
  0x16, //d => -..  => 00 10 01 01 => 00 01 01 10
  0x01, //e => .    => 00 00 00 01 => 00 00 00 01
  0x65, //f => ..-. => 01 01 10 01 => 01 10 01 01
  0x1A, //g => --.  => 00 10 10 01 => 00 01 10 10
  0x55, //h => .... => 01 01 01 01 => 01 01 01 01
  0x05, //i => ..   => 00 00 01 01 => 00 00 01 01
  0xA9, //j => .--- => 01 10 10 10 => 10 10 10 01
  0x26, //k => -.-  => 00 10 01 10 => 00 10 01 10
  0x59, //l => .-.. => 01 10 01 01 => 01 01 10 01
  0x0A, //m => --   => 00 00 10 10 => 00 00 10 10
  0x06, //n => -.   => 00 00 10 01 => 00 00 01 10
  0x2A, //o => ---  => 00 10 10 10 => 00 10 10 10
  0x69, //p => .--. => 01 10 10 01 => 01 10 10 01
  0x9A, //q => --.- => 10 10 01 10 => 10 01 10 10
  0x19, //r => .-.  => 00 01 10 01 => 00 01 10 01
  0x15, //s => ...  => 00 01 01 01 => 00 01 01 01
  0x02, //t => -    => 00 00 00 10 => 00 00 00 10
  0x25, //u => ..-  => 00 01 01 10 => 00 10 01 01
  0x95, //v => ...- => 01 01 01 10 => 10 01 01 01
  0x29, //w => .--  => 00 01 10 10 => 00 10 10 01
  0x96, //x => -..- => 10 01 01 10 => 10 01 01 10
  0xA6, //y => -.-- => 10 01 10 10 => 10 10 01 10
  0x5A, //z => --.. => 10 10 01 01 => 01 01 10 10
};

void print_morse_char();
void print_morse_word();
void print_alphabet();

int main(){
  print_alphabet();
  print_morse_word("wesley");
  printf("\n");
  return 0;
}

void print_morse_word(char word[]){
  int length = strlen(word);
  int i = 0;
  for(i = 0; i < length; i++){
    int letter = word[i] - 97;
    print_morse_char(morse[letter]);
  }
}

void print_morse_char(int encoded_char) {
  do {
    int tmp = encoded_char % 4;
    encoded_char = encoded_char / 4;
    if(tmp == 2){
      printf("-");
    } else {
      printf(".");
    }
  } while (encoded_char != 0);
  printf(" ");
}

void print_alphabet(){
  int i = 0;
  for(i = 0; i < 26; i++){
    printf("%i) %c: ", i, i + 97);
    print_morse_char(morse[i]);
    printf("\n");
  };
}
