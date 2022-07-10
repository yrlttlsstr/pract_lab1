#ifndef ACUTE_TRIANGLE_H
#define ACUTE_TRIANGLE_H

#define PI 3.14159265

#include <math.h> 
#include "figure.h"

// Класс остроугольного треугольника (наследуется от класса фигура).
class __declspec(dllexport) acute_triangle : public figure {
protected:
	// Поля класса: массив длин 3 сторон.
	double _side[3];
public:
	// Конструкторы:
	acute_triangle();
	acute_triangle(double, double, double);
	// Копирования.
	acute_triangle(const acute_triangle&);

	// Деструктор.
	~acute_triangle() {};

	// Переопределение операторов.
	acute_triangle& operator=(const acute_triangle&);

	// Геттеры.
	// Для сторон.
	double get_side_a() const;
	double get_side_b() const;
	double get_side_c() const;

	// Для углов.
	double get_angle_a() const;
	double get_angle_b() const;
	double get_angle_c() const;

	// Для периметра.
	double get_perimeter() const;

	// Для площади.
	double get_area() const;

	// Метод возвращает тип объекта.
	std::string type() const override { return "trinagle"; };

	// Метод печатает объект.
	void print() const override;
};

#endif // ACUTE_TRIANGLE_H
