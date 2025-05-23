#define RCC_BASE 0x4002100
#define GPIOC_BASE 0x40011000
#define DELAY 200000
#define TIM2_BASE 0x40000000

#define RCC_APB1ENR *(volatile unsigned int *)(RCC_BASE + 0x1c)
#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE + 0x18)
#define GPIOC_CRH *(volatile unsigned int *)(GPIOC_BASE + 0x04)
#define GPIOC_ODR *(volatile unsigned int *)(GPIOC_BASE + 0x0C)
#define GPIOC_BSRR *(volatile unsigned int *)(GPIOC_BASE + 0x10)

#define TIM2PSC *(volatile unsigned int *)(TIM2_BASE + 0x28)
#define TIM2_ARR *(volatile unsigned int *)(TIM2_BASE + 0x2C)
#define TIM2_CR1 *(volatile unsigned int *)(TIM2_BASE + 0x00)
#define TIM2_SR *(volatile unsigned int *)(TIM2_BASE + 0x10)

int main() {
	RCC_APB2ENR |= (1u << 4);
	GPIOC_CRH &= ~(0xF << 20);
	GPIOC_CRH &= ~(1u << 20);
	GPIOC_CRH |= ~(1u << 21);
	GPIOC_CRH &= ~(1u << 22);
	GPIOC_CRH &= ~(1u << 23);

	RCC_APB1ENR |= (1u << 0);
	TIM2_PSC = 7999;
	TIM2_ARR = 999;
	TIM2_CR1 |= (1u << 0);

	while (1) {
		if (TIM2_SR & (1u << 0)) {
			TIM2_SR &= ~(1u << 0);
			GPIOC_ODR ^= (1u << 13);
		}
	}
}
