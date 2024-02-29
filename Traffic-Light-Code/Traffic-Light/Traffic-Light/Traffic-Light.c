#include <avr/io.h>
#include <avr/interrupt.h>

#include "BUZZER.h"
#include "LED.h"
#include "TIMER.h"
#include "BUTTON.h"
#include "seven segment.h"

#define F_CPU               8000000UL
#define RedLed              'D' , 5
#define YellowLed           'D' , 6
#define GreenLed            'D' , 7

volatile signed char seconds = 60;
volatile unsigned char ten_msecond = 0;
volatile unsigned char mpx = 0;
volatile unsigned char buz_on = 0;

int main(void)
{
	timer0_CTC_init_interrupt();
	BUTTON_vInit('B' , 5);
	LED_vInit('D' , 5);
	LED_vInit('D' , 6);
	LED_vInit('D' , 7);
	BUZZER_vInit('C' , 0);
	DIO_vsetPINDir('B' , 0 , 1);
	DIO_vsetPINDir('B' , 1 , 1);
	
    while(1)
    {
	    unsigned char second = (seconds - 1)%30 + 1;
		
		if(mpx == 0){
			DIO_write('B' , 0 , 0);
			DIO_write('B' , 1 , 1);
			seven_seg_write('A' ,second%10 , 0);
		}
		else{
			DIO_write('B' , 0 , 1);
			DIO_write('B' , 1 , 0);
			seven_seg_write('A' , second/10 , 0);
		}
		
		
        if(BUTTON_u8read('B' , 5) == 0){
			buz_on = (1 - buz_on);
			while(BUTTON_u8read('B' , 5) == 0);
		}
		else{
			buz_on = buz_on;
		}			
		
		
		if(buz_on == 1){
			BUZZER_vTurnOn('C' , 0);
		}
		else{
			BUZZER_vTurnOff('C' , 0);
			
			if(ten_msecond >= 100){
				seconds--;
				ten_msecond = 0;
				
				if(seconds <= 0){
					seconds = 60;
				}
				else{}
			}
			else{}
				
				
			if(seconds >= 36 && seconds <= 60){
				LED_vTurnOn(RedLed);
				LED_vTurnOff(YellowLed);
				LED_vTurnOff(GreenLed);
			}
			else if((seconds >= 31 && seconds <= 35)){
				LED_vTurnOn(RedLed);
				LED_vTurnOn(YellowLed);
				LED_vTurnOff(GreenLed);
			}
			else if(seconds >= 6 && seconds <= 30){
				LED_vTurnOn(GreenLed);
				LED_vTurnOff(RedLed);
				LED_vTurnOff(YellowLed);
			}
			else if(seconds >= 1 && seconds <= 5){
				LED_vTurnOn(GreenLed);
				LED_vTurnOn(YellowLed);
				LED_vTurnOff(RedLed);
			}
		}				
    }
}

ISR(TIMER0_COMP_vect)
{
	if(buz_on == 0){
	  ten_msecond++;
	}	  
	mpx = (1 - mpx);	
}