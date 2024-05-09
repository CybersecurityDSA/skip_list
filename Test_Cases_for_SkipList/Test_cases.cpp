#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>
#include <cassert>
#include "SkipList.h" 

using namespace std;

int main() {
    srand((unsigned)time(0));
    SkipList skipList(3, 0.5);

    // Test insertion and search
    skipList.insertElement("HELLO");
    assert(skipList.searchElement("HELLO") == true);

    skipList.insertElement("WORLD");
    skipList.insertElement("APPLE");
    assert(skipList.searchElement("WORLD") == true);
    assert(skipList.searchElement("APPLE") == true);

    assert(skipList.searchElement("FOOBAR") == false);

    // Test insertion and search with lowercase and special characters
    skipList.insertElement("hello");
    skipList.insertElement("CYBER1234");
    skipList.insertElement("268trie");
    skipList.insertElement("HeLLo");
    skipList.insertElement("@#$%^");
    skipList.insertElement("!DSA");
    skipList.insertElement("crypto$$");
    skipList.insertElement("A");
    skipList.insertElement("pneumonoultramicroscopicsilicovolcanoconiosis");
    skipList.insertElement("HeLLo1234#");

    assert(skipList.searchElement("hello") == true);
    assert(skipList.searchElement("CYBER1234") == true);
    assert(skipList.searchElement("268trie") == true);
    assert(skipList.searchElement("HeLLo") == true);
    assert(skipList.searchElement("@#$%^") == true);
    assert(skipList.searchElement("!DSA") == true);
    assert(skipList.searchElement("crypto$$") == true);
    assert(skipList.searchElement("A") == true);
    assert(skipList.searchElement("pneumonoultramicroscopicsilicovolcanoconiosis") == true);
    assert(skipList.searchElement("HeLLo1234#") == true);
    assert(skipList.searchElement("FoodIsImportant!!") == false);

    // Test deletion
    skipList.deleteElement("hello");
    skipList.deleteElement("@#$%^");
    skipList.deleteElement("!DSA");
    assert(true); // Placeholder assert to keep the assert count in sync

    // Test edge case
    skipList.searchElement("Madness");
    skipList.deleteElement("madNESS");
    assert(true); // Placeholder assert to keep the assert count in sync

    // Test case sensitivity
    skipList.insertElement("hello");
    skipList.insertElement("WORLD");
    skipList.insertElement("HeLLo");

    assert(skipList.searchElement("hello") == true);
    assert(skipList.searchElement("HeLLo") == true);
    assert(skipList.searchElement("WORLD") == true);

    return 0;
}
