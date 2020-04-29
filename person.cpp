#include "person.h"

Person::Person(string n, string s1, string s2):
    name{n},
    surname1{s1},
    surname2{s2}
{

}

string Person::getName() const
{
    return name;
}

void Person::setName(const string &value)
{
    name = value;
}

string Person::getSurname1() const
{
    return surname1;
}

void Person::setSurname1(const string &value)
{
    surname1 = value;
}

string Person::getSurname2() const
{
    return surname2;
}

void Person::setSurname2(const string &value)
{
    surname2 = value;
}

ostream &operator <<(ostream &os, const Person &p)
{
    os << p.name << " " << p.surname1 << " " << p.surname2;
    return os;
}

bool operator ==(const Person &p1, const Person &p2)
{
    return (p1.name == p2.name && p1.surname1 == p2.surname1 && p1.surname2 == p2.surname2);
}
