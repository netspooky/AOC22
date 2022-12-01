#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> /* For INT_MIN */

/* Function to print three largest elements - Stole from https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/ */
void print3largest(int arr[], int arr_size)
{
    int i, first, second, third;
    int total; // This is the total output
    /* There should be at least three elements */
    if (arr_size < 3) {
        printf(" Invalid Input ");
        return;
    }
    third = first = second = INT_MIN;
    for (i = 0; i < arr_size; i++) {
        /* If current element is greater than first*/
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        /* If arr[i] is in between first and second then update second  */
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third)
            third = arr[i];
    }
 
    printf("The three largest totals are:\n  \x1b[38;5;196m1. \x1b[38;5;40m%d\x1b[38;5;196m\n  2. \x1b[38;5;40m%d\x1b[38;5;196m\n  3. \x1b[38;5;40m%d\x1b[0m\n", first, second, third);
    total = first + second + third;
    printf("The total of all three is: \x1b[38;5;40m%d\x1b[0m\n",total);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("\x1b[38;5;40mAdvent of Code \x1b[38;5;196mDay 01\x1b[0m\nUsage: ./day1 file.txt\n");
        exit(1);
    }
    char const* const filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
       printf("File not found!\n");   
       exit(2);             
    }
    char line[256]; // This is where the file data is stored in a temp buffer
    int valz[1024] = { 0 }; // 1024 possible values to store
    int curval = 0; // This is where the current value is stored
    int elfnum = 0; // This is the index in valz, also tells me the number of elements at the end
    int biggest = 0; // This will be the offset of the biggest one

    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) > 1) {
            curval = curval + atoi(line);
        } else {
            valz[elfnum] = curval;
            curval = 0;
            elfnum = elfnum + 1;
        }
    }
    if (curval > 0) {
        // This checks if there was a line that was missed
        valz[elfnum] = curval;
        curval = 0;
        elfnum = elfnum + 1;
    }
    printf("There were \x1b[38;5;196m%d\x1b[0m elfs in total.\n",elfnum);
    print3largest(valz,elfnum);
    fclose(file);
    return 0;
}