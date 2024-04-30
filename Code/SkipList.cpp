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

    void insertElement(int data) {
        SkipNode *current = header;
        SkipNode *update[MAX_LEVEL+1];
        for (int i=0;i<=MAX_LEVEL;i++){
            update[i] = nullptr;
        }

        for(int i=level;i>=0;i--){
            while(current->forward[i] != nullptr && current->forward[i]->data < data)
                current = current->forward[i];
            update[i] = current;

        current = current->forward[0];

        if(current == nullptr || current->data != data) {
            int newLevel = randomLevel();

            if(newLevel > level){
                for(int i=level+1; i<=newLevel;i++)
                    update[i] = header;
                level = newLevel;
            }

            SkipNode *newNode = new SkipNode(data, newLevel);

            for(int i=0;i<=newLevel;i++){
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }
};
bool searchElement(int data) {
    SkipNode *current = header;
    for (int i = level; i >=0; i--) {
        while (current->forward[i] && current->forward[i]->data < data)
            current = current->forward[i];
    }
    current = current->forward[0];
    return current != nullptr && current->data == data;
    
}
void deleteElement(int data) {
        SkipNode *current = header;
        SkipNode *update[MAX_LEVEL +1];
        for (int i = 0; i <= MAX_LEVEL; i++) {
            update[i] = nullptr;
        }

        for (int i = level; i >=0; i--) {
            while (current->forward[i] != nullptr && current ->forward[i]->data < data)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->data == data) {
            for (int i = 0; i <=level; i++) {
                if (update[i]->forward[i] != current)
                    break;
                update[i]->forward[i] = current->forward[i];
            }

            delete current;

            while (level > 0 && header->forward[level] == nullptr)
                level--;
        }
    }

    void displayList() {
        cout << "Skip List: " << endl;
        for (int i = 0; i <= level; i++) {
            SkipNode *node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->data << " ";
                node = node->forward[i];
            }
            cout << endl;
        }
    }
};


