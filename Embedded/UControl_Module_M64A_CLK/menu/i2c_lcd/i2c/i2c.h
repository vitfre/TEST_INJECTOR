/*
 * i2c_1.h
 *
 * Created: 11.02.2014 17:33:24
 *  Author: �������������
 */ 


#ifndef I2C_H
#define I2C_H
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
//---------------------------------------------------------------------------------------
#define DDR_I2C  DDRD
#define PORT_I2C PORTD
#define PIN_I2C  PIND
#define SDA      PC0
#define SCL      PC1
#define pause    1
//---------------------------------------------------------------------------------------
/** defines the data direction (reading from I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_READ    1
/** defines the data direction (writing to I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_WRITE   0

/**************************************************************************
*   Function name : i2c_init
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ������������� i2c
****************************************************************************/
void i2c_init(void);
/**************************************************************************
*   Function name : i2c_start
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ����� i2c
****************************************************************************/
void i2c_start(void);
/**************************************************************************
*   Function name : i2c_start_wait
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ����� ������ ����������� i2c
****************************************************************************/
void i2c_start_wait (unsigned char addr);
/**************************************************************************
*   Function name : i2c_write
*   Returns :       ���
*   Parameters :    ������ �� ��������
*   Purpose :       �������� 1�� ����� �� i2c
****************************************************************************/
void i2c_write(unsigned char byt);
/**************************************************************************
*   Function name : i2c_stop
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ���� i2c
****************************************************************************/
void i2c_stop(void);
/**************************************************************************
*   Function name : i2c_ack
*   Returns :       ���
*   Parameters :    ���� �����������
*   Purpose :       ������ � ���������� ����� i2c
****************************************************************************/
unsigned char i2c_ack(void);


void i2c_acknowledge(void);


/**************************************************************************
*   Function name : i2c_mack
*   Returns :       ���
*   Parameters :    ���� �����������
*   Purpose :       ������ � ���������� ����� i2c
****************************************************************************/
void i2c_mack(void);
/**************************************************************************
*   Function name : i2c_nack
*   Returns :       ���
*   Parameters :    ���� �����������
*   Purpose :       ��� ������� � ���������� ����� i2c
****************************************************************************/
void i2c_nack(void);
/**************************************************************************
*   Function name : i2c_read
*   Returns :       �������� �����e
*   Parameters :    ���
*   Purpose :       ���� 1�� ����� �� i2c
****************************************************************************/
unsigned char i2c_read(void);
/**************************************************************************
*   Function name : i2c_readAck
*   Returns :       �������� ������
*   Parameters :    ���
*   Purpose :       ���� 1�� ����� �� i2c � �������� ����������
****************************************************************************/
unsigned char i2c_readAck(void);
/**************************************************************************
*   Function name : i2c_readAck
*   Returns :       �������� ������
*   Parameters :    ���
*   Purpose :       ���� 1�� ����� �� i2c ��� ������� ����������
****************************************************************************/
unsigned char i2c_readNak(void);

#endif /* I2C_H */


