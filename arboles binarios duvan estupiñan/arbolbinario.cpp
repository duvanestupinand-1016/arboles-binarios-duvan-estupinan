
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    else if (valor > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

void preorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

void inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierda);
        cout << raiz->dato << " ";
        inorden(raiz->derecha);
    }
}

void posorden(Nodo* raiz) {
    if (raiz != nullptr) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

void liberarArbol(Nodo* raiz) {
    if (raiz != nullptr) {
        liberarArbol(raiz->izquierda);
        liberarArbol(raiz->derecha);
        delete raiz;
    }
}

void mostrarArbol(int secuencia[], int cantidad, int numero) {
    Nodo* raiz = nullptr;

    for (int i = 0; i < cantidad; i++) {
        raiz = insertar(raiz, secuencia[i]);
    }

    cout << "\n SECUENCIA " << numero << "\n";

    cout << "Preorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPosorden: ";
    posorden(raiz);

    cout << "\n";

    liberarArbol(raiz);
}

int main() {
    int secuencia1[] = {50, 30, 70, 20, 40};
    int secuencia2[] = {60, 40, 80, 30, 50};
    int secuencia3[] = {45, 25, 65, 15, 35};
    int secuencia4[] = {90, 70, 110, 60, 80};
    int secuencia5[] = {35, 20, 55, 10, 25};

    mostrarArbol(secuencia1, 5, 1);
    mostrarArbol(secuencia2, 5, 2);
    mostrarArbol(secuencia3, 5, 3);
    mostrarArbol(secuencia4, 5, 4);
    mostrarArbol(secuencia5, 5, 5);

    return 0;
}
