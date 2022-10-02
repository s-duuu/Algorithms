#include <iostream>
#include <vector>

int CountDigit(int N)
{
    int ten_flag = 1;
    int flag = 1;
    while (N / ten_flag != 0)
    {
        if (N / ten_flag == 0)
        {
            break;
        }
        ten_flag *= 10;
        flag ++;
    }
    flag --;
    return flag;
}

int main()
{
    int N;
    std::cin >> N;

    
}