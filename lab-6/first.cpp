#include "stdio.h" 
#include <vector>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <omp.h>

using namespace std;

vector<float>  total_vector;
int size = 30;

void fill_vector(int size, int range_init, int range_end){
    float ran = 0;
    srand (time(NULL));

    for(int i=0; i<size; i++)
    {
        ran = rand() % range_end + range_init;
        total_vector.push_back(ran);
    }
}

void print_vector(vector<float> vectorr){
    for (int i = 0; i<vectorr.size(); ++i)
    {
        cout<<vectorr[i]<<" ";
    }
}

void calculate_chunk(){
    cout<<endl;
    int my_rank = omp_get_thread_num();
    /*cout<<"my_rank: "<<my_rank<<endl;*/
    vector<float> block;
    for(int i=0; i < size; i++){
        if (total_vector[i] <= my_rank && total_vector[i] > my_rank - 1){
            /*cout<<"total_vector[i]: "<<total_vector[i]<<endl;*/
            block.push_back(total_vector[i]);
        }
    }

    cout<<"PRINTING ONE BLOCK OF BLOCK: "<<my_rank<<endl;
    print_vector(block);
}

int main(int argc, char *argv[])
{

    fill_vector(30, 0.0, 10.0);
    print_vector(total_vector);

    int thread_count = strtol(argv[1], NULL, 10);
    /*cout<<"thread_count: "<<thread_count<<endl;*/

    #pragma omp parallel num_threads(thread_count)
    {
        calculate_chunk();
    }

    return(0);
}
