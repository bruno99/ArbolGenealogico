#include "tree.h"

Tree::Tree()
{

}

Node *Tree::getIt() const
{
    return it;
}

void Tree::setIt(Node *value)
{
    it = value;
}

void Tree::print() const
{
    if(!it) return;
    it->resetPrint();
    it->print();
}

Node *Tree::search(string name, string surname1, string surname2)
{
    if(!it) return nullptr;
    it->resetVisited();
    return it->search(name,surname1,surname2);
}
