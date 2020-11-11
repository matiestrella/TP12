
#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //string manipulations
#include <unistd.h> //sleep


void exportar_todo (void);
void actualizar_leds(void);
void mod_pin(char ,char cont[]);

#endif //HARDWARE_H 

