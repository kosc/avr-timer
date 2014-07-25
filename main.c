#include <avr/io.h>
#include <avr/interrupt.h>

int main() {
	TIMSK |= (1<<TOIE2);
	TCNT0 = 0;
	ASSR |= (1<<AS2);
	TCCR2 |= (1<<CS22)|(1<<CS20);
	sei();
	DDRD |= 0b1;
	while(1);
	return 0;
}

ISR(TIMER2_OVF_vect) {
	PORTD ^= _BV(PD0);
}
