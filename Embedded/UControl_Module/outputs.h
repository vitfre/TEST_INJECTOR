/*
 * outputs.h
 *
 * Created: 07.09.2015 17:22:20
 *  Author: vmk
 */ 

#include "bits_macros.h"

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

#define SET_OUT_1       (PORTB|=(1<<3));
#define CLR_OUT_1       (PORTB&=~(1<<3));
#define SET_OUT_2       (PORTB|=(1<<4));
#define CLR_OUT_2       (PORTB&=~(1<<4));
#define SET_OUT_3       (PORTB|=(1<<5));
#define CLR_OUT_3       (PORTB&=~(1<<5));
#define SET_OUT_4       (PORTB|=(1<<6));
#define CLR_OUT_4       (PORTB&=~(1<<6));
#define SET_OUT_5       (PORTB|=(1<<7));
#define CLR_OUT_5       (PORTB&=~(1<<7));

#define SET_OUT_6       (PORTG|=(1<<3));
#define CLR_OUT_6       (PORTG&=~(1<<3));
#define SET_OUT_7       (PORTG|=(1<<4));
#define CLR_OUT_7       (PORTG&=~(1<<4));

#define SET_OUT_8       (PORTC|=(1<<7));
#define CLR_OUT_8       (PORTC&=~(1<<7));

#define SET_OUT_9       (PORTD|=(1<<7));
#define CLR_OUT_9       (PORTD&=~(1<<7));

#define SET_OUT_10      (PORTA|=(1<<0));
#define CLR_OUT_10      (PORTA&=~(1<<0));

#define SET_OUT_11       (PORTD|=(1<<5));
#define CLR_OUT_11       (PORTD&=~(1<<5));

#define SET_OUT_12       (PORTF|=(1<<4));
#define CLR_OUT_12       (PORTF&=~(1<<4));

#endif /* OUTPUTS_H_ */