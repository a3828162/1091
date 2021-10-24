#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	ifstream fin("test2.bmp", ios::binary | ios::in);
		
	if (!fin)
	{
		cout << "FIle not opened" << endl;
		exit(1);
	}

	fin.seekg(0x36); //跳過開頭54個byte

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
			if (two > 126) //讀到結尾就結束
				break;
			output.push_back(two);
			two = 0, count = 0, IMP.clear();
		}
	}

	cout << output << endl;

	return 0;
}


/*#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
unsigned char* pBmpBuf;

typedef struct
{
	BYTE b;
	BYTE g;
	BYTE r;
}RGB;

int main() 
{
    FILE* fp = fopen("test1.bmp", "rb");

	if (fp == 0)
	{
		cout << "file not opened!" << endl;
		exit(1);
	}

    fseek(fp, sizeof(BITMAPFILEHEADER), 0);

    BITMAPINFOHEADER head;

    fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);

	int height = 0, width = 0;

	height = head.biHeight;
	width = head.biWidth;

	RGB** imp = new RGB *[height]();
	for (int i = 0; i < height; ++i)
		imp[i] = new RGB[width]();
	int size = height * width;


	for (int i = 0; i < height; ++i)
	{
		fread(imp[i], sizeof(RGB), 1, fp);
	}
	for (int i = 0; i < height; ++i)
	{
		cout << imp[i][1] << endl;
	}
	return 0;
}*/