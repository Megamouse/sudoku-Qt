#ifndef _INCLUDE
	#include <cstdio>
	#include <iostream>
	#include <algorithm>

	#define INF 0x3f3f3f3f
	#define _INCLUDE 
#endif

namespace sudoku{
	class matrix{
		public:
		void solve();
		int output(int (*mat)[10]);
		matrix(int (*mat)[10]);

		private:
		int obj[10][10];
		int row[10];
		int col[10];
		int block[5][5];
		int dfs(int ni, int nj);
	};
}
