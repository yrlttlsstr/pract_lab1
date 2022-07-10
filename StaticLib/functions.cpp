#include "functions.h"

// Чтение фигур из файла.
void fread_figures(std::ifstream& fin, list<figure*>& list) {
	// Считываем кол-во фигур.
	int count;
	fin >> count;

	for (int i = 0; i < count; i++) {
		// Считываем тип фигуры, который хотим ввести.
		std::string type_fugure;
		fin >> type_fugure;

		double side_a, side_b, side_c, height;

		if (type_fugure == "triangle") {
			// Считываем данные для создания фигуры.
			fin >> side_a >> side_b >> side_c;

			try {
				// Добавляем ее в список.
				list.push_back(new acute_triangle(side_a, side_b, side_c));
			}
			// Отлавливаем ошибки.
			catch (std::string ex) {
				if (ex == "wrong_data")
					std::cout << "In line " << i + 2 << " you entered incorrect data.\n";
				else if (ex == "not_acute_angle")
					std::cout << "In line " << i + 2 << " not acute triangle.\n";
			}
		}
		else if (type_fugure == "prism") {
			// Считываем данные для создания фигуры.
			fin >> side_a >> side_b >> side_c >> height;

			try {
				// Добавляем ее в список.
				list.push_back(new prism(side_a, side_b, side_c, height));
			}
			// Отлавливаем ошибки.
			catch (std::string ex) {
				if (ex == "wrong_data")
					std::cout << "In line " << i + 2 << " you entered incorrect data.\n";
				else if (ex == "not_acute_angle")
					std::cout << "In line " << i + 2 << " not acute triangle at the base.\n";
			}
		}
		else {
			std::cout << "In line " << i + 2 << " you entered an invalid figure type.\n\n";
		}
	}
}

// Вывод списока фигур.
void print_figures(list<figure*>& list) {
	node<figure*>* curr = list.get_front();
	int count = 1;

	while (curr) {
		std::cout << "Figure " << count << '\n';
		curr->get_value()->print();
		std::cout << '\n';
		curr = curr->get_next();
		count++;
	}
}

// Поиск треугольника с максимальной стороной и призмы с максимальным объемом.
void search_max_triangle_and_prism(list<figure*>& list, acute_triangle& max_triangle, prism& max_prism) {
	node<figure*>* curr = list.get_front();
	while (curr) {
		if (typeid(*(curr->get_value())) == typeid(max_triangle)) {
			acute_triangle* object = dynamic_cast<acute_triangle*>(curr->get_value());
			// Если тругольник из списка, который мы сейчас рассматриваем, больше по стороне, чем текущий максимальный, то меняем максимум.
			if (std::max(object->get_side_a(), std::max(object->get_side_b(), object->get_side_c()))
	> std::max(max_triangle.get_side_a(), std::max(max_triangle.get_side_b(), max_triangle.get_side_c())))
				max_triangle = *object;
		}
		else if (typeid(*(curr->get_value())) == typeid(prism)) {
			prism* object = dynamic_cast<prism*>(curr->get_value());
			// Если призма из списка, которую мы сейчас рассматриваем, больше по объему, чем текущая максимальная, то меняем максимум.
			if (object->get_volume() > max_prism.get_volume())
				max_prism = *object;
		}
		curr = curr->get_next();
	}
}