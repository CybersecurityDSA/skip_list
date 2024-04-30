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

class SkipList{
    int MAX_LEVEL;
    float P;
    int level;
    SkipNode *header;
public;
    SkipList(int max_lvl,float prob){
        MAX_LEVEL = max_lvl;
        P = prob;
        level = 0;
        heder = new SkipNode(INT_MIN,MAX_LEVEL);
    }

    ~SkipList(){
        delete header;
    }

    int randomLevel(){
        float r = (float)rand() / RAND_MAX;
        itn lvl = 0;
        while(r<P && lvl < MAX_LEVEL){
            lvl++;
            r = (float)rand() / RAND_MAX;
        }
        return lvl;
    }
}
