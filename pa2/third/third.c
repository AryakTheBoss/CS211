#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isPalindrome(unsigned short x);
unsigned short get(unsigned short x, unsigned short n);

int main(int argc, char* argv[])
{
 if(argc == 1){
    printf("No Number Given");
    return 0;
  }
  unsigned short x = atoi(argv[1]);
  
  if(isPalindrome(x))
    printf("Is-Palindrome\n");
  else
    printf("Not-Palindrome\n");
 
}

int isPalindrome(unsigned short x){
  int length = sizeof(unsigned short)*8; //2 bytes with 8 bits per byte
  int i;
  for(i=0; i<length;i++){
    if(get(x,i) == get(x,length-i-1)){
      continue;
    }else{
      return 0;
    }
  }


 
  return 1;

}

unsigned short get(unsigned short x, unsigned short n){
  return (x >> n) & 1;
}
