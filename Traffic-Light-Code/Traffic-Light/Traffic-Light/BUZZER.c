#include "DIO.h"

void BUZZER_vInit(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,1);//Set the given pin in the given port as an output
}

void BUZZER_vTurnOn(unsigned char portname,unsigned char pinnumber)
{
	DIO_write(portname,pinnumber,1);//Set the given pin in the given port to one(on)
}

void BUZZER_vTurnOff(unsigned char portname,unsigned char pinnumber)
{
	DIO_write(portname,pinnumber,0);//Set the given pin in the given port to zero(off)
}

void BUZZER_vToggle(unsigned char portname,unsigned char pinnumber)
{
	DIO_toggle(portname,pinnumber);//Set the given pin in the given port to zero if it is one or set it to one if it is zero
}

unsigned char BUZZER_ReadStatues(unsigned char portname,unsigned char pinnumber){
	return DIO_u8read(portname , pinnumber);
}

 
