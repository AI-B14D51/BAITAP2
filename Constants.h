#include <string>
#pragma once
using namespace std;

enum ALG
{
	aDFS,
	aBFS,
	abestFS
};

class Constants
{
public:
	Constants();
	~Constants();

	static ALG ALGORITHM;
	static int NUM_THREAD;
	static int start;
	static int end;
	static string FILEIN;
	static int n_nodes;
	static int limit;
};
