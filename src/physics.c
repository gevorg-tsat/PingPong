#include <stdio.h>
#define POCK1 2
#define POCK2 75
#define ROOF 25
#define FLOOR 1

void movement(int *ball_x, int *ball_y, int rocket1, int rocket2, int *ball_speedx, int *ball_speedy, int *score_left, int *score_right) {
    ball_x += ball_speedx;
    ball_y += ball_speedy;
    if (ball_x < POCK1) { //выход за поле (за левую ракетку)
        score_right++;
        ball_x = 40;
        ball_y = 12;
        ball_speedy = -(ball_speedy); //можно вернуть и ракетки
        ball_speedx = -(ball_speedx);
        return;
    }
    if (ball_x > POCK2) { //выход за правую ракетку
        (score_left)++;
        ball_x = 40;
        ball_y = 12;
        ball_speedy = -(ball_speedy);
        ball_speedx = -(ball_speedx);
        return;
    }
    if ((ball_x == POCK1)  && (ball_y == rocket1 || ball_y == (rocket1 + 1) || ball_y == (rocket1 - 1))) { //попадание в первую ракетку
        ball_speedx = - (ball_speedx);
        ball_x += (ball_speedx);
        ball_y += (ball_speedy);
        return;
    }
    if ((ball_x == POCK2)  && (ball_y == rocket2 || ball_y == (rocket2 + 1) || ball_y == (rocket2 - 1))) { //попадание во вторую
        ball_speedx = - (ball_speedx);
        ball_x += (ball_speedx);
        ball_x += (ball_speedx);
        return;
    }
    if (ball_y == FLOOR || ball_y == ROOF) { //пол и потолок
        ball_speedy = - (ball_speedy);
        ball_y += (ball_speedy);
        ball_y += (ball_speedy);
        return;
    }
}
