#ifndef _RELIABILITY_H
#define _RELIABILITY_H

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


// Function Prototypes
long double R(long double p, int e, int d, vector< vector<int> > S);
int max(vector<int> d0, int size);
void print(vector<int> d0, int size);
void d_comparison(int n, int e, vector< vector<int> > S_1, vector< vector<int> > S_2);

#endif
