#include "print_error.h"


void print_error(){
    perror(strerror(errno));
}

