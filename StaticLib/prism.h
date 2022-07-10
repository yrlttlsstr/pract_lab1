#ifndef PRISM_H
#define PRISM_H

#include "acute_triangle.h"

// Класс призмы с остроугольным треугольником в основании (наследуется от класса остроугольного треугольника).
class prism : public acute_triangle {
private:
	// Поля класса: высота.
	double _height;
public:
	// Конструкторы:
	prism();
	prism(double, double, double, double);
	// Копирования.
	prism(const prism&);

	// Деструктор.
	~prism() {};

	// Переопределение операторов.
	prism& operator=(const prism&);

	// Геттеры.
	// Для объема.
	double get_volume() const;
	// Для площади поверхности.
	double get_surface_area() const;

	// Метод возвращает тип объекта.
	std::string type() const override { return "prism"; };

	// Метод печатает объект.
	void print() const override;
};

#endif // PRISM_H
