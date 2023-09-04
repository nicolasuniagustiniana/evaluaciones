#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    Nodo* siguiente;
    
    Nodo(int val) : valor(val), siguiente(NULL) {}
};


class ListaCircular {
private:
    Nodo* cabeza;
    
public:
    ListaCircular() : cabeza(NULL) {}
    
   
    void insertarAlFinal(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza; 
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza; 
        }
    }
    
    void imprimir() {
        if (!cabeza) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }
        
        Nodo* temp = cabeza;
        do {
            std::cout << temp->valor << " ";
            temp = temp->siguiente;
        } while (temp != cabeza);
        
        std::cout << std::endl;
    }
    
    ~ListaCircular() {
        if (!cabeza) return;
        
        Nodo* actual = cabeza;
        Nodo* siguiente = cabeza->siguiente;
        
        while (siguiente != cabeza) {
            delete actual;
            actual = siguiente;
            siguiente = siguiente->siguiente;
        }
        
        delete actual; 
    }
};

int main() {
    ListaCircular lista;
    lista.insertarAlFinal(2);
    lista.insertarAlFinal(4);
    lista.insertarAlFinal(7);
    lista.insertarAlFinal(8);
    lista.insertarAlFinal(10);
    lista.insertarAlFinal(12);

    std::cout << "Lista circular: ";
    lista.imprimir();

    return 0;
}
