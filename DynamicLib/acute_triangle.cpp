#include "acute_triangle.h"
#include <iostream>
#include <string>

// Функция для перевода радианс в градусы.
__declspec(dllexport) double degree(double x) {
	return x * 180.0 / PI;
}

// Функция для перевода градусов в радиансы.
__declspec(dllexport) double radiance(double x) {
	return x * PI / 180.0;
}

// Конструкторы:
acute_triangle::acute_triangle() : _side{ 0, 0, 0 } {}

acute_triangle::acute_triangle(double side_a, double side_b, double side_c) {
	if ((side_a < 0 or side_b < 0 or side_c < 0) or ((side_a + side_b <= side_c) or (side_a + side_c <= side_b) or (side_b + side_c <= side_a)))
		throw std::string("wrong_data");
	_side[0] = side_a;
	_side[1] = side_b;
	_side[2] = side_c;
	if (get_angle_a() >= 90 or get_angle_b() >= 90 or get_angle_c() >= 90)
		throw std::string("not_acute_angle");
}

// Копирования.
acute_triangle::acute_triangle(const acute_triangle& object) {
	for (int i = 0; i < 3; i++)
		_side[i] = object._side[i];
}

// Переопределение оператора присваивания.
acute_triangle& acute_triangle::operator=(const acute_triangle& value) {
	if (&value == this) return *this;
	for (int i = 0; i < 3; i++)
		_side[i] = value._side[i];
	return *this;
}

// Геттеры.
// Для сторон.
double acute_triangle::get_side_a() const { return _side[0]; }
double acute_triangle::get_side_b() const { return _side[1]; }
double acute_triangle::get_side_c() const { return _side[2]; }

// Для углов.
double acute_triangle::get_angle_a() const {
	return degree(acos(((_side[0] * _side[0]) + (_side[2] * _side[2]) - (_side[1] * _side[1])) / (2.0 * _side[0] * _side[2])));
}
double acute_triangle::get_angle_b() const {
	return degree(acos(((_side[0] * _side[0]) + (_side[1] * _side[1]) - (_side[2] * _side[2])) / (2.0 * _side[0] * _side[1])));
}
double acute_triangle::get_angle_c() const {
	return degree(acos(((_side[1] * _side[1]) + (_side[2] * _side[2]) - (_side[0] * _side[0])) / (2.0 * _side[1] * _side[2])));
}

// Для периметра.
double acute_triangle::get_perimeter() const {
	return _side[0] + _side[1] + _side[2];
}

// Для площади.
double acute_triangle::get_area() const {
	if (_side[0] == 0 or _side[1] == 0) return 0.0;
	return 0.5 * _side[0] * _side[1] * sin(radiance(get_angle_c()));
}

// Метод печатает объект.
void acute_triangle::print() const {
	std::cout << "Acute triangle:" <<
		"\n  Side a: " << get_side_a() <<
		"\n  Side b: " << get_side_b() <<
		"\n  Side c: " << get_side_c() <<
		"\n  Angle A: " << get_angle_a() <<
		"\n  Angle B: " << get_angle_b() <<
		"\n  Angle C: " << get_angle_c() <<
		"\n  Perimeter: " << get_perimeter() <<
		"\n  Area: " << get_area() << "\n\n";
}