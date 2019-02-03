/* Includes */
#include "stm32f0xx.h"
#include "ADC.h"
#include "GPIO.h"
#include <stdlib.h>

int SI = 6;
int CLK = 7;


int clearRegister();

void waitForAMoment(int Moment){
	volatile int j;
	for(int i = 0; i < Moment;i++){
		j++;
	}
}

int main(void)
{
	volatile int pixels = 0;
	volatile float voltage = 0;
	GPIO_initialize();
	GPIO_PinMode(SI,0,0);
	GPIO_PinMode(CLK,0,0);
	ADCInitialize();
	ADCChannelSelect(1);
	while (1){
		clearRegister();
		GPIO_Set(SI);
		GPIO_Set(CLK);
		GPIO_Reset(SI);
		GPIO_Reset(CLK);
		for(int i = 0; i < 128; i++){
			ADC1 -> CR |= ADC_CR_ADSTART;
			while((ADC1->ISR & ADC_ISR_EOC) == 0){
			}
			pixels = ADC1->DR;
			voltage = pixels*3.3/4096;
			GPIO_Set(CLK);
			GPIO_Reset(CLK);
		}
	}
}

int clearRegister(){
	GPIO_Set(SI);
	GPIO_Set(CLK);
	GPIO_Reset(SI);
	GPIO_Reset(CLK);
	for(int i = 0; i < 128; i++){
		GPIO_Set(CLK);
		GPIO_Reset(CLK);
	}
}
