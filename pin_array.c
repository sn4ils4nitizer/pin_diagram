#include "pin_array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Pin pin_array[PIN_AMOUNT];

void pin_init(Pin *pin, int num){
  pin->pin_num = num;
  pin->description = NULL;
}

void pin_array_init(Pin *pins) {
  for(int i = 0; i < PIN_AMOUNT; i++) {
   pin_init(&pins[i], i); 
 } 
}
 
void display_pin_diagram(const Pin *pin_array) {
  for (int i = 0; i < PIN_AMOUNT; i++) {
    printf("%d: %s \n", pin_array[i].pin_num, pin_array[i].description);
  }
}

void set_pin(Pin *pin_array, int pin_num, const char *desc){
  if (pin_num < 1 || pin_num > 40) {
    printf("Pin numnber out of range.");
  }

  free(pin_array[pin_num].description);
  pin_array[pin_num].description = strdup(desc);
}

int read_pin_diagram() {

  FILE *fptr;
  fptr = fopen("pindiagram.txt", "r");

  if (fptr == NULL) {
    perror("Failed to read the file.");
    return -1;
 }

  char *line = NULL;
  size_t line_len = 0;
  
  while(getline(&line, &line_len, fptr) != -1) {
    char *token = strtok(line, " ");
    if(token != NULL) {
      int pin = atoi(token);
      char *desc = strtok(NULL, "\n");
      if(desc != NULL) {
        set_pin(pin_array, pin, desc);
      }
    }
  }

  free(line);
  fclose(fptr);
  return 0;
}

int write_pin_diagram() {

  FILE *fptr;
  fptr = fopen("pin_diagram.txt", "w");

  if (fptr == NULL) {
    perror("Failed to write file.");
    return -1;
  }

  for (int i = 0; i < PIN_AMOUNT; i++ ) {
    fprintf(fptr, "%d %s\n", pin_array[i].pin_num + 1, pin_array[i].description);
  }

  fclose(fptr);
  return 0;

}
