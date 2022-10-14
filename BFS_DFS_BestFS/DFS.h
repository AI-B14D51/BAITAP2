#pragma once
#include "Framework.h"

class DFS : public Framework
{
public:
	DFS(Network *g);
	~DFS();
	double Time_Memory(bool is_ds = true);
	void Input_DFS(string filein);
	int Sum_Of_Mark(int end);
	void DFS_exe(int vt, int end);
	void Print_DFS(int end);
	void Run_DFS(string filein, int begin, int end);
};
