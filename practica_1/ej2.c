#include <htc.h>
int volatile timer_flag=0;

void restart_timer(){
	T0IF=0; //resetear flag
	TMR0=12; //iniciar en 60 el contador
}

void initDevices(){
	//configuro como entrada los pulsadores
	TRISA = 0b11; 
	//configuro como salida los leds
	TRISB &= ~((1<<4) | (1<<5));
	//estado inicial de leds encendidos
	RB4=1;
	RB5=1;
}

void initTimer(){
	//configuracion timer0
	T0CS=0; //clock interno
	PSA=0; // setear prescaler para timer 0
	OPTION_REG = 0b00000111; //prescaler 256
	TMR0=12; //Iniciar en 60 el contador
}

void main(){
	int status=0;
	initDevices();
	initTimer();
	while(1){
		if(((RA0 == 0) || (RA1 == 0)) & (status==0)) {
			status = 1;
			RB4 = 0;
			INTCON |= (1<<7)|(1<<5); //habilitar interrupciones generales y de overflow del timer	
		}
		if(timer_flag){
			timer_flag=0;
			RB4 = !RB4;
			RB5 = !RB5;
		}
	}
}


void interrupt manejador(void){
	static int contador=0;
	timer_flag=1;
	restart_timer();
}