#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>

void Swap(int *arr, int a, int b)
{
    if (a == b)
    {
        return;
    }

    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void InsertionSort(int *arr, int first, int last)
{
    for (int i = first+1; i < last; i++)
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

        if (arr[first] > tmp)
        {
            arr[first] = tmp;
        }
    }
}

void MedianSort(int *arr, int a, int b, int c)
{
    if (arr[a] > arr[b])
    {
        if (arr[b] > arr[c])
        {
            Swap(arr, b, c);
            Swap(arr, a, b);
        }
        else if (arr[a] > arr[c])
        {
            Swap(arr, a, b);
        }
        else
        {
            Swap(arr, a, c);
            Swap(arr, a, b);
        }
    }

    else 
    {
        if (arr[a] > arr[c])
        {
            Swap(arr, a, c);
        }
        else if (arr[b] > arr[c])
        {
            return;
        }
        else 
        {
            Swap(arr, b, c);
        }
    }
}

void QuickSort(int *arr, int first, int last)
{
    //std::cout << "Sorting... " << first << " " << last << std::endl;
    if (last - first <= 10)
    {
        InsertionSort(arr, first, last);
        //return;
    }

    else 
    {
        MedianSort(arr, first, (first+last)/2, last-1);

        //std::cout << "Pivot(idx) : " << pivot << "(" << pivot_idx << ")" << std::endl;
        int pivot = arr[last - 1];
        int low = first + 1;
        int high = last - 2;

        while (arr[low] < pivot)
        {
            low++;
        }

        while (arr[high] > pivot)
        {
            high--;
        }

        while (low < high)
        {    
            //std::cout << "low : " << low << " high : " << high << std::endl;
            Swap(arr, low, high);
            low++;
            high--;

            while (arr[low] < pivot)
            {
                low++;
            }

            while (arr[high] > pivot)
            {
                high--;
            }
        }

        arr[last - 1] = arr[low];
        arr[low] = pivot;

        QuickSort(arr, first, low);
        QuickSort(arr, high, last);
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
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dist(0, 100000);
    int n = dist(gen);
    std::cout << n << std::endl;
    //std::cin >> n;

    int *arr = new int [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(gen);
        //std::cin >> arr[i];
    }

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    QuickSort(arr, 0, n);

    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::chrono::milliseconds elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    double res_time = elapsed_time.count();

    if (Validate(n, arr))
    {
        std::cout << "Sort Succeed" << std::endl << res_time << std::endl;
    }

    else 
    {
        std::cout << "Failed!!!" << std::endl;
    }

    delete [] arr;

    return 1;
}