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

bool LUSolver(vector< vector<double> > &A, int n, double *X);

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
    bool success = LUSolver(A, n, X);
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

bool LUSolver(vector< vector<double> > &A, int n, double *X)
{

}
