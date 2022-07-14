#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

#include "figure.h"
#include "acute_triangle.h"
#include "acute_prism.h"
#include "list.h"

// Чтение фигур из файла.
void fread_figures(std::ifstream&, list<figure*>&);

// Вывод списока фигур.
void print_figures(list<figure*>&);

// Поиск треугольника с максимальной стороной.
void search_max_triangle(list<figure*>&, acute_triangle&);

// Поиск призмы с максимальным объемом.
void search_max_prism(list<figure*>&, acute_prism&);

#endif // FUNCTIONS_H
