#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin(argv[1], ios::binary | ios::in);

	if (!fin)
	{
		cout << "FIle not opened" << endl;
		exit(1);
	}

	fin.seekg(0x36);

	char B, G, R;
	int BI, GI, RI, count = 0, two = 0;
	vector<int> IMP;
	string output;

	while (fin.get(B) && fin.get(G) && fin.get(R))
	{
		++count, BI = B, GI = G, RI = R;
		if (BI == 0 && GI == 0 && RI == 0)
			IMP.push_back(1);
		else if (BI == -1 && GI == -1 && RI == -1)
			IMP.push_back(0);

		if (count == 8)
		{
			for (int i = 0; i < count; ++i)
				if (IMP[i] == 1)
					two += pow(2, (7 - i));
			if (two > 126)
				break;
			char give = two;
			output.push_back(give);
			two = 0, count = 0, IMP.clear();
		}
	}

	cout << output << endl;

	return 0;
}