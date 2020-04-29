#include <iostream>

#include "person.h"
#include "tree.h"

using namespace std;

static string person;   // Creo una variable global que me guarda el puntero en el que estoy dentro del arbol para cambiar de posicion y asi agregar padres y hermanos ilimitados

void showMenu()
{
    cout << endl << "--------------- Introduzca que desea hacer ---------------" << endl;
    cout << "(a) Añadir padres." << endl;
    cout << "(b) Añadir hermanos." << endl;
    cout << "(c) Posicionarse en otra persona." << endl;
    cout << "(d) Imprimir arbol." << endl;
    cout << "(e) Realizar busqueda." << endl;
    cout << "(z) Salir." << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Estas en: " << person << endl;
    cout << "Opcion: ";
}

int main()
{
    Tree tree;
    string name, surname1, surname2;

    cout << "********************   BIENVENIDO A TU ARBOL GENEALOGICO   ********************" << endl << endl;
    cout << "!!! NOTA: Si vas a ingresar un nombre compuesto, tiene que ser del formato: 'Nombre_Compuesto' !!!" << endl << endl;

    cout << "Ingresa tu nombre: ";
    cin >> name;
    cout << "Ingresa tu primer apellido: ";
    cin >> surname1;
    cout << "Ingresa tu segundo apellido: ";
    cin >> surname2;

    person = name + " " + surname1 + " " + surname2;

    Person* pme = new Person(name,surname1,surname2);
    Node* it = new Node(pme);
    tree.setIt(it);

    char option='x';
    while(option != 'z'){
        switch(option){

        // AÑADIR PADRE
        case 'a': {
            cout << "Ingresa su nombre: ";
            cin >> name;
            cout << "Ingresa su primer apellido: ";
            cin >> surname1;
            cout << "Ingresa su segundo apellido: ";
            cin >> surname2;

            Person* pparent = new Person(name,surname1,surname2);
            Node* nparent = new Node(pparent);

            it->addParent(nparent);
            break;
        }

        // AÑADIR HERMANO
        case 'b': {
            cout << "Ingresa su nombre: ";
            cin >> name;
            cout << "Ingresa su primer apellido: ";
            cin >> surname1;
            cout << "Ingresa su segundo apellido: ";
            cin >> surname2;

            Person* psibling = new Person(name,surname1,surname2);
            Node* nsibling = new Node(psibling);

            it->addSibling(nsibling);
            break;
        }

        // CAMBIAR DE PERSONA
        case 'c': {
            cout << "Ingresa su nombre: ";
            cin >> name;
            cout << "Ingresa su primer apellido: ";
            cin >> surname1;
            cout << "Ingresa su segundo apellido: ";
            cin >> surname2;

            Node* it2 = tree.search(name,surname1,surname2);
            if(it2){
                it = it2;
                tree.setIt(it);
                person = name + " " + surname1 + " " + surname2;
            }else{
                cout << "ERROR: Persona no encontrada." << endl;
            }
            break;
        }

        // IMPRIMIR ARBOL
        case 'd': {
            tree.print();
            break;
        }

        // BUSCAR PERSONA
        case 'e': {
            cout << "Ingresa su nombre: ";
            cin >> name;
            cout << "Ingresa su primer apellido: ";
            cin >> surname1;
            cout << "Ingresa su segundo apellido: ";
            cin >> surname2;

            Node* result = tree.search(name,surname1,surname2);
            if(result){
                result->printRelatives();
            }else{
                cout << "ERROR: Persona no encontrada." << endl;
            }
            break;
        }

        }

        showMenu();
        cin >> option;

    }

    cout << endl << "Hasta pronto!" << endl;
    return 0;
}

