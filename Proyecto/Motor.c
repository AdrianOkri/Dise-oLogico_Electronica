// Adrián Okri
// UPEM 19/06/2018
// Proyecto de motor
#include <16f84a.h>
#fuses XT,NOWDT
#use delay(clock=4000000)
// Funciones prototipos ********************************************************
void Esperar(int tiempo);
void EncenderMotorPaso(int puerto);
void EncenderLedPrueba();
void CicloMotor(int numPuerta[4]);
int LedEM();
// Variables globales **********************************************************
int t = 3, tiempoUsuario= 5000, lim = 5, limite = 250; // Variable del tiempo en el que ir� el motor
// Funci�n princial  ***********************************************************
void main() {
   set_tris_b(0x00); // Utilizar todas las compuertas B
   
   int numPuerta[4] = {0x05, 0x09, 0x0a, 0x06}; // Arreglo que contiene las salidas de la compuerta B
   int numPuertaInv[4] = {0x06, 0x0a, 0x09, 0x05}; // Arreglo que contiene las salidas de la compuerta B de forma inversa 
   char posElevador = '<'; // Variable que me dir� si el elevador se encuentra en el lado izquierdo o derecho
   
   EncenderLedPrueba(); // Llamar al led de prueba que ser� la que nos diga que hay corriente y el programa funciona 
   // La funci�n CicloMotor har� todo el proceso de girar el motor en un sentido
   if (LedEM() == 1) { // La funci�n LedEM nos retornar� un 1 si, ha detectado un objeto en la puerta de la izquierda y un 2 si es en la derecha
      switch(posElevador) 
      {
         case '<': CicloMotor(numPuerta);  posElevador = '>'; break;
         case '>': CicloMotor(numPuertaInv);  posElevador = '<'; break;
      }
   } else if (LedEM() == 2) {
      switch(posElevador) 
      {
         case '<': CicloMotor(numPuerta); posElevador = '>'; break;
         case '>': CicloMotor(numPuertaInv); posElevador = '<'; break;
      }
   }
}
void EncenderLedPrueba() {
   int i ,tiempoLed = 500;
   for(i=0; i<=2; i++) {
      output_high(pin_a1); delay_ms(tiempoLed);
      output_low(pin_a1);  delay_ms(tiempoLed);
   }
}
// Funci�n que encender� una de las compuertas b para el motor paso a paso
void EncenderMotorPaso(int puerto) {
   output_b(puerto);
   delay_ms(t);
}
// Har� todo el proceso de encender las compuertas en el orden que les mandes
void CicloMotor(int numPuerta[4]) {
   int i, j, k; // Variables de los ciclos
   delay_ms(tiempoUsuario);
   for(i = 0; i <= lim; i++) {
      for(j = 0; j <= limite; j++) {
         for(k = 0; k <= 3; k++) { EncenderMotorPaso(numPuerta[k]); }
      }
   }
}
// Funci�n que retornar� un valorfalso dependiendo si ha detectado un objeto
int LedEM() {
   if(input(pin_a2) == 1){ // pin_a2 serán los LEDS de la izquierda
         while(input(pin_a2) == 1) { delay_ms(30); }
         return 1;
   } else if (input(pin_a3) == 1){ // pin_a3 serám los LEDS de la derecha
         while(input(pin_a3) == 1) { delay_ms(30); }
         return 2;
   }
   return 0;
}
