#include <stdio.h>
#include "../inc/leds.h"
 

void  leds_init(void){
		volatile uint32_t myDelay;
		//  Enable the Clock GPIO port F 
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // some delay by reading reg 
    myDelay = SYSCTL_RCGC2_R;

    // Enable the GPIO pin for digital function.    
    GPIO_PORTF_DEN_R = 0x0E; 

    // Set the direction as output for the GPIO pin PF1 and PF2, 
    // Set the direction asinput for the GPIO pin PF4 and PF0
    GPIO_PORTF_DIR_R = 0x0E;
    // turn off the leds 
		GPIO_PORTF_DATA_R |= 0x00;
}

void ledR_on(void){
    // turn on the ledR 
		GPIO_PORTF_DATA_R = 0x02;
}

void ledB_on(void){
    // turn on the ledR 
		GPIO_PORTF_DATA_R = 0x04;
}

void ledG_on(void){
    // turn on the ledR 
		GPIO_PORTF_DATA_R = 0x08;
}

void leds_on(void){
    // turn on the ledR 
		GPIO_PORTF_DATA_R = 0x0E;
}
void led_off(void){
		// turn on the ledR 
		GPIO_PORTF_DATA_R = 0x00;
}

