#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void printmatriks(int matriks[4][4])
{
	for(int i=0; i<4; i++)
	{
		for(int j= 0; j < 4; j++)
		{
			cout << matriks[i][j] << ' ';
		}
		cout<< endl;
	}

}

int main(){
	int matriks[4][4];

	for(int i=0; i < 4; i++)
	{
		for(int j=0; j<4; j++)
		{
			srand(time(NULL));
			matriks[i][j] = rand()%100;
			usleep(900000);
		}
	}
	printmatriks(matriks);

	return 0;


}