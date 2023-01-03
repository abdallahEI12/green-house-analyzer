/*
 * rain.c
 *
 * Created: 12/25/2022 10:40:20 AM
 *  Author: Mina
 */ 
#include "rain.h"
DIO_Channel rain_lcd_pins[] = {
	DIO_PIND_0,
	DIO_PIND_1,
	DIO_PIND_2,
	DIO_PIND_3,
	DIO_PIND_4,
	DIO_PIND_5,
	DIO_PIND_6,
};
DIO_PinCFG rspin = {DIO_PINC_0,INPUT};

void rain(void){
	DIO_INIT_PIN(rspin);
	curpos(rain_lcd_pins,2,0);
	LCD_PRINT_STR(rain_lcd_pins,"Rain:");
	if (DIOReadPin(DIO_PINC_0)==1){
		curpos(rain_lcd_pins,2,6);
		LCD_PRINT_STR(rain_lcd_pins,"Raining");
		}
	else{
		curpos(rain_lcd_pins,2,6);
		LCD_PRINT_STR(rain_lcd_pins,"No Rain");
	}
}