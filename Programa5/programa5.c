// Adrián Okri
// 31/05/2018
// 3 Secuencias de leds
#include <16f84a.h>
#fuses XT,NOWDT, NOPROTECT, NOPUT
#use delay(clock=4000000)
#use fast_io(B) // Declarar r�pido cambios de memorias
#use fast_io(A)

void main (){
   set_tris_b(0x00);
   output_b(0x00);
   int i, j, k, m;
   for(i=0; i<=2; i++) {
      output_high(pin_a1);
      delay_ms(500);
      output_low(pin_a1);  
      delay_ms(500);
   }
   int t=500;
   delay_ms(t);
   while (true)
   {
      for ( j=0; j<=4; j++)
      {
         output_b(0x01);
         delay_ms(t);
         output_b(0x02);
         delay_ms(t);
         output_b(0x04);
         delay_ms(t);
         output_b(0x08);
         delay_ms(t);
         output_b(0x10);
         delay_ms(t);
         output_b(0x20);
         delay_ms(t);
         output_b(0x40);
         delay_ms(t);
         output_b(0x80);
         delay_ms(t);
         output_b(0x40);
         delay_ms(t);
         output_b(0x20);
         delay_ms(t);
         output_b(0x10);
         delay_ms(t);
         output_b(0x08);
         delay_ms(t);
         output_b(0x04);
         delay_ms(t);
         output_b(0x02);
         delay_ms(t);
      }
      for (k=0; k<=4; k++)
      {
         output_b(0x81);
         delay_ms(t);
         output_b(0x42);
         delay_ms(t);
         output_b(0x24);
         delay_ms(t);
         output_b(0x18);
         delay_ms(t);
         output_b(0x24);
         delay_ms(t);
         output_b(0x42);
         delay_ms(t);
      }
      for (m=0; m<=4; m++)
      {
         output_b(0xc0);
         delay_ms(t);
         output_b(0x30);
         delay_ms(t);
         output_b(0x0c);
         delay_ms(t);
         output_b(0x03);
         delay_ms(t);
         output_b(0x0c);
         delay_ms(t);
         output_b(0x30);
         delay_ms(t);
      }
   }
}
