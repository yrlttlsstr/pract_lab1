#include "prism.h"
#include <iostream>

// ������������:
prism::prism() : _height(0) {}

prism::prism(double side_a, double side_b, double side_c, double height) :
	acute_triangle(side_a, side_b, side_c),
	_height(height) {
	if (_height < 0)
		throw std::string("wrong_data");
}

// �����������.
prism::prism(const prism& object) {
	_height = object._height;
}

// ��������������� ��������� ������������.
prism& prism::operator=(const prism& value) {
	if (&value == this) return *this;
	for (int i = 0; i < 3; i++)
		_side[i] = value._side[i];
	_height = value._height;
	return *this;
}

// �������.
// ��� ������.
double prism::get_volume() const {
	return _height * get_area();
}

// ��� ������� �����������.
double prism::get_surface_area() const {
	return 2 * get_area() + get_perimeter() * _height;
}

// ����� �������� ������.
void prism::print() const {
	std::cout << "Info about prism with an acute triangle at the base:" <<
		"\nTriangle at the base:\n";
	acute_triangle::print();
	std::cout << "Valume: " << get_perimeter() <<
		"\n  Surface area: " << get_area() << "\n\n";
}