// "Copyright [2022] <Copyright Desperos>"
#include <stdio.h>
#define FIELD_SIZE_X 80  // Размер поля по горизонтали 80 + 2 стенки
#define FIELD_SIZE_Y 25  // Размер поля по вертикали 25 + 2 стенки
#define RACKET_LEFT_X 5  // Положение по Х ЛЕВОЙ ракетки
#define RACKET_RIGHT_X 75  // Положение по Х ПРАВОЙ ракетки
#define SCORE_INT_1 2  // Интервал внутренних цифр счета
#define SCORE_INT_2 4  // Интервал внешних цифр счета
#define CENTER_SCORE 9  // Коэфицент центровки счета
#define CENTER_SCORE 9  // Коэфицент центровки счета

int print(int win,  int ball_x, int ball_y, int racket_left_y,
int racket_right_y, int score_1, int score_2, int score_3,
int score_4);  // Прототип фунцкии отрисовки
int score(int cifra);  // Прототип фунцкии счетчика отчков

// Функция отрисовки
int print(int win, int ball_x, int ball_y, int racket_left_y,
int racket_right_y, int score_1, int score_2, int score_3,
int score_4) {
  printf("\033[0d\033[2J");  // Отчистка экрана
  printf("\e[8;$35;$82;t");  // Задание размеров экрана
  printf("\n");

  // Перевод входящих цифр под формат Switch Case
  score_1 = (score_1 == 0) ? 11 : score_1;  // Пересчет нуля для Switch
  score_2 = (score_2 == 0) ? 11 : score_2;  // Пересчет нуля для Switch
  score_3 = (score_3 == 0) ? 11 : score_3;  // Пересчет нуля для Switch
  score_4 = (score_4 == 0) ? 11 : score_4;  // Пересчет нуля для Switch

  // Вывод табло со счетом
  for (int score_y = 1; score_y <= 5; score_y++) {  // Цикл по оси Y для счета
    for (int score_x = 1; score_x <= FIELD_SIZE_X - 20;
    score_x++) {  // Цикл по оси Х для счета
      (score_x == FIELD_SIZE_X / 2 - CENTER_SCORE - SCORE_INT_2)  // Цифра 1
      ? score(score_1 * 10 + score_y)  // Вывод цифры 1 и умножение для CASE
      : (score_x == FIELD_SIZE_X / 2 - CENTER_SCORE - SCORE_INT_1)  // Цифра 2
      ? score(score_2 * 10 + score_y)  // Вывод цифры 2 и умножение для CASE
      : (score_x == FIELD_SIZE_X / 2 - CENTER_SCORE) ? printf(":")  // Делитель
      : (score_x == FIELD_SIZE_X / 2 - CENTER_SCORE + SCORE_INT_1)  // Цифра 3
      ? score(score_3 * 10 + score_y)  // Вывод цифры 3 и умножение для CASE
      : (score_x == FIELD_SIZE_X / 2 - CENTER_SCORE + SCORE_INT_2)  // Цифра 4
      ? score(score_4 * 10 + score_y)  // Вывод цифры 4 и умножение для CASE
      : printf(" ");  // Вывод пустоты в счетчике очков
    }
    printf("\n");
  }

  /* Отображение победителя игры. 0 - левый, 1 - правый,
  2 - информация для выхода из игры 
  deffault - пустота */
  switch (win) {  // CASE для выбора победителя
  case 0:  // Победил левый игрок
    printf("\n");
    for (int x = 1; x < FIELD_SIZE_X / 2 - 8; x++) {
      printf(" ");  // Вывод пустоты до нужного положения фразы
    }
    printf("Player LEFT WIN!\n");  // Победил правый игрок
    break;
  case 1:  // Победил правый игрок
    printf("\n");
    for (int x = 1; x < FIELD_SIZE_X / 2 - 8; x++) {
      printf(" ");  // Вывод пустоты до нужного положения фразы
    }
    printf("Player RIGHT WIN\n");  // Победил правый игрок
    break;
  case 2:  // Победил правый игрок
    printf("\n");
    for (int x = 1; x < FIELD_SIZE_X / 2 - 19; x++) {
      printf(" ");  // Вывод пустоты до нужного положения фразы
    }
    printf("Для выхода из игры нажмите / и Enter\n");  // Победил правый игрок
    break;
  default:
    printf("\n");  // Победителя нет
    break;
  }

  // Отобрадения поля игры, его границ, мяча и ракеток
  for (int field_y = 1; field_y <= FIELD_SIZE_Y;
  field_y++) {  // Цикл по оси Х
    for (int field_x = 1; field_x <= FIELD_SIZE_X;
    field_x++) {  // Цикл по оси Х
      (ball_x == field_x && ball_y == field_y)
      ? printf("@") :  // Положение мяча
      (field_x == 1 && field_y == 1) ||  // Верхний левый угол
      (field_x == FIELD_SIZE_X && field_y == 1) ||  // Верхний правый угол
      (field_x == 1 && field_y == FIELD_SIZE_Y) ||  // Нижний левый угол
      (field_x == FIELD_SIZE_X && field_y == FIELD_SIZE_Y)  // Нижний правый у
      ? printf("╬") :  // Отрисовка углов
      (field_y == FIELD_SIZE_Y) ||  // Нижняя стенка
      (field_y == 1) ?  // Верхняя стенка
      printf("-") :  // Отрисовка верхней и нижней стенок
      (field_x == 1) ||  // Левая стенка
      (field_x == (FIELD_SIZE_X - 1) / 2) ||
      (field_x == FIELD_SIZE_X) ||  // Праввая стенка
      // Положение верхнего края левой ракетки
      (RACKET_LEFT_X == field_x && racket_left_y == field_y - 1) ||
      // Среднее положение левой ракетки
      (RACKET_LEFT_X == field_x && racket_left_y == field_y) ||
      // Положение нижнего края левой ракетки
      (RACKET_LEFT_X == field_x && racket_left_y == field_y + 1) ||
      // Положение верхнего края правой ракетки
      (RACKET_RIGHT_X == field_x && racket_right_y == field_y - 1) ||
      // Среднее положение правой ракетки
      (RACKET_RIGHT_X == field_x && racket_right_y == field_y) ||
      // Положение нижнего края правой ракетки
      (RACKET_RIGHT_X == field_x && racket_right_y == field_y + 1) ?
      printf("|") :  // Отрисовка левой и правой стенок
      printf(" ");  // Отрисовка пустого поля
    }
    printf("\n");
  }
  return 0;
}

