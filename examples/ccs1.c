#include <16f84a.h>

#use fast_io(a)
#use fast_io(b)
#use delay (clock=1000000)

void main(){
   
   int cont = 0;
   
   set_tris_a(0x03);
   set_tris_b(0x00);
  
   output_b(cont);
   
   while(TRUE){
      if(!input(PIN_A0)){
         cont++;
         output_b(cont);
         delay_ms(500);
      }
   }
}
