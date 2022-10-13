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
vector<ii> graphbfs[max];
int d[max];

int check[max];

void BFS::input_bfs(string filein)
{
    fstream fin;
    fin.open(filein, ios::in);
    while (!fin.eof())
    {
        int u, v, w;
        fin >> u >> v >> w;
        graphbfs[u].push_back(make_pair(v, w));
        graphbfs[v].push_back(make_pair(u, w));
    }
    fin.close();
}

void BFS::print_dfs(int begin, int destination)
{
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "BFS\n";
    fout << "Path : " << endl;
    fout << destination << " <= ";
    int i = check[destination];
    while (i != begin)
    {
        fout << i << " <= ";
        i = check[i];
    }
    fout << begin;
    fout << endl
         << "Length : " << d[destination] << endl;
    double vm, rss;
    process_mem_usage(vm, rss);
    fout << "\nMemory: "
         << "VM: " << vm << " KB"
         << "; RSS: " << rss << "KB" << endl;
    fout.close();
}

void BFS::bfs_execute(int root)
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
        int u = top.fi;
        if (d[u] != top.se)
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graphbfs[u][i].fi;
            int uv = graphbfs[u][i].se;
            if (d[v] > d[u] + uv)
            {
                d[v] = d[u] + uv;
                road.push(ii(v, d[v]));
                check[v] = u;
            }
        }
    }
}

void BFS::run_bfs(string filein, int begin, int destination)
{

    clock_t start = clock();
    input_bfs(filein);
    bfs_execute(begin);
    print_dfs(begin, destination);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    fstream fout;
    fout.open("output.out", ios::app);
    fout << "Time taken by bfs: " << time_taken * 1000 << " miliseconds";
    fout.close();
}

double BFS::get_solution(bool is_ds)
{

    run_bfs(Constants::FILEIN, Constants::start, Constants::end);
    return 0.0;
}