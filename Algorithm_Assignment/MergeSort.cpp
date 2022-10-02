#include <iostream>
#include <cstdlib>
#include <random>

void Merge(int *arrayA, int *arrayB, int nA, int nB, int *arrayOut)
{
    int posA = 0, posB = 0, k = 0;
    while (posA < nA && posB < nB)
    {
        if (arrayA[posA] < arrayB[posB])
        {
            arrayOut[k] = arrayA[posA];
            posA++;
        }

        else 
        {
            arrayOut[k] = arrayB[posB];
            posB++;
        }
        k++;
    }
    
    for ( ; posA < nA; posA++)
    {
        arrayOut[k] = arrayA[posA];
        k++;
    }

    for ( ; posB < nB; posB++)
    {
        arrayOut[k] = arrayB[posB];
        k++;
    }
}

void InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = arr[i];
        for (int j = i; j > 0; j--)
        {
            if (arr[j-1] > tmp)
            {
                arr[j] = arr[j-1];
            }

            else 
            {
                arr[j] = tmp;
                break;
            }
        }

        if (arr[0] > tmp)
        {
            arr[0] = tmp;
        }
    }
}

void MergeSort(int *arr, int first, int last)
{
    if (last - first <= 10)
    {
        InsertionSort(&arr[first], last-first);
    }

    else 
    {
        int midpoint = (first+last)/2;

        MergeSort(arr, first, midpoint);
        MergeSort(arr, midpoint, last);

        int *tmp = new int [last-first];
        Merge(&arr[first], &arr[midpoint], midpoint-first, last-midpoint, tmp);
        
        for (int i = 0; i < last-first; i++)
        {
            arr[first+i] = tmp[i];
        }
        
        delete [] tmp;
    }
}

bool Validate(int n, int *d)
{
	for(int i=1;i<n;i++)
	{
		if( d[i-1] > d[i] )
		{
			return false;
		}
	}
	return true;
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 10000);
    int n = 5000;
    std::cout << n << std::endl;

    int *arr = new int [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = dis(gen);
    }

    MergeSort(arr, 0, n);

    if (Validate(n, arr))
    {
        std::cout << "Sort Succeed!" << std::endl;
    }

    else 
    {
        std::cout << "Failed..." << std::endl;
    }

    std::cout << std::endl;
    delete [] arr;

    return 1;
}