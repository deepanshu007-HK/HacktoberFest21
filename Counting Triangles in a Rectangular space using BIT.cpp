
#include<bits/stdc++.h>
#define maxn 2005
using namespace std;


int bit[maxn][maxn];

void update(int x, int y)
{
	int y1;
	while (x < maxn)
	{

		y1 = y;
		while ( y1 < maxn )
		{
			bit[x][y1]++;
			y1 += ( y1 & -y1 );
		}

		x += x & -x;
	}
}

int query(int x, int y)
{
	int res = 0, y1;
	while (x > 0)
	{

		y1 = y;
		while (y1 > 0)
		{
			res += bit[x][y1];
			y1 -= y1 & -y1;
		}


		x -= x & -x;
	}
	return res;
}

int pointsInRectangle(int x1, int y1, int x2, int y2)
{


	return query(x2, y2) - query(x1 - 1, y2) -W
		query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}


int findTriangles(int n)
{

	return (n * (n - 1) * (n - 2)) / 6;
}


int main()
{
	//inserting points
	update(2, 2);
	update(3, 5);
	update(4, 2);
	update(4, 5);
	update(5, 4);

	cout << "No. of triangles in the rectangle (1, 1)"
			" (6, 6) are: "
		<< findTriangles(pointsInRectangle(1, 1, 6, 6));

	update(3, 3);

	cout << "\nNo. of triangles in the rectangle (1, 1)"
			" (6, 6) are: "
		<< findTriangles( pointsInRectangle(1, 1, 6, 6));

	return 0;
}
