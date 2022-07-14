#ifndef ACUTE_PRISM_H
#define ACUTE_PRISM_H

#include "acute_triangle.h"

// ����� ������ � ������������� ������������� � ��������� (����������� �� ������ �������������� ������������).
class __declspec(dllexport) acute_prism : public acute_triangle {
private:
	// ���� ������: ������.
	double _height;
public:
	// ������������:
	acute_prism();
	acute_prism(double, double, double, double);
	// �����������.
	acute_prism(const acute_prism&);

	// ����������.
	~acute_prism() {};

	// ��������������� ����������.
	acute_prism& operator=(const acute_prism&);

	// �������.
	// ��� ������.
	double get_volume() const;
	// ��� ������� �����������.
	double get_surface_area() const;

	// ����� ���������� ��� �������.
	std::string type() const override { return "prism"; };

	// ����� �������� ������.
	void print() const override;
};

#endif // ACUTE_PRISM_H
