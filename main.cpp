#include <iostream>
#include <chrono>
#include <fstream>

#include "list.h"
#include "sortsUtils.h"

using namespace std;

using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;

int main() 
{
    // BUBBLE SORT

    int iNumLinhas = 100;

    // Inicialização da semente do gerador de números aleatórios com o tempo atual
    srand(time(nullptr)); 
    ofstream outputFile1("output/bubbleSort_time.csv", ios::out | ios::trunc);
    
    outputFile1 << "Tempo Bubble Sort Padrão,Tempo Bubble Sort Otimizado" << endl;

    Node* head1 = nullptr;
    Node* head2 = nullptr;
   
    for (int i = 1; i <= iNumLinhas ; i ++) 
    {
        addRandomElements(&head1, 10000, i);
        head2 = copyList(&head1);

        auto timeStart1 = high_resolution_clock::now();
        bubbleSort(&head1);
        auto timeStop1 = high_resolution_clock::now();

        auto timeStart2 = high_resolution_clock::now();
        optimizedBubbleSort(&head2,10000);
        auto timeStop2 = high_resolution_clock::now();

        auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
        auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);

        outputFile1 << timeDuration1.count() << "," << timeDuration2.count() << endl;
        clearList(&head1);
        clearList(&head2);
    }

    outputFile1.close();

    // SELECTION SORT

    // Inicialização da semente do gerador de números aleatórios com o tempo atual
    srand(time(nullptr)); 
    ofstream outputFile2("output/selectionSort_time.csv", ios::out | ios::trunc);
    
    outputFile2 << "Tempo Selection Sort Padrão,Tempo Selection Sort Otimizado" << endl;

    Node* head3 = nullptr;
    Node* head4 = nullptr;

    for (int i = 1; i <= iNumLinhas ; i ++) 
    {
        addRandomElements(&head3, 10000, i);
        head4 = copyList(&head3);

        auto timeStart3 = high_resolution_clock::now();
        selectionSort(&head3);
        auto timeStop3 = high_resolution_clock::now();

        auto timeStart4 = high_resolution_clock::now();
        optimizedSelectionSort(&head4);
        auto timeStop4 = high_resolution_clock::now();

        auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3);
        auto timeDuration4 = duration_cast<nanoseconds>(timeStop4 - timeStart4);

        outputFile2 << timeDuration3.count() << "," << timeDuration4.count() << endl;
        clearList(&head3);
        clearList(&head4);
    }

    outputFile2.close();

    // INSECTION SORT

    // Inicialização da semente do gerador de números aleatórios com o tempo atual
    srand(time(nullptr)); 
    ofstream outputFile3("output/insertSort_time.csv", ios::out | ios::trunc);
    
    outputFile3 << "Tempo (nanossegundos)" << endl;

    Node* head5 = nullptr;

    for (int i = 1; i <= iNumLinhas ; i ++) 
    {
        addRandomElements(&head5, 10000, i);

        auto timeStart5 = high_resolution_clock::now();
        insertSort(&head5);
        auto timeStop5 = high_resolution_clock::now();

        auto timeDuration5 = duration_cast<nanoseconds>(timeStop5 - timeStart5);

        outputFile3 << timeDuration5.count() << endl;
        clearList(&head5);
    }

    outputFile3.close();
    
    // RADIX SORT

    // Inicialização da semente do gerador de números aleatórios com o tempo atual
    srand(time(nullptr)); 
    ofstream outputFile4("output/radixtSort_time.csv", ios::out | ios::trunc);
    
    outputFile4 << "Tempo (nanossegundos)" << endl;

    Node* head6 = nullptr;

    for (int i = 1; i <= iNumLinhas ; i ++) 
    {
        addRandomElements(&head6, 10000, i);

        auto timeStart6 = high_resolution_clock::now();
        radixSort(&head6, 10000);
        auto timeStop6 = high_resolution_clock::now();

        auto timeDuration6 = duration_cast<nanoseconds>(timeStop6 - timeStart6);

        outputFile4 << timeDuration6.count() << endl;
        clearList(&head6);
    }

    outputFile4.close();

    return 0;
}