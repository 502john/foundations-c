#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
(binary example)
radix_sort[ arr, n (num items), k (bit length) ]

    Create buckets (16 hexa, 10 deci, 8 octal, 2 binary )
    
    for i in range k 
        
        for j in range n
            
            if bit @ i (right indexed) is 0
                move to bucket #0
            
            
            if bit @ i (right indexed) is 1
                move to bucket #1

            ...
                
        arr = bucket 0 + bucket 1
        
    
*/

void radix_sort(float arr[], int n, int k)
{
    int base = 2;

    float buckets[2][n];
    unsigned int key_buckets[2][n];

    int counts[2];

    unsigned int keys[n];

    for (int j = 0; j < n; j++)
    {
        float val = arr[j];
        unsigned int *p = (unsigned int *) &val;
        unsigned int u = *p;

        if (u & 0x80000000U)
        {
            keys[j] = ~u;
        }
        else
        {
            keys[j] = u ^ 0x80000000U;
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int x = 0; x < base; x++)
        {
            counts[x] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            unsigned int key = keys[j];
            unsigned int bit = (key >> i) & 1U;

            int idx = counts[bit];

            buckets[bit][idx]      = arr[j];
            key_buckets[bit][idx]  = key;
            counts[bit] += 1;
        }

        int arr_idx = 0;
        for (int b = 0; b < base; b++)
        {
            for (int c = 0; c < counts[b]; c++)
            {
                arr[arr_idx]  = buckets[b][c];
                keys[arr_idx] = key_buckets[b][c];
                arr_idx += 1;
            }
        }
    }

    return;
}

void print_arr(float arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%f\n", arr[i]);
    }
    return;
}

int main()
{
    int x;

    if (scanf("%d", &x) != 1)
    {
        return 1;
    }

    if (x < 0 || x > 100)
    {
        return 1;
    }

    float arr[x];

    for (int i = 0; i < x; i++)
    {
        if (scanf("%f", &arr[i]) != 1)
        {
            return 1;
        }
    }

    radix_sort(arr, x, 32);

    for (int i = 0; i < x; i++)
    {
        printf("%f\n", arr[i]);
    }

    return 0;
}
