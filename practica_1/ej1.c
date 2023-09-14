#include "htc.h"

void main(){
	int titilar=0;
	TRISA = 0b00000011; //RA0 y RA1 como entradas
	TRISB = 0b11001111; //RB4 y RB5 como salidas
	PORTB=0b00110000; //encender leds
	
	while(1){
		if((RA0==0)||(RA1==0)){
			titilar=1;
		}
		if(titilar==1){
			RB4=!RB4;
			__delay_ms(250);
			RB4=!RB4;
			RB5=!RB5;
			__delay_ms(250);
			RB5=!RB5;
		}
	}
}