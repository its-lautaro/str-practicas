#include <htc.h>

void initADC(){
	ADCON1 = 0b10001110; //justificacion a derecha y RA0 como entrada analogica 
	ADCON0 = 0b01000001; //Fosc/8, ADON activado
	ADIE = 0; 
}

void initMCU(){
	RD6 = 0;
	RD7 = 0;
	TRISA |= 1; //setear AN0/RA0 como entrada
	TRISB = 0; //PORTB como salida
	TRISD = 0b00111111; //RB6 y RB7 como salida
}

void polling(){
	ADCON0 |= (1<<2); //activa la conversion 
	while((ADCON0 &(1<<2)));
	PORTB = ADRESH; //envia la parte alta
	RD7 = 1; //activa LE del latch U3
	RD7 = 0;
	PORTB = ADRESL; //envia la parte baja 
	RD6 = 1; //activa LE del latch U2
	RD6 = 0; 
}


int main(){
	initMCU();
	initADC(); //configuracion inicial del ADC
	while(1){
		polling();
	} 
}