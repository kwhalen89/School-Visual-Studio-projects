// PrimsAlgorithm.cpp
// Kurt Whalen
// 4/13/14

#include "stdafx.h"
#include <iostream>
using namespace std;

int prim(int arr[][8])
{
	int node = 1;
	int sum = 0;
	while (node < 8)
	{
		int isl1 = 0;
		int isl2 = 0;
		int possible = 999;
		int count = 0;
		
		while (count < 8)
		{
			if (arr[count][node] == 0)
			{
				count++;
			}
			else
			{
				if (arr[count][node] < possible)
				{
					possible = arr[count][node];
					isl1 = node;
					isl2 = count;
					count++;
				}
				else
				{
					count++;
				}
			}
		}
		sum += possible;
		cout << "Bridge built between " << isl2 + 1 << " and " << isl1 + 1 << "." << endl;
		node++;
	}
	cout << "Total cost of the bridges is: " << sum << "." << endl;
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int edge[8][8] = 
	{
	{ 999, 240, 210, 340, 280, 200, 345, 120 },
	{ 999, 999, 265, 175, 215, 180, 185, 155 },
	{ 999, 999, 999, 260, 115, 350, 435, 195 },
	{ 999, 999, 999, 999, 160, 330, 295, 230 },
	{ 999, 999, 999, 999, 999, 360, 400, 170 },
	{ 999, 999, 999, 999, 999, 999, 175, 205 },
	{ 999, 999, 999, 999, 999, 999, 999, 305 },
	{ 999, 999, 999, 999, 999, 999, 999, 999 }
	};
	prim(edge);
	edge[0][7] = 220;
	prim(edge);
	return 0;
}

