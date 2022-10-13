#include<iostream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "BestFS.h"
#include "Constants.h"

#include "memory.h"
using namespace std;

BestFS::BestFS(Network * g) : Framework(g)
{
}

BestFS::~BestFS()
{
}

#define MAX 100
int dMin2 = 1e8;                   // đường đi ngắn nhất BestFS
vector<bool> visited2(MAX, false); // các đỉnh đã ghé thăm BestFS
vector<int> mark2, res2;            // Lưu vết đường đi
vector<int> trongso2={20,10,5,0,30,12,16,25,24,22,16,11,19,10,8,15,17,18,19,20};

void BestFS::InitBestFS(string filein, int n, int s, int t, vector<vector<int>> &Matrix)
{
    fstream fin;
    fin.open(filein, ios::in);
    Matrix = vector<vector<int>>(MAX, vector<int>(MAX, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Matrix[i][j] = 0;
    while (!fin.eof())
    {
        int u, v;
        fin >> u >> v;
        Matrix[u][v] = 1;
        Matrix[v][u] = 1;
    }
    fin.close();
}

int BestFS::sumOfMark(vector<vector<int>> Matrix)
{
    int res = 0;
    for (int i = 0; i < mark2.size() - 1; i++)
    {
        res += trongso2[i];
    }
    return res;
}

void BestFS::alg_BestFS(int n, int u, int t, vector<vector<int>> Matrix)
{
    int trongsomin=100;
    for (int i = 0; i < n; i++)
    {
        if(!visited2[i] && Matrix[u][i]&&trongso2[i]< trongsomin){
            trongsomin=trongso2[i];
            }
    for (int i = 0; i < n; i++)
    {
        if(!visited2[i] && Matrix[u][i]&&trongso2[i]== trongsomin){
            mark2.push_back(i);
            visited2[i] = true;
            if (i == t)
            {
                if (sumOfMark(Matrix) < dMin2)
                {
                    dMin2 = sumOfMark(Matrix);
                    res2 = mark2;
                }
                break;
                mark2.pop_back();
                visited2[i] = false;

            }
            else
            {
                alg_BestFS(n, i, t, Matrix);
                mark2.pop_back();
                visited2[i] = false;
            }
            }

        }
    }
}

void BestFS::ResultBestFS(int s, int t){
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "BestFS\n";
    fout << "Duong di ngan nhat tu " << s << " den " << t << " la:" << endl;
    for (int i = 0; i < res2.size() - 1; i++)
    {
        fout << res2[i] << "=>";
    }
    fout << res2[res2.size() - 1];
    fout << endl;
    fout << "Do dai duong di la : ";
    fout << dMin2;
    double vm, rss;
    process_mem_usage(vm, rss);
    fout << "\nMemory: " << "VM: " << vm << " KB" << "; RSS: " << rss << "KB" << endl;
    fout.close();
}

void BestFS::runBestFS(string filein, int n, int s, int t, vector<vector<int>> &Matrix) {
    clock_t start = clock();
    InitBestFS(filein, n, s, t, Matrix);
    mark2.push_back(s);
    visited2[s] = true;
    alg_BestFS(n, s, t, Matrix);
    ResultBestFS(s, t);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    fstream fout;
    fout.open("output.out", ios::app);
    fout << "thoi gian: " << time_taken * 1000 << " miliseconds";
    fout.close();
}

double BestFS::get_solution(bool is_ds)
{
	vector<vector<int>> Matrix;
    runBestFS(Constants::FILEIN, Constants::n_nodes, Constants::start, Constants::end, Matrix);
	return 0.0;
}
