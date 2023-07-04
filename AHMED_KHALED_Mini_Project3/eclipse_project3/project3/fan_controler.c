/*
 ================================================================================================
 Name        : fan_control
 Author      : Ahmed Khaled
 Description :
 Date        : 6/26/2023
 ================================================================================================
 */
#include "lcd.h"
#include "common_macros.h"
#include "lm35_sensor.h"
#include "dc.h"
#include "adc.h"
uint8 temprature=0;


int main(void)
{
	ADC_ConfigType* ADC_ptr;
	ADC_ConfigType ADC_str;
	ADC_ptr=&ADC_str;
	ADC_ptr->prescaler=prescaler_8;
	ADC_ptr->volt_selct=internal_2And_Half;
	ADC_init(ADC_ptr);
	LCD_init();
	DcMotor_Init();
	LCD_moveCursor(0,0);
	LCD_displayString("TEMP =     C");
	LCD_moveCursor(1,0);
	LCD_displayString("FAN IS     ");
while(1)
{

	temprature=LM35_getTemperature();
	LCD_moveCursor(0,7);
	LCD_intgerToString(temprature);
	LCD_displayString(" ");
	if(temprature>=120)
	{
		LCD_moveCursor(1,7);
		LCD_displayString("ON");
		DcMotor_Rotate(CW, 100);

	}
	else if(temprature>=90)
	{

		LCD_moveCursor(1,7);
		LCD_displayString("ON");
		DcMotor_Rotate(CW, 75);
	}
	else if(temprature>=60)
	{
		LCD_moveCursor(1,7);
		LCD_displayString("ON");
		DcMotor_Rotate(CW, 50);
	}
	else if(temprature>=30)
	{
		LCD_moveCursor(1,7);
		LCD_displayString("ON");
		DcMotor_Rotate(CW, 25);
	}
	else {
		LCD_moveCursor(1 ,7);
		LCD_displayString("OFF");
		DcMotor_Rotate(CW, 0);
	}
	LCD_displayString(" ");

}
}
