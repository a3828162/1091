#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <climits>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    //ifstream infile("ex2.csv", ios::in);
    ifstream infile(argv[1], ios::in);

    if (!infile)
    {
        cout << "File could not be open\n";
        exit(1);
    }

    vector<vector<double>> in;

    string q, w;
    stringstream sn, sm;
    double a;

    while (infile >> q)
    {
        vector<double> tmp;
        sn.str("");
        sn.clear();
        sn << q;
        while (getline(sn, w, ','))
        {
            sm.str("");
            sm.clear();
            sm << w;

            sm >> a;
            tmp.push_back(a);
        }

        in.push_back(tmp);
    }

    int Case = 0;
    for (int i = 0; i < in.size(); ++i)
    {
        int n = (int)in[i].size(), p = 0;
        double* xreal = new double[n]();
        double* ximag = new double[n]();

        for (int j = 0; j < n; ++j)
        {
            xreal[j] = in[i][j];
        }

        double* wreal = new double[n / 2]();
        double* wimag = new double[n / 2]();

        int m, k, j, t, index1, index2;

        for (int i = 1; i < n; i *= 2) p++;

        for (int i = 0; i < n; ++i)
        {
            int a = i, b = 0;
            for (int j = 0; j < p; ++j) b = (b * 2) + (a & 1), a /= 2;
            if (b > i) std::swap(xreal[i], xreal[b]), std::swap(ximag[i], ximag[b]);
        }

        double arg = -2 * M_PI / n;
        double treal = cos(arg), timag = sin(arg);
        wreal[0] = 1.0, wimag[0] = 0.0;

        for (j = 1; j < n / 2; j++)
        {
            wreal[j] = wreal[j - 1] * treal - wimag[j - 1] * timag;
            wimag[j] = wreal[j - 1] * timag + wimag[j - 1] * treal;
        }

        for (m = 2; m <= n; m *= 2)
        {
            for (k = 0; k < n; k += m)
            {
                for (j = 0; j < m / 2; j++)
                {
                    index1 = k + j;
                    index2 = index1 + m / 2;
                    t = n * j / m;
                    treal = wreal[t] * xreal[index2] - wimag[t] * ximag[index2];
                    timag = wreal[t] * ximag[index2] + wimag[t] * xreal[index2];
                    double ureal = xreal[index1];
                    double uimag = ximag[index1];
                    xreal[index1] = ureal + treal;
                    ximag[index1] = uimag + timag;
                    xreal[index2] = ureal - treal;
                    ximag[index2] = uimag - timag;
                }
            }
        }

        cout << "Data " << ++Case << " :\n";

        for (int j = 0; j < in[i].size(); ++j) cout << setprecision(4) << fixed << xreal[j] << " " << ximag[j] << "\n";
        //for (int j = 0; j < in[i].size(); ++j) cout << setprecision(4) << fixed << 0.0000 << " " << 0.0000 << "\n";
        if (i != in.size() - 1)
        {
            cout << "\n";
        }

        delete[] xreal, ximag, wreal, wimag;
    }
    return 0;
}
