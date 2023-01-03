/*
 * dht11.c
 *
 * Created: 12/25/2022 10:44:27 AM
 *  Author: Mina
 */ 
#include "dht11.h"
char c=0,I_RH,D_RH,I_Temp,D_Temp,CheckSum;
DIO_Channel lcd_pins[] = {
	DIO_PIND_0,
	DIO_PIND_1,
	DIO_PIND_2,
	DIO_PIND_3,
	DIO_PIND_4,
	DIO_PIND_5,
	DIO_PIND_6,
};

DIO_Channel DHTpin;


void Requestt()
{	
	DIO_PinCFG dhtpincfg = {DHTpin,OUTPUT};
	DIO_INIT_PIN(dhtpincfg);
	DIOWritePin(DHTpin,LOW);	/* set to low pin */
	_delay_ms(20);			/* wait for 20ms */
	DIOWritePin(DHTpin,HIGH);
}
void Responsee()
{	DIO_PinCFG dhtpincfg = {DHTpin,INPUT};
	DIO_INIT_PIN(dhtpincfg); //make pin input
	while(DIOReadPin(DHTpin));      //wait for dht11 low pulse
	while(DIOReadPin(DHTpin)==0);   //wait for dht11 high pulse
	while(DIOReadPin(DHTpin));      //wait for dht11 low pulse
}

unsigned char Receive_dataa()			//receive data
{	DIO_PinCFG dhtpincfg = {DHTpin,INPUT};
	for (int q=0; q<8; q++)
	{
		while(DIOReadPin(DHTpin) == 0);  // check received bit 0 or 1
		_delay_us(30);
		if(DIOReadPin(DHTpin))           // if high pulse is greater than 30ms
		c = (c<<1)|(0x01);	   // then its logic HIGH
		else			       // otherwise its logic LOW
		c = (c<<1);
		while(DIOReadPin(DHTpin));
	}
	return c;
}
void int_Dhtt (DIO_Channel pin){
	DHTpin = pin;
	char data[5];
	curpos(lcd_pins,1,0);
	LCD_PRINT_STR(lcd_pins,"Humidity =");
	curpos(lcd_pins,2,0);
	LCD_PRINT_STR(lcd_pins,"Temp =");
	Requestt();		           // send start pulse
	Responsee();		       // receive response
	I_RH=Receive_dataa();	   // store first eight bit in I_RH
	D_RH=Receive_dataa();	   // store next eight bit in D_RH
	I_Temp=Receive_dataa();	   // store next eight bit in I_Temp
	D_Temp=Receive_dataa();	   // store next eight bit in D_Temp
	CheckSum=Receive_dataa();  // store next eight bit in CheckSum
	if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
	{
		curpos(lcd_pins,1,0);
		LCD_PRINT_STR(lcd_pins,"Error");
	}
	
	else
	{
		itoa(I_RH,data,10);
		curpos(lcd_pins,1,11);
		LCD_PRINT_STR(lcd_pins,data);
		LCD_PRINT_STR(lcd_pins,".");
		
		itoa(D_RH,data,10);
		LCD_PRINT_STR(lcd_pins,data);
		LCD_PRINT_STR(lcd_pins,"%");

		itoa(I_Temp,data,10);
		curpos(lcd_pins,2,7);
		LCD_PRINT_STR(lcd_pins,data);
		LCD_PRINT_STR(lcd_pins,".");
		
		itoa(D_Temp,data,10);
		LCD_PRINT_STR(lcd_pins,data);
		LCD_PRINT_STR(lcd_pins,"C ");
		curpos(lcd_pins,2,12);
	}
}