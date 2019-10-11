#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkParity(unsigned short x);
int numberOf1BitPairs(unsigned short x);

int main(int argc, char* argv[])
{
 
  if(argc == 1){
    printf("No Number Given");
    return 0;
  }
  unsigned short x = atoi(argv[1]);

  if(checkParity(x)){
    printf("%s\t%d\n","Even-Parity",numberOf1BitPairs(x));
  }else{
  printf("%s\t%d\n","Odd-Parity",numberOf1BitPairs(x));
  }


}

int checkParity(unsigned short x){ //returns 0 if odd 1 if even

int count = 0, i;

    for(i = 0; i < 32; i++){
        if(x & (1 << i))
	  count++;
    }

    if(count % 2)
      return 0;

    return 1;

}
int numberOf1BitPairs(unsigned short x){

  int count=0;

while (x != 0)
    {
      if ((x & 1) == 1){//if it finds 1
       
	x = x >> 1; //shift again
	if((x & 1) == 1){//check if next is 1
	  count++;
	}
	 
      }
      
      x = x >> 1;
    }

  return count;

}
