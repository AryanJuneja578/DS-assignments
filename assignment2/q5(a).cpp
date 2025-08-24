#include <iostream>
using namespace std;

int main()
{
	int matrix[3][3]= {{20,0,0},
		{0,30,0},
		{0,0,40}
	};
	int size=sizeof(matrix[0])/sizeof(matrix[0][0]);

	int diag[size];

	for(int i=0; i<3; i++) {
		diag[i]=matrix[i][i];
	}

	return 0;
}
