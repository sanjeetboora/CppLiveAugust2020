#include <bits/stdc++.h>
using namespace  std;

int main()
{
	int n = 9;
	cout << "sizeof(n) => " << sizeof(n) << endl;
	cout << "&n =>" << &n << endl;

	//type cast address to number
	// long long int ptrN = (long long int)&n;
	// cout << "ptrN =>" << ptrN << endl;

	int *ptrN = &n;
	cout << "ptrN =>" << ptrN << endl;
	cout << "sizeof(ptrN) => " << sizeof(ptrN) << endl;
	cout << "*ptrN =>" << *ptrN << endl; //dereference

	cout << "-------------------------" << endl;
	// bool b = false;
	// cout << "&b =>" << &b << endl;

	// bool* ptrB = &b;
	// cout << "ptrB =>" << ptrB << endl;


	//address of pointer
	cout << "&ptrN => " << &ptrN << endl;

	int** ptrptrN = &ptrN;
	cout << "ptrptrN => " << ptrptrN << endl;
	cout << "sizeof(ptrptrN) => " << sizeof(ptrptrN) << endl;
	cout << "&ptrptrN => " << &ptrptrN << endl;
	cout << "*ptrptrN => " << *ptrptrN << endl;
	cout << "**ptrptrN => " << **ptrptrN << endl;
	cout << "-------------------------" << endl;

	int*** ptrPtrPtrN = &ptrptrN;
	cout << "ptrPtrPtrN => " << ptrPtrPtrN << endl;
	cout << "sizeof(ptrPtrPtrN) => " << sizeof(ptrPtrPtrN) << endl;
	cout << "*ptrPtrPtrN => " << *ptrPtrPtrN << endl;
	cout << "***ptrPtrPtrN => " << ***ptrPtrPtrN << endl;
	cout << "-------------------------" << endl;
	bool b =  true;
	bool* ptrB = &b;
	cout << "ptrB => " << ptrB << endl;
	cout << "sizeof(ptrB) => " << sizeof(ptrB) << endl;
	cout << "*ptrB => " << *ptrB << endl;
	cout << "-------------------------" << endl;

	long long int lli =  12345678910;
	cout << "lli => " << lli << endl;
	int i_lli = (int)lli;
	cout << "i_lli => " << i_lli << endl;

	long long int lli2 = i_lli;


	return 0;
}




