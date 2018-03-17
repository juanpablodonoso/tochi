#include <18f4550.h>

#use fast_io(a)
#use fast_io(b)

int cont = 0;

#INT_EXT
void isr_ext(){
      cont++;
      output_a(cont);
}

void main(){
   set_tris_a(0x00);
   set_tris_b(0x01);
  
   output_a(cont);
   
   ext_int_edge( H_TO_L );
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);

   while(TRUE){
   }
}
