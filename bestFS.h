#pragma once
#include "Framework.h"

class bestFS : public Framework
{
public:
    bestFS(Network *g);
    ~bestFS();
    double Time_Memory(bool is_ds = true);
    void input_BestFS(string filein);
    void best_first_search(int actual, int target, int n);
};
