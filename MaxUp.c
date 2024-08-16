#include <stdio.h>
#define INPUTS 3
struct stats {
 short int l; //level
 short int m; //muscles
} s; //student
int main(int argc, char* argv[]) {
 char* input=0;
 char playing=1;
 input = malloc(INPUTS);
 s.l=1;
 s.m=0;
 while(playing==1) {
  printf("Max Up!\n");
  printf("1. Train 2. Fight 3. Exit ");
  fgets(input, INPUTS, stdin);
  if(input[1]!='\n'||(input[0]!='\n'&&input[1]!='\n')) {
   while(input[0] !='\n' && input[1] != '\n')
    fgets(input, INPUTS, stdin);
   input[0]=0;
  }
  if(input[1]!='\n'||input[0] <'1'||input[0]>'3') {
   printf("Incorrect Input\n");
   continue;
  }
  if(input[0] == '3') {
   playing=0;
   printf("May you train another day!\n");
  }
  if(input[0] == '1') {
   if(s.m <20) {
    s.m++;
   } else
    printf("Your muscles are Maxed Up!\n");
   printf("Muscles: %d\n", s.m);
  }
  if(input[0] == '2') {
   if(s.m>=s.l*2) {
    s.l++;
    if(s.l>=10) {
     printf("+------------------------------+\n");
     printf("|Victory, you are now a Master!|\n");
     printf("|Level: %d                     |\n", s.l);
     printf("|Muscles: %d                   |\n", s.m);
     printf("+------------------------------+\n");
     playing=0;
     getch();
    } else
     printf("Level: %d\n", s.l);
   } else {
    printf("You were defeated!\n");
   }
  }
 }
 if(input)
  free(input);
 exit(0);
}