// lab 4 prog tech task 2

#include "stdio.h"

using namespace std;


template <typename T>
class element
{
public:
	T value;
	element* next;

	element(T _val)
	{
		value = _val;
		next = nullptr;
	}
};

template <typename T>
class Queue
{
	element<T>* HEAD;
	element<T>* LAST;
public:

	Queue()
	{
		HEAD = new element<T>(0);
		LAST = HEAD;
	}

	void show_q()
	{
		element<T>* ptr = this->HEAD->next;
		cout << "this queue is: ";
		while (ptr != nullptr)
		{
			cout << ptr->value << " ";
			cout << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}

	int operator !()// isEmpty
	{
		return (HEAD->next == nullptr);
	}

	friend ostream& operator<<(ostream& os, Queue<T>* _q)
	{
		if (_q->HEAD->next == nullptr)
		{
			e.setExep((char*)"exeption: Q is empty!\n");
			throw e;
		}
		element<T>* memo = _q->HEAD->next->next;
		os << "pop: ";
		myCout(os, &_q->HEAD->next->value);
		os << endl;
		if (_q->HEAD->next == _q->LAST)
		{
			_q->LAST = _q->HEAD;
		}
		delete _q->HEAD->next;
		_q->HEAD->next = memo;
		return os;
	}

	friend istream& operator>>(istream& is, Queue<T>* _q)
	{
		T* new_val = new T;
		cout << "enter value: ";
		myCin(is, new_val);

		element<T>* new_el = new element<T>(*new_val);
		_q->LAST->next = new_el;
		_q->LAST = new_el;
		return is;
	}

	Queue<T>& operator+(Queue<T>& _q2)
	{
		Queue<T>* q1 = this;
		element<T>* last1st = q1->LAST;

		element<T>* head2nd = _q2.HEAD->next;

		while (head2nd != nullptr)
		{
			element<T>* new_el = new element<T>(head2nd->value);
			last1st->next = new_el;
			last1st = new_el;
			q1->LAST = last1st;
			head2nd = head2nd->next;
		}
		return *this;
	}

	int operator-(Queue<T>& _q2)
	{
		element<T>* head1st = HEAD->next;
		element<T>* memo;
		element<T>* prev1st = HEAD;
		element<T>* head2nd = _q2.HEAD->next;

		while (head2nd != nullptr)
		{
			while (head1st != nullptr)
			{
				if (compar(head1st->value, head2nd->value) == 0)
				{
					memo = head1st;
					prev1st->next = head1st->next;
					head1st = prev1st->next;
					if (memo == LAST)
						LAST = prev1st;
					delete memo;
				}
				else
				{
					head1st = head1st->next;
					prev1st = prev1st->next;
				}
			}

			head1st = HEAD->next;
			prev1st = HEAD;
			head2nd = head2nd->next;
		}

		return 0;
	}
};

//EOF