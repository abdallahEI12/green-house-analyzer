
/*
 * soil.c
 *
 * Created: 12/25/2022 10:29:53 AM
 *  Author: Mina
 */ 
#include "soil.h"
DIO_Channel soil_lcd_pins[] = {
	DIO_PIND_0,
	DIO_PIND_1,
	DIO_PIND_2,
	DIO_PIND_3,
	DIO_PIND_4,
	DIO_PIND_5,
	DIO_PIND_6,
};
void soil(void){
	unsigned short int adc_value;
	float moisture;
	char array[10];
	adc_value = readadc(adc_channel_0);
	moisture = 100-(adc_value*100.00)/1023.00;
	curpos(soil_lcd_pins,1,0);
	LCD_PRINT_STR(soil_lcd_pins ,"Moisture:");
	dtostrf(moisture,3,2,array);  //turn float to string dtostrf(float_value, min_width, num_digits_after_decimal, where_to_store_string)
	strcat(array,"%   ");  //join to string
	curpos(soil_lcd_pins,1,10);
	LCD_PRINT_STR(soil_lcd_pins ,array);
	memset(array,0,10); //fill block of memory
}
