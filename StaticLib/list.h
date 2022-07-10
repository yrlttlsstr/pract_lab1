#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

// ����� ����.
template <class Type>
class node {
private:
	// ���� ������: ��������, ������ �� ����������, ������ �� ���������.
	Type _value;
	node* _previous;
	node* _next;
public:
	// �����������.
	node(const Type& value) : _value(value), _previous(nullptr), _next(nullptr) {}

	// �������.
	// ���������� ��������.
	Type get_value() const { return _value; }
	// ���������� ��������� �� ���������� ����.
	node<Type>* get_pervious() const { return _previous; }
	// ���������� ��������� �� ��������� ����.
	node<Type>* get_next() const { return _next; }

	// ������ ��� ��������.
	void set_value(Type value) { _value = value; }

	template <class Type1> friend class list;
};

// ����.
template <class Type>
class list {
private:
	// ���� ������: ������ �� ������ � �� ��������� ����.
	node<Type>* _first;
	node<Type>* _last;
public:
	// �����������.
	list() : _first(nullptr), _last(nullptr) {}
	// ����������.
	~list();

	// �������� ������ �� �������.
	bool is_empty() { return _first == nullptr; }

	// �������.
	// ���������� �������� ������� �������� � ������.
	node<Type>* get_front() { return _first; }
	// ���������� �������� ���������� �������� � ������.
	node<Type>* get_back() { return _last; }

	// ��������� ������� � ������ ������.
	void push_front(const Type&);
	// ��������� ������� � ����� ������.
	void push_back(const Type&);

	// ������� ������� ������ ������� �� ���������� ������.
	void remove_first();
	// ������� ������� ��������� ������� �� ���������� ������.
	void remove_last();

	// ������� ������� � ��������� ������ �� �������.
	Type get_at_idx(const int idx) const;

	// ������ ������ � �������.
	void print();
	// ������ ������ � ����.
	void fprint(std::ofstream&);
};

// ����������.
template <class Type>
list<Type>::~list() {
	node<Type>* curr = _first;
	while (curr) {
		node<Type>* temp = curr->_next;
		delete curr;
		curr = temp;
	}
}

// ��������� ������� � ������ ������.
template <class Type>
void list<Type>::push_front(const Type& value) {
	if (is_empty()) {
		push_back(value);
		return;
	}
	node<Type>* new_elem = new node<Type>{ value };
	new_elem->_next = _first;
	_first->_previous = new_elem;
	_first = new_elem;
}

// ��������� ������� � ����� ������.
template <class Type>
void list<Type>::push_back(const Type& value) {
	node<Type>* new_elem = new node<Type>{ value };
	if (is_empty()) {
		_first = new_elem;
		_last = new_elem;
		return;
	}
	_last->_next = new_elem;
	new_elem->_previous = _last;
	_last = new_elem;
}

// ������� ������� ������ ������� �� ���������� ������.
template <class Type>
void list<Type>::remove_first() {
	// � ������ �������� ������ ������� ����� �� �������� ������.
	if (is_empty()) return;
	if (_last == _first) {
		delete _first;
		_first = _last = nullptr;
		return;
	}
	node<Type>* curr = _first;
	_first = curr->_next;
	_first->_previous = nullptr;
	delete curr;
}

// ������� ������� ��������� ������� �� ���������� ������.
template <class Type>
void list<Type>::remove_last() {
	// � ������ �������� ������ ������� ����� �� �������� ������.
	if (is_empty()) return;
	if (_last == _first) {
		delete _last;
		_first = _last = nullptr;
		return;
	}
	node<Type>* curr = _last;
	_last = _last->_previous;
	_last->_next = nullptr;
	delete curr;
}

// ������� ������� � ��������� ������ �� �������.
template <class Type>
Type list<Type>::get_at_idx(const int idx) const {
	int pos = 0;
	node<Type>* curr = _first;
	if (is_empty() == true) throw 1;
	while (curr and pos < idx) {
		curr = curr->_next;
		pos++;
	}
	if (idx > pos || idx < 0) throw 1;
	return curr->_value;
}

// ������ ������ � �������.
template <class Type>
void list<Type>::print() {
	node<Type>* curr = _first;
	while (curr) {
		std::cout << curr->_value << ' ';
		curr = curr->_next;
	}
	std::cout << '\n';
}

// ������ ������ � ����.
template <class Type>
void list<Type>::fprint(std::ofstream& fout) {
	node<Type>* curr = _first;
	while (curr) {
		fout << curr->_value << ' ';
		curr = curr->_next;
	}
	fout << '\n';
}

#endif // LIST_H