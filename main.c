#include "stm32f401xc.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    
    GPIOA->MODER &= ~GPIO_MODER_MODER5;
    GPIOA->MODER |= GPIO_MODER_MODER5_0;
    
    while(1) {
        GPIOA->BSRR = GPIO_BSRR_BS5;    
        for(int i=0; i<1000000; i++);  
        GPIOA->BSRR = GPIO_BSRR_BR5;  
        for(int i=0; i<1000000; i++);  
    }
}

void NMI_Handler(void) {}
void HardFault_Handler(void) { while(1); }
void SysTick_Handler(void) {}