#ifndef _GPIO_MMAP_
#define _GPIO_MMAP_

extern int *gpioMapPtr;

int gpioMap(void);
int gpioUnmap(void);
void gpioSetOutput(int bank, int pin);
void gpioSetInput(int bank, int pin);
//int gpioRead(long offset);
//void gpioWrite(long offset, long value);

#define GPIO_BASE												0x80018000

#define GPIO_WRITE_PIN(gpio, value)			GPIO_WRITE((gpio) >> 5, (gpio) & 31, value)
#define GPIO_WRITE(bank, pin, value)			(gpioMapPtr[0x140 + ((bank) << 2) + ((value) ? 1 : 2)] = 1 << (pin))
#define GPIO_READ_PIN(gpio)							GPIO_READ((gpio) >> 5, (gpio) & 31)
#define GPIO_READ(bank, pin)							((gpioMapPtr[0x180 + ((bank) << 2)] >> (pin)) & 1)

#define GPIO_MAP_SIZE										0xfff

#endif
