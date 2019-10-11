#include "first.h"

int main(int argc, char** argv) {

    // even first sorted ascending
    // odd after, sorted ascending

    FILE *input;
    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("Error Opening File");
        return 0;
    }

    int i = 0, j = 0, oddCount = 0, evenCount = 0, currentNum, size;

    int even[20]; // at most 20 in length
    int odd[20];

    fscanf(input, "%d\n", &size); // need to skip first line

    while(!feof(input)) {

        if (feof(input)) {
            break;
        }

        fscanf(input, "%d\t", &currentNum);

        if (currentNum % 2 == 0 || currentNum == 0) { // is even or 0
            even[evenCount] = currentNum;
            ++evenCount;
        } else { // is odd
            odd[oddCount] = currentNum;
            ++oddCount;
        }

        i++; // increment only after checking eof
    }

    fclose(input);

    sort(even, evenCount);
    sort(odd, oddCount);

    for(j = 0; j < evenCount; j++) { 
        printf("%d\t", even[j]);    
    }

    for(j = oddCount - 1; j >= 0;j--) { 
        printf("%d\t", odd[j]);
    }

    return 0;
}

void sort(int array[], int size) {
    int i, j, current;

    for (i = 1; i < size; i++) {
        current = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = current;
    }
}
