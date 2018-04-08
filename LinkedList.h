//
// Created by thiago on 06/04/2018.
//

#ifndef SIMPLES_LINKED_LIST_LINKEDLIST_H
#define SIMPLES_LINKED_LIST_LINKEDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

class LinkedList {

private:
    node *topo;
    node *resto;
    int contador = 0;

public:
    LinkedList() {
        this->topo = 0;
        this->resto = 0;
    }

    ~LinkedList() {
        for (node *p; !this->isEmpty();) {
            p = topo->proximo;
            delete topo;
            topo = p;
        }
    }

    int isEmpty() {
        return this->topo == 0;
    }

    void insereNoTopo(int elemento) {
        this->topo = new node(elemento, this->topo);
        if (this->resto == 0)
            this->resto = topo;
        ++this->contador;
    }

    void insereNoFim(int elemento) {
        if (this->resto != 0) {
            this->resto->proximo = new node(elemento);
            this->resto = this->resto->proximo;
        } else {
            this->topo = this->resto = new node(elemento);
        }
        ++this->contador;
    }

    int removeTopo() {

        int elemento = this->topo->info;
        node *tmp = this->topo;

        if (this->topo == this->resto)
            this->topo = this->resto;
        else
            this->topo = this->topo->proximo;

        delete tmp;

        --this->contador;

        return elemento;

    }

    int removeFim() {
        int elemento = this->resto->info;
        if (this->topo == this->resto) {
            delete this->topo;
            this->topo = this->resto = 0;
        } else {
            node *tmp;
            for (tmp = this->topo; tmp->proximo != this->resto; tmp = tmp->proximo);
            delete this->resto;
            this->resto = tmp;
            this->resto->proximo = 0;
        }

        --this->contador;

        return elemento;
    }

    void displayList() { //mostra lista
        if (!isEmpty()) {
            node *tmp;
            cout << "[ ";
            for (tmp = this->topo; tmp != 0; tmp = tmp->proximo) {
                cout << tmp->info << " ";
            }
            cout << " ]" << endl << endl;
            cout << endl;
        } else {
            cout << "Lista Vazia!\n";
        }
    }

    int removeNode(int elemento) {

        if (this->topo->info == elemento) {
            return this->removeTopo();
        }

        if (this->topo->info == elemento) {
            return this->removeFim();
        }

        if (this->topo == this->resto) {
            if (this->topo->info == elemento) {
                return this->removeTopo();
            }
            if (this->topo->info == elemento) {
                return this->removeFim();
            }
        } else if (this->estaNaLista(elemento)) {
            int cond = 1;
            node *tmp, *anterior;

            for (tmp = this->topo; cond != 0; tmp = tmp->proximo) {
                if (tmp->info == elemento) {
                    anterior->proximo = tmp->proximo;
                    cond = 0;
                    delete tmp;
                } else {
                    anterior = tmp;
                }
            }

            return elemento;
        } else {
            cout << "NAO ESTA NA LISTA!\n";
        }

        return -9999;

    }

    bool estaNaLista(int elemento) {
        cout << "FUNCAO ESTA NA LISTA" << endl;

        if (this->topo->info == elemento) {
            cout << "Este elemento esta no topo" << endl;
            return true;
        } else if (this->resto->info == elemento) {
            cout << "Este elemento esta no fim" << endl;
            return true;
        } else {
            node *tmp;
            int posicao = 0;
            int quantidade = 0;
            for (tmp = this->topo; tmp->proximo != this->resto; tmp = tmp->proximo) {
                ++posicao;
                if (tmp->info == elemento) {
                    cout << "Legal. Temos esse elemento na posicao " << posicao << endl;
                    ++quantidade;
                }
            }
            if (quantidade == 0)
                cout << "Nao achamos nenhum elemento com este valor" << endl << endl;
            else
                return true;
        }
        return false;

    }

    int showTopo() {
        return this->topo->info;
    }

    int showResto() {
        return this->resto->info;
    }

    int getTamanho() {
        return this->contador;
    }

};


#endif //SIMPLES_LINKED_LIST_LINKEDLIST_H
