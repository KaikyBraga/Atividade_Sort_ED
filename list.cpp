#include <iostream>
#include "list.h"

using namespace std;

Node* createNode(int iPayload)
{
    // Essa função cria um novo nó

    // Alocando memória para um nó
    Node* temp = (Node*) malloc(sizeof(Node));
    
    // Carga do nó
    temp->iPayload = iPayload;
    
    // Inicializando nó apontando para nulo (Sem nós na frente e na traseira)
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}

void displayList(Node* node)
{
    // Essa função printa a lista duplamente encadeada

    // Caso não existam nós na lista
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return; 
    }
    
    // Caso o nó passado estiver no meio o no final da lista
    if  (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }
    
    // Caso o nó passado seja o primeiro elemento da lista
    Node* temp = node;
     
    cout << "Payload: ";
    
    // Print de todos os elementos da lista
    while(temp != nullptr)
    {
        cout << temp->iPayload<< " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    // Essa função insere um nó no início de uma lista duplamente encadeada

    Node* newNode = createNode(iPayload);
    // newNode->ptrPrev = nullptr; (Cuidado Dobrado, não é necessário nesse caso)
    
    // Caso exista pelo menos um nó na lista
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        
        return;
    }
    
    // Caso não existam nós na lista
    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload)
{
    // Essa função inserre um novo nó no final da lista

    Node* newNode = createNode(iPayload);   
    //newNode->ptrNext = nullptr;

    // Caso a lista seja nula, inserimos um novo nó no final passado
    if (*head == nullptr)
    {
        //newNode->ptrPrev = nullptr;
        (*head) = newNode;
        return;
    }

    // Caso a lista não seja nula
    Node* temp = (*head);

    // Percorremos a lista até seu fim (ptrNext do último nó é nulo)
    while(temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }

    // Temos agora o último nó da lista

    // newNode aponta para o fim da Lista
    newNode->ptrPrev = temp;

    // Antigo elemento aponta para o novo nó
    temp->ptrNext = newNode; 
}

void deleteNode(Node** head, Node* ptrDelete)
{
    // Essa função deleta um nó específico da lista

    // Caso a lista seja nulo ou o nó seja nulo
    if (*head == nullptr || ptrDelete == nullptr)   
    {
        cout << "Não foi possível remover." << endl;
        return;
    }
    
    // Caso o ptrDelete seja o primeiro elemento da lista
    if (*head == ptrDelete) 
        (*head) = ptrDelete->ptrNext;
    
    // Se o ptrDelete não é o último nó
    if (ptrDelete->ptrNext != nullptr) 
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev; 
    
    // Se o ptrDelete não é o primeiro nó
    if (ptrDelete->ptrPrev != nullptr)
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    free(ptrDelete);
}

void swapValue(Node* node1, Node* node2)
{
    // Essa função troca os valores dos nós passados.

    int iTemp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = iTemp;
}

Node* copyList(Node** head)
{
    // Essa função copia uma lista duplamente encadeada

    Node* ptrCurrent = *head;
    Node* newHead = createNode(ptrCurrent->iPayload);

    while (ptrCurrent != nullptr)
    {
        insertEnd(&newHead, ptrCurrent->iPayload);
        ptrCurrent = ptrCurrent->ptrNext;
    }
    
    return newHead;
}

void clearList(Node** head)
{
    // Essa função esvazia uma lista duplamente encadeada

    Node* ptrCurrent = *head;

    // Confere se já está vazia
    if (ptrCurrent == nullptr) return;

    // Percorre a lista até o último elemento
    while (ptrCurrent->ptrNext != nullptr) ptrCurrent = ptrCurrent->ptrNext;
    
    // Faz o caminho contrário e deleta o último nó a cada iteração
    while (ptrCurrent != *head)
    {
        ptrCurrent = ptrCurrent->ptrPrev;

        deleteNode(head, ptrCurrent->ptrNext);
    }
    // Por fim, deleta o primeiro nó
    deleteNode(head, ptrCurrent);
}

int maxList(Node* head)
{
    /*
    Essa função calcula o valor máximo de uma lista.
    */

    int iMaxValue = head->iPayload;
    Node* current = head;

    while (current != nullptr)
    {
        if (current->iPayload > iMaxValue)
        {
            iMaxValue = current->iPayload;
        }

        current = current->ptrNext;
    }

    return iMaxValue;
}
