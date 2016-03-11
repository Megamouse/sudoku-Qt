#include "include.h"

sudoku::matrix::matrix(int (*mat)[10])
{
	for (int i = 0; i < 9; ++i)
	{
		this->row[i] = this->col[i] = 0;
		this->block[i/3][i%3] = 0;
	}
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (mat[i][j])
			{
				(this->obj)[i][j] = mat[i][j];
				int sig = (1 << ((this->obj)[i][j]-1));
				// std::cout << sig << std::endl;
				(this->row)[i] |= sig;
				(this->col)[j] |= sig;
				(this->block)[i/3][j/3] |= sig;
			}
			else (this->obj)[i][j] = 0;
		}
	}
	/*
	for (int i = 0; i < 9; ++i)
	{
		std::cout << row[i] << std::endl;
	}
	*/
}

int sudoku::matrix::dfs(int ni, int nj)
{
	// std::cout << '(' << ni << ',' << nj << ')' << std::endl;
	if ((this->obj)[ni][nj])
	{
		if (nj+1 < 9)
			return dfs(ni, nj+1);
		else if (ni+1 < 9)
			return dfs(ni+1, 0);
		else
			return 1;
	}
	else
	{
		int sig = (this->row)[ni] | (this->col)[nj] | (this->block)[ni/3][nj/3];
		// std::cout << sig << std::endl;
		for (int i = 0; i < 9; ++i)
		{
			// std::cout << i;
			if (!(sig & (1<<i)))
			{
				// std::cout << std::endl << i << std::endl;
				int sign = 1<<i;
				(this->obj)[ni][nj] = i+1;
				(this->row)[ni] |= sign;
				(this->col)[nj] |= sign;
				(this->block)[ni/3][nj/3] |= sign;
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
				// (this->obj)[ni][nj] = 0;
				(this->row)[ni] ^= sign;
				(this->col)[nj] ^= sign;
				(this->block)[ni/3][nj/3] ^= sign;
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
			mat[i][j] = (this->obj)[i][j];
			res = res && mat[i][j];
		}
	}
	return 1;
}
