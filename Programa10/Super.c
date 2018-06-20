// Adrián Okri
// 04/06/2018
// Super
#include <16f84a.h>
#fuses XT,NOWDT
#use delay(clock=4000000)

void main() {
   set_tris_b(0x00);
   output_b(0x00);
   
   int i, t = 500, contador = 0;
   
   for(i=0; i<=2; i++) {
      output_high(pin_a1);
      delay_ms(t);
      output_low(pin_a1);  
      delay_ms(t);
   }
   
   while(true) {
      if(input(pin_a2) == 1){
         while(input(pin_a2) == 1) {
            delay_ms(30);
         }
         switch(contador) {
            case 0: output_b(0xC0); break; //Encender el Cero
            case 1: output_b(0xF9); break; // Uno
            case 2: output_b(0xA4); break; // Dos
            case 3: output_b(0xB0); break; // Tres
            case 4: output_b(0x99); break; // Cuatro
            case 5: output_b(0x92); break; // Cinco
            case 6: output_b(0x82); break; // Seis
            case 7: output_b(0xB8); break; // Siete
            case 8: output_b(0x80); break; // Ocho
            case 9: output_b(0x98); break; // Nueve
            case 10:output_b(0x92); break; // N = 5
            case 11:output_b(0xC0); break; // O = 0
            case 12:output_b(0x86); break; // E = 3
            default:contador = 0;
         }
         contador++;
      }
   }
}
