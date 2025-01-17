/*
 * i2c_lcd.h
 *
 * Created: 28.07.2015 18:49:58
 *  Author: vmk
 */ 


#ifndef I2C_LCD_H_
#define I2C_LCD_H_
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
//---------------------------------------------------------------------------------------
#include "i2c/i2c.h"
//---------------------------------------------------------------------------------------
#define PCF8574_ADDR 0x4E //device address		//#define PCF8574_ADDR (0x27<<1) //device address
//---------------------------------------------------------------------------------------
//#define ATcommand	0x4  //LCD command   EN=1 ; RS=0      0000  0001
//#define ATdata		0x5  //LCD data      EN=1 ; RS=1      0000  0101

#define lcd_kom		0UL
#define lcd_sym		1UL

//#define On_leds		0x08  //
//#define Of_leds		0x00  //



#define RS_H		0x02  //
#define RS_L		0x00  //

#define RW_H		0x04  //
#define RW_L		0x00  //

#define E_H			0x08  //
#define E_L			0x00  //
//---------------------------------------------------------------------------------------
//****************************************************************************************
//****************************************************************************************
void PCF8574_Write(unsigned char data);
//****************************************************************************************
unsigned char PCF8574_Read(void);
//***************************************************************************************
//Procedure sending LCD byte
//Input: Byte, Kommand/Symbol data
//***************************************************************************************
void send_i2c_lcd_byte(unsigned char lcd_data, unsigned char rs_status );
/**************************************************************************
*   Function name : i2c_lcd_init
*   Returns :       ������������ lcd
*   Parameters :
*   Purpose :       ���������� i2c_lcd
****************************************************************************/
void i2c_lcd_init(void);

//***************************************************************************************
//Procedure sending LCD symbol
//Input: Symbol
//***************************************************************************************
void send_i2c_lcd_symbol(unsigned char temp_symbol);
//***************************************************************************************
//Procedure setting LCD position
//Input: Line(1,2), Position(1..16)
//***************************************************************************************
void set_i2c_lcd_position(unsigned char temp_line, unsigned char temp_pos);
//***************************************************************************************
//Procedure send symbol string to LCD
//Input: Symbol string
//***************************************************************************************
void send_i2c_lcd_string(const char *temp_string);
//***************************************************************************************
//Procedure send symbol string to LCD from FLASH
//Input: Symbol string
//***************************************************************************************
void send_i2c_lcd_string_P(const char *string);
//***************************************************************************************
//��������� ������ �� ���������  16 ��������
//�������� ��� �������, ����� � ����� � ���� ('A',0x55)
//***************************************************************************************
void send_i2c_lcd_code_string(char s1,char s2,char s3,char s4,char s5,char s6,char s7,char s8,char s9,char s10,char s11,char s12,char s13,char s14,char s15,char s16);
//***************************************************************************************
//Procedure clearing LCD
//***************************************************************************************
void clear_i2c_lcd(void);
//***************************************************************************************
//Procedure detecting symbol
//Input: Digit,
//Output: Symbol
//***************************************************************************************
unsigned char detect_i2c_symbol(unsigned char temp_det_sym);
//***************************************************************************************
//������� �� ��������� 1 �����
//***************************************************************************************
void detect_i2c_shortt_string(unsigned char temp_volt);
//***************************************************************************************
//������� �� ��������� �������� ������ �� 2-� ����
//***************************************************************************************
void detect_i2c_short_string(unsigned char temp_volt);
//***************************************************************************************
//������� �� ��������� �������� ������ �� 3-� ����
//***************************************************************************************
void detect_i2c_short_3_string(unsigned int temp_volt);
//***************************************************************************************
//������� �� ��������� �������� ������ �� 4-� ����
//***************************************************************************************
void detect_i2c_string(unsigned int temp_volt);
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************


#endif /* I2C_LCD_H_ */