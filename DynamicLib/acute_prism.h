#ifndef ACUTE_PRISM_H
#define ACUTE_PRISM_H

#include "acute_triangle.h"

// Класс призмы с остроугольным треугольником в основании (наследуется от класса остроугольного треугольника).
class __declspec(dllexport) acute_prism : public acute_triangle {
private:
	// Поля класса: высота.
	double _height;
public:
	// Конструкторы:
	acute_prism();
	acute_prism(double, double, double, double);
	// Копирования.
	acute_prism(const acute_prism&);

	// Деструктор.
	~acute_prism() {};

	// Переопределение операторов.
	acute_prism& operator=(const acute_prism&);

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

#endif // ACUTE_PRISM_H
