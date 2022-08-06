// "Copyright [2022] <Copyright Desperos>"
#include <stdio.h>
#include <stdlib.h>
#define FIELD_SIZE_X 82  // Размер поля по горизонтали 80 + 2 стенки
#define FIELD_SIZE_Y 27  // Размер поля по вертикали 25 + 2 стенки
#define RACKET_LEFT_X 2  // Положение по Х ЛЕВОЙ ракетки
#define RACKET_RIGHT_X 75  // Положение по Х ПРАВОЙ ракетки
#define SCORE_LEFT 17  // Крайнее левое положение счета
#define SCORE_INT 2  // Интервал между цифрами

int print(int ball_x, int ball_y, int racket_left_y, int racket_right_y, int score_1, int score_2, int score_3, int score_4) {
  score_1 = (score_1 == 0) ? 11 : score_1;
  score_2 = (score_2 == 0) ? 11 : score_2;
  score_3 = (score_3 == 0) ? 11 : score_3;
  score_4 = (score_4 == 0) ? 11 : score_4;
  for (int score_y = 1; score_y <= 5; score_y++) {  // Цикл по оси Y для счета
    for (int score_x = 1; score_x <= FIELD_SIZE_X - 20; score_x++) {  // Цикл по оси Х для счета
      (score_x == FIELD_SIZE_X / 2 - 9 - 2) ? score(score_1 * 10 + score_y) : 
      (score_x == FIELD_SIZE_X / 2 - 9 - 1) ? score(score_2 * 10 + score_y) : 
      (score_x == FIELD_SIZE_X / 2 - 9) ? printf(":") : 
      (score_x == FIELD_SIZE_X / 2 - 9 + 1) ? score(score_3 * 10 + score_y) : 
      (score_x == FIELD_SIZE_X / 2 - 9 + 2) ? score(score_4 * 10 + score_y) : 
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
  for (int field_y = 1; field_y <= FIELD_SIZE_Y; field_y++) {  // Цикл по оси Y
    for (int field_x = 1; field_x <= FIELD_SIZE_X; field_x++) {  // Цикл по оси Х
      (ball_x == field_x && ball_y == field_y) ?   printf("@") : // Положение мяча
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
int score(int cifra) {
  switch (cifra) {
  case 111:
    printf("|---|");
    break;
  case 112:
    printf("|   |");
    break;
  case 113:
    printf("|   |");
    break;
  case 114:
    printf("|   |");
    break;
  case 115:
    printf("|---|");
    break;
  case 11:
    printf("   /|");
    break;
  case 12:
    printf("  / |");
    break;
  case 13:
    printf("    |");
    break;
  case 14:
    printf("    |");
    break;
  case 15:
    printf("    |");
    break;
  case 21:
    printf("----|");
    break;
  case 22:
    printf("    |");
    break;
  case 23:
    printf("-----");
    break;
  case 24:
    printf("|    ");
    break;
  case 25:
    printf("|----");
    break;
  case 31:
    printf("----|");
    break;
  case 32:
    printf("    |");
    break;
  case 33:
    printf("|---|");
    break;
  case 34:
    printf("    |");
    break;
  case 35:
    printf("----|");
    break;
  case 41:
    printf("|   |");
    break;
  case 42:
    printf("|   |");
    break;
  case 43:
    printf("|---|");
    break;
  case 44:
    printf("    |");
    break;
  case 45:
    printf("    |");
    break;
  case 51:
    printf("|----");
    break;
  case 52:
    printf("|    ");
    break;
  case 53:
    printf("|---|");
    break;
  case 54:
    printf("    |");
    break;
  case 55:
    printf("----|");
    break;
  case 61:
    printf("-----");
    break;
  case 62:
    printf("|    ");
    break;
  case 63:
    printf("|---|");
    break;
  case 64:
    printf("|   |");
    break;
  case 65:
    printf("|---|n");
    break;
  case 71:
    printf("|---|");
    break;
  case 72:
    printf("    |");
    break;
  case 73:
    printf("    |");
    break;
  case 74:
    printf("    |");
    break;
  case 75:
    printf("    |");
    break;
  case 81:
    printf("|---|");
    break;
  case 82:
    printf("|   |");
    break;
  case 83:
    printf("|---|");
    break;
  case 84:
    printf("|   |");
    break;
  case 85:
    printf("|---|n");
    break;
  case 91:
    printf("|---|");
    break;
  case 92:
    printf("|   |");
    break;
  case 93:
    printf("|---|");
    break;
  case 94:
    printf("    |");
    break;
  case 95:
    printf("----|");
    break;
  }
  return 0;
}