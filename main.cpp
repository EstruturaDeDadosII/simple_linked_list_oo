#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList list;

void menu();

int main() {
    menu();
    system("PAUSE");
    return 0;
}

void menu() {

    char choice = 'f';
    int elemento;

    cout << "MENU PRINCIPAL -------------------" << endl << endl;

    cout << "[0] Imprime a lista" << endl << endl << endl;
    cout << "[1] Verifica se a lista esta vazia" << endl;
    cout << "[2] Insere no topo da lista" << endl;
    cout << "[3] Insere no fim da lista" << endl;
    cout << "[4] Remove do topo da lista" << endl;
    cout << "[5] Remove do fim da lista" << endl;
    cout << "[6] Remove um elemento escolhido pelo usuario" << endl;
    cout << "[7] Pesquisa um elemento na lista" << endl;
    cout << "[8] Exibe elemento do topo e do fim da lista" << endl;
    cout << "[9] Quantidade de elementos na lista" << endl;
    cout << "[E/e] EXIT" << endl << endl;

    cout << "Digite uma opcao valida: ";
    cin.clear();
    fflush(stdin);
    cin >> choice;

    switch (choice) {

        case 'E':
        case 'e':
            cout << "Finalizando programa." << endl << endl;
            return;

        case '0':
            cout << "Imprimindo lista" << endl;
            if (!list.isEmpty())
                list.displayList();
            else
                cout << "A lista esta vazia" << endl << endl;
            break;

        case '1':
            if (!list.isEmpty())
                cout << "A lista NAO esta vazia" << endl << endl;
            else
                cout << "SIM, a lista esta vazia" << endl << endl;
            break;

        case '2':
            cout << "Digite um elemento para inserir no topo da lista: ";
            cin.clear();
            fflush(stdin);
            cin >> elemento;
            list.insereNoTopo(elemento);
            break;

        case '3':
            cout << "Digite um elemento para inserir no fim da lista: ";
            cin.clear();
            fflush(stdin);
            cin >> elemento;
            list.insereNoFim(elemento);
            break;

        case '4':
            if (!list.isEmpty())
                cout << "Voce removeu o elemento do topo: " << list.removeTopo() << endl << endl;
            else
                cout << "A lista esta vazia" << endl << endl;
            break;

        case '5':
            if (!list.isEmpty())
                cout << "Voce removeu o elemento do fim da lista: " << list.removeFim() << endl << endl;
            else
                cout << "A lista esta vazia" << endl << endl;
            break;

        case '6':
            if (!list.isEmpty()) {
                cout << "Digite um numero para remover: ";
                cin.clear();
                fflush(stdin);
                cin >> elemento;
                int retorno = list.removeNode(elemento);

                if (retorno < 0)
                    cout << "NAO ENCONTRAMOS O ELEMENTO" << endl;
                else
                    cout << "NUMERO REMOVIDO COM SUCESSO" << endl << endl;


            } else {
                cout << "A lista esta vazia" << endl << endl;
            }
            break;

        case '7':
            if (!list.isEmpty()) {
                cout << "Digite um numero para pesquisar: ";
                cin.clear();
                fflush(stdin);
                cin >> elemento;
                list.estaNaLista(elemento);
            } else {
                cout << "A lista esta vazia" << endl << endl;
            }
            break;

        case '8':
            if (!list.isEmpty()) {
                cout << "Elemento do topo: " << list.showTopo() << endl << endl;
                cout << "Elemento do Fim: " << list.showResto() << endl << endl;
            } else {
                cout << "A lista esta vazia" << endl << endl;
            }
            break;

        case '9':
            if (list.isEmpty() || (list.getTamanho() == 0)) {
                cout << "Voce nao tem nenhum elemento na lista." << endl << endl;
            } else {
                if (list.getTamanho() == 1) {
                    cout << "Voce tem " << list.getTamanho() << " elemento na lista" << endl << endl;
                } else {
                    cout << "Voce tem " << list.getTamanho() << " elementos na lista" << endl << endl;
                }
            }
            break;

        default:
            cout << "Opcao invalida. Tente novamente." << endl << endl;
    }

    menu();

}