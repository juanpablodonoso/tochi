#include <tarjeta.h>


int aux  = 0;
int pwm = 127;


#INT_TIMER0
void isr_tmr0(){
   set_timer0(65067);
   if(aux <= pwm)
         led_on();
      else
         led_off();
      aux++;
}

void main(){
   setup_timer_0(RTCC_INTERNAL);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);    
   while(TRUE){
      if(P2){
         pwm += 10;
         while (P2){}
      }
   }
}

