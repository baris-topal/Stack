#include <iostream>

using namespace std;

class st {
public:
	int boyut;
	int top;
	int* d;
	int pop(st* s);
	void push(int x, st* s);
	void yazdir(st* s);
	st* tanimla();
	st* stack1;
	st* stack2;
};

st* st::tanimla() {
	st* s = new st;
	s->boyut = 2;
	s->top = -1;
	s->d = NULL;
	return s;
}

int st::pop(st* s) {
	if (s->top <= s->boyut / 2)
	{
		int* d2;
		d2 = new int[s->boyut / 2];
		for (int i = 0; i <= s->top; i++)
			d2[i] = s->d[i];
		s->d = d2;
		s->boyut = s->boyut / 2;
	}
	return s->d[s->top--];
}

void st::push(int x, st* s) {
	if (s->top == -1)
		s->d = new int[s->boyut];

	if (s->top >= s->boyut)
	{
		int* d2;
		d2 = new int[s->boyut * 2];
		for (int i = 0; i <= s->top; i++)
			d2[i] = s->d[i];
		s->d = d2;
		s->boyut = s->boyut * 2;
	}

	s->d[++s->top] = x;
}

void st::yazdir(st* s) {
	if (s->top == -1)
	{
		cout << "Stack Bos\n";
	}
	else {
		for (int i = s->top; i > -1; i--)
			cout << s->d[i] << endl;
	}
}

int main() {
	st st;
	st.stack1 = st.tanimla();
	st.stack2 = st.tanimla();

	for (int i = 0; i < 10; i++)
		st.push(i * 7, st.stack1);

	cout << "Stack1\n";
	st.yazdir(st.stack1);

	cout << "\nStack2\n";
	st.yazdir(st.stack2);

	cout << "\nPop-Push Islemi\n\n";

	for (int i = 0; i < 10; i++) {
		st.push(st.pop(st.stack1), st.stack2);
	}

	cout << "Stack1\n";
	st.yazdir(st.stack1);

	cout << "\nStack2\n";
	st.yazdir(st.stack2);

	system("pause");
}