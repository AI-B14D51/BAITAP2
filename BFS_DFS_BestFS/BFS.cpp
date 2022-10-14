#include <iostream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <utility>
#include <queue>

#include "BFS.h"
#include "Constants.h"
#include "memory.h"
using namespace std;

BFS::BFS(Network *g) : Framework(g)
{
}

BFS::~BFS()
{
}

#define max 100
#define maxr 9999999

typedef pair<int, int> ii;
vector<ii> grpBFS[max];
int d[max];

int check[max];

void BFS::Input_BFS(string filein)
{
    fstream fin;
    fin.open(filein, ios::in);
    while (!fin.eof())
    {
        int u, v, w;
        fin >> u >> v >> w;
        grpBFS[u].push_back(make_pair(v, w));
        grpBFS[v].push_back(make_pair(u, w));
    }
    fin.close();
}

void BFS::Print_BFS(int begin, int end)
{
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "BFS\n";
    fout << "Duong di : " << endl;
    fout << end << " <= ";
    int i = check[end];
    while (i != begin)
    {
        fout << i << " <= ";
        i = check[i];
    }
    fout << begin;
    fout << endl
         << "Do dai duong di : " << d[end] << endl;
         
    double vm, rss;
    process_mem_usage(vm, rss);
    fout << "\nMemory BFS: "<< "VM: " << vm << " KB"<< "; RSS: " << rss << "KB" << endl;
    fout.close();
}

void BFS::BFS_exe(int root, int n)
{
    priority_queue<ii, vector<ii>, greater<ii>> road;
    for (int i = 0; i <= n; i++)
    {
        d[i] = maxr;
    }
    d[root] = 0;
    road.push(ii(root, 0));
    while (!road.empty())
    {
        ii top = road.top();
        road.pop();
        int u = top.first;
        if (d[u] != top.second)
            continue;

        for (int i = 0; i < grpBFS[u].size(); i++)
        {
            int v = grpBFS[u][i].first;
            int uv = grpBFS[u][i].second;
            if (d[v] > d[u] + uv)
            {
                d[v] = d[u] + uv;
                road.push(ii(v, d[v]));
                check[v] = u;
            }
        }
    }
}

void BFS::Run_BFS(string filein, int begin, int end)
{

    clock_t start = clock();
    Input_BFS(filein);
    BFS_exe(begin, Constants::n_nodes);
    Print_BFS(begin, end);
    clock_t stop = clock();
    
    double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    fstream fout;
    fout.open("output.out", ios::app);
    fout << "Thoi gian BFS: " << time * 1000 << " miliseconds";
    fout.close();
}

double BFS::Time_Memory(bool is_ds)
{

    Run_BFS(Constants::FILEIN, Constants::start, Constants::end);
    return 0.0;
}
