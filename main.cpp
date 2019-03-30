#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


int main() {

    ifstream fin("intrare.in");

    int var, x, y;
    char c, cA; // c reprezinta litera citita pentru a schimba o stare, cA reprezinta prima litera a alfabetului
    int randuri, coloane, nrStariF; //randuri = nr. de stari, coloane = literele din alfabet, nrStariF = numar de stari finale
    fin >> randuri >> coloane >> nrStariF >> cA;
    char alf[100];
    fin >> alf;
  /*  cout << cA << ' ' << randuri << ' ' << coloane << ' ' << nrStariF;
    cout << endl << alf << endl;*/

    int **matrice = new int *[randuri];

    for (int i = 0; i < randuri; i++) { matrice[i] = new int[coloane + 1]; }
    for (int i = 0; i < randuri; i++) { matrice[i][coloane] = 0; }
    for (int i = 0; i < randuri; i++)
    {
        for(int j = 0; j < coloane; j++)
        {
            matrice[i][j]=-1;
        }
    }

    for (int i = 0; i < nrStariF; i++) {
        fin >> var;
        matrice[var][coloane] = 1;
    }

    for (int i = 0; i < randuri * coloane; i++) {
        fin >> x >> c >> y;
        int z = (int)c - (int) cA;
        matrice[x][z] = y;

    }
/*
    for (int i = 0; i < randuri; i++) {
        for (int j = 0; j < coloane + 1; j++) {
            cout << matrice[i][j] << " | ";
        }
        cout << endl << "---------------" << endl;
    }
*/

    char sir[100];
    cout << "Introduceti un sir: ";
    cin >> sir;
    cout << endl;
    int len = 0; //lungimea sirului parcurs
    int stare = 0; //starea in care se afla cuvantul

    while(len!=strlen(sir))
    {
        char k = sir[len];
        if(matrice[stare][(int)k - (int)cA]==-1)
        {
            break;
        }
            else
        {
            stare = matrice[stare][(int)k - (int)cA];
            len++;
        }
    }


    if(len==strlen(sir))
    {
        if (matrice[stare][coloane] == 1) { cout << "Cuvantul " << sir << " apartine alfabetului!" << endl; }
        else {
            cout << "Cuvantul " << sir << " nu apartine alfabetului!" << endl;
        }
    }
    else
        cout << "Cuvantul " << sir << " nu apartine alfabetului!" << endl;

    fin.close();
    return 0;
}
