#define GPIOC_BASE 0x40011000
#define RCC_BASE 0x40021000

#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE + 0x18)

int main() {
	APB2ENR |= (1u << 4);

	return 0;
}
