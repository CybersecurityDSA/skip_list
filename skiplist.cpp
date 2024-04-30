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
    while (rand() % 2 && lvl <MAX_LEVEL)
        lvl++;
    return lvl;
}

SkipNode* SkipList::createNode(int key, int level)
{
    SkipNode* newNode = new SkipNode;
    newNode->key = key;
    for (int i = 0; i<= level; i++)
        newNode->forword[i] = nullptr;
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
    while (current->forword[i] != nullptr && current->forword[i]->key< key)
            current = current->forword[i];
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
    newNode->forword[i] = update[i]->forword[i];
    update[i]->forword[i] = newNode;
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
    while (current->forword[i] != nullptr && current->forword[i]->key < key)
        current = current->forword[i];
}
    current = current->forword[0];

    if (current != nullptr && current->key == key)
        return true;
    return false;
}

void SkipList::deleteElement(int key)
{
    SkipNode* current = header;
    SkipNode* update[MAX_LEVEL + 1];
    for (int i = 0; i <= MAXLEVEL; i++)
        update[i] = nullptr;

    for(int i = level; i>= o; i--)
{
    while (current->forword[i] != nullptr && current->forword[i]->key < key)
            current = current->forword[i];
    update[i] = current;
}

 current = current->forword[0];

if (current != nullptr && current->key == key)
{
    for (int i = 0; i <= level; i++)
{
    if (update[i]->forword[i] != current)
        break;
    update[i]->forword[i] = current->forword[i];
}

    while (level > 0 && header->forword[level] == nullptr)
        level--;

    delete current;
    cout << "Element " << key << " deleted successfully." << end1;
}
    else {
cout << "Element " << key << " not found in the list." << end1;
    }
}

void SkipList::displayList()
{
    cout << "Skip list level wise: \n";
    for (int i = 0; i <= level; i++)
{
    SkipNode* node = header->forword[i];
    cout << " level " << i << ": " ;
    while (node != nullptr)
{
    cout << node->key << " ";
    node = node->forword[i];
}
    cout << end1;
}

}

int main() 
 {
    srand((unsigned)time(nullptr));

    SkipList skipList;

    int choice, key;
    while (true)
{
    cout << "\nSkip List Operations:" << end1;
    cout << "1. Insert Element" << end1;
    cout << "2. Search Element" << end1;
    cout << "3. Delete Element" << end1;
    cout << "4. Display List" << end1;
    cout << "5. Exit" << end1;
    cin >> choice;

    switch (choice)
{
case 1:
    cout << "Enter element to insert: ";
    cin >> key;
    skipList.insertElement(key);
    break;
case 2:
    cout << "Enter element to search: ";
    cin >> key;
    if(skipList.searchElement((key))
        cout << "Elememt " << Key << " is in the list." << end1;        
    else
        cout << "Element " << key << " is not in the list." << end1;
    break;
case 3:
    cout << "Enter element to delete: ";
    cin >> key;
    skipList.deleteElement(key);
    break;
case 4:
    skipList.displayList();
    break;
case 5:
    cout << "Exirting..." << end1;
    exit(0);
default:
    cout << " Invalid choice ! Pleace try again." << end1;
}
}

return;
 }

                      
    

