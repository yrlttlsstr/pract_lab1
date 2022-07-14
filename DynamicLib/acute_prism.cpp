#include "acute_prism.h"
#include <iostream>

// Конструкторы:
acute_prism::acute_prism() : _height(0) {}

acute_prism::acute_prism(double side_a, double side_b, double side_c, double height) :
	acute_triangle(side_a, side_b, side_c),
	_height(height) {
	if (_height < 0)
		throw std::string("wrong_data");
}

// Копирования.
acute_prism::acute_prism(const acute_prism& object) {
	_height = object._height;
}

// Переопределение оператора присваивания.
acute_prism& acute_prism::operator=(const acute_prism& value) {
	if (&value == this) return *this;
	for (int i = 0; i < 3; i++)
		_side[i] = value._side[i];
	_height = value._height;
	return *this;
}

// Геттеры.
// Для объема.
double acute_prism::get_volume() const {
	return _height * get_area();
}

// Для площади поверхности.
double acute_prism::get_surface_area() const {
	return 2 * get_area() + get_perimeter() * _height;
}

// Метод печатает объект.
void acute_prism::print() const {
	std::cout << "Prism with an acute triangle at the base:" <<
		"\nTriangle at the base:\n";
	acute_triangle::print();
	std::cout << "Valume: " << get_perimeter() <<
		"\n  Surface area: " << get_area() << "\n\n";
}