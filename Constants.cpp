#include "Constants.h"
using namespace std;

Constants::Constants()
{
}

Constants::~Constants()
{
}

ALG Constants::ALGORITHM = aBFS;
int Constants::NUM_THREAD = 70;
int Constants::start = 0;
int Constants::end = 12;
string Constants::FILEIN = "input.in";
int Constants::n_nodes = 20;
int Constants::limit = 10;

// for sensor
// double Constants::EPS = 0.0;
// int Constants::NO_DENOISE_STEPS = 1;