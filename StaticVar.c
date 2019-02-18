#include <stdio.h>
// Global variables
int A;
int B;

int fun(){
  static int count = 0;   // Static variable 
  count++;
  return count;
}

int Add(){
  return A + B;
}

int main(){
  int answer;   // Local variable 
  A = 5; 
  B = 7;
  answer = Add();
  printf("%d\n", answer);
  printf("%d\n", fun());
  printf("%d\n", fun());
  return 0;
}
