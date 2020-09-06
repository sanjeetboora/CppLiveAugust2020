#include <bits/stdc++.h>
using namespace std;

// outputDataType functionName(inputDataType1 inputName1, inputDataType2 inputName2) {
// 	outputDataType value;

// 	return value;
// }


int fact(int N) {
	cout << "inside fact 1 argument" << endl;
	int factN =  1;
	//factorial of N
	for (int i = 1; i <= N; ++i)
	{
		factN = factN * i;
	}
	return factN;

}

int fact(int N, int R) {
	cout << "inside fact 2 argument" << endl;
	int factN =  1;
	//factorial of N
	for (int i = 1; i <= N; ++i)
	{
		factN = factN * i;
	}
	return factN;

}

//redefinition error
// int fact(int N, int X) {
// 	cout << "inside fact 2 argument -- version 2" << endl;
// 	int factN =  1;
// 	//factorial of N
// 	for (int i = 1; i <= N; ++i)
// 	{
// 		factN = factN * i;
// 	}
// 	return factN;

// }




int main() {

	int n = 5;
	int r = 2;
	// int factN =  1;
	// //factorial of N
	// for (int i = 1; i <= n; ++i)
	// {
	// 	factN = factN * i;
	// }

	// cout << factN << endl;

	// int factR =  1;
	// //factorial of R
	// for (int i = 1; i <= r; ++i)
	// {
	// 	factR = factR * i;
	// }

	// cout << factR << endl;


	// int factNR =  1;
	// //factorial of R
	// for (int i = 1; i <= (n - r); ++i)
	// {
	// 	factNR = factNR * i;
	// }

	// cout << factNR << endl;



	//function call
	//	cout << "fact(n) : " << fact(n) << endl;
	// int factN = fact(n); //function call
	// cout << "factN : " << factN << endl;
	// int factR = fact(r); //function call
	// int factNR = fact(n - r); //function call

	//int nCr = factN / (factR * factNR);
//	int nCr = fact(n) / (fact(r) * fact(n - r));


	cout << fact(5) << endl;
	cout << fact(5, 2) << endl;




	//cout << "nCr " << nCr << endl;
}








