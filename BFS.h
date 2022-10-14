#pragma once
#include "Framework.h"

class BFS : public Framework
{
public:
	BFS(Network *g);
	~BFS();
	double Time_Memory(bool is_ds = true);
	void Input_BFS(string filein);
	void Print_BFS(int begin, int end);
	void BFS_exe(int root, int n);
	void Run_BFS(string filein, int begin, int end);
};
