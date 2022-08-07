#include <stdio.h>
#include "print.c"
#define POCK1 5
#define POCK2 75
#define ROOF 25
#define FLOOR 1


int main() {
    char button = ' ';
    int ball_x = 40, ball_y = 10, rocket1 = 10, rocket2 = 10, ball_speedx = 1, ball_speedy = 1, score_left = 0, score_right = 0;
    print(3, ball_x, ball_y, rocket1, rocket2, score_left / 10, score_left % 10, score_right / 10, score_right % 10);
    while (button != '/') {
        printf("\e[8;$35;$82;t");
        button = getchar();
        fflush(stdin);
        if ((button == 'A' || button == 'a') && rocket1 != 3) 
            rocket1--;
        if ((button == 'Z' || button == 'z') && rocket1 != 23)
            rocket1++;
        if ((button == 'K' || button == 'k') && rocket2 != 3)
            rocket2--;
        if ((button == 'M' || button == 'm') && rocket2 != 23)
            rocket2++;
        if (button == 'M' || button == 'm' || button == 'Z' || button == 'z'|| button == 'A' || button == 'a' || button == 'K' || button == 'k' || button == ' ') {
                ball_x += ball_speedx;
                ball_y += ball_speedy;
                if (ball_x < POCK1) { //выход за поле (за левую ракетку)
                    score_right++;
                    ball_x = 40;
                    ball_y = 12;
                    ball_speedy = -(ball_speedy); //можно вернуть и ракетки
                    ball_speedx = -(ball_speedx);
                }  
                if (ball_y == FLOOR || ball_y == ROOF) { //пол и потолок
                    ball_speedy = - (ball_speedy);
                    ball_y += (ball_speedy);
                    ball_y += (ball_speedy);
                }
                if (ball_x > POCK2) { //выход за правую ракетку
                    (score_left)++;
                    ball_x = 40;
                    ball_y = 12;
                    ball_speedy = -(ball_speedy);
                    ball_speedx = -(ball_speedx);
                }
                if ((ball_x == POCK1)  && (ball_y == rocket1 || ball_y == (rocket1 + 1) || ball_y == (rocket1 - 1))) { //попадание в первую ракетку
                    ball_speedx = - (ball_speedx);
                    ball_x += (ball_speedx);
                    ball_y += (ball_speedy);
                }
                if ((ball_x == POCK2)  && (ball_y == rocket2 || ball_y == (rocket2 + 1) || ball_y == (rocket2 - 1))) { //попадание во вторую
                    ball_speedx = - (ball_speedx);
                    ball_x += (ball_speedx);
                    ball_x += (ball_speedx);
                } 
        }
        if (score_left == 21) {
            print(0, ball_x, ball_y, rocket1, rocket2, score_left / 10, score_left % 10, score_right / 10, score_right % 10);
            break;
        }
        if (score_right == 21) {
            print(1, ball_x, ball_y, rocket1, rocket2, score_left / 10, score_left % 10, score_right / 10, score_right % 10);
            break;
        }
        print(2, ball_x, ball_y, rocket1, rocket2, score_left / 10, score_left % 10, score_right / 10, score_right % 10);
    }
    return 0;
}

//1 _*_ 
//4 *_* 
//else ***

// 