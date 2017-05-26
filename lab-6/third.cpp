
void Count sort (int a[], int n ) {
    int i, j, count;
    int∗ temp = malloc(n ∗sizeof(int));
    for(i=0; i<n; i++) {
        count = 0;
        for (j= 0; j<n; j++){
            if (a[j] < a[i])
                count ++;
            else if (a[j] == a[i] && j < i )
                count ++;        
        }
        temp[count] = a[i];
    }
    memcpy(a, temp, n ∗sizeof(int));
    free(temp);
}

int main(int argc, char const *argv[])
{
    int a = [1, 5, 6, 2, 3, 8];
    Count(a, 6);
    return 0;
}