#include "gpio-mmap.h"

#include <stdio.h>
#include <unistd.h>

int main() {

	gpioMap();

	gpioSetOutput(2, 1); // GPIO65 (bank 2, bit 1); the on-board green LED

	while (1) {
		printf("LED on\n");
		GPIO_WRITE_PIN(65, 1);
		usleep(100000);

		printf("LED off\n");
		GPIO_WRITE_PIN(65, 0);
		usleep(100000);
	}
}
