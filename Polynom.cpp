#include "Polynom.h"

Polynom::Polynom(uint8_t deg, uint64_t value) {
	this->deg = deg;
	this->value = value;
}

uint8_t	Polynom::getDegree() const {
	return deg;
}

uint64_t Polynom::getValue() const {
	return value;
}

Polynom Polynom::operator+(const Polynom &a) const {
	return Polynom(deg, value + a.getValue());
}

Polynom Polynom::operator*(const Polynom &a) const {
	return Polynom(deg + a.getDegree(), value * a.getValue());
}

Polynom Polynom::operator^(const Polynom &a) const {
	uint64_t val = value ^ a.getValue();
	if (val == 0)
		return Polynom(0, 0);
	for (uint64_t i = 63; i > 0; --i) {
		if (((val & (1 << i)) >> i) == 1)
			return Polynom(i, val);
	}
	return *this;
}

const Polynom& Polynom::operator=(const Polynom &a) {
	deg = a.getDegree();
	value = a.getValue();
	return *this;
}

Polynom Polynom::shiftValue(uint8_t shift) const {
	return Polynom(deg + shift, value << shift);
}

Polynom::Polynom(const Polynom &a) {
	deg = a.getDegree();
	value = a.getValue();
}

void Polynom::print() const {
	for (uint8_t i = deg; i > 0; --i)
		printf(" %ldx^%d ", (value & (1 << i)) >> i, i);
	printf(" %ld\n", value & 1);
}

Polynom Polynom::operator%(const Polynom &a) const {
	Polynom p(*this);
	while (true) {
		Polynom divider = a.shiftValue(p.getDegree() - a.getDegree());
		Polynom res = p ^ divider;
		if (res.getDegree() < a.getDegree())
			return res;
		p = res;
	}
	return *this;
}
