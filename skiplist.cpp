#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_LEVEL = 5;

struct SkipNode 
{
    int key;
    SkipNode* forword[MAX_LEVEL + 1];
};
