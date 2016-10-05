/**
*作者：Bittersweet
*Date: 2016.10.5
*输入：A=(aij), b = (b1, b2, ..., bn)T, 维数n
*输出：方程组解x1, x2, ..., xn, 或者无解信息
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

bool GaussSolver(vector< vector<double> > &A, int n, double *X);

int main()
{
    int n;
    //Input
    cout<<"Input n:";
    cin>>n;
    vector< vector<double> > A;
    cout<<"Input matrix:"<<endl;
    for(int i = 0; i < n; ++i)
    {
        vector<double> t;
        for(int j = 0; j < n + 1; ++j)
        {
            double tmp;
            cin>>tmp;
            t.push_back(tmp);
        }
        A.push_back(t);
    }
    //solve
    double *X = new double[n];
    bool success = GaussSolver(A, n, X);
    //output
    if(success)
    {
        for(int i = 0; i < n; ++i)
            cout<<"X"<<i + 1<<": "<<X[i]<<endl;
    }
    else
        cout<<"No unique solution!"<<endl;
    return 0;
}

bool GaussSolver(vector< vector<double> > &A, int n, double *X)
{
    for(int k = 0; k < n - 1; ++k)
    {
        int maxi = k;
        for(int i = k; i < n; ++i)
        {
            if(abs(A[i][k]) > abs(A[maxi][k]))
                maxi = i;
        }
        if(A[maxi][k] == 0)
            return false;
        if(maxi != k)
        {
            for(int j = k; j < n + 1; ++j)
                swap(A[k][j], A[maxi][j]);
        }
        for(int i = k + 1; i < n; ++i)
        {
            double l = A[i][k] / A[k][k];
            for(int j = k + 1; j < n + 1; ++j)
            {
                A[i][j] -= l * A[k][j];
            }
        }
    }
    if(A[n - 1][n - 1] == 0)
        return false;
    X[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
    for(int i = n - 2; i >= 0; --i)
    {
        double sum = 0;
        for(int j = i + 1; j < n; ++j)
            sum += A[i][j] * X[j];
        X[i] = (A[i][n] - sum) / A[i][i];
    }
    return true;
}
