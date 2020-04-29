#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
public:

    friend ostream & operator << (ostream & os, Person const & p);
    friend bool operator == (Person const & p1, Person const & p2);

    Person(string n, string s1, string s2);

    string getName() const;
    void setName(const string &value);

    string getSurname1() const;
    void setSurname1(const string &value);

    string getSurname2() const;
    void setSurname2(const string &value);

private:
    string name, surname1, surname2;
};

ostream &operator << (ostream & os, Person const & p);
bool operator == (Person const & p1, Person const & p2);

#endif // PERSON_H
