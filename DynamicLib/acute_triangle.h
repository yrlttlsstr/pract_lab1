#ifndef ACUTE_TRIANGLE_H
#define ACUTE_TRIANGLE_H

#define PI 3.14159265

#include <math.h> 
#include "figure.h"

// ����� �������������� ������������ (����������� �� ������ ������).
class __declspec(dllexport) acute_triangle : public figure {
protected:
	// ���� ������: ������ ���� 3 ������.
	double _side[3];
public:
	// ������������:
	acute_triangle();
	acute_triangle(double, double, double);
	// �����������.
	acute_triangle(const acute_triangle&);

	// ����������.
	~acute_triangle() {};

	// ��������������� ����������.
	acute_triangle& operator=(const acute_triangle&);

	// �������.
	// ��� ������.
	double get_side_a() const;
	double get_side_b() const;
	double get_side_c() const;

	// ��� �����.
	double get_angle_a() const;
	double get_angle_b() const;
	double get_angle_c() const;

	// ��� ���������.
	double get_perimeter() const;

	// ��� �������.
	double get_area() const;

	// ����� ���������� ��� �������.
	std::string type() const override { return "trinagle"; };

	// ����� �������� ������.
	void print() const override;
};

#endif // ACUTE_TRIANGLE_H
