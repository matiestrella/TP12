
#include "hardware.h"
#include "ports.h"


void exportar_todo (void)
{
    
FILE *file_gpio17; //file pointer
FILE *file_gpio4; 
FILE *file_gpio18; 
FILE *file_gpio23; 
FILE *file_gpio24; 
FILE *file_gpio25; 
FILE *file_gpio22; 
FILE *file_gpio27; 



 //Write to 'export' file, so we gain access to port

 file_gpio17=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio17, "17"); 
 fclose(file_gpio17);
 
  file_gpio4=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio4, "4"); 
 fclose(file_gpio4);
 
  file_gpio18=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio18, "18"); //GPIO22 is DO9
 fclose(file_gpio18);
 
  file_gpio23=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio23, "23"); //GPIO22 is DO9
 fclose(file_gpio23);
 
  file_gpio24=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio24, "24"); //GPIO22 is DO9
 fclose(file_gpio24);
 
  file_gpio25=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio25, "25"); //GPIO22 is DO9
 fclose(file_gpio25);
 
  file_gpio22=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio22, "22"); //GPIO22 is DO9
 fclose(file_gpio22);
 
  file_gpio27=fopen("/sys/class/gpio/export", "w");
 fprintf(file_gpio27, "27"); //GPIO22 is DO9
 fclose(file_gpio27);
 
 
 //Write 'out' to this port 'direction' file, so it's output port
 file_gpio17=fopen("/sys/class/gpio/gpio17/direction", "w");
 fprintf(file_gpio17, "out");
 fclose(file_gpio17);
 
 file_gpio4=fopen("/sys/class/gpio/gpio4/direction", "w");
 fprintf(file_gpio4, "out");
 fclose(file_gpio4);
 
 file_gpio18=fopen("/sys/class/gpio/gpio18/direction", "w");
 fprintf(file_gpio18, "out");
 fclose(file_gpio18);
 
 file_gpio23=fopen("/sys/class/gpio/gpio23/direction", "w");
 fprintf(file_gpio23, "out");
 fclose(file_gpio23);
 
 file_gpio24=fopen("/sys/class/gpio/gpio24/direction", "w");
 fprintf(file_gpio24, "out");
 fclose(file_gpio24);
 
 file_gpio25=fopen("/sys/class/gpio/gpio25/direction", "w");
 fprintf(file_gpio25, "out");
 fclose(file_gpio25);
 
 file_gpio22=fopen("/sys/class/gpio/gpio22/direction", "w");
 fprintf(file_gpio22, "out");
 fclose(file_gpio22);
 
 file_gpio27=fopen("/sys/class/gpio/gpio27/direction", "w");
 fprintf(file_gpio27, "out");
 fclose(file_gpio27);
 
 }
 

void mod_pin(char pin,char cont[])
{
 FILE *file_gpio; 
 
char n1,n2;
char direc[] = "/sys/class/gpio/gpio17/value";

 if(pin==1)
 {
 file_gpio=fopen("/sys/class/gpio/gpio4/value", "w");
 }
 else
 {
    switch (pin)
    {
        case 0 : n1='1'; n2='7';break;
        case 2 : n1='1'; n2='8';break;
        case 3 : n1='2'; n2='3';break;
        case 4 : n1='2'; n2='4';break;
        case 5 : n1='2'; n2='5';break;
        case 6 : n1='2'; n2='2';break;
        case 7 : n1='2'; n2='7';break;
    }
    direc[20]= n1;
    direc[21]= n2;
  file_gpio=fopen(direc, "w");  
 }

 fprintf(file_gpio, cont);
 fclose(file_gpio);
}


void actualizar_leds(void)
{
    char i;
    char s[]="0";
    for (i=0;i<=7;i++)
    {
    s[0] = (bitGet ('A', i) + '0');
    mod_pin(i,s);
    }
}