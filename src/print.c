#include <stdio.h>


int field_size_y = 27; // Размер поля по вертикали 25 + 2 стенки
int field_size_x = 82; // Размер поля по горизонтали 80 + 2 стенки
//int print(int ball_x, int ball_y, int racket_left_x, int racket_left_y,int racket_right_x, int racket_right_y);
int ball_x, ball_y, racket_left_x, racket_left_y, racket_right_x, racket_right_y;
int print();
/*ball_x = 1;
ball_y = 1;
racket_left_x = 1;
racket_left_y = 1;
racket_right_x = 1;
racket_right_y = 1;
*/

int main() {
  printf("Ball X-%d Y-%d\nRacket Left X-%d Y-%d\nRacket X-%d Y-%d\n\n", ball_x, ball_y, racket_left_x, racket_left_y, racket_right_x, racket_right_y);
  print();


return 0;
}

int print() {
  for(int field_y = 1; field_y <= field_size_y; field_y++) {
    for(int field_x = 1; field_x <= field_size_x; field_x++) {
      (field_x == 1 && field_y == 1) || 
      (field_x == field_size_x && field_y == 1) || 
      (field_x == 1 && field_y == field_size_y) || 
      (field_x == field_size_x && field_y == field_size_y) ?
      printf("*") : 
      (field_y == field_size_y) ||
      (field_y == 1)
      ? printf("-") :
      (field_x == 1) ||
      (field_x == field_size_x) ?
      printf("|") :
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
