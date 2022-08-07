#include <stdio.h>
#include "physics.c"
#include "print.c"

int main() {
    char button = ' ';
    int ball_x = 40, ball_y = 10, rocket1 = 10, rocket2 = 10, ball_speedx = 1, ball_speedy = 1, score_left = 0, score_right = 0;
    print(ball_x, ball_y, rocket1, rocket2, score_left / 10, score_left % 10, score_right / 10, score_right % 10);
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
        if (button == 'M' || button == 'm' || button == 'Z' || button == 'z'|| button == 'A' || button == 'a' || button == 'K' || button == 'k' || button == ' ')
            movement(&ball_x, &ball_y, rocket1, rocket2, &ball_speedx, &ball_speedy, &score_left, &score_right);
        print(ball_x, ball_y, rocket1, rocket2, score_left / 10, score_left % 10, score_right / 10, score_right % 10);
    }
    return 0;
}

//1 _*_ 
//4 *_* 
//else ***

// 