#include <tarjeta.h>
/* INPUTS: 
 * 	IN1 : bumper izquirdo
 * 	IN2 : bumper derecho  
 * 	IN3 : sensor frontera trasero  
 * 	IN4 : sensor proximida 
 * 	IN5 : 
 * MOTORS: 
 * 	M1  : motor izquierdo 
 * 	M3  : motor derecho 
 * */

/* revoluciones */ 
#define MAX 240 
#define MIN 0
#define MID 140

/* movimientos */ 
#define PARAR 0
#define AVANZAR 1
#define IZQUIERDA 2
#define DERECHA 3

/* estados */ 
#define _INICIAL 0	
#define _BUSQUEDA 1
#define _ECHAR 2

unsigned int siguiente  = AVANZAR, /*siguiente movimiento*/
	     estado 	=  _INICIAL /*estado actual*/ 
	     velocidad  = MID; 	/*velocidad*/
int aux  = 0,  // contador velocidad 
    pwm = MID;  // velocidad inicial 



void girar_derecha() {
   M3_P(); 
   M1_A();   
}
void girar_izquierda() { 
   M1_P(); 
   M3_H();
}

void frenar() {
   M1_P(); 
   M3_P(); 
}

void acelerar() {
   M1_A();
   M3_H(); 
   
}

      
/*** subrutina de interrupcion **/

#INT_TIMER0
void isr_tmr0(){
   set_timer0(65067);
   if(aux <= pwm)
   {
	switch(siguiente) 
	{
		case PARAR: frenar(); break; 
		case AVANZAR: acelerar(); break; 
		case DERECHA: girar_derecha(); break;  
		case IZQUIERDA: girar_izquirda(); break;  
	}
   }
   else 
		frenar(); 
   aux++;
}




void main(){
   /*incializacion TIMER0*/
   setup_timer_0(RTCC_INTERNAL);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);    

   /*lectura y ejecucion*/
   while(TRUE){
    if(IN1) {  // golpe por la izquierda 
    }else if(IN2){ // golpe por la dercha
			siguiente = 
    } else if(IN1 && IN2) {
			
    }
    else  _avanzar(); 
   
 
      if(P2){
         pwm += 10;
         while (P2){}    
      }
   }
}

