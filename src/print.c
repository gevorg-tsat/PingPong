// "Copyright [2022] <Copyright Desperos>"
#include <stdio.h>
#define FIELD_SIZE_X 82 // Размер поля по горизонтали 80 + 2 стенки
#define FIELD_SIZE_Y 27 // Размер поля по вертикали 25 + 2 стенки

int print(int ball_x, int ball_y, int racket_left_x, int racket_left_y, int racket_right_x, int racket_right_y);

int main() {
  print(20, 20, 2, 6, 81, 20); // ХУ Ball, XY racket L, XY racket R


return 0;
}

int print(int ball_x, int ball_y, int racket_left_x, int racket_left_y, int racket_right_x, int racket_right_y) {
  for (int field_y = 1; field_y <= FIELD_SIZE_Y; field_y++) {  // Цикл по оси Y
    for (int field_x = 1; field_x <= FIELD_SIZE_X; field_x++) {  // Цикл по оси Х
      (ball_x == field_x && ball_y == field_y) ? printf("@") : // Положение мяча
      (field_x == 1 && field_y == 1) ||  // Верхний левый угол
      (field_x == FIELD_SIZE_X && field_y == 1) ||  // Верхний правый угол
      (field_x == 1 && field_y == FIELD_SIZE_Y) ||  // Нижний левый угол
      (field_x == FIELD_SIZE_X && field_y == FIELD_SIZE_Y) ?  // Нижний правый угол
      printf("*") :  // Отрисовка углов
      (field_y == FIELD_SIZE_Y) ||  //Нижняя стенка
      (field_y == 1)  // Верхняя стенка
      ? printf("-") :  // Отрисовка верхней и нижней стенок
      (field_x == 1) ||  // Левая стенка
      (field_x == (FIELD_SIZE_X - 1) / 2) ||
      (field_x == FIELD_SIZE_X) ||  // Праввая стенка
      (racket_left_x == field_x && racket_left_y == field_y - 1) || // Положение верхнего края левой ракетки
      (racket_left_x == field_x && racket_left_y == field_y) || // Среднее положение левой ракетки
      (racket_left_x == field_x && racket_left_y == field_y + 1) || // Положение нижнего края левой ракетки
      (racket_right_x == field_x && racket_right_y == field_y - 1) || // Положение верхнего края правой ракетки
      (racket_right_x == field_x && racket_right_y == field_y) || // Среднее положение правой ракетки
      (racket_right_x == field_x && racket_right_y == field_y + 1) ? // Положение нижнего края правой ракетки
      printf("|") :  // Отрисовка левой и правой стенок
      printf(" ");  // Отрисовка пустого поля
    }
    printf("\n");
  }
  return 0;
}
