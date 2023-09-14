/*
 * System.cpp
 *
 * Created: 9/10/2023 7:10:28 PM
 * Author : dex
 */ 

#include <avr/io.h>
#include <util/delay.h>

char lightNumber(int number){
	if (number == 1)
	{
		return 0b11001111;
	}
	else if(number == 2){
		return 0b10100100;
	}
	else if(number == 3){
		return 0b10110000;
	}
	else if(number == 4){
		return 0b10011001;
	}
	else if(number == 5){
		return 0b10010010;
	}
	else if(number == 6){
		return 0b10000010;
	}
	else if(number == 7){
		return 0b11111000;
	}
	else if(number == 8){
		return 0b10000000;
	}
	else if(number == 9){
		return 0b10010000;
	}
	
	
	return 0b00000000;
}

void animateBulbs(int fromNumber){
	char bulb_light[7] = {0b00000001,0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000};
	for (int i = fromNumber; i > 0; i--){
		if(i < 8){
		PORTH = bulb_light[i - 1];
		_delay_ms(300);
	}
	PORTF = lightNumber(i);
	_delay_ms(100);
	}
}


int main(void)
{
    /* Replace with your application code */
	DDRF = 0b11111111;
	DDRH = 0b00000000;
	DDRK = 0b00000111;
	
	int selected = 0;
	
	PINK = 0b11111111;
	
    while (1) 
    {
		PORTK = 0b00000011;
		PORTH = 0b00000000;
		PORTF = 0b11111111;
		
		if((PINK & 0b00001000) == 0){
			
			selected = 1;
			animateBulbs(selected);
			
		}
		
		if((PINK & 0b00010000) == 0){
			
			selected = 4;
			animateBulbs(selected);
			
		}
		
		if((PINK & 0b00100000) == 0){
			
			selected = 7;
			animateBulbs(selected);
			
		}
		
		
		PORTK = 0b00000101;
		if((PINK & 0b00001000) == 0){
			
			selected = 2;
			animateBulbs(selected);
			
		}
		
		if((PINK & 0b00010000) == 0){
			
			selected = 5;
			animateBulbs(selected);
			
		}
		
		if((PINK & 0b00100000) == 0){
			
			selected = 8;
			animateBulbs(selected);
			
		}
		
		PORTK = 0b00000110;
		if((PINK & 0b00001000) == 0){
			
			selected = 3;
			animateBulbs(selected);
			
		}
		
		if((PINK & 0b00010000) == 0){
			
			selected = 6;
			animateBulbs(selected);
			
		}
		
		if((PINK & 0b00100000) == 0){
			
			selected = 9;
			animateBulbs(selected);
			
		}
		
    }
}

