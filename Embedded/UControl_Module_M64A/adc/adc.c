/*
 * adc.c
 *
 * Created: 18.10.2013 12:20:42
 *  Author: vmk
 */

#include "adc.h"


/**************************************************************************
*   Function name : init_adc
*   Returns :       
*   Parameters :    
*   Purpose :       Ініціалізаціяу АЦП
****************************************************************************/
void init_adc(void)
{
	// ADC initialization
	// ADC Clock frequency: 500,000 kHz
	// ADC Voltage Reference: AREF pin
	ADMUX=ADC_VREF_TYPE & 0xff;
	ADCSRA=0x85;
};
/**************************************************************************
*   Function name : read_adc
*   Returns :       Результати оцифровки
*   Parameters :    Канал АЦП
*   Purpose :       Оцифровка по указаному каналу АЦП
****************************************************************************/
unsigned int read_adc(unsigned char adc_input)
{
	unsigned int ADC_RESULT;
	ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
	// Delay needed for the stabilization of the ADC input voltage
	_delay_us(20);//_delay_us(10);
	// Start the AD conversion
	ADCSRA|=0x40;
	// Wait for the AD conversion to complete
	while ((ADCSRA & 0x10)==0);
	ADCSRA|=0x10;
	ADC_RESULT=ADCL;
	ADC_RESULT=ADC_RESULT+(ADCH<<8);
	return ADC_RESULT;
};
/**************************************************************************
*   Function name : rd_adc
*   Returns :       Результати оцифровки
*   Parameters :    Канал АЦП
*   Purpose :       Оцифровка по указаному каналу і розрахунок середнього арифметичного з 4х вимірів по указаному каналу АЦП
****************************************************************************/
unsigned int get_average_adc(unsigned char adc_input)
{
	unsigned int temp_adc = 0;
	//_delay_us(500);
	temp_adc=read_adc(adc_input);
	_delay_us(10);//_delay_us(50);
	temp_adc=temp_adc + read_adc(adc_input);
	_delay_us(10);//_delay_us(50);
	temp_adc=temp_adc + read_adc(adc_input);
	_delay_us(10);//_delay_us(50);
	temp_adc=temp_adc + read_adc(adc_input);
	temp_adc=temp_adc>>2;
	return temp_adc;
};
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************