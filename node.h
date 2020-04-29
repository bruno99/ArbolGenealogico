#ifndef NODE_H
#define NODE_H

#include <vector>
#include <array>

#include "person.h"

using namespace std;

class Node
{
public:
    Node(Person *p);

    Person *getPerson() const;
    void setPerson(Person *value);

    void addChildren(Node* n);
    void addParent(Node* p);
    void addSibling(Node* s);

    vector<Node *> getChildren() const;
    array<Node *, 2> getParents() const;
    vector<Node *> getSiblings() const;

    void printRelatives() const;
    void print();

    Node* search(string name, string surname1, string surname2);

    void resetPrint();
    void resetVisited();

private:
    Person* person;
    vector<Node *> children;
    array<Node *, 2> parents;
    vector<Node *> siblings;
    bool printed;
    bool visited;
};

#endif // NODE_H
