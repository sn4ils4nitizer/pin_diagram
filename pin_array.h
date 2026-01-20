#ifndef PIN_ARRAY_H_

#define PIN_ARRAY_H_
#define PIN_AMOUNT 40

typedef struct {
  int pin_num;
  char *description;
} Pin;

extern Pin pin_array[PIN_AMOUNT];

// Initializers
void pin_init(Pin *pin, int num);
void pin_array_init(Pin *pins);

void display_pin_diagram(const Pin *pin_array);
void set_pin(Pin *pin_array, int pin_num, const char *desc);

#endif // PIN_ARRAY_H_
