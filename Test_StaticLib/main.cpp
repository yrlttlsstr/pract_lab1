#include <iostream>
#include <fstream>

#include "..\StaticLib\acute_triangle.h"
#include "..\StaticLib\prism.h"
#include "..\StaticLib\list.h"
#include "..\StaticLib\functions.h"
#include "..\StaticLib\figure.h"

int main() {
	list<figure*> list;
	std::ifstream fin("input.txt");

	fread_figures(fin, list);
	print_figures(list);
	acute_triangle max_triangle;
	prism max_prism;
	search_max_triangle_and_prism(list, max_triangle, max_prism);
	max_triangle.print();
	max_prism.print();

	fin.close();
	return 0;
}