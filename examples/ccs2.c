#include <16f84a.h>

#use fast_io(a)
#use fast_io(b)

void main(){
   
   int cont = 0;
   
   set_tris_a(0x03);
   set_tris_b(0x00);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_64);
   
   output_b(cont);
   
   while(TRUE){
      if(!input(PIN_A0)){
         cont = (get_timer0() % 6) + 1;
         output_b(cont);
         while(!input(PIN_A0)); //Hasta q se suelte el botón
      }
   }
}
