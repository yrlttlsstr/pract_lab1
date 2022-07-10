#ifndef PRISM_H
#define PRISM_H

#include "acute_triangle.h"

// ����� ������ � ������������� ������������� � ��������� (����������� �� ������ �������������� ������������).
class prism : public acute_triangle {
private:
	// ���� ������: ������.
	double _height;
public:
	// ������������:
	prism();
	prism(double, double, double, double);
	// �����������.
	prism(const prism&);

	// ����������.
	~prism() {};

	// ��������������� ����������.
	prism& operator=(const prism&);

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

#endif // PRISM_H
