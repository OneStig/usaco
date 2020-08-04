/*
ID: stevenh6
TASK: prefix
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ofstream fout("prefix.out");
ifstream fin("prefix.in");

int point;
int cache[200050];
string read[201];
string sum;

int main()
{
	string in;

	while (fin >> in)
	{
		if (in == ".")
		{
			break;
		}

		read[point] = in;
		point++;
	}

	fin.ignore(1);

	while (getline(fin, in))
	{
		sum += in;
	}

	cache[0] = 1;
	for (int i = 0; i < sum.length(); i++)
	{
		if (cache[i])
		{
			for (int j = 0; j < point; j++)
			{
				string port = sum.substr(i, read[j].length());
				if (read[j] == port)
				{
					cache[i + read[j].length()] = 1;
				}
			}
		}
	}

	for (int i = sum.length(); i >= 0; i--)
	{
		if (cache[i])
		{
			fout << i << endl;
			return 0;
		}
	}
}