// "Copyright [2022] <Copyright Desperos>"
#include <stdio.h>
#include <stdlib.h>
#define FIELD_SIZE_X 82  // Размер поля по горизонтали 80 + 2 стенки
#define FIELD_SIZE_Y 27  // Размер поля по вертикали 25 + 2 стенки
#define SCORE_SIZE_X 22  // Размер счета по горизонтали 22 + 2 стенки
#define SCORE_SIZE_Y 12  // Размер счета по вертикали 12 + 2 стенки
#define RACKET_LEFT_X 6  // Положение по Х ЛЕВОЙ ракетки
#define RACKET_RIGHT_X 75  // Положение по Х ПРАВОЙ ракетки

int print(int ball_x, int ball_y, int racket_left_y, int racket_right_y) {
  for (int score_y = 1; score_y <= SCORE_SIZE_Y; score_y++) {  // Цикл по оси Y для счета
    for (int score_x = 1; score_x <= SCORE_SIZE_X; score_x++) {  // Цикл по оси Х для счета

    }
    printf("\n");
  }
  

  for (int field_y = 1; field_y <= FIELD_SIZE_Y; field_y++) {  // Цикл по оси Y
    for (int field_x = 1; field_x <= FIELD_SIZE_X; field_x++) {  // Цикл по оси Х
      (ball_x == field_x && ball_y == field_y) ?   printf("%ls", L"@") : // Положение мяча
      (field_x == 1 && field_y == 1) ||  // Верхний левый угол
      (field_x == FIELD_SIZE_X && field_y == 1) ||  // Верхний правый угол\xe2\x99\xa7
      (field_x == 1 && field_y == FIELD_SIZE_Y) ||  // Нижний левый угол
      (field_x == FIELD_SIZE_X && field_y == FIELD_SIZE_Y) ?  // Нижний правый угол
      printf("╬") :  // Отрисовка углов
      (field_y == FIELD_SIZE_Y) ||  //Нижняя стенка
      (field_y == 1) ?  // Верхняя стенка
      printf("-") :  // Отрисовка верхней и нижней стенок
      (field_x == 1) ||  // Левая стенка
      (field_x == (FIELD_SIZE_X - 1) / 2) ||
      (field_x == FIELD_SIZE_X) ||  // Праввая стенка
      (RACKET_LEFT_X == field_x && racket_left_y == field_y - 1) || // Положение верхнего края левой ракетки
      (RACKET_LEFT_X == field_x && racket_left_y == field_y) || // Среднее положение левой ракетки
      (RACKET_LEFT_X == field_x && racket_left_y == field_y + 1) || // Положение нижнего края левой ракетки
      (RACKET_RIGHT_X == field_x && racket_right_y == field_y - 1) || // Положение верхнего края правой ракетки
      (RACKET_RIGHT_X == field_x && racket_right_y == field_y) || // Среднее положение правой ракетки
      (RACKET_RIGHT_X == field_x && racket_right_y == field_y + 1) ? // Положение нижнего края правой ракетки
      printf("|") :  // Отрисовка левой и правой стенок
      printf(" ");  // Отрисовка пустого поля
    }
    printf("\n");
  }
  return 0;
}