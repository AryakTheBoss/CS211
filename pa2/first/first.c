#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned short set(unsigned short x,unsigned short n, unsigned short v);
unsigned short comp(unsigned short x,unsigned short n);
unsigned short get(unsigned short x, unsigned short n);

int main(int argc, char* argv[])
{

    FILE *input;
    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("Error Opening File");
        return 0;
    }
   
    unsigned short xC;
   
    char currentCommand[100];
    unsigned short currN;
    unsigned short currV;
    

fscanf(input, "%hu\n", &xC);
 while(!feof(input)) {

        if (feof(input)) {
            break;
        }
	
	fscanf(input, "%s\t%hu\t%hu\n",currentCommand,&currN,&currV);
	if(currentCommand==NULL){
	  printf("currentCommand was NULL\n");
	  printf("currN is %u and currV is %u, x is %u\n",currN,currV,xC);
	  return 0;
	}

	if(strcmp(currentCommand,"set")==0){
	  xC = set(xC,currN,currV);
	  printf("%hu\n",xC);
	}else if(strcmp(currentCommand,"comp")==0){
	  xC = comp(xC,currN);
	  printf("%hu\n",xC);
	}else if(strcmp(currentCommand,"get")==0){
	  
	  printf("%hu\n",get(xC,currN));
	}
 }

}

unsigned short set(unsigned short x,unsigned short n, unsigned short v){

  if(v==1)
    return (1 << n) | x;
  else if(v==0)
    return ~(1 << n) & x;
  else 
    return 9999; // some contingency

}
unsigned short comp(unsigned short x,unsigned short n){
  return x ^ (1 << n);
}
unsigned short get(unsigned short x, unsigned short n){
  return (x >> n) & 1;
}
