//
// Created by thiago on 06/04/2018.
//

#ifndef SIMPLES_LINKED_LIST_SIMPLE_LINKED_LIST_H
#define SIMPLES_LINKED_LIST_SIMPLE_LINKED_LIST_H


class node {

public:
    int info;
    node *proximo;

public:
    node() {
        proximo = 0;
    }
    node(int elemento, node *ponteiro = 0) {
        this->info = elemento;
        this->proximo = ponteiro;
    }

};


#endif //SIMPLES_LINKED_LIST_SIMPLE_LINKED_LIST_H
