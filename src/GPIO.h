#ifndef GPIO_H_
#define GPIO_H_

void GPIO_initialize(){
	//Enable the GPIO clock for Pot C using the AHB and RCC
	RCC -> AHBENR |= RCC_AHBENR_GPIOCEN;
	RCC -> AHBENR |= RCC_AHBENR_GPIOBEN;
	//Set control registers for portC pin 6
	//OtypeR
}

void GPIO_PinMode(int Pin, int Mode, int PUPD){
	if(Mode == 0){
		GPIOC -> MODER |= GPIO_MODER_MODER0_0 << 2*Pin;
		GPIOC -> MODER &= ~(GPIO_MODER_MODER0_1 << 2*Pin);
		GPIOC -> OTYPER &= ~(GPIO_OTYPER_OT_0 << Pin);
		GPIOC -> OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0 << 2*Pin;
		switch(PUPD){
		//No Pull-Up/Pull-Down
		case 0:
			GPIOC -> PUPDR &= ~(GPIO_PUPDR_PUPDR0 << 2*Pin);
		break;
		//Pull-Up
		case 1:

		break;
		//Pull-Down
		case 2:
		break;
		//Reversed
		case 3:
		break;
		}
	}else if(Mode == 1){
		GPIOB -> MODER &= ~(GPIO_MODER_MODER1);
		GPIOB -> MODER &= ~(GPIO_PUPDR_PUPDR6);
	}

}

void GPIO_Set(int Pin){
	GPIOC -> BSRR |= GPIO_BSRR_BS_0 << Pin;
}

void GPIO_Reset(int Pin){
	GPIOC ->BRR |= GPIO_BRR_BR_0 << Pin;
}


#endif /* GPIO_H_ */
