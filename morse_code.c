#include <stdlib.h>

#define dit_length 300 //dit length
#define dash_length dit_length* 3 //dash length

//using hex
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

int morse[26] = {0x09, 0x56, 0x66};

void print_morse();

int main(){
  char b = 'c';
  print_morse(morse[b - 97]);
  return 0;
}

void print_morse(int encoded_char) {
  do {
    int tmp = encoded_char % 4;
    encoded_char = encoded_char / 4;
    if(tmp == 2){
      printf("-");
    } else {
      printf(".");
    }
  } while (encoded_char != 0);
  printf("\n");
}
