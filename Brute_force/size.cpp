#include <iostream>

struct size
{
    int weight;
    int height;
};

void compare(size *candidate, int N, int *rank)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }

            else 
            {
                if (candidate[j].height > candidate[i].height && candidate[j].weight > candidate[i].weight)
                {
                    rank[i]++;
                }
            }
        }
    }
}

int main()
{
    int N;
    std::cin >> N;

    size *candidate = new size [N];
    int *rank = new int [N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> candidate[i].weight >> candidate[i].height;
        rank[i] = 1;
    }

    compare(candidate, N, rank);
    
    for (int i = 0; i < N; i++)
    {
        std::cout << rank[i] << " ";
    }

    return 0;
}