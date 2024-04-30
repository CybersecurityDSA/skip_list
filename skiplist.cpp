#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_LEVEL = 5;

struct SkipNode 
{
    int key;
    SkipNode* forword[MAX_LEVEL + 1];
};

class SkipList
{
 public:
    Skiplist();
    void insertElement(int key);
    bool searchElement(int key);
    void deleteElement(int key);
    void displayList();

 private:
    int randomLevel();
    SkipNode* createNode(int key, int level);
    SkipNode* header;
    int level;
}
//Constructor
SkipList::SkipList()
{
    header = new SkipNode;
    header->key = INI_MAX;
    for (int i = 0; i <= MAX_LEVEL; i++)
        header->forword[i] = nullptr;
    level = 0;
}

int SkipList::randomLevel()
{
    int lvl = 0;
    while (rand() % 2 && lvl <bMAX_LEVEL)
        lvl++;
    return lvl;
}

SkipNode* SkipList::createNode(int key, int level)
{
    SkipNode* newNode = new SkipNode;
    newNode->key = key;
    for (int i = 0; i<= level; i++)
        newNode->forward[i] = nullptr;
    return newNode;
}