// Набор цифр для счетчика очков построчно, 5 строк Х, 8 строк У
int score(int cifra) {
  switch (cifra) {
  // ********************* 0
  case 111:
    printf("#####");
    break;
  case 112:
    printf("#   #");
    break;
  case 113:
    printf("#   #");
    break;
  case 114:
    printf("#   #");
    break;
  case 115:
    printf("#####");
    break;
  // ********************* 1
  case 11:
    printf("    #");
    break;
  case 12:
    printf("    #");
    break;
  case 13:
    printf("    #");
    break;
  case 14:
    printf("    #");
    break;
  case 15:
    printf("    #");
    break;
  // ********************* 2
  case 21:
    printf("#####");
    break;
  case 22:
    printf("    #");
    break;
  case 23:
    printf("#####");
    break;
  case 24:
    printf("#    ");
    break;
  case 25:
    printf("#####");
    break;
  // ********************* 3
  case 31:
    printf("#####");
    break;
  case 32:
    printf("    #");
    break;
  case 33:
    printf("#####");
    break;
  case 34:
    printf("    #");
    break;
  case 35:
    printf("#####");
    break;
  // ********************* 4
  case 41:
    printf("#   #");
    break;
  case 42:
    printf("#   #");
    break;
  case 43:
    printf("#####");
    break;
  case 44:
    printf("    #");
    break;
  case 45:
    printf("    #");
    break;
  // ********************* 5
  case 51:
    printf("#####");
    break;
  case 52:
    printf("#    ");
    break;
  case 53:
    printf("#####");
    break;
  case 54:
    printf("    #");
    break;
  case 55:
    printf("#####");
    break;
  // ********************* 6
  case 61:
    printf("#####");
    break;
  case 62:
    printf("#    ");
    break;
  case 63:
    printf("#####");
    break;
  case 64:
    printf("#   #");
    break;
  case 65:
    printf("#####");
    break;
  // ********************* 7
  case 71:
    printf("#####");
    break;
  case 72:
    printf("    #");
    break;
  case 73:
    printf("    #");
    break;
  case 74:
    printf("    #");
    break;
  case 75:
    printf("    #");
    break;
  // ********************* 8
  case 81:
    printf("#####");
    break;
  case 82:
    printf("#   #");
    break;
  case 83:
    printf("#####");
    break;
  case 84:
    printf("#   #");
    break;
  case 85:
    printf("#####");
    break;
  // ********************* 9
  case 91:
    printf("#####");
    break;
  case 92:
    printf("#   #");
    break;
  case 93:
    printf("#####");
    break;
  case 94:
    printf("    #");
    break;
  case 95:
    printf("#####");
    break;
  }
  return 0;
}
