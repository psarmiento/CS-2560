#include <stdio.h>

int main(){
  int var = 20;
  int x = 10;
  int *ip;    // pointer declaration of type int 
  ip = NULL;    // point to address 0 for safety
  
  ip = &var;    // now pointing to address of var 
  
  x = x + *ip;    // x = 10 + 20  grabbing data where pointer is pointing is called derefrencing 
  
  ip = &x;      // change where ip is pointing, now pointing to address of x 
  
  // pointer calculation 
  ip = ip + 3;      // address of ip + (3 * sizeof(int)) = address of ip + 12
  
  printf("Address of var variable: %x\n", &car);
  
  // address stored in pointer variable 
  printf("Adress stored in ip variable: %x\n", ip);
  
  // access the value using the pointer 
  printf("Value of *ip variable: %d\n", *ip);
  
  return 0;

}
