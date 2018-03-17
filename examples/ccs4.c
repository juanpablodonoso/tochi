#include <tarjeta.h>

#use delay (clock=48000000)

void main(){
   
     
   while(TRUE){
      led_on();
      delay_ms(1000);
      led_off();
      delay_ms(1000);
   }
}
