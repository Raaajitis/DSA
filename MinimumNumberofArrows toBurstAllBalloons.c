#include <stdio.h>

struct Balloon {
    int start;
    int end;
};

void sortBalloons(struct Balloon balloons[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (balloons[j].end > balloons[j + 1].end) {

                struct Balloon temp = balloons[j];

                balloons[j] = balloons[j + 1];

                balloons[j + 1] = temp;
            }
        }
    }
}

int minimumArrows(struct Balloon balloons[], int n) {

    if (n == 0) {
        return 0;
    }

    sortBalloons(balloons, n);

    int arrows = 1;

    int arrowPosition = balloons[0].end;

    for (int i = 1; i < n; i++) {

        if (balloons[i].start > arrowPosition) {

            arrows++;

            arrowPosition = balloons[i].end;
        }
    }

    return arrows;
}

int main() {

    struct Balloon balloons[] = {
        {10, 16},
        {2, 8},
        {1, 6},
        {7, 12}
    };

    int n = sizeof(balloons) / sizeof(balloons[0]);

    int result = minimumArrows(balloons, n);

    printf("Minimum arrows required: %d\n", result);

    return 0;
}