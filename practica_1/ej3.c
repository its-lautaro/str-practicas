#include <htc.h>


void initADC(){
	ADCON1 = 0b10001110; //justificacion a derecha y AN0 como entrada analogica 
	ADCON0 = 0b01000001; //osc/8, ADON activado
	ADIE = 0; 
	TRISA |= 1; //setear AN0/RA0 como entrada
}

unsigned short poll(){
	ADCON0 |= (1<<2); //activa la conversion 
	while((ADCON0 &(1<<2))){} 
	return (ADRESH << 8 | ADRESL) ;
}

void sendValue(v){
	PORTB = 
}

int main(){
	unsigned short valor;
	initADC(); //configuracion inicial del ADC
	while(1){
		valor = poll();
	} 
}