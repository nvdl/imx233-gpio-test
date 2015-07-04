#include "gpio-mmap.h"

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

int *gpioMapPtr = NULL;

int gpioMap(void) {

	int fd;

	if (gpioMapPtr != NULL) return -1;

	fd = open("/dev/mem", O_RDWR);
	assert(fd != -1);

	gpioMapPtr = (int*) mmap(NULL, GPIO_MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);

	assert(gpioMapPtr != NULL);
	assert(close(fd) != -1);

	return 0;
}

int gpioUnmap(void) {

	int rc;

	rc = munmap(gpioMapPtr, GPIO_MAP_SIZE);
	assert(rc == 0);
}

void gpioSetOutput(int bank, int pin) {

	assert(gpioMapPtr != NULL);
	gpioMapPtr[0x1C1 + (bank * 4)] = 1 << pin;
}

void gpioSetInput(int bank, int pin) {

	assert(gpioMapPtr != NULL);
	gpioMapPtr[0x1C2 + (bank * 4)] = 1 << pin;
}

/*int gpioRead(long offset) {

	assert(gpioMapPtr != NULL);
	return gpioMapPtr[offset / 4];
}

void gpioWrite(long offset, long value) {

	assert(gpioMapPtr != NULL);
	gpioMapPtr[offset / 4] = value;
}*/
