/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the edito
 */

/* 
 * File:   main.c
 * Author: matias
 *
 * Created on 4 de noviembre de 2020, 12:25
 */

#include <stdio.h>
#include <stdlib.h>

FILE * handle;
int nWritten;
char *pin22 ="/sys/class/gpio/gpio22/value";

void main(void)
{
if ((handle = fopen(pin22,"w")) == NULL)
{
printf("Cannot open device. Try again later.\n");
exit(1);
}
else
{
printf("Device successfully opened\n");
}
if(fputc('0' ,handle)==-1) // Set pin low
{
printf("Clr_Pin: Cannot write to file. Try again later.\n");
exit(1);
}
else
printf("Write to file %s successfully done.\n",pin22);
fclose(handle);
}