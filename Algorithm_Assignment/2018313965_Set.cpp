#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int Find_Set(int x, int *parent)
{
    while (parent[x] != x)
    {
        x = parent[x];
    }

    return x;
}

void Union_Set(int x, int y, int *parent, int *height)
{
    x = Find_Set(x, parent);
    y = Find_Set(y, parent);

    if (height[x] == height[y])
    {
        parent[y] = x;
        height[x]++;
    }

    else if (height[x] > height[y])
    {
        parent[y] = x;
    }

    else 
    {
        parent[x] = y;
    }
}

bool Check(int x, int y, int *parent)
{
    if (Find_Set(x, parent) == Find_Set(y, parent))
    {
        return true;
    }

    else 
    {
        return false;
    }
}

int main(int argc, char **argv)
{
    int n, m;
    //std::cin >> n >> m;
    std::ifstream read_txt;
    read_txt.open(argv[1]);
    read_txt >> n >> m;
    
    int *parent = new int [n];
    int *height = new int [n];
    std::vector<char> output;
    std::ofstream write_txt;
    write_txt.open(argv[2]);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        read_txt >> a >> b >> c;

        if (a == 0)
        {
            Union_Set(b, c, parent, height);
        }

        else if (a == 1)
        {
            if (Check(b, c, parent) == true)
            {
                write_txt << 'Y' << std::endl;
            }

            else 
            {
                write_txt << 'N' << std::endl;
            }
        }
    }

    return 0;
}