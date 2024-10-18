#ifndef TASK3_H
#define TASK3_H
using namespace std;
#include <string>
template <typename Key, typename Info>
class Dictionary
{ // AVL
private:
    struct Node
    {
        Key key;
        Info info;
        Node *left;
        Node *right;
        int height = 1;
    };
    Node *root;
    void rotateRight(Node *&nptr);
    void rotateLeft(Node *&nptr);
    bool insertElement(Node *&nptr, const Key &what, const Info &iwhat);
    int height(Node *nptr);
    void balanceSubtree(Node *&nptr);
    bool remove(Node *&nptr, const Key &what);
    void clearContents(Node *nptr);
    void printInOrder(Node *nptr);
    void graph(ostream &out, int indent, Node *nptr);
    void copySubtree(Node *&nptr, Node *toCopy);
    int getBalanceFactor(Node *nptr);
    Node *getMinimumNode(Node *nptr);
    Node *findNode(Node *nptr, const Key &what);

public:
    Dictionary();
    Dictionary(const Dictionary &toCopy);
    Dictionary<Key, Info> &operator=(const Dictionary &toCopy);
    void insertElement(const Key &what, const Info &iwhat);
    bool updateInfo(const Key &what, Info newInfo);
    bool search(const Key &what, Info &toReturn);
    bool remove(const Key &what);
    void clearContents();
    void printInOrder();
    void graph(ostream &out);
};
bool readFromFile(Dictionary<string, int> &where, string fileName);
/*key = string - chain of characters; unique
info = int; counts how many there are
reads from file any text and prints all keys that appeared in this text + a counter of how many times each text appeared
any chain of characters is understood as a key (not spaces and EOL)
each chain creates a key; if there's a new one we increment the counter
*/
#endif