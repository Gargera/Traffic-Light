#ifndef BUZZER_H_
#define BUZZER_H_

/*
	Function Name        : BUZZER_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Initialize the pin as an output pin to connect the BUZZER.
*/
void BUZZER_vInit(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : BUZZER_vTurnOn
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Turn on the BUZZER connected to the given pin and port.
*/
void BUZZER_vTurnOn(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : BUZZER_vTurnOff
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Turn off the BUZZER connected to the given pin and port.
*/
void BUZZER_vTurnOff(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : BUZZER_vToggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Toggle the BUZZER connected to the given pin and port.
*/
void BUZZER_vToggle(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : BUZZER_ReadStatues
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/

unsigned char BUZZER_ReadStatues(unsigned char portname,unsigned char pinnumber);

#endif /* BUZZER_H_ */