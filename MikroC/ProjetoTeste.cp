#line 1 "C:/Users/joser/Documents/Desktop/EngComp/LabII/ProjetoTeste/MikroC/ProjetoTeste.c"

void main() {

 TRISB = 0;

 do {
 PORTB = 0x00;
 Delay_ms(1000);

 PORTB = 0xFF;
 Delay_ms(1000);
 } while(1);
}
