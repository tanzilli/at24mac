# AT24MAC

Utility to read the MAC address from a Microchip AT24MAC400 chip

* at24mac    Read the unique EUI-48 mac address (i.e. FC:C2:3D:0D:A6:EB)
* at24serial Read the unique 126 bit Serial number (i.e. 0A70080064100460746CA000A0000000)

## To cross compile for Acme Systems Acqua board

	arm-linux-gnueabihf-gcc at24mac.c -o at24mac 
	arm-linux-gnueabihf-gcc at24serial.c -o at24mac 

## Execute

	sudo ./at24mac
	FC:C2:3D:0D:A6:EB

	sudo ./at24serial
	0A70080064100460746CA000A0000000

## Links

* <https://www.acmesystems.it/acqua_at24mac402>

