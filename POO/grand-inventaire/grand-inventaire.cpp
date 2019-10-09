#include <iostream>
#include <vector>
#include <list>

#define NB_PRODUITS_MAX 10

using namespace std;

struct Operation
{
int numero;
int quantite;
};

void saisirOperations(const int &nbOperation, list<Operation> &listesOperations)
{
    Operation operation;
    
    for(int i=0;i<nbOperation;i++)
    {
        cin >> operation.numero >> operation.quantite;
        listesOperations.push_back(operation);
    }
}

void calculerStock(const list<Operation>&listesOperations, vector<int> &stockProduits)
{
    for (list<Operation>::const_iterator it = listesOperations.begin(); it != listesOperations.end(); ++it)
    {
        stockProduits[(*it).numero - 1] += (*it).quantite;
    }
}

void afficherStock(const vector<int> &stockProduits)
{
    for (int i=0;i< NB_PRODUITS_MAX;i++)
    {
        cout << stockProduits[i] << endl;
    }
}

int main()
{
    int nbOperations=0;
    vector<int> stockProduits(NB_PRODUITS_MAX,0);
    list<Operation> listesOperations;
    cin >> nbOperations;
    saisirOperations(nbOperations, listesOperations);
    calculerStock(listesOperations, stockProduits);
    afficherStock(stockProduits);

    return 0;
}

