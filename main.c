/*
 * main.c
 *
 *  Created on: 21 wrz 2017
 *      Author: filip
 */
#include "inc/stm32f100xb.h"
#include "gpio/gpio.h"

int main(void){



	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;
//
//	GPIOC->CRH &= ~GPIO_CRH_CNF9_0;	//output PP
//	GPIOC->CRH |= GPIO_CRH_MODE9_1; //maks f 2MHz
//
//	GPIOC->CRH &= ~GPIO_CRH_CNF8_0;
//	GPIOC->CRH |= GPIO_CRH_MODE8_1;P
//
//	uint32_t reg32;
//
//	GPIOC->LCKR = GPIO_LCKR_LCKK | GPIO_LCKR_LCK8;
//	GPIOC->LCKR = GPIO_LCKR_LCK8;
//	GPIOC->LCKR = GPIO_LCKR_LCKK | GPIO_LCKR_LCK8;
//
//	reg32 = GPIOC->LCKR;
//	//reg32 = GPIOC->LCKR;


	TIM1->ARR = 999;	//podzielenie f
	TIM1->PSC = 3999;	//prescaler
	TIM1->CR1 = TIM_CR1_CEN;	//wlaczenie licznika
	TIM1->DIER = TIM_DIER_UIE;	//wlaczenie przerwan od update
	TIM1->CR1 |= TIM_CR1_DIR;

	gpio_pin_cfg(GPIOC, PC8, gpio_mode_output_PP_2MHz);
	gpio_pin_cfg(GPIOC, PC9, gpio_mode_output_PP_2MHz);

	gpio_pin_cfg(GPIOA, PA0, gpio_mode_input_floating);		//pull down na plytce do PA0
	gpio_pin_cfg(GPIOC, PC13, gpio_mode_input_pull);

	GPIOC->ODR |= GPIO_ODR_ODR13;		//pull up

	AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PA;	//podpi�cie przerwania EXTI0 do portu a

	AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PC;	//podpiecie przerwania exti13 do portu c

	EXTI->IMR |= EXTI_IMR_MR0;					//wlaczenie przerwan id exti0
	EXTI->RTSR |= EXTI_RTSR_TR0;					//przerwanie od narastania rising

	EXTI->IMR |= EXTI_IMR_MR13;				//wlaczenie przerwan od exti143
	EXTI->FTSR |= EXTI_FTSR_TR13;			//przerwanie od opadania falling exti13

	__NVIC_EnableIRQ(EXTI0_IRQn);			//wlaczenie globalnych przerwan od exti0

	__NVIC_EnableIRQ(EXTI15_10_IRQn);		//wlaczenie globalnych przerwan od ext15_10

	__NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);


	uint8_t ala;

	
	

	SysTick_Config(4000000);


while(1){

//		GPIOC->ODR |= GPIO_ODR_ODR9;
//		GPIOC->ODR |= GPIO_ODR_ODR8;
//		for(uint32_t i = 1000000; i; i--);
//		GPIOC->ODR &= ~GPIO_ODR_ODR9;
//		GPIOC->ODR &= ~GPIO_ODR_ODR8;
//		for(uint32_t i = 1000000; i; i--);


//		if( GPIOA->IDR & PA0){
//			GPIOC->ODR |= GPIO_ODR_ODR9;
//			GPIOC->BSRR = GPIO_BSRR_BR8;
//
//		} else {
//			GPIOC->ODR &= ~GPIO_ODR_ODR9;
//			GPIOC->BSRR = GPIO_BSRR_BS8;
//		}




	}


}

__attribute__((interrupt)) void SysTick_Handler(void){
				//GPIOC->ODR ^= GPIO_ODR_ODR9;

}


__attribute__((interrupt)) void EXTI0_IRQHandler(void){
	if(EXTI->PR & EXTI_PR_PR0){		//sprawdzenie od czego przerwanie czy na pewno od exti0
		EXTI->PR = EXTI_PR_PR0;		//kasowanie flagi
		GPIOC->ODR ^= GPIO_ODR_ODR8;
	}
}

__attribute__((interrupt)) void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & EXTI_PR_PR13){
		EXTI->PR = EXTI_PR_PR13;
		GPIOC->ODR ^= GPIO_ODR_ODR8;

	}
}


__attribute__((interrupt)) void TIM1_UP_TIM16_IRQHandler(void){
	if(TIM1->SR & TIM_SR_UIF){
		TIM1->SR = ~TIM_SR_UIF;

		GPIOC->ODR ^= GPIO_ODR_ODR9;
	}
}
