#include <iostream>
#include <cstdlib>
#include <vector>

struct Grade
{
    int document;
    int interview;
};

void Insert(std::vector<int> &reduction, int index)
{
    int flag = 0;
    for (int i = 0; i < reduction.size(); i++)
    {
        if (reduction.at(i) == index)
        {
            flag++;
        }
    }

    if (flag == 0)
    {
        reduction.push_back(index);
    }
}

void Check(Grade *grades, int N, std::vector<int> &nums)
{
    std::vector<int> reduction;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (grades[j].document > grades[i].document && grades[j].interview > grades[i].interview)
            {
                Insert(reduction, j);
            }

            else if (grades[i].document > grades[j].document && grades[i].interview > grades[j].interview)
            {
                Insert(reduction, i);
            }
        }
    }

    nums.push_back(N - reduction.size());
}


int main()
{
    int T, N;
    std::vector<int> nums;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        Grade *grades = new Grade [N];
        for (int j = 0; j < N; j++)
        {
            std::cin >> grades[j].document >> grades[j].interview;
        }

        Check(grades, N, nums);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums.at(i) << std::endl;
    }

    return 0;

}