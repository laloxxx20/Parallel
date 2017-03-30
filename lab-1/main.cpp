#include <iostream>
#include <algorithm>

using namespace std;

const int size = 3;

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
    int s = 1;
    int temp = 0;
    for(int i0=0; i0<size; i0++){
        for(int j0=0; j0<size; j0++){
            for(int k0=0; k0<size; k0++){
                for(int i=i0; i<std::min(i0+i-1, size); i++){
                    for(int j = j0; j<std::min(j0+j-1, size); j++){
                        temp = 0;
                        for(int k = k0; k<std::min(k0+k-1, size); k++){
                            c[i][j] = c[i][j] + a[i][k]*b[k][j];
                        }
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
    int a[3][3] = {{1, -2, 5},
                    {4, 2, 6},
                    {7, 0, -1}};

    int b[3][3] = {{-4, 1, -3},
                    {3, -2, 2},
                    {4, 5, 6}};

    int c[3][3] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};

    multiplication(a, b, c);
    print_matriz(c);
    /*multi_six(a, b, c);
    print_matriz(c);
    multi_six2(a, b, c);
    print_matriz(c);*/

    return 0;
}