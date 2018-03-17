#include <tarjeta.h>

#use delay (clock=48000000)

void main(){
   
     
   while(TRUE){
   
      M4_A();
      //M4_P();
      delay_ms(1000);
      //M4_H();
      M4_P();
      delay_ms(1000);
      
      M4_H();
      delay_ms(1000);
      
      M4_P(); 
      delay_ms(1000); 
   }
}

