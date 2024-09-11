/*
 * Lab4_C_Code.c
 *
 * Created: 13/02/1402 07:56:54 ب.ظ
 * Author : asus
 */ 

#include <avr/io.h>
#include <stdbool.h>

int digit_count = 1;

char number[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

unsigned int hour2 = 0;
unsigned int hour1 = 0;

unsigned int min2 = 0;
unsigned int min1 = 9;

unsigned int sec2 = 0;
unsigned int sec1 = 9;



void delay_ms(int time)
{
	digit_count = digit_count + 1;
	
	if (digit_count == 7)
		digit_count = 1;
	
	
	bool end_9_seconds = (sec1 == 9);
	bool end_59_seconds = (sec1 == 9 && sec2 == 5);

	bool end_9_minutes = (sec1 == 9 && sec2 == 5 &&
						  min1 == 9);
	
	bool end_59_minutes = (sec1 == 9 && sec2 == 5 && 
							min1 == 9 && min2 == 5);

	bool end_9_hours = (sec1 == 9 && sec2 == 5 && 
						min1 == 9 && min2 == 5 &&
						hour1 == 9);
	
	bool end_24_hours = (sec1 == 9 && sec2 == 5 &&
						 min1 == 9 && min2 == 5 &&
						 hour1 == 3 && hour2 == 2);
						
	
	if (end_24_hours)
	{
		hour2 = 0;
		hour1 = 0;
		min2 =  0;
		min1 = 0;
		sec2 = 0;
		sec1 = 0;
	}
	
	else if (end_9_hours)
	{
		hour2++;
		hour1 = 0;
		min2 = 0;
		min1 = 0;
		sec2 = 0;
		sec1 = 0;
	}
	
	else if (end_59_minutes)
	{
		hour1++;
		min2 = 0;
		min1 = 0;
		sec2 = 0;
		sec1 = 0;
	}
	
	else if (end_9_minutes)
	{
		min2++;
		min1 = 0;
		sec2 = 0;
		sec1 = 0;
	}
	
	else if (end_59_seconds)
	{
		min1++;
		sec2 = 0;
		sec1 = 0;
	}
	
	else if (end_9_seconds)
	{
		sec2++;
		sec1 = 0;
	}
	
	else
	{
		sec1++;
	}
	
	
	time = time * 200;
	
	for (int c = 0; c <= time ; c++)
	{
		for (int d = 0; d <= time ; d++)
		{
			
		}
	}
	
}

void simple_delay(int time){
	digit_count = digit_count + 1;
	
	if (digit_count == 7)
		digit_count = 1;
	
	time = time * 200;
	
	for (int c = 0; c <= time ; c++)
	{
		for (int d = 0; d <= time ; d++)
		{
			
		}
	}
}


int main(void)
{
	unsigned char a = 5;
	
	// Input/Output Ports initialization
	// Port A initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
	PORTA=0x00;
	DDRA=0x00;

	// Port B initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
	PORTB=0x00;
	DDRB=0x00;

	// Port C initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
	// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0
	PORTC=0x00;
	DDRC=0xFF;

	// Port D initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
	// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0
	PORTD=0x00;
	DDRD=0xFF;
	
    while (1) 
    {
		//Digit 1
		if (digit_count == 1)
		{
			PORTD = 0b11111110;
			PORTC = number[hour2];
			simple_delay(a);
		}
		
		// Digit 2
		else if (digit_count == 2)
		{
			PORTD = 0b11111101;
			PORTC = number[hour1];
			simple_delay(a);
		}
		
		// Digit 3
		else if (digit_count == 3)
		{
			PORTD = 0b11111011;
			PORTC = number[min2];
			simple_delay(a);
		}
		
		// Digit 4
		else if (digit_count == 4)
		{
			PORTD = 0b11110111;
			PORTC = number[min1];
			simple_delay(a);
		}
		
		
		// Digit 5
		else if (digit_count == 5)
		{
			PORTD = 0b11101111;
			PORTC = number[sec2];
			simple_delay(a);
		}
		
		// Digit 6
		else
		{
			PORTD = 0b11011111;
			PORTC = number[sec1];
			delay_ms(a);
		}
    }
	
	return 0;
}

