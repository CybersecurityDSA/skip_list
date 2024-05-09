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
    assert(skipList.deleteElement("hello") == true);
    assert(skipList.deleteElement("@#$%^") == true);
    assert(skipList.deleteElement("!DSA") == true);
    assert(skipList.deleteElement("dsa!@") == false);

    // Test edge case
    assert(skipList.searchElement("Madness") == false);
    assert(skipList.deleteElement("madNESS") == false);

    // Test case sensitivity
    skipList.insertElement("hello");
    skipList.insertElement("WORLD");
    skipList.insertElement("HeLLo");

    assert(skipList.searchElement("hello") == true);
    assert(skipList.searchElement("HeLLo") == true);
    assert(skipList.searchElement("WORLD") == true);

    // Test empty SkipList
    SkipList emptySkipList(3, 0.5);
    assert(emptySkipList.searchElement("EMPTY") == false);

    // Test insertion and deletion of one element
    SkipList oneElementSkipList(3, 0.5);
    oneElementSkipList.insertElement("ONE");
    assert(oneElementSkipList.searchElement("ONE") == true);
    assert(oneElementSkipList.deleteElement("ONE") == true);
    assert(oneElementSkipList.searchElement("ONE") == false);

    // Test insertion and deletion of multiple elements
    SkipList multipleElementSkipList(3, 0.5);
    multipleElementSkipList.insertElement("1");
    multipleElementSkipList.insertElement("2");
    multipleElementSkipList.insertElement("3");
    multipleElementSkipList.insertElement("4");
    multipleElementSkipList.insertElement("5");
    assert(multipleElementSkipList.searchElement("1") == true);
    assert(multipleElementSkipList.searchElement("2") == true);
    assert(multipleElementSkipList.searchElement("3") == true);
    assert(multipleElementSkipList.searchElement("4") == true);
    assert(multipleElementSkipList.searchElement("5") == true);
    assert(multipleElementSkipList.deleteElement("1") == true);
    assert(multipleElementSkipList.deleteElement("3") == true);
    assert(multipleElementSkipList.searchElement("1") == false);
    assert(multipleElementSkipList.searchElement("3") == false);
    assert(multipleElementSkipList.searchElement("5") == true);


    return 0;
}
