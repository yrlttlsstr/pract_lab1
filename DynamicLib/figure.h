#ifndef FIGURE_H
#define FIGURE_H

#include <string>

// Абстрактный класс фигуры.
class __declspec(dllexport) figure {
public:
	// Виртуальный метод, который возвращает тип фигуры.
	std::string virtual type() const = 0;

	//  Виртуальный метод, который печатает всю информацию о фигуре.
	void virtual print() const = 0;
};

#endif // FIGURE_H
