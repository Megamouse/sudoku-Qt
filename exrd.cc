#include <iostream>
#include "rdarray.h"

int main()
{
	sudoku::rdarray ra;

	for (int i = 0; i < 9; ++i)
	{
		ra.narray();
		for (int j = 0; j < 9; ++j)
		{
			std::cout << ra.read(j) << ' ';
		}
		std::cout << std::endl;
	}
}
