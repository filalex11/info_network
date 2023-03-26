#include "Polynom.h"

int main() {
	Polynom a(6, 0x56);
	Polynom b(4, 0x17);
	//printf("%lu\n", (a + b).getValue());
	//printf("%lu\n", (a % b).getValue());
	//printf("%lu %d\n", (a ^ b.shiftValue(2)).getValue(), (a ^ b.shiftValue(2)).getDegree());
	a.print();
	b.print();
	(a % b).print();
	return 0;
}
