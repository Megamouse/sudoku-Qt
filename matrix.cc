#include "matrix.h"

void sudoku::matrix::init()
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
			if(this->obj[i][j])
			{
				int sig = (1 << (obj[i][j] - 1));
				this->row[i] |= sig;
				this->col[j] |= sig;
				this->block[i/3][j/3] |= sig;
			}
		}
	}
}

int sudoku::matrix::input(int (*mat)[10])
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			this->obj[i][j] = mat[i][j];
		}
	}
	init();
}

sudoku::matrix::matrix(int (*mat)[10]):ra()
{
	input(mat);
}

int sudoku::matrix::dfs(int ni, int nj)
{
	// std::cout << '(' << ni << ',' << nj << ')' << std::endl;
	if (this->obj[ni][nj])
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
		int sig = this->row[ni] | this->col[nj] | this->block[ni/3][nj/3];
		// std::cout << sig << std::endl;
		this->ra.narray();
		for (int i = 0; i < 9; ++i)
		{
			int ri = this->ra.read(i);
			int sign = (1<<(ri-1));
			// std::cout << i;
			if (!(sig & sign))
			{
				// std::cout << std::endl << i << std::endl;
				this->obj[ni][nj] = ri;
				this->row[ni] |= sign;
				this->col[nj] |= sign;
				this->block[ni/3][nj/3] |= sign;
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
				this->obj[ni][nj] = 0;
				this->row[ni] ^= sign;
				this->col[nj] ^= sign;
				this->block[ni/3][nj/3] ^= sign;
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
			mat[i][j] = this->obj[i][j];
			res = res && mat[i][j];
		}
	}
	return res;
}
