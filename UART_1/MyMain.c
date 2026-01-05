#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/myuart.h"
#include "../inc/leds.h"

int main(void){ 
	uint8_t i; 
	int data = 0; 
	char mystring[256];
  const char* myendVar = "FINISH";	
  UART_Init();              // initialize UART
	leds_init();              // initialize leds
  printf("Welcome to Processor based Systems\n");
  printf("===========================\n"); 
  while(1){
		printf("Here is the MENU\n");
		 printf("===============\n"); 
		printf("To Turn on led R type 1 and press Enter\n");
		printf("To Turn on led B type 2 and press Enter\n");
		printf("To Turn on led G type 3 and press Enter\n");
		printf("To Turn on leds type 4 and press Enter\n");
		printf("To turn off led(s) type 5 and press Enter\n");
		printf("or\n");
		printf("Type FINISH and press Enter to resume\n");
		scanf("%s",mystring); 
		printf("\n");
		i = strcmp(mystring,myendVar);
		if (i==0){
			printf("You have chosen to end the programm\n");
			break; 
		}	
    else {
      data = atoi(mystring);
				if (data==1){
					printf("Your choice is %d : Turn on led R\n",data);
					ledR_on();
				} else if (data==2){
						printf("Your choice is %d : Turn on led B\n",data);
					  ledB_on();
				} else if (data==3){
						printf("Your choice is %d : Turn on led G\n",data);
					  ledG_on();
				}	else if (data==4){
						printf("Your choice is %d : Turn on the leds \n",data);
					  leds_on();
				} else if (data==5){
						printf("Your choice is %d : Turn off the led or the leds \n",data);
					  led_off();
				}else {
					printf("Unkown Command : Please read the MENU\n");
				}
		}
  }
}
