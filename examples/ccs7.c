#include <tarjeta.h>

#use delay (clock=48000000)

int aux  = 0;
int pwm = 63;

void main(){
 
   while(TRUE){
      if(aux <= pwm)
         led_on();
      else
         led_off();
      aux++;
   }
}

