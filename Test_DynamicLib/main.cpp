#include <iostream>
#include <fstream>
#include <Windows.h>

#include "..\DynamicLib\acute_triangle.h"
#include "..\DynamicLib\prism.h"
#include "..\DynamicLib\list.h"
#include "..\DynamicLib\functions.h"
#include "..\DynamicLib\figure.h"

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

	typedef void (*fread_figuresDLL) (std::ifstream&, list<figure*>&);
	fread_figuresDLL fread_figures;
	fread_figures = (fread_figuresDLL)GetProcAddress(load, "fread_figures");
	fread_figures(fin, List);

	typedef void (*print_figuresDLL) (list<figure*>&);
	print_figuresDLL print_figures;
	print_figures = (print_figuresDLL)GetProcAddress(load, "print_figures");
	print_figures(List);

	acute_triangle max_triangle;
	prism max_prism;

	typedef void(*search_max_triangle_and_prismDLL) (list<figure*>&, acute_triangle&, prism&);
	search_max_triangle_and_prismDLL search_max_triangle_and_prism;
	search_max_triangle_and_prism = (search_max_triangle_and_prismDLL)GetProcAddress(load, "search_max_triangle_and_prism");
	search_max_triangle_and_prism(List, max_triangle, max_prism);

	max_triangle.print();
	max_prism.print();

	FreeLibrary(load);

	fin.close();
	return 0;
}