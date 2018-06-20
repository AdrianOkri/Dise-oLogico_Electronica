// Adrián Okri
// 01/05/2018
// Dos botones
#include <16f84a.h>
#fuses XT,NOWDT, NOPROTECT, NOPUT
#use delay(clock=4000000)

void main() {
   set_tris_b(0x00);
   set_tris_a(0x24);
   output_b(0x00);
   int i, j, k, m;
   for(i=0; i<=2; i++) {
      output_high(pin_a1);
      delay_ms(500);
      output_low(pin_a1);  
      delay_ms(500);
   }
   while(true) {
      if(input(pin_a2) == 1){
         while(input(pin_a2) == 1) {
            delay_ms(30);
         }
         output_high(pin_b0);
      }
      if(input(pin_a3) == 1){
         while(input(pin_a3) == 1) {
            delay_ms(30);
         }
         output_low(pin_b0);
      }
   }
}
