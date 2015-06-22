/*OOP344 WORKSHOP 2 Generic Pointers 
w2.cpp
This Program written By
Hyungi Henry Kim
Student ID: 025 741 125
myseneca ID: hkim142
OOP344 A Winter 2014
to Prof. Kamal-Al-Deen, Hasan*/
#include "w2.h"
#include <iostream>
#include <ctime>
#include <typeinfo>
using namespace std;
template<typename T>
void Chronomeasure()
{
	clock_t t1, t2;
	double elapTime;
	T a, b;
	t1 = clock();
	for (int i = 0; i < 1000000000; i++){
		swap(&a, &b, sizeof(T));
	}
	t2 = clock();
	elapTime = ((double)(t2 - t1) / CLOCKS_PER_SEC);
	cout << "Process time for " << typeid(T).name() << " is " << elapTime << " secs" << endl;
}
void swap(void *a, void*b, int size)
{
	void*temp = a;
	a = b;
	b = temp;
}
int main()
{
	Chronomeasure<int>();
	Chronomeasure<double>();
	Chronomeasure<short>();
	Chronomeasure<unsigned long long>();
	return 0;

