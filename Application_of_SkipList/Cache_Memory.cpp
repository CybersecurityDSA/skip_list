#include <iostream>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

const int MAX_LEVEL = 16;

struct skipnode
{
  int key;
  int value;
  skipnode **forward;
  skipnode *prev;

  skipnode(int level, int key, int value) : key(key), value(value), prev(nullptr)
  {
    forward = new skipnode *[level + 1]();
  }

  ~skipnode()
  {
    delete[] forward;
  }
};

class skiplistcache
{
  int level;
  int capacity;
  int size;
  skipnode *header;
  std::unordered_map<int, skipnode *> keyMap;

public:
  skiplistcache(int capacity) : capacity(capacity), size(0)
  {
    level = 0;
    header = new skipnode(MAX_LEVEL, -1, -1);
  }

  ~skiplistcache()
  {
    clear();
    delete header;
  }

  int randomlevel()
  {
    int lvl = 0;
    while ((float)rand() / RAND_MAX < 0.5 && lvl < MAX_LEVEL)
    {
      lvl++;
    }
    return lvl;
  }

  void insert(int key, int value)
  {
    if (keyMap.find(key) != keyMap.end())
    {
      skipnode *node = keyMap[key];
      node->value = value;
      movetofront(node);
      return;
    }

    skipnode *current = header;
    skipnode *update[MAX_LEVEL + 1] = {};

    for (int i = level; i >= 0; i--)
    {
      while (current->forward[i] != nullptr && current->forward[i]->key < key)
      {
        current = current->forward[i];
      }
      update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->key != key)
    {
      int newlevel = randomlevel();

      if (newlevel > level)
      {
        for (int i = level + 1; i <= newlevel; i++)
        {
          update[i] = header;
        }
        level = newlevel;
      }

      skipnode *newnode = new skipnode(newlevel, key, value);
      for (int i = 0; i <= newlevel; i++)
      {
        newnode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newnode;
      }

      newnode->prev = update[0];
      if (newnode->forward[0] != nullptr)
      {
        newnode->forward[0]->prev = newnode;
      }

      keyMap[key] = newnode;
      size++;

      if (size > capacity)
      {
        removeLRU();
      }
    }
  }

  void removeLRU()
  {
    if (size <= 0)
      return;

    skipnode *current = header->prev;
    if (current == nullptr)
      return;

    keyMap.erase(current->key);

    for (int i = 0; i <= level; i++)
    {
      if (header->forward[i] == current)
      {
        header->forward[i] = current->forward[i];
      }
    }

    if (current->forward[0] != nullptr)
    {
      current->forward[0]->prev = current->prev;
    }

    delete current;
    size--;
  }

  void movetofront(skipnode *node)
  {
    if (node == nullptr || node == header->prev)
      return;

    skipnode *prevnode = node->prev;
    skipnode *nextnode = node->forward[0];

    if (prevnode != nullptr)
    {
      prevnode->forward[0] = nextnode;
    }
    if (nextnode != nullptr)
    {
      nextnode->prev = prevnode;
    }

    node->prev = header;
    node->forward[0] = header->forward[0];

    if (header->forward[0] != nullptr)
    {
      header->forward[0]->prev = node;
    }

    header->forward[0] = node;
  }

  int get(int key)
  {
    if (keyMap.find(key) != keyMap.end())
    {
      skipnode *node = keyMap[key];
      movetofront(node);
      return node->value;
    }
    return -1;
  }

  bool contains(int key)
  {
    return keyMap.find(key) != keyMap.end();
  }

  int getSize() const
  {
    return size;
  }

  void clear()
  {
    skipnode *current = header->forward[0];
    while (current != nullptr)
    {
      skipnode *temp = current;
      current = current->forward[0];
      keyMap.erase(temp->key);
      delete temp;
    }

    for (int i = 0; i <= MAX_LEVEL; ++i)
    {
      header->forward[i] = nullptr;
    }

    size = 0;
    level = 0;
  }

  void display()
  {
    std::cout << "Cache Contents: " << std::endl;
    for (int i = MAX_LEVEL; i >= 0; --i)
    {
      skipnode *node = header->forward[i];
      std::cout << "Level " << i << ": ";
      while (node != nullptr)
      {
        std::cout << "(Key: " << node->key << ", Value: " << node->value << ") ";
        node = node->forward[i];
      }
      std::cout << std::endl;
    }
  }
};

int main()
{
  srand(static_cast<unsigned>(time(0)));

  std::cout << "Enter the capacity of cache: ";
  int capacity;
  std::cin >> capacity;

  skiplistcache cache(capacity);

  std::string choice;
  do
  {
    std::cout << "\nMenu: \n1. Insert\n2. Get\n3. Check if Key Exists\n4. Cache Size\n5. Clear Cache\n6. Display\n7. Exit\nEnter Your Choice: ";
    std::cin >> choice;

    if (choice == "1")
    {
      int key, value;
      std::cout << "Enter key to insert: ";
      std::cin >> key;
      std::cout << "Enter value for key " << key << " to insert: ";
      std::cin >> value;
      cache.insert(key, value);
    }
    else if (choice == "2")
    {
      int key;
      std::cout << "Enter key to get value: ";
      std::cin >> key;
      int value = cache.get(key);
      if (value != -1)
      {
        std::cout << "Value for key " << key << ": " << value << std::endl;
      }
      else
      {
        std::cout << "Key not found in cache." << std::endl;
      }
    }
    else if (choice == "3")
    {
      int key;
      std::cout << "Enter key to check if it exists: ";
      std::cin >> key;
      if (cache.contains(key))
      {
        std::cout << "Key " << key << " exists in cache." << std::endl;
      }
      else
      {
        std::cout << "Key " << key << " does not exist in cache." << std::endl;
      }
    }
    else if (choice == "4")
    {
      std::cout << "Cache Size: " << cache.getSize() << std::endl;
    }
    else if (choice == "5")
    {
      cache.clear();
      std::cout << "Cache cleared." << std::endl;
    }
    else if (choice == "6")
    {
      cache.display();
    }
    else if (choice != "7")
    {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while (choice != "7");

  return 0;
}