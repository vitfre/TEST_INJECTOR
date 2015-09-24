/*
 * i2c.c
 *	����� ������� ��� ����������� ���������� I2C
 * Created: 11.02.2014 17:33:24
 *  Author: �������������
 */ 

#include "i2c.h"

/**************************************************************************
*   Function name : i2c_init
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ������������� i2c
****************************************************************************/
void i2c_init(void)
{
	(PORT_I2C&=~(1<<SDA));
	(PORT_I2C&=~(1<<SCL));
	(DDR_I2C&=~(1<<SDA));
	(DDR_I2C&=~(1<<SCL));
	_delay_us(pause);
};
/**************************************************************************
*   Function name : i2c_start
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ����� i2c
****************************************************************************/
void i2c_start(void)         
{ 
	(DDR_I2C|=(1<<SDA)); _delay_us(pause);
	(DDR_I2C|=(1<<SCL)); _delay_us(pause); 
};
/**************************************************************************
*   Function name : i2c_start_wait
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ����� ������ ����������� i2c
****************************************************************************/
void i2c_start_wait (unsigned char addr)
{
	i2c_start();
	i2c_write(addr);
	_delay_us(pause);
};
/**************************************************************************
*   Function name : i2c_write
*   Returns :       ���
*   Parameters :    ������ �� ��������
*   Purpose :       �������� 1�� ����� �� i2c
****************************************************************************/
void i2c_write(unsigned char byt)  
{ 
    unsigned char k;                       
    for (k = 0; k < 8; k++)    
    { 
		(DDR_I2C|=(1<<SCL));
        if(0x01 & (byt >> (7 - k)))
		{
			(DDR_I2C&=~(1<<SDA));
		}else
		{
			(DDR_I2C|=(1<<SDA));
		};
	    _delay_us(pause);   
        (DDR_I2C&=~(1<<SCL));
		_delay_us(pause);             
    };
	(DDR_I2C&=~(1<<SDA));
	(DDR_I2C|=(1<<SCL));
	_delay_us(pause);
	(DDR_I2C&=~(1<<SCL));
	_delay_us(pause);
	(DDR_I2C|=(1<<SCL));
};
/**************************************************************************
*   Function name : i2c_stop
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ���� i2c
****************************************************************************/
void i2c_stop(void)            
{ 
    (DDR_I2C|=(1<<SDA)); _delay_us(pause);   
    (DDR_I2C&=~(1<<SCL)); _delay_us(pause);           
    (DDR_I2C&=~(1<<SDA)); _delay_us(pause);                                 
};
/**************************************************************************
*   Function name : i2c_ack
*   Returns :       ���
*   Parameters :    ���� �����������
*   Purpose :       ������ � ���������� ����� i2c
****************************************************************************/
unsigned char i2c_ack(void)     
{ 
    unsigned char check=0;        
    (DDR_I2C|=(1<<SCL)); 
	(DDR_I2C|=(1<<SDA));
	_delay_us(pause);                   
    /*for (y = 3; y > 0; y--)       
    { 
	    _delay_us(pause_1);                      
        if(bit_is_clear(PIN_I2C_1, SDA_1)) break;//if ((check = SDA) == 0) break; 
    }
    check = PIN_I2C_1 & (1<<SDA_1);
	*/
    (DDR_I2C&=~(1<<SCL));
	_delay_us(pause);
	
	(DDR_I2C&=~(1<<SDA));
	//_delay_us(pause_1);
    return (check);      
};

void i2c_acknowledge(void)
{
	(DDR_I2C&=~(1<<SDA));
	//delayMicroseconds(1);
	(DDR_I2C|=(1<<SCL));
	_delay_us(pause);
	(DDR_I2C&=~(1<<SCL));
	//delayMicroseconds(1);
	//digitalWrite(SDA, LOW);
	//delayMicroseconds(1);
};
/**************************************************************************
*   Function name : i2c_mack
*   Returns :       ���
*   Parameters :    ���� �����������
*   Purpose :       ������ � ���������� ����� i2c
****************************************************************************/
void i2c_mack(void)      
{ 
    DDR_I2C |= _BV(SDA);
    PORT_I2C &= ~ _BV(SDA); _delay_us(pause);   
    PORT_I2C |=  _BV(SCL); _delay_us(pause*2);    
    PORT_I2C &= ~ _BV(SCL); _delay_us(pause);
    DDR_I2C &= ~_BV(SDA);         
};
/**************************************************************************
*   Function name : i2c_nack
*   Returns :       ���
*   Parameters :    ���� �����������
*   Purpose :       ��� ������� � ���������� ����� i2c
****************************************************************************/
void i2c_nack(void)          
{ 
    (DDR_I2C|=(1<<SCL));
    //(DDR_I2C_1|=(1<<SDA_1));
    _delay_us(pause);   
    /*for (y = 3; y > 0; y--)      
    {
        _delay_us(pause_1); 
        if(bit_is_set(PIN_I2C_1,SDA_1)) break; 
    };*/
    (DDR_I2C&=~(1<<SCL));
    _delay_us(pause);
    (DDR_I2C|=(1<<SCL));
    //(DDR_I2C_1&=~(1<<SDA_1)); 
};
/**************************************************************************
*   Function name : i2c_read
*   Returns :       �������� �����e
*   Parameters :    ���
*   Purpose :       ���� 1�� ����� �� i2c
****************************************************************************/
unsigned char i2c_read(void)   
{ 
    unsigned char k, d=0;       
    for (k = 0; k < 8; k++)    
    {
		_delay_us(pause);
        (DDR_I2C&=~(1<<SCL));
		_delay_us(pause);
        d = d << 1; 
        if((((PIN_I2C)>>(SDA))&1)==0x1)
		{
			d |= 0x01;
		}else   
		{
			d &= ~0x01;
		};
        (DDR_I2C|=(1<<SCL)); 
    };
    return d;      
};
/**************************************************************************
*   Function name : i2c_readAck
*   Returns :       �������� ������
*   Parameters :    ���
*   Purpose :       ���� 1�� ����� �� i2c � �������� ����������
****************************************************************************/
unsigned char i2c_readAck(void)
{
	unsigned char d=0;
	d=i2c_read();
	i2c_ack();
	return d;
};
/**************************************************************************
*   Function name : i2c_readAck
*   Returns :       �������� ������
*   Parameters :    ���
*   Purpose :       ���� 1�� ����� �� i2c ��� ������� ����������
****************************************************************************/
unsigned char i2c_readNak(void)
{
	unsigned char d=0;
	d=i2c_read();
	i2c_nack();
	return d;
};
