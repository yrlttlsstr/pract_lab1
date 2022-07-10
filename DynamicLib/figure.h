#ifndef FIGURE_H
#define FIGURE_H

#include <string>

// ����������� ����� ������.
class __declspec(dllexport) figure {
public:
	// ����������� �����, ������� ���������� ��� ������.
	std::string virtual type() const = 0;

	//  ����������� �����, ������� �������� ��� ���������� � ������.
	void virtual print() const = 0;
};

#endif // FIGURE_H
