#include <stdio.h>
#include "physics.c"
#include "print.c"

int main() {
    char button = ' ';
    int ball_x = 40, ball_y = 10, rocket1 = 10, rocket2 = 10, ball_speedx = 1, ball_speedy = 1, score_left = 0, score_right = 0;
    while (button != '/') {
        print(ball_x, ball_y, rocket1, rocket2);
        scanf("%c", &button);
        if (button == 'A' || button == 'a')
            rocket1++;
        if (button == 'Z' || button == 'z')
            rocket1++;
        if (button == 'K' || button == 'k')
            rocket2++;
        if (button == 'M' || button == 'm')
            rocket2++;
        movement(&ball_x, &ball_y, rocket1, rocket2, &ball_speedx, &ball_speedy, &score_left, &score_right);
        print(ball_x, ball_y, rocket1, rocket2);
    }
}