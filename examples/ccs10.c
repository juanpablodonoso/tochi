#include <tarjeta.h>


void main(){

   while (1) { 
   
      if (IN1) 
         led_on(); 
      else 
         led_off(); 
         
      if (IN2) 
         led_on(); 
      else 
         led_off();
   
   }
//!   setup_timer_0(RTCC_INTERNAL);
//!   enable_interrupts(INT_TIMER0);
//!   enable_interrupts(GLOBAL);    
//!   while(TRUE){
//!      if(P2) pwm += 10; 
   
}

