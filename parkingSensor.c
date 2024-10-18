 /******************************************************************************
 * parkingSensor.c
 *
 *  Created on: Oct 13, 2024
 *      Author: Malak
 *******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include "buzzer.h"
#include "icu.h"
#include "lcd.h"
#include "led.h"
#include "ultrasonic.h"

int main(void)
{
	 SREG |= (1<<7);		/* Enable I-bit */

	/* Drivers initialization */
	BUZZER_init();
	LCD_init();
	LEDS_init();
	Ultrasonic_init();

	LCD_displayString("Distance =   cm");

	uint16 distance = 0;

	while(1)
	{
		distance = Ultrasonic_readDistance();		/* Get the distance */

		LCD_moveCursor(0,11);
		if(distance<10){
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
		else LCD_intgerToString(distance);

		if (distance > 20)
		{
			LED_off(RED_LED_ID);
			LED_off(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);

			BUZZER_off();
		}
		else if(distance <= 20 && distance >= 16)
		{
			LED_on(RED_LED_ID);
			LED_off(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);

			BUZZER_off();
		}
		else if(distance <= 15 && distance >= 11)
		{
			LED_on(RED_LED_ID);
			LED_on(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);

			BUZZER_off();
		}
		else if(distance <= 10 && distance >= 6)
		{
			LED_on(RED_LED_ID);
			LED_on(GREEN_LED_ID);
			LED_on(BLUE_LED_ID);

			BUZZER_off();
		}
		else
		{
			while(distance<=5)
			{
				_delay_ms(1);
				distance = Ultrasonic_readDistance();
				LCD_moveCursor(0,11);
				LCD_intgerToString(distance);

				LCD_moveCursor(1,6);
				LCD_displayString("Stop");

				LED_on(RED_LED_ID);
				LED_on(GREEN_LED_ID);
				LED_on(BLUE_LED_ID);
				BUZZER_on();

				_delay_ms(300);

				LED_off(RED_LED_ID);
				LED_off(GREEN_LED_ID);
				LED_off(BLUE_LED_ID);

				BUZZER_off();

				_delay_ms(300);
			}
			LCD_moveCursor(1,6);
			LCD_displayString("    ");
		}
	}
}


