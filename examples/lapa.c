#include <tarjeta.h>


// flags para controlar los movimientos 
int choque_derecha = 0,
    choque_izquierda = 0, 
    parar = 0;
int aux  = 0;  // contador velocidad 
int pwm = 90;  // velocidad inicial 


void avanza_izquierda() {
   M3_P(); 
   M1_A();   
}
void avanza_derecha() { 
   M1_P(); 
   M3_H();
}

void _stop() {
   M1_P(); 
   M3_P(); 
}

void _avanzar() {
   M1_A();
   M3_H(); 
   
}


#INT_TIMER0
void isr_tmr0(){
   set_timer0(65067);
   if(aux <= pwm){
        if(choque_izquierda) { // activado el bumper derecho
         avanza_derecha();  
        }else if(choque_derecha){ // activo el bumber izquierdo
         avanza_izquierda(); 
        }else if(choque_izquierda && choque_derecha) {
           //_stop();
           pwm +=20; 
           _avanzar(); 
        }else{ // Pvanzan
         _avanzar(); 
        }        
   }
   aux++;
}





void main(){
   setup_timer_0(RTCC_INTERNAL);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);    
   while(TRUE){
    if(IN1) {
      //avanzar_derecha(); 
      choque_izquierda = 1; choque_derecha = 0; 
       
    }else if(IN2){
      choque_derecha = 1; choque_izquierda = 0; 
      //while(IN2) {} 
    } else if(IN1 && IN2) {
      choque_derecha = 1; 
      choque_izquierda = 1; 
    }
    else  _avanzar(); 
   
 
      if(P2){
         pwm += 10;
         while (P2){}    
      }
   }
}

