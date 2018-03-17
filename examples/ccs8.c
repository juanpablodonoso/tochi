#include <tarjeta.h>

#use delay (clock=48000000)

long int aux  = 0;
long int pwm = 0;

void main(){
 
   while(TRUE){
      if(P2)
         pwm += 4;
      if(aux <= pwm)
         led_on();
      else
         led_off();
      aux++;
   }
}


