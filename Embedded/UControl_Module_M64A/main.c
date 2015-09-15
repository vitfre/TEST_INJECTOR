/*
 * main.c
 *
 * Created: 01.09.2015 11:47:42
 *  Author: vmk
 */ 

#include "main.h"

int main(void)
{
	//---------------------------------------------------------------------------------------
	// Declare your local variables here
	unsigned char cnt = 0;
	//---------------------------------------------------------------------------------------
	init_mcu();
	//---------------------------------------------------------------------------------------
	rs485_0_init();
	uart_1_init();
	i2c_lcd_init();
	BUT_Init();
	_delay_ms(10);
	//---------------------------------------------------------------------------------------
	asm("sei");
	//---------------------------------------------------------------------------------------
    while(1)
    {
        //TODO:: Please write your application code
		SET_OUT_1
		CLR_OUT_1
		SET_OUT_2
		CLR_OUT_2
		SET_OUT_3
		CLR_OUT_3
		SET_OUT_4
		CLR_OUT_4
		
		SET_OUT_5
		CLR_OUT_5
		SET_OUT_6
		CLR_OUT_6
		SET_OUT_7
		CLR_OUT_7
		SET_OUT_8
		CLR_OUT_8
		
		SET_OUT_9
		CLR_OUT_9
		SET_OUT_10
		CLR_OUT_10
		SET_OUT_11
		CLR_OUT_11
		SET_OUT_12
		CLR_OUT_12
		
		
// 		Main_menu_i2c (cnt);
 		rs485_0_write (cnt);
// 		uart_1_write (cnt);
 		_delay_ms(100);
 		cnt++;
    }
}