#ifndef ADC_H_
#define ADC_H_

void ADCInitialize(){
	// ADC calibration

	ADC1->CR &= ~ADC_CR_ADEN;

	ADC1->CR |= ADC_CR_ADCAL;
	while((ADC1->CR & ADC_CR_ADCAL) != 0){
	}

	// Select a clock source for the ADC

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	RCC->CR2 |= RCC_CR2_HSI14ON;
	while((RCC->CR2 & RCC_CR2_HSI14RDY) == 0){
	}
	ADC1->CFGR2 |= ADC_CFGR2_CKMODE;

	// ADC Enable

	ADC1->CR |= ADC_CR_ADEN;
	while((ADC1 -> ISR& ADC_ISR_ADRDY) == 0){
	}

	ADC1->SMPR |= ADC_SMPR_SMP_0 | ADC_SMPR_SMP_1 | ADC_SMPR_SMP_2;

}

void ADCChannelSelect(int Channel){
	ADC1->CHSELR |= ADC_CHSELR_CHSEL0 << Channel;
}




#endif /* ADC_H_ */
