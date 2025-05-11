
void main() {

  TRISB = 0;           // set direction to be output

  do {
    PORTB = 0x00;       // Turn OFF LEDs on PORTB
    Delay_ms(1000);    // 1 second delay

    PORTB = 0xFF;       // Turn ON LEDs on PORTB
    Delay_ms(1000);    // 1 second delay
  } while(1);          // Endless loop
}