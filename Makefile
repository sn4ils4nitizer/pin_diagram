##
# RaspPi Pin Diagram
#
# @file
# @version 0.1

CC = clang
CFLAGS = -Wall -Wextra -Wpedantic

main: main.o pin_array.o
	$(CC) $(CFLAGS) main.o pin_array.o -o main

main.o: main.c pin_array.h 
	$(CC) $(CFLAGS) -c main.c

pin_array.o: pin_array.c pin_array.h
	$(CC) $(CFLAGS) -c pin_array.c

clean:
	rm -f *.o main

# end	
