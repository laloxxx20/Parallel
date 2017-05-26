#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda.h>
#include <iostream>
#include <time.h>       /* time */

using namespace std;


__global__
void vecAddKernel(float* A, float* B, float* C, int n)
{
    int i = threadIdx.x + blockDim.x * blockIdx.x;
    if(i<n) C[i] = A[i] + B[i];
}

void print_vec(float* vector, int size)
{
    for(int i=0; i<size; i++)
        cout << vector[i] << " ";
    cout<<endl;
}

void vecAdd(float* A, float* B, float* C, int n)
{
    int size = (n * sizeof(float)) * 2;
    A = (float*)malloc(size);
    C = (float*)malloc(size);
    B = (float*)malloc(size);
    srand (time(NULL));

    for( int i = 0; i < n; i++ ) 
    {
        A[i] = rand() % n + 1;
        B[i] = rand() % n + 1;
    }

    print_vec(A, size);
    cout<<"-------------"<<endl;
    print_vec(B, size);

    float *d_A, *d_B, *d_C;

    cudaMalloc((void**)&d_A, size);
    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);

    cudaMalloc((void**)&d_B, size);
    cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);

    cudaMalloc((void**)&d_C, size); 
    vecAddKernel<<<ceil((float)n/256.0), 256>>>(d_A, d_B, d_C, n);
    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);

    cudaFree(d_A); 
    cudaFree(d_B); 
    cudaFree(d_C);

    print_vec(C, size);
}

int main()
{
    // Size of vectors
    int n = 50;
 
    // Host input vectors
    float* h_a;
    float* h_b;
    float* h_c;

    vecAdd(h_a, h_b, h_c, n);
    return 0;
}