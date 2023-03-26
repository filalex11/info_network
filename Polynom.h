#ifndef POLYNOM_H
#define POLYNOM_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

class Polynom {
	uint64_t value;
	uint8_t deg;
public:
	Polynom(uint8_t deg, uint64_t value = 0);
	Polynom(const Polynom &a);
	uint64_t getValue() const;
	uint8_t getDegree() const;
	Polynom operator+(const Polynom &a) const;
	Polynom operator*(const Polynom &a) const;
	Polynom operator^(const Polynom &a) const;
	const Polynom& operator=(const Polynom &a);
	void print() const;
	Polynom shiftValue(uint8_t shift) const;
	Polynom operator%(const Polynom &a) const;
};
#endif
