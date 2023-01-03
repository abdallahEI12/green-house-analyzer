#include "main.h"
int state = 0;
void toggle(void);
DIO_PinCFG main_lcd_pins[]= {
	DIO_PIND_0,
	DIO_PIND_1,
	DIO_PIND_2,
	DIO_PIND_3,
	DIO_PIND_4,
	DIO_PIND_5,
	DIO_PIND_6,
};

int main(void)
{
	EXINTCFG intcfg = {
		EXINT0,
		enabled,
		Falling_Edge
	};
	INT_INIT(intcfg);
	
	_delay_ms(2000);
	LCD_INIT(main_lcd_pins);
	initadc(AVCC,by128);
	
	CLR_LCD(main_lcd_pins);
	while (1)
	{
		intcallback(EXINT0,toggle);
		if (state ==1){
			int_Dhtt(DIO_PINC_1);
			_delay_ms(2000);
		}
		CLR_LCD(main_lcd_pins);
		_delay_ms(5);
		if (state == 0 ){
			soil();
			rain();
			_delay_ms(2000);
		}
		CLR_LCD(main_lcd_pins);
		_delay_ms(5);
	}

}

void toggle(void){
	if (state == 1){
		state = 0;
	}
	else{
		state = 1;
	}
}