#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
	Matrix A(3);
	Matrix B(3);
	Matrix C(3);
	
	// 1 method for assigning data	
	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 5;
	A[1][0] = 3;
	A[1][1] = 9;
	A[1][2] = 11;
	A[2][0] = 4;
	A[2][1] = 24;
	A[2][2] = 17;
	
	
	// 2 method for assigning data
	B.setDate(0,0,12);
	B.setDate(0,1,24);
	B.setDate(0,2,5);
	
	B.setDate(1,0,4);
	B.setDate(1,1,19);
	B.setDate(1,2,13);
	
	B.setDate(2,0,14);
	B.setDate(2,1,8);
	B.setDate(2,2,5);
	
	C[0][0] = 1;
	C[1][1] = 5;
	C[2][1] = 8;
	C[2][2] = 10;
	
	
	cout<<"\nMatrix A:\n\n";
	cout<<A;
	cout<<"\nMatrix B:\n\n";
	cout<<B;
	cout<<"\nMatrix C:\n\n";
	cout<<C;
	
	cout<<"\n\n/////// Adding two matrices ///////";
	cout<<"\nMatrix A + Matrix B:\n\n";
	cout<<A+B;
	
	cout<<"\n\n/////// Multiplication of two matrices ///////";
	cout<<"\nMatrix A * 5.4:\n\n";
	cout<<A*5.4;
	
	cout<<"\n\n/////// Multiplication of a number by a matrix ///////";
	cout<<"\n5.4 * B:\n\n";
	cout<<5.4*B;
	
	cout<<"\n\n/////// Multiplication of a number by a matrix ///////";
	cout<<"\nMatrix C:\n\n";
	cout<<C;
	cout<<"\n6 * C:\n\n";
	cout<<6*C;
	
	
	Matrix D(A);
	cout<<"\nMatrix D:\n\n";
	cout<<D;
	
	cout<<"\n\n/////// Assigning matrix B to matrix D ---- D = B ///////";
	D = B;
	cout<<"\nMatrix D:\n\n";
	cout<<D;
	
	Matrix G(3);
	
	cout<<"\n\n/////// Sum of matrices B and A assigned to matrix G ///////";
	G = B + A;
	cout<<"\nMatrix G:\n\n";
	cout<<G;
	
	
	cout<<"\n\n/////// Matrix multiplication by matrix ///////";
	cout<<"\nMatrix D * Matrix G:\n\n";
	cout<<D*G;
	
	
	// Entering data into the matrix by the user
	/*
	Matrix H(3);
	cout<<"\n\n/////// Matrix H ///////\n\n";
	cin>>H;
	cout<<"\n\nMatrix H:\n\n"<<H;
	*/
	
	cout<<"\nhttps://github.com/hubert-m\n";
	return 0;
}
