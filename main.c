#include <avr/io.h>
#include <avr/interrupt.h>

int main() {
	TIMSK |= (1<<TOIE2);
	TCNT0 = 0;
	ASSR = 0x08;
	TCCR2 = 0x05;
	sei();
	DDRD |= 0b1;
	while(1);
	return 0;
}

ISR(TIMER2_OVF_vect) {
	PORTD ^= _BV(PD0);
}
