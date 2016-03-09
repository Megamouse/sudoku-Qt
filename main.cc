#include <cstdio>
#include <iostream>
#include <algorithm>

int obj[10][10];
int row[10]; // ---
int col[10]; // |||
int box[5][5]; // ::

int init()
{
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if (obj[i][j])
            {
                int sig = (1 << (obj[i][j]-1));
                row[i] |= sig;
                col[j] |= sig;
                box[i/3][j/3] |= sig;
            }
        }
    }

    return 0;
}

int dfs(int ni, int nj)
{
    if (obj[ni][nj])
    {
        if(nj+1 < 9)
            return dfs(ni, nj+1);
        else if(ni+1 < 9)
            return dfs(ni+1, 0);
        else
            return 1;
    }
    else
    {
        int sig = row[ni] | col[nj] | box[ni/3][nj/3];
        // std::cout << sig << std::endl;
        for (int i = 0; i < 9; ++i)
        {
            if (!(sig & (1<<i)))
            {
                obj[ni][nj] = i+1;
                int sign = 1<<i;
                row[ni] |= sign;
                col[nj] |= sign;
                box[ni/3][nj/3] |= sign;

                if(nj+1 < 9)
                {
                    if (dfs(ni, nj+1) > 0) return 1;
                }
                else if(ni+1 < 9)
                {
                    if (dfs(ni+1, 0) > 0) return 1;
                }
                else
                    return 1;

                obj[ni][nj] = 0;
                row[ni] ^= sign;
                col[nj] ^= sign;
                box[ni/3][nj/3] ^= sign;
            }
        }

        return -1;
    }
}

int main()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::cin >> obj[i][j];
        }
    }

    init();

    if(dfs(0, 0) > 0)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                std::cout << obj[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
    else
        std::cout << "No Solution" << std::endl;
    
    return 0;
}

