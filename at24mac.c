#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h> 
#include <unistd.h>

#define I2C_ADDR 0x58
 
int main (void) {
	char buffer[20];
	int fd;
	int i;
	int len;

	fd = open("/dev/i2c-3", O_RDWR);

	if (fd < 0) {
		printf("Open error: %s\n", strerror(errno));
		return 1;
	}

	if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
		printf("ioctl error: %s\n", strerror(errno));
		return 1;
	}

	// EUI-48 value (Datasheet page 8)

	buffer[0]=0x9A;
	if (write(fd, buffer, 1) != 1) {
		printf("Write error: %s\n", strerror(errno));
		return 1;
	}

	if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
		printf("ioctl error: %s\n", strerror(errno));
		return 1;
	}

	len=read(fd, buffer, 16);
	if (len<16) {
		printf("Read error: %s\n", strerror(errno));
		return 1;
	}
	 
	for (i=0;i<6;i++) {
		printf("%02X",buffer[i]);
		if (i<5) 
			printf(":");
	}
	printf("\n");

	usleep(100000);
	close(fd);

	return 0;
}
