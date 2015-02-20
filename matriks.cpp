#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void printmatriks(int** matriks)
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

int** kalimatriks(int** b, int** c)
{
	int** a = new int*[4];
	for (int i = 0; i < 4; ++i)
	{
	   	a[i] = new int[4];
	}

   int i,j,k;
//#pragma omp parallel shared(a,b,c) private(i,j,k) 
  // {
//#pragma omp for  schedule(static)
   for (i=0; i<4; i=i+1){
      for (j=0; j<4; j=j+1){
         a[i][j]=0.;
         for (k=0; k<4; k=k+1){
            a[i][j]=(a[i][j])+((b[i][k])*(c[k][j]));
         }
      }
   }
  // }
   return a;
}

int** generate()
{
	int** matriks = new int*[4];
	for (int i = 0; i < 4; ++i)
	{
	   	matriks[i] = new int[4];
	}

	for(int i=0; i < 4; i++)
	{
		for(int j=0; j<4; j++)
		{
			srand(time(NULL));
			matriks[i][j] = rand()%100;
			usleep(200000);
		}
	}

	return matriks;
}



int main(){

	int** matriks1 = new int*[4]; //generate matriks random pertama
	for (int i = 0; i < 4; ++i)
	   	matriks1[i] = new int[4];
	matriks1 = generate();

	int** matriks2 = new int*[4]; //generate matriks random kedua
	for (int i = 0; i < 4; ++i)
	   	matriks2[i] = new int[4];
	matriks2 = generate();

	cout << "Matriks pertama : " << endl;
	printmatriks(matriks1); cout << endl;
	cout << "Matriks kedua : " << endl;
	printmatriks(matriks2); cout << endl;

	int** matrikshasil = new int*[4]; //generate matriks random kedua
	for (int i = 0; i < 4; ++i)
	   	matrikshasil[i] = new int[4];
	matrikshasil = kalimatriks(matriks1, matriks2);
	cout << "Hasil kali matriks pertama dan kedua : " << endl;
	printmatriks(matrikshasil);

	return 0;


}