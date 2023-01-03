/*
 * main.h
 *
 * Created: 1/2/2023 11:55:07 PM
 *  Author: bedoa
 */ 


#ifndef MAIN_H_
#define MAIN_H_
#define  F_CPU 16000000UL
#include <avr/io.h>

#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_CONFIG.h"
#include "MCAL/DIO/DIO_TYPES.h"

#include "MCAL/ADC/ADC.h"
#include "MCAL/EXINT/EXINT.h"

#include "HAL/DHT11/dht11.h"
#include "HAL/MS/soil.h"
#include "HAL/RS/rain.h"
#include "HAL/LCD/LCD.h"
#endif /* MAIN_H_ */