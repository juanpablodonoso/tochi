#include <tarjeta.h>

#INT_TIMER0
void isr_tmr0(){
   set_timer0(18661);
   output_toggle(PIN_A5);
}

void main(){
   set_timer0(18661);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);  
   while(TRUE){}
}

