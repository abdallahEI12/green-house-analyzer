/*
 * dht11.h
 *
 * Created: 12/25/2022 10:44:59 AM
 *  Author: Mina
 */ 


#ifndef DHT11_H_
#define DHT11_H_
#define  F_CPU 16000000UL
#include <stdlib.h>
#include <util/delay.h>

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CONFIG.h"
#include "../../MCAL/DIO/DIO_TYPES.h"
#include "../LCD/LCD.h"


void int_Dhtt (DIO_Channel pin);



#endif /* DHT11_H_ */