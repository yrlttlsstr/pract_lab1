#include <iostream>
#include <fstream>
#include <Windows.h>

#include "acute_triangle.h"
#include "acute_prism.h"
#include "list.h"
#include "functions.h"
#include "figure.h"

int main() {
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");

	if(load == 0){
		printf("Ошибка - не могу найти proba.dll\n");
		system("pause");
		return 0;
	}

	list<figure*> List;
	std::ifstream fin("input.txt");

	typedef void (*fread_figuresDLL) (list<figure*>&);
	fread_figuresDLL fread_figures;
	fread_figures = (fread_figuresDLL)GetProcAddress(load, "fread_figures");
	fread_figures(List);

	typedef void (*print_figuresDLL) (list<figure*>&);
	print_figuresDLL print_figures;
	print_figures = (print_figuresDLL)GetProcAddress(load, "print_figures");
	print_figures(List);

	acute_triangle max_triangle;
	acute_prism max_prism;

	typedef void(*search_max_triangleDLL) (list<figure*>&, acute_triangle&);
	search_max_triangleDLL search_max_triangle;
	search_max_triangle = (search_max_triangleDLL)GetProcAddress(load, "search_max_triangle");
	search_max_triangle(List, max_triangle);

	typedef void(*search_max_prismDLL) (list<figure*>&, acute_prism&);
	search_max_prismDLL search_max_prism;
	search_max_prism = (search_max_prismDLL)GetProcAddress(load, "search_max_prism");
	search_max_prism(List, max_prism);

	max_triangle.print();
	max_prism.print();

	FreeLibrary(load);
	return 0;
}