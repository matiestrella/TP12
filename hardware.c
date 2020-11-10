/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hardware.h"

void export_pin22 (void);
void set_pin22_output(void);
void set_pin22_low (void);

void export_pin22 (void)
{
FILE *handle_export;
int nWritten;
if ((handle_export = fopen("/sys/class/gpio/export","w")) == NULL)
{
printf("Cannot open EXPORT File. Try again later.\n"));
exit(1);
}
nWritten=fputs(“22”,handle_export);
if (nWritten==-1)
{
printf ("Cannot EXPORT PIN . Try again later.\n");
exit(1);
}
else
printf("EXPORT File opened succesfully \n");
fclose(handle_export); // Be carefull do this for EACH pin !!!
}

void set_pin22_output(void)
{
FILE * handle_direction;
int nWritten;
if ((handle_direction = fopen(“/sys/class/gpio/gpio22/direction”,"w")) == NULL)
{
printf("Cannot open DIRECTION File”);
exit(1);
}
// Set pin Direction
if ((nWritten=fputs(“out”,handle_direction))==-1)
{
printf("Cannot open DIRECTION pin. Try again later.\n");
exit(1);
}
else
{
printf("DIRECTION File for PIN opened succesfully\n”);
}
fclose(handle_direction); // Be carefull do this for EACH pin !!!
}


