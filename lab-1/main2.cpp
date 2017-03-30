#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   

using namespace std;

const int size = 3;

void fill(int a[size][size], bool zeros)
{
    srand (time(NULL));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int data = rand() % 5 + 1;
            if(zeros)
                data = 0;
            a[i][j]= data;
        }
    }
}

void multiplication(int a[size][size], int b[size][size], int c[size][size]){
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                c[i][j] += a[i][k] * b[k][j];
}

void multi_six(int a[size][size], int b[size][size], int c[size][size]){
    int s = 1;
    int temp = 0;
    for(int jj=0; jj<size; jj+= s){
        for(int kk=0; kk<size; kk+= s){
            for(int i=0; i<size; i++){
                for(int j = jj; j<((jj+s)>size?size:(jj+s)); j++){
                    temp = 0;
                    for(int k = kk; k<((kk+s)>size?size:(kk+s)); k++){
                        temp += a[i][k]*b[k][j];
                    }
                    c[i][j] += temp;
                }
            }
        }
    }
}

void multi_six2(int a[size][size], int b[size][size], int c[size][size]){
    int t=sqrt(size);

    for (int i = 0; i < size; i=i+t)
    {
        for (int j = 0; j < size; j=j+t)
        {
            for (int k = 0; k < size; k=k+t)
            {
                //c[i][j]+=a[i][k]*b[k][j];
                for (int l = i; l < min(i+t,size); ++l)
                {
                    for (int m = j; m < min(j+t,size); ++m)
                    {
                        int sum=0;
                        for (int n = k; n < min(k+t,size); ++n)
                        {
                            sum+=a[l][n]*b[n][m];
                        }
                        c[l][m]=sum;
                    }
                }
            }
        }
    }
}

void print_matriz(int m[size][size]){
    for (int i = 0; i < size; ++i){        
        for (int j = 0; j < size; ++j)
            cout <<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}


int main()
{
    /*int a[3][3] = {{1, -2, 5},
                    {4, 2, 6},
                    {7, 0, -1}};

    int b[3][3] = {{-4, 1, -3},
                    {3, -2, 2},
                    {4, 5, 6}};

    int c[3][3] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};*/

    int a[size][size], b[size][size], c[size][size];
    fill(a, false);
    fill(b, false);
    fill(c, false);
    print_matriz(a);
    print_matriz(b);
    /*multi_six(a, b, c);
    print_matriz(c);*/
        
    multi_six2(a, b, c);
    print_matriz(c);

    return 0;
}
