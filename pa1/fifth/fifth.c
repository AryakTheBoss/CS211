#include "fifth.h"

int main(int argc, char ** argv) {

    int i, j = 0;
    for (i = 1; i < argc; i++) {
        for (j = 0; argv[i][j] != '\0'; j++) {
	  switch(argv[i][j]) {//if char is vowel print it
                case 'a': 
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    printf("%c", argv[i][j]);
                default:
                    continue;
            }
        }
    }

    return 0;
}
