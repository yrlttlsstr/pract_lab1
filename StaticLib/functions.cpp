#include "functions.h"

// ������ ����� �� �����.
void fread_figures(std::ifstream& fin, list<figure*>& list) {
	// ��������� ���-�� �����.
	int count;
	fin >> count;

	for (int i = 0; i < count; i++) {
		// ��������� ��� ������, ������� ����� ������.
		std::string type_fugure;
		fin >> type_fugure;

		double side_a, side_b, side_c, height;

		if (type_fugure == "triangle") {
			// ��������� ������ ��� �������� ������.
			fin >> side_a >> side_b >> side_c;

			try {
				// ��������� �� � ������.
				list.push_back(new acute_triangle(side_a, side_b, side_c));
			}
			// ����������� ������.
			catch (std::string ex) {
				if (ex == "wrong_data")
					std::cout << "In line " << i + 2 << " you entered incorrect data.\n";
				else if (ex == "not_acute_angle")
					std::cout << "In line " << i + 2 << " not acute triangle.\n";
			}
		}
		else if (type_fugure == "prism") {
			// ��������� ������ ��� �������� ������.
			fin >> side_a >> side_b >> side_c >> height;

			try {
				// ��������� �� � ������.
				list.push_back(new prism(side_a, side_b, side_c, height));
			}
			// ����������� ������.
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

// ����� ������� �����.
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

// ����� ������������ � ������������ �������� � ������ � ������������ �������.
void search_max_triangle_and_prism(list<figure*>& list, acute_triangle& max_triangle, prism& max_prism) {
	node<figure*>* curr = list.get_front();
	while (curr) {
		if (typeid(*(curr->get_value())) == typeid(max_triangle)) {
			acute_triangle* object = dynamic_cast<acute_triangle*>(curr->get_value());
			// ���� ���������� �� ������, ������� �� ������ �������������, ������ �� �������, ��� ������� ������������, �� ������ ��������.
			if (std::max(object->get_side_a(), std::max(object->get_side_b(), object->get_side_c()))
	> std::max(max_triangle.get_side_a(), std::max(max_triangle.get_side_b(), max_triangle.get_side_c())))
				max_triangle = *object;
		}
		else if (typeid(*(curr->get_value())) == typeid(prism)) {
			prism* object = dynamic_cast<prism*>(curr->get_value());
			// ���� ������ �� ������, ������� �� ������ �������������, ������ �� ������, ��� ������� ������������, �� ������ ��������.
			if (object->get_volume() > max_prism.get_volume())
				max_prism = *object;
		}
		curr = curr->get_next();
	}
}