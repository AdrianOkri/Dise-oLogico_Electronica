// Adrián Okri
// Programa P3 Alternando leds
// Dise�o logica
#include <16f84a.h>
#fuses XT, NOWDT // Fuses, son las configuraciones con las que arranca el PIC
#use delay (clock=4000000)

void main() {
   set_tris_b(0x00); // Usar todas las filas B
   output_b (0x00);
   int i;
   for (i = 0; 0 <= 2; i++) {
      output_HIGH(pin_a1); // Prender la compuerta A-1
      delay_ms(500);
      output_LOW(pin_a1);// APAGAR la puerta a-1
      delay_ms(500);
   }
   
   while(true) {
      output_HIGH(pin_b0); //Prender b0
      output_LOW(pin_b1); // Apagar b1
      delay_ms(500);
      output_HIGH(pin_b1); // Prender b1
      output_LOW(pin_b0); // Apagar b0
   }
}
