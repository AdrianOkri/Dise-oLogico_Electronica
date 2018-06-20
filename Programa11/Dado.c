// Adrián Okri
// 05/06/2018
// Dado
#include <16f84a.h>
#fuses XT,NOWDT
#use delay(clock=4000000)

void main() {
   set_tris_b(0x00);
   output_b(0x00);
   
   set_tris_a(0x0c);
   
   int i;
   int display[7] = {0xc0, 0xf9, 0xa4, 0xb0,0x99,0x92, 0x82};
   char j = 0;
   
   for(i=0; i<=2; i++) {
      output_high(pin_a1);
      delay_ms(500);
      output_low(pin_a1);  
      delay_ms(500);
   }
   
   while(true) {
      if(input(pin_a2) == 1){
         output_b(display[j]); delay_ms(50);
         j++;
         
         if(j >= 6) { j = 0; }
      }
   }
}
