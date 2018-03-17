#include <tarjeta.h>

#use delay (clock=48000000)

long int aux  = 100;

void main(){
 
   while(TRUE){
      if(P2){
         aux += 50;
      }
      led_on();
      delay_ms(aux);
      led_off();
      delay_ms(aux);
   }
}
