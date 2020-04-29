#include "node.h"

Node::Node(Person *p):
    person{p},
    parents{{nullptr,nullptr}},
    printed{false},
    visited{false}
{

}

Person *Node::getPerson() const
{
    return person;
}

void Node::setPerson(Person *value)
{
    person = value;
}

void Node::addChildren(Node *n)
{
    children.push_back(n);
}

void Node::addParent(Node *p)
{
    if(parents.at(0) == nullptr){
        parents.at(0) = p;
    }else if(parents.at(1) == nullptr){
        parents.at(1) = p;
    }else{
        cout << "ERROR: Ya tienes dos padres.";
    }
    p->addChildren(this);
}

void Node::addSibling(Node *s)
{
    siblings.push_back(s);

    for(unsigned int i = 0; i < s->siblings.size() ; i++){
        if(siblings.at(i) == nullptr){
            siblings.at(i) = s;
        }
        s->addSibling(this);
        this->addSibling(s);
    }
}

vector<Node *> Node::getChildren() const
{
    return children;
}

array<Node *,2> Node::getParents() const
{
    return parents;
}

vector<Node *> Node::getSiblings() const
{
    return siblings;
}

void Node::printRelatives() const
{
    cout << "- Nombre: " << *person << endl;

    cout << "- Padres: " << endl;
    for(auto p: getParents()){
        if(p) cout << *(p->getPerson()) << endl;
    }

    cout << "- Hermanos/as: " << endl;
    for(auto p: getSiblings()){
        if(p) cout << *(p->getPerson()) << endl;
    }
}

void Node::print()
{

    if(printed) return;
    printed = true;

    cout << *(person) << endl;

    for(auto p: children){
        if(p) p->print();
    }

    for(auto p: parents){
        if(p) p->print();
    }

    for(auto p: siblings){
        if(p) p->print();
    }
}

Node *Node::search(string name, string surname1, string surname2)
{
    if(visited) return nullptr;
    visited = true;

    if(name == person->getName() && surname1 == person->getSurname1() && surname2 == person->getSurname2()) return this;

    for(auto p: children){
        if(p){
            Node* aux = p->search(name,surname1,surname2);
            if(aux) return aux;
        }
    }

    for(auto p: parents){
        if(p){
            Node* aux = p->search(name,surname1,surname2);
            if(aux) return aux;
        }
    }

    for(auto p: siblings){
        if(p){
            Node* aux = p->search(name,surname1,surname2);
            if(aux) return aux;
        }
    }

    return nullptr;
}

void Node::resetPrint()
{
    if(!printed) return;
    printed = false;

    for(auto p: children){
        if(p) p->resetPrint();
    }

    for(auto p: parents){
        if(p) p->resetPrint();
    }

    for(auto p: siblings){
        if(p) p->resetPrint();
    }
}

void Node::resetVisited()
{
    if(!visited) return;
    visited = false;

    for(auto p: children){
        if(p) p->resetVisited();
    }

    for(auto p: parents){
        if(p) p->resetVisited();
    }

    for(auto p: siblings){
        if(p) p->resetVisited();
    }
