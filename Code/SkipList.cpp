#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class SkipNode{
    public:
        int data;
        SkipNode **forward;

        SkipNode(int data, int level){
            this->data = data;
            forward = new SkipNode *[level + 1];
            for(int i =0;i<=level;i++){
                forward[i] = nullptr;
            }

        }

        ~SkipNode(){
            delete[] forward;
        }

};


