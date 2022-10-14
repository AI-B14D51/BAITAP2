#include <iostream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "DFS.h"
#include "Constants.h"
#include "memory.h"
using namespace std;

DFS::DFS(Network *g) : Framework(g)
{
}

DFS::~DFS()
{
}

#define max 100
#define INT32_MAX
int length_road = INT32_MAX;
vector<int> grpDFS[max];
vector<int> mark;
vector<int> result;
bool visited[max];
int matrix[max][max];

void DFS::Input_DFS(string filein)
{
    fstream fin;
    fin.open(filein, ios::in);
    while (!fin.eof())
    {
        int x, y, z;
        fin >> x >> y >> z;
        grpDFS[x].push_back(y);
        grpDFS[y].push_back(x);
        matrix[x][y] = z;
        matrix[y][x] = z;
    }
    fin.close();
}

int DFS::Sum_Of_Mark(int end)
{
    int res = 0;
    for (int i = 0; i < (int)mark.size() - 1; i++)
    {
        res += matrix[mark[i]][mark[i + 1]];
    }
    return res + matrix[mark[mark.size() - 1]][end];
}

void DFS::DFS_exe(int vt, int end)
{
    for (int i = 0; i < grpDFS[vt].size(); i++)
    {
        int v = grpDFS[vt][i];
        if (!visited[v])
        {
            visited[v] = true;
            if (v == end)
            {
                int distance = Sum_Of_Mark(end);
                if (length_road > distance)
                {
                    length_road = distance;
                    result = mark;
                }
                visited[v] = false;
            }
            else
            {
                mark.push_back(v);
                DFS_exe(v,end);
                visited[v] = false;
                mark.pop_back();
            }
        }
    }
}

void DFS::Print_DFS(int end)
{
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "DFS" << endl;
    fout << "Duong di: " << endl;
    for (int i = 0; i < result.size(); i++)
        fout << result[i] << " => ";
    fout << end << endl;
    fout << "Do dai duong di: " << length_road << endl;
    
    double vm, rss;
    process_mem_usage(vm, rss);
    fout << "Memory DFS: "<< "VM: " << vm << " KB"<< "; RSS: " << rss << "KB" << endl;
    fout.close();
}

void DFS::Run_DFS(string filein, int begin, int end)
{
    clock_t start = clock();
    Input_DFS(filein);
    mark.push_back(begin);
    visited[begin] = true;
    DFS_exe(begin, end);
    Print_DFS(end);
    clock_t stop = clock();
    
    double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    fstream fout;
    fout.open("output.out", ios::out | ios::trunc);
    fout << "Thoi gian DFS: " << time * 1000 << " miliseconds";
    fout.close();
}

double DFS::Time_Memory(bool is_ds)
{
    Run_DFS(Constants::FILEIN, Constants::start, Constants::end);
    return 0.0;
}
