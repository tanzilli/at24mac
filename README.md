# AT24MAC

Utility to read the MAC address from a Microchip AT24MAC400 chip

* at24mac    Read the unique EUI-48 mac address (i.e. FC:C2:3D:0D:A6:EB)
* at24serial Read the unique 128 bit Serial number (i.e. 0A70080064100460746CA000A0000000)

## To cross compile for Acme Systems Acqua board

	arm-linux-gnueabihf-gcc at24mac.c -o at24mac 
	arm-linux-gnueabihf-gcc at24serial.c -o at24serial 

## Execute

	sudo ./at24mac
	FC:C2:3D:0D:A6:EB

	sudo ./at24serial
	0A70080064100460746CA000A0000000

## Device tree

This is the device tree binding to enable the bitbanging internal I2C
serial port to have access to the AT24MAC400 chip available on the Acqua A5
board:

	i2c3@ {
		compatible = "i2c-gpio";
		gpios = <&pioE 1 0 /* SDA */
				 &pioE 2 0 /* SCK */
				>;
		i2c-gpio,delay-us = <4>;    /* ~178 kHz */
		#address-cells = <1>;
		#size-cells = <0>;
	};

## Links

* <https://www.acmesystems.it/acqua_at24mac402>

