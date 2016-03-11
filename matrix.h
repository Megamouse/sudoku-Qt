#ifndef _MATRIX
	#include "rdarray.h"
	
	#define _MATRIX
#endif

namespace sudoku{
	class matrix{
		public:
		void solve();
		int output(int (*mat)[10]);
		int input(int (*mat)[10]);
		matrix(int (*mat)[10]);

		private:
		int obj[10][10];
		int row[10];
		int col[10];
		int block[5][5];
		sudoku::rdarray ra;
		int dfs(int ni, int nj);
		void init();
	};
}
