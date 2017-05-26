#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda.h>
#include <iostream>

using namespace std;


void initArray(float* vec, int n) {
    int i;
    for(i=0; i<n; i++)
        vec[i] = rand() % 9 + 1;
}

void initMat(float* mat, int n) {
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            mat[i*n+j] = rand() % 9 + 1;
}

void printVec(float* vector, int size)
{
    for(int i=0; i<n; i++)
        cout << vector[i] << " ";
    cout<<endl;
}

void printMat(float *a, int n) {
    int i, j;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cout<< a[i*n+j] << " ";
    cout<<endl;
    }    
}

__global__
void mulKernel(float *vec, float *mat, float* c, int n)
{
    int i = threadIdx.x + blockDim.x * blockIdx.x ;
    float sum=0;

    if(i < n){
        for(int j=0; j<n; j++)
            sum += vec[j]*mat[(j*n) + i];
        c[i]=sum;
    }
}

void mulVecMat(float* vec, float* mat, int n){
    float* c;
    float* dev_a, * dev_b, * dev_c;

    vec = (float*)malloc(sizeof(float)*n);
    mat = (float*)malloc(sizeof(float)*n*n);
    c = (float*)malloc(sizeof(float)*n);

    initArray(vec, n);
    initMat(mat, n*n);
    initMat(c, n);

    printVec(a, n);
    printMat(b, n);
    printVec(c, n);

    cudaMalloc((void**)&dev_a, sizeof(float)*n);
    cudaMemcpy(dev_a, vec, sizeof(float)*n, cudaMemcpyHostToDevice);

    cudaMalloc((void**)&dev_b, sizeof(float)*n*n);
    cudaMemcpy(dev_b, mat, sizeof(float)*n*n, cudaMemcpyHostToDevice);

    cudaMalloc((void**)&dev_c, sizeof(float)*m);
    mulKernel<<<ceil(n/256.0), 256>>>(dev_a, dev_b, dev_c, n);
    cudaMemcpy(c, dev_c, sizeof(float)*n, cudaMemcpyDeviceToHost);

    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    
    printMat(c, n);
}

int main()
{
    // Size of vectors
    int n = 100;
 
    // Host input vectors
    float* h_a;
    float* h_ma;

    void mulVecMat(h_a, h_ma, n);
    return 0;
}