#include <iostream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <queue>
#include "bestFS.h"
#include "Constants.h"
#include "memory.h"
using namespace std;

bestFS::bestFS(Network *g) : Framework(g)
{
}

bestFS::~bestFS()
{
}

typedef pair<int, int> ii;
vector<vector<ii>> grpBest;

void bestFS::input_BestFS(string filein)
{
    fstream fin;
    fin.open(filein, ios::in);
    while (!fin.eof())
    {
        int x, y, z;
        fin >> x >> y >> z;
        grpBest[x].push_back(make_pair(y,z));
        grpBest[y].push_back(make_pair(x,z));
    }
    fin.close();
}

void bestFS::best_first_search(int actual, int target, int n)
{
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "Duong di: ";
    vector<bool> visited(n, false);

    priority_queue<ii, vector<ii>, greater<ii>> prQueue;
    prQueue.push(make_pair(0, actual));
    int s = actual;
    visited[s] = true;
    while (!prQueue.empty())
    {
        int x = prQueue.top().second;

        fout << x << " => ";
        prQueue.pop();
        if (x == target)
            break;

        for (int i = 0; i < grpBest[x].size(); i++)
        {
            if (!visited[grpBest[x][i].second])
            {
                visited[grpBest[x][i].second] = true;
                prQueue.push(make_pair(grpBest[x][i].first, grpBest[x][i].second));
            }
        }
    }
    fout.close();
}

double bestFS::Time_Memory(bool is_ds)
{
    clock_t start = clock();
    
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "Best First Search" << endl;
    fout.close();
    
    input_BestFS(Constants::FILEIN);
    best_first_search(Constants::start, Constants::end, Constants::n_nodes);
    
    clock_t stop = clock();
    double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "Thoi gian Best FS: " << time * 1000 << " miliseconds" << endl;
    
	double vm, rss;
    process_mem_usage(vm, rss);
    fout << "Memory Best FS: "<< "VM: " << vm << " KB"<< "; RSS: " << rss << "KB" << endl;
    fout.close();
    
    return 0.0;
}
