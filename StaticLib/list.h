#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

// Класс узла.
template <class Type>
class node {
private:
	// Поля класса: значение, ссылка на предыдущий, ссылка на следующий.
	Type _value;
	node* _previous;
	node* _next;
public:
	// Конструктор.
	node(const Type& value) : _value(value), _previous(nullptr), _next(nullptr) {}

	// Геттеры.
	// Возвращает значение.
	Type get_value() const { return _value; }
	// Возвращает указатель на предыдущий узел.
	node<Type>* get_pervious() const { return _previous; }
	// Возвращает указатель на следующий узел.
	node<Type>* get_next() const { return _next; }

	// Сеттер для значения.
	void set_value(Type value) { _value = value; }

	template <class Type1> friend class list;
};

// Лист.
template <class Type>
class list {
private:
	// Поля класса: ссылки на первый и на последний узлы.
	node<Type>* _first;
	node<Type>* _last;
public:
	// Конструктор.
	list() : _first(nullptr), _last(nullptr) {}
	// Деструктор.
	~list();

	// Проверка списка на пустоту.
	bool is_empty() { return _first == nullptr; }

	// Геттеры.
	// Возвращает значение первого элемента в списке.
	node<Type>* get_front() { return _first; }
	// Возвращает значение последнего элемента в списке.
	node<Type>* get_back() { return _last; }

	// Добавляет элемент в начало списка.
	void push_front(const Type&);
	// Добавляет элемент в конец списка.
	void push_back(const Type&);

	// Функция удаляет первый элемент из ненулевого списка.
	void remove_first();
	// Функция удаляет последний элемент из ненулевого списка.
	void remove_last();

	// Функция доступа к элементам списка по индексу.
	Type get_at_idx(const int idx) const;

	// Печать списка в консоль.
	void print();
	// Печать списка в файл.
	void fprint(std::ofstream&);
};

// Деструктор.
template <class Type>
list<Type>::~list() {
	node<Type>* curr = _first;
	while (curr) {
		node<Type>* temp = curr->_next;
		delete curr;
		curr = temp;
	}
}

// Добавляет элемент в начало списка.
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

// Добавляет элемент в конец списка.
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

// Функция удаляет первый элемент из ненулевого списка.
template <class Type>
void list<Type>::remove_first() {
	// В случае нулевого списка функция никак не изменяет список.
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

// Функция удаляет последний элемент из ненулевого списка.
template <class Type>
void list<Type>::remove_last() {
	// В случае нулевого списка функция никак не изменяет список.
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

// Функция доступа к элементам списка по индексу.
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

// Печать списка в консоль.
template <class Type>
void list<Type>::print() {
	node<Type>* curr = _first;
	while (curr) {
		std::cout << curr->_value << ' ';
		curr = curr->_next;
	}
	std::cout << '\n';
}

// Печать списка в файл.
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