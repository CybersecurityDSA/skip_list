#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>

using namespace std;

class SkipNode{
    public:
        string data;
        SkipNode **forward;

        SkipNode(string data, int level){
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
public:
    SkipList(int max_lvl,float prob){
        MAX_LEVEL = max_lvl;
        P = prob;
        level = 0;
        header = new SkipNode("INT_MIN",MAX_LEVEL);
    }

    ~SkipList(){
        delete header;
    }

    int randomLevel(){
        float r = (float)rand() / RAND_MAX;
        int lvl = 0;
        while(r<P && level < MAX_LEVEL){
            lvl++;
            r = (float)rand() / RAND_MAX;
        }
        return level;
    }

    void insertElement(string data) {
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
}
bool searchElement(string data) {
    SkipNode *current = header;
    for (int i = level; i >=0; i--) {
        while (current->forward[i] && current->forward[i]->data < data)
            current = current->forward[i];
    }
    current = current->forward[0];
    return current != nullptr && current->data == data;
    
}
void deleteElement(string data) {
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
            cout<<"Element "<<data<<" is deleted"<<endl;

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

int main() {
    srand((unsigned)time(0));
    SkipList skipList(3, 0.5);

    int choice;
    string element;
    do {
        cout << "\n1. Insert Element";
        cout << "\n2. Delete Element";
        cout << "\n3. Search Element";
        cout << "\n4. Display Skip List";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

         
        
        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> element;
                skipList.insertElement(element);
                break;
            case 2 :
                cout << "Enter the element to be deleted: ";
                cin >> element;
                skipList.deleteElement(element);
                break;
            case 3 :
                cout << "Enter the element to be searched: ";
                cin >> element;
                if (skipList.searchElement(element))
                    cout << "Element found." << endl;
                else 
                    cout << "Element not found." << endl;
                break;
            case 4 :
                skipList.displayList();
                break;
            case 5 :
                cout << "Exiting....";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice !=5);

    return 0;
}


