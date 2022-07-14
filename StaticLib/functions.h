#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

#include "figure.h"
#include "acute_triangle.h"
#include "acute_prism.h"
#include "list.h"

// ������ ����� �� �����.
void fread_figures(std::ifstream&, list<figure*>&);

// ����� ������� �����.
void print_figures(list<figure*>&);

// ����� ������������ � ������������ ��������.
void search_max_triangle(list<figure*>&, acute_triangle&);

// ����� ������ � ������������ �������.
void search_max_prism(list<figure*>&, acute_prism&);

#endif // FUNCTIONS_H
