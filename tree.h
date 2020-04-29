#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree
{
public:
    Tree();

    Node *getIt() const;
    void setIt(Node *value);

    void print() const;

    Node* search(string name, string surname1, string surname2);

private:
    Node* it;
};

#endif // TREE_H
