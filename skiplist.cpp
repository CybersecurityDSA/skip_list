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

void SkipList::insertElement(int key)
{
    SkipNode* current = header ;
    SkipNode* update[MAX_LEVEL + 1];
    for (int i 0; i<= MAX_LEVEL; i++)
        update[i] = nullptr;

    for (int i = level; i >= 0; i--)
{
    while (current->forward[i] != nullptr && current->forward[i]->key< key)
            current = current->forward[i];
    update[i] = current;
}

current = currentforward[0];

level

if (current == nullptr || current->key != key)
{
    int newlevel = randomLevel();
 value with header
    if (newlevel > level)
{
    for (int i = level + 1; i <= newlevel; i++)
        update[i] = header;
    level = newlevel;
}

SkipNode* newNode = createNode(key, newlevel);

for (int i = 0; i <= newlevel; i++)
{
    newNode->forward[i] = update[i]->forward[i];
    update[i]->forward[i] = newNode;
}
cout << "Element " << key << " inserted successfully." << end1;
}

else {
    cout << "Element " << key << " already exists in the list." << end1;
}
}

bool SkpList::searchElement(int key)
{
    SkipNode* current = header;
    for (int i = level; i >= 0; i--)
{
    while (current->forward[i] != nullptr && current->forward[i]->key < key)
        current = current->forward[i];
}
    current = current->forward[0];

    if (current != nullptr && current->key == key)
        return true;
    return false;
}

                      
    

