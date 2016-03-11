#include "include.h"


sudoku::matrix::matrix(int (*mat)[10])
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			obj[i][j] = mat[i][j];
			int sig = 1 << (obj[i][j]-1);
			row[i] |= sig;
			col[j] |= sig;
			block[i/3][j/3] |= sig;
		}
	}
}

int sudoku::matrix::dfs(int ni, int nj)
{
	if (obj[ni][nj])
	{
		if (nj+1 < 9)
			return dfs(ni, nj+1);
		else if (ni+1 <9)
			return dfs(ni+1, 0);
		else
			return 1;
	}
	else
	{
		int sig = row[ni] | col[nj] | block[ni/3][nj/3];
		for (int i = 0; i < 9; ++i)
		{
			if (!(sig & (1<<i)))
			{
				obj[ni][nj] = i+1;
				row[ni] |= 1<<i;
				col[nj] |= 1<<i;
				block[ni/3][nj/3] |= 1<<i;
				if (nj+1 < 9)
				{
					if (dfs(ni, nj+1) > 0)
						return 1;
				}
				else if (ni+1 < 9)
				{
					if (dfs(ni+1, 0) > 0)
						return 1;
				}
				else
				{
					return 1;
				}
				row[ni] ^= 1<<i;
				col[nj] ^= 1<<i;
				block[ni/3][nj/3] ^= 1<<i;
			}
		}
		return -1;
	}
}

void sudoku::matrix::solve()
{
	dfs(0, 0);
}

int sudoku::matrix::output(int (*mat)[10])
{
	int res = 1;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			mat[i][j] = obj[i][j];
			res = res && mat[i][j];
		}
	}
	return 1;
}
