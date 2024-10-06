#include <stdio.h>

void printCombinations(int score) {
    printf("Possible combinations of scoring plays if a team’s score is %d:\n\n", score);
    
    for (int td8 = 0; td8 * 8 <= score; td8++) {
        for (int td7 = 0; td7 * 7 + td8 * 8 <= score; td7++) {
            for (int td6 = 0; td6 * 6 + td7 * 7 + td8 * 8 <= score; td6++) {
                for (int fg = 0; fg * 3 + td6 * 6 + td7 * 7 + td8 * 8 <= score; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td6 * 6 + td7 * 7 + td8 * 8 <= score; safety++) {
                        if (td8 * 8 + td7 * 7 + td6 * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td8, td7, td6, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        printCombinations(score);
    }
    
    return 0;
}