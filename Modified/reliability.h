#ifndef _RELIABILITY_H
#define _RELIABILITY_H

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


// Function Prototypes
float R(float p, int e, vector< vector<int> > S);
void d_comparison(int n, int e, vector< vector<int> > S_1, vector< vector<int> > S_2);

#endif
