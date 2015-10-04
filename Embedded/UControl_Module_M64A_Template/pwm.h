/*
 * pwm.h
 *
 * Created: 18.09.2015 13:48:10
 *  Author: vmk
 */ 


#ifndef PWM_H_
#define PWM_H_
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
//---------------------------------------------------------------------------------------
#define MASK_PWM 				(1<<pwm_1)|(1<<pwm_2)|(1<<pwm_3)
//---------------------------------------------------------------------------------------
//порт, к которому подключены кнопки
#define PORT_PWM 				PORTB
#define PIN_PWM 				PINB
#define DDRX_PWM 				DDRB
//---------------------------------------------------------------------------------------
//номера выводов, к которым подключены кнопки
#define pwm_1 					5UL
#define pwm_2 					6UL
#define pwm_3					7UL
//---------------------------------------------------------------------------------------
/**************************************************************************
*   Function name : init_pwm
*   Returns :
*   Parameters :
*   Purpose :       Ініціалізаціяу ШИМ
****************************************************************************/
void init_pwm(void)
{
	//---------------------------------------------------------------------------------------
	DDRX_PWM |= (MASK_PWM);
	PORT_PWM &=~ MASK_PWM;
	//---------------------------------------------------------------------------------------
	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: 16000,000 kHz
	// Mode: Fast PWM top=0x03FF
	// OC1A output: Non-Inv.
	// OC1B output: Non-Inv.
	// OC1C output: Non-Inv.
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer1 Overflow Interrupt: Off
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	// Compare C Match Interrupt: Off
	TCCR1A=0xAB;
	TCCR1B=0x09;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;
	OCR1CH=0x00;
	OCR1CL=0x00;
	//---------------------------------------------------------------------------------------
};
/**************************************************************************
*   Function name : stop_pwm
*   Returns :
*   Parameters :
*   Purpose :       Стоп ШИМ
****************************************************************************/
void stop_pwm(void)
{
	//---------------------------------------------------------------------------------------
	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: Timer1 Stopped
	// Mode: Normal top=0xFFFF
	// OC1A output: Discon.
	// OC1B output: Discon.
	// OC1C output: Discon.
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer1 Overflow Interrupt: Off
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	// Compare C Match Interrupt: Off
	TCCR1A=0x00;
	TCCR1B=0x00;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;
	OCR1CH=0x00;
	OCR1CL=0x00;
	//---------------------------------------------------------------------------------------
	DDRX_PWM |= (MASK_PWM);
	PORT_PWM &=~ MASK_PWM;
	//---------------------------------------------------------------------------------------
};

/**************************************************************************
*   Function name : set_pwm
*   Returns :       
*   Parameters :    Значение
*   Purpose :       
****************************************************************************/
void set_pwm(unsigned char chanel, unsigned int val)
{
	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------
	switch (chanel)
	{
		case pwm_1 :
		{
			//---------------------------------------------------------------------------------------
			OCR1A=val ;
			//---------------------------------------------------------------------------------------
		};
		break;
		case pwm_2 :
		{
			//---------------------------------------------------------------------------------------
			OCR1B=val;
			//---------------------------------------------------------------------------------------
		};
		break;
		case pwm_3 :
		{
			//---------------------------------------------------------------------------------------
			OCR1C=val ;
			//---------------------------------------------------------------------------------------
		};
		break;
		default :;
	};   //switch (chanel)
	//---------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------
};


#endif /* PWM_H_ */