#include <stdio.h>
#include <string.h>
#include "pin_array.h"

int main(int argc, char *argv[]) {

if (argc == 1){
     printf("No args were provided.\n");
 }
  
 for (int i = 1; i < argc; i++){
   if (strcmp(argv[1], "-d") == 0) {
     pin_array_init(pin_array);
     set_pin(pin_array, 4, "This pin does something");
     set_pin(pin_array, 23, "This pin does something too!~");
     display_pin_diagram(pin_array);
   }
 } 
  
   
  return 0;
}
