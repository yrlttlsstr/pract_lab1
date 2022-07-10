#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

#include "figure.h"
#include "acute_triangle.h"
#include "prism.h"
#include "list.h"

// Чтение фигур из файла.
void fread_figures(std::ifstream& fin, list<figure*>& list);

// Вывод списока фигур.
void print_figures(list<figure*>& list);

// Поиск треугольника с максимальной стороной и призмы с максимальным объемом.
void search_max_triangle_and_prism(list<figure*>& list, acute_triangle& max_triangle, prism& max_prism);

#endif // FUNCTIONS_H
