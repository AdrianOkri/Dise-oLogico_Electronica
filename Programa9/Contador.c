// Adrián Okri
// 04/06/2018
// Contador
#include <16f84a.h>
#fuses XT,NOWDT, NOPROTECT, NOPUT
#use delay(clock=4000000)
#use fast_io(B) // Declarar r�pido cambios de memorias
#use fast_io(A)

void main() {
   set_tris_b(0x00);
   output_b(0x00);
   int i, t = 500, op = 0;
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
   
   output_b(0xC0); //Encender el Cero
   delay_ms(t);
   output_b(0xF9); //Encender el UNO
   delay_ms(t);
   output_b(0xA4); //Encender el Dos
   delay_ms(t);
   output_b(0xB0); //Encender el Tres
   delay_ms(t);
   output_b(0x99); //Encender el Cuatro
   delay_ms(t);
   output_b(0x21); //Encender el Cinco
   delay_ms(t);
   output_b(0x02); //Encender el Seis
   delay_ms(t);
   output_b(0xF8); //Encender el Siete
   delay_ms(t);
   output_b(0x80); //Encender el Ocho
   delay_ms(t);
   output_b(0x98); //Encender el Nueve
   delay_ms(t);
   output_b(0x21); //Encender el N
   delay_ms(t);
   output_b(0xC0); //Encender el 0
   delay_ms(t);
   output_b(0x86); //Encender el E
   delay_ms(t);
   output_b(0xC0); //Encender el 0
   delay_ms(t);
   output_b(0x21); //Encender el N
   delay_ms(t);
   output_b(0x98); //Encender el Nueve
   delay_ms(t);
   output_b(0x80); //Encender el Ocho
   delay_ms(t);
   output_b(0xF8); //Encender el Siete
   delay_ms(t);
   output_b(0x02); //Encender el Seis
   delay_ms(t);
   output_b(0x21); //Encender el Cinco
   delay_ms(t);
   output_b(0x99); //Encender el Cuatro
   delay_ms(t);
   output_b(0xB0); //Encender el Tres
   delay_ms(t);
   output_b(0xA4); //Encender el Dos
   delay_ms(t);
   output_b(0xF9); //Encender el UNO
   delay_ms(t);
   }
   }
}
