#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>

#include "figure.h"
#include "acute_triangle.h"
#include "acute_prism.h"
#include "list.h"

// ������ ����� �� �����.
__declspec(dllexport) void fread_figures(list<figure*>&);

// ����� ������� �����.
__declspec(dllexport) void print_figures(list<figure*>&);

// ����� ������������ � ������������ ��������.
__declspec(dllexport) void search_max_triangle(list<figure*>&, acute_triangle&);

// ����� ������ � ������������ �������.
__declspec(dllexport) void search_max_prism(list<figure*>&, acute_prism&);

#endif // FUNCTIONS_H
