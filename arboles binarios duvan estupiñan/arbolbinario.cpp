
#include <iostream>
#include <algorithm>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int valor) {
        dato = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return new Nodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    } else {
        cout << "El valor ya existe en el arbol.\n";
    }

    return raiz;
}

Nodo* buscar(Nodo* raiz, int valor) {
    while (raiz != nullptr && raiz->dato != valor) {
        if (valor < raiz->dato) {
            raiz = raiz->izquierdo;
        } else {
            raiz = raiz->derecho;
        }
    }

    return raiz;
}

Nodo* minimo(Nodo* raiz) {
    if (raiz == nullptr) {
        return nullptr;
    }

    while (raiz->izquierdo != nullptr) {
        raiz = raiz->izquierdo;
    }

    return raiz;
}

Nodo* maximo(Nodo* raiz) {
    if (raiz == nullptr) {
        return nullptr;
    }

    while (raiz->derecho != nullptr) {
        raiz = raiz->derecho;
    }

    return raiz;
}

Nodo* eliminar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return nullptr;
    }

    if (valor < raiz->dato) {
        raiz->izquierdo = eliminar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = eliminar(raiz->derecho, valor);
    } else {
        if (raiz->izquierdo == nullptr) {
            Nodo* temporal = raiz->derecho;
            delete raiz;
            return temporal;
        }

        if (raiz->derecho == nullptr) {
            Nodo* temporal = raiz->izquierdo;
            delete raiz;
            return temporal;
        }

        Nodo* sucesor = minimo(raiz->derecho);
        raiz->dato = sucesor->dato;
        raiz->derecho = eliminar(raiz->derecho, sucesor->dato);
    }

    return raiz;
}

void preorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}

void inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inorden(raiz->derecho);
    }
}

void postorden(Nodo* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }

    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}

int altura(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }

    int alturaIzquierda = altura(raiz->izquierdo);
    int alturaDerecha = altura(raiz->derecho);

    return 1 + max(alturaIzquierda, alturaDerecha);
}

void liberarMemoria(Nodo* raiz) {
    if (raiz != nullptr) {
        liberarMemoria(raiz->izquierdo);
        liberarMemoria(raiz->derecho);
        delete raiz;
    }
}

int main() {
    Nodo* raiz = nullptr;

    int valoresIniciales[] = {45, 15, 79, 10, 20, 55, 90};

    for (int valor : valoresIniciales) {
        raiz = insertar(raiz, valor);
    }

    int opcion;
    int valor;
    int nuevoValor;

    do {
        cout << "\n========== MENU ARBOL BINARIO DE BUSQUEDA ==========\n";
        cout << "1. Insertar un valor\n";
        cout << "2. Buscar un valor\n";
        cout << "3. Actualizar un valor\n";
        cout << "4. Eliminar un valor\n";
        cout << "5. Recorrido en preorden\n";
        cout << "6. Recorrido en inorden\n";
        cout << "7. Recorrido en postorden\n";
        cout << "8. Mostrar valor minimo\n";
        cout << "9. Mostrar valor maximo\n";
        cout << "10. Contar nodos\n";
        cout << "11. Calcular altura del arbol\n";
        cout << "12. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor que desea insertar: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                break;

            case 2:
                cout << "Ingrese el valor que desea buscar: ";
                cin >> valor;

                if (buscar(raiz, valor) != nullptr) {
                    cout << "El valor " << valor << " si existe en el arbol.\n";
                } else {
                    cout << "El valor no se encuentra en el arbol.\n";
                }
                break;

            case 3:
                cout << "Ingrese el valor que desea actualizar: ";
                cin >> valor;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;

                if (buscar(raiz, valor) == nullptr) {
                    cout << "El valor que desea actualizar no existe.\n";
                } else if (buscar(raiz, nuevoValor) != nullptr) {
                    cout << "El nuevo valor ya existe en el arbol.\n";
                } else {
                    raiz = eliminar(raiz, valor);
                    raiz = insertar(raiz, nuevoValor);
                    cout << "Valor actualizado correctamente.\n";
                }
                break;

            case 4:
                cout << "Ingrese el valor que desea eliminar: ";
                cin >> valor;

                if (buscar(raiz, valor) == nullptr) {
                    cout << "El valor no existe en el arbol.\n";
                } else {
                    raiz = eliminar(raiz, valor);
                    cout << "Valor eliminado correctamente.\n";
                }
                break;

            case 5:
                cout << "Recorrido en preorden: ";
                preorden(raiz);
                cout << "\n";
                break;

            case 6:
                cout << "Recorrido en inorden: ";
                inorden(raiz);
                cout << "\n";
                break;

            case 7:
                cout << "Recorrido en postorden: ";
                postorden(raiz);
                cout << "\n";
                break;

            case 8: {
                Nodo* menor = minimo(raiz);

                if (menor != nullptr) {
                    cout << "El valor minimo es: " << menor->dato << "\n";
                } else {
                    cout << "El arbol esta vacio.\n";
                }
                break;
            }

            case 9: {
                Nodo* mayor = maximo(raiz);

                if (mayor != nullptr) {
                    cout << "El valor maximo es: " << mayor->dato << "\n";
                } else {
                    cout << "El arbol esta vacio.\n";
                }
                break;
            }

            case 10:
                cout << "Cantidad de nodos: " << contarNodos(raiz) << "\n";
                break;

            case 11:
                cout << "Altura del arbol: " << altura(raiz) << "\n";
                break;

            case 12:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }

    } while (opcion != 12);

    liberarMemoria(raiz);

    return 0;
}

