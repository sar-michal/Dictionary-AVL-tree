#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
template <typename Key, typename Info>
void Dictionary<Key, Info>::rotateRight(Node *&nptr)
{
    Node *temp = nptr->left;
    nptr->left = temp->right;
    temp->right = nptr;
    nptr->height = 1 + max(height(nptr->left), height(nptr->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));
    nptr = temp;
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::rotateLeft(Node *&nptr)
{
    Node *temp = nptr->right;
    nptr->right = temp->left;
    temp->left = nptr;
    nptr->height = 1 + max(height(nptr->left), height(nptr->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));
    nptr = temp;
}

template <typename Key, typename Info>
int Dictionary<Key, Info>::getBalanceFactor(Node *nptr)
{
    if (!nptr)
    {
        return 0;
    }
    return height(nptr->left) - height(nptr->right);
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::insertElement(Node *&nptr, const Key &what, const Info &iwhat)
{
    if (!nptr)
    {
        Node *newNode = new Node;
        newNode->key = what;
        newNode->info = iwhat;
        newNode->left = nullptr;
        newNode->right = nullptr;
        nptr = newNode;
        return true;
    }
    if (what < nptr->key)
    {
        insertElement(nptr->left, what, iwhat);
    }
    else if (what > nptr->key)
    {
        insertElement(nptr->right, what, iwhat);
    }
    else
        return false;

    nptr->height = 1 + max(height(nptr->left), height(nptr->right));
    balanceSubtree(nptr);
    return true;
}

template <typename Key, typename Info>
int Dictionary<Key, Info>::height(Node *nptr)
{
    if (!nptr)
    {
        return 0;
    }
    return nptr->height;
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::balanceSubtree(Node *&nptr)
{
    if (getBalanceFactor(nptr) > 1)
    {
        if (getBalanceFactor(nptr->left) < 0)
        {
            rotateLeft(nptr->left);
        }
        rotateRight(nptr);
    }
    else if (getBalanceFactor(nptr) < -1)
    {
        if (getBalanceFactor(nptr->right) > 0)
        {
            rotateRight(nptr->right);
        }
        rotateLeft(nptr);
    }
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node *Dictionary<Key, Info>::findNode(Node *nptr, const Key &what)
{
    if (!nptr)
    {
        return nullptr;
    }
    if (what == nptr->key)
    {
        return nptr;
    }
    if (what < nptr->key)
    {
        return findNode(nptr->left, what);
    }
    return findNode(nptr->right, what);
}

template <typename Key, typename Info>
typename Dictionary<Key, Info>::Node *Dictionary<Key, Info>::getMinimumNode(Node *nptr)
{
    if (!nptr)
    {
        return nullptr;
    }
    while (nptr->left != nullptr)
    {
        nptr = nptr->left;
    }
    return nptr;
}
template <typename Key, typename Info>
bool Dictionary<Key, Info>::remove(Node *&nptr, const Key &what)
{
    if (!nptr)
    {
        return false;
    }
    if (what < nptr->key)
    {
        remove(nptr->left, what);
    }
    else if (what > nptr->key)
    {
        remove(nptr->right, what);
    }
    else
    {
        Node *toDelete = nptr;
        if (!(nptr->left) && !(nptr->right))
        {
            nptr = nullptr;
        }
        else if (!nptr->left)
        {
            nptr = nptr->right;
        }
        else if (!nptr->right)
        {
            nptr = nptr->left;
        }
        else
        {
            toDelete = getMinimumNode(nptr->right);
            nptr->key = toDelete->key;
            nptr->info = toDelete->info;
            remove(nptr->right, toDelete->key);
            toDelete = nullptr;
        }
        delete toDelete;
        return true;
    }
    nptr->height = 1 + max(height(nptr->left), height(nptr->right));
    balanceSubtree(nptr);
    return true;
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::clearContents(Node *nptr)
{
    if (!nptr)
    {
        return;
    }
    clearContents(nptr->left);
    clearContents(nptr->right);
    delete nptr;
}
template <typename Key, typename Info>

Dictionary<Key, Info>::Dictionary() : root(nullptr)
{
}

template <typename Key, typename Info>
Dictionary<Key, Info>::Dictionary(const Dictionary &toCopy)
{
    root = nullptr;
    copySubtree(root, toCopy.root);
}
template <typename Key, typename Info>
void Dictionary<Key, Info>::copySubtree(Node *&nptr, Node *toCopy)
{
    if (!toCopy)
    {
        return;
    }
    Node *newNode = new Node;
    nptr = newNode;
    nptr->key = toCopy->key;
    nptr->info = toCopy->info;
    nptr->height = toCopy->height;
    nptr->right = nullptr;
    nptr->left = nullptr;
    copySubtree(nptr->left, toCopy->left);
    copySubtree(nptr->right, toCopy->right);
}

template <typename Key, typename Info>
Dictionary<Key, Info> &Dictionary<Key, Info>::operator=(const Dictionary &toCopy)
{
    if (this == &toCopy)
    {
        return *this;
    }
    clearContents();
    copySubtree(root, toCopy.root);
    return *this;
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::insertElement(const Key &what, const Info &iwhat)
{
    insertElement(root, what, iwhat);
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::updateInfo(const Key &what, Info newInfo)
{
    Node *found = findNode(root, what);
    if (!found)
    {
        return false;
    }
    found->info = newInfo;
    return true;
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::search(const Key &what, Info &toReturn)
{
    Node *found = findNode(root, what);
    if (!found)
    {
        return false;
    }
    toReturn = found->info;
    return true;
}

template <typename Key, typename Info>
bool Dictionary<Key, Info>::remove(const Key &what)
{
    return remove(root, what);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::printInOrder()
{
    Dictionary<Key, Info>::printInOrder(root);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::printInOrder(Node *nptr)
{
    if (!nptr)
    {
        return;
    }
    printInOrder(nptr->left);
    cout << nptr->key << " " << nptr->info << endl;
    printInOrder(nptr->right);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::clearContents()
{
    clearContents(root);
    root = nullptr;
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::graph(ostream &out)
{
    graph(out, 0, root);
}

template <typename Key, typename Info>
void Dictionary<Key, Info>::graph(ostream &out, int indent, Dictionary<Key, Info>::Node *nptr)
{
    if (!nptr)
    {
        return;
    }
    graph(out, indent + 8, nptr->right);
    out << setw(indent) << " " << nptr->key << endl;
    graph(out, indent + 8, nptr->left);
}
bool readFromFile(Dictionary<string, int> &where, string fileName)
{
    ifstream file;
    file.open(fileName);
    if (!file)
    {
        return false;
    }
    string word;
    int count;
    while (file >> word)
    {
        if (where.search(word, count))
        {
            where.updateInfo(word, count + 1);
        }
        else
        {
            where.insertElement(word, 1);
        }
    }
    file.close();
    return true;
}
