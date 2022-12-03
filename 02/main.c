#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("\x1b[38;5;40mAdvent of Code \x1b[38;5;196mDay 02\x1b[0m\nUsage: ./day2 file.txt part\n");
        exit(1);
    }
    char const* const filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
       printf("File not found!\n");   
       exit(2);             
    }
    int score = 0;
    char line[69];
    char buff[420];
    int m = 0;
    if (strcmp(argv[2],"2") == 0) { m = 1; } // This just sets which part to answer
    while (fgets(line, sizeof(line), file)) {
        memcpy(buff, line , 3);
        if (strcmp(buff,  "A X") == 0) { score = (m == 1) ? ( score + 0 + 3 ) : ( score + 1 + 3 ); } // Rock vs Rock (Draw)
        if (strcmp(buff,  "A Y") == 0) { score = (m == 1) ? ( score + 3 + 1 ) : ( score + 2 + 6 ); } // Rock vs Paper (Win)
        if (strcmp(buff,  "A Z") == 0) { score = (m == 1) ? ( score + 6 + 2 ) : ( score + 3 + 0 ); } // Rock vs Scissors (Lose)
        if (strcmp(buff,  "B X") == 0) { score = (m == 1) ? ( score + 0 + 1 ) : ( score + 1 + 0 ); } // Paper vs Rock (Lose)
        if (strcmp(buff,  "B Y") == 0) { score = (m == 1) ? ( score + 3 + 2 ) : ( score + 2 + 3 ); } // Paper vs Paper (Draw)
        if (strcmp(buff,  "B Z") == 0) { score = (m == 1) ? ( score + 6 + 3 ) : ( score + 3 + 6 ); } // Paper vs Scissors (Win)
        if (strcmp(buff,  "C X") == 0) { score = (m == 1) ? ( score + 0 + 2 ) : ( score + 1 + 6 ); } // Scissors vs Rock (Win)
        if (strcmp(buff,  "C Y") == 0) { score = (m == 1) ? ( score + 3 + 3 ) : ( score + 2 + 0 ); } // Scissors vs Paper (Lose)
        if (strcmp(buff,  "C Z") == 0) { score = (m == 1) ? ( score + 6 + 1 ) : ( score + 3 + 3 ); } // Scissors vs Scissors (Draw)
    }
    printf("score: %d\n",score);

    return 0;
}
