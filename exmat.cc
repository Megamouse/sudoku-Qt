#include "include.h"

int obj[10][10];

int main()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::cin >> obj[i][j];
        }
    }
	sudoku::matrix mat(obj);
	mat.solve();
	if (mat.output(obj))
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
		std::cout << "NO Answer" << std::endl;
    return 0;
}

