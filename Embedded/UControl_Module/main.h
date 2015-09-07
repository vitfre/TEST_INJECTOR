/*
 * main.h
 *
 * Created: 05.09.2015 14:58:48
 *  Author: vmk
 */ 

#ifndef MAIN_H_
#define MAIN_H_
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
#include "menu\menu.h"
#include "buart\buart_1.h"
#include "service\buttons.h"
#include "service\init_mcu.h"
#include "rs485\rs485_0.h"
//---------------------------------------------------------------------------------------
#endif /* MAIN_H_ */