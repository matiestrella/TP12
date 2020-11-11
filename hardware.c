
#include "hardware.h"


void export_pin22 (void)
{
    FILE * handle_export = fopen("/sys/class/gpio/export","w");
    int nWritten;
    if (handle_export == NULL)
    {
    printf("Cannot open EXPORT File. Try again later.\n");
    exit(1);
    }
    nWritten=fputs("22",handle_export);
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
    FILE * handle_direction = fopen("/sys/class/gpio/gpio22/direction","w");
    int nWritten;
    if (handle_direction == NULL)
    {
    printf("Cannot open DIRECTION File");
    exit(1);
    }
    // Set pin Direction
    if ((nWritten=fputs("out",handle_direction))==-1)
    {
    printf("Cannot open DIRECTION pin. Try again later.\n");
    exit(1);
    }
    else
    {
    printf("DIRECTION File for PIN opened succesfully\n");
    }
    fclose(handle_direction); // Be carefull do this for EACH pin !!!
}

void set_pin22 (void)
{
    FILE * handle;
    int nWritten;
    char *pin22 ="/sys/class/gpio/gpio22/value";
    if ((handle = fopen(pin22,"w")) == NULL)
    {
    printf("Cannot open device. Try again later.\n");
    exit(1);
    }
    else
    {
    printf("Device successfully opened\n");
    }
    if(fputc('1' ,handle)==-1) // Set pin low
    {
    printf("Clr_Pin: Cannot write to file. Try again later.\n");
    exit(1);
    }
    else
    printf("Write to file %s successfully done.\n",pin22);
    fclose(handle);
}
