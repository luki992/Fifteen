#ifndef LOGIC_HPP_INCLUDED
#define LOGIC_HPP_INCLUDED
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include "pomoc.hpp"
using namespace std;
class Logic
{
private:
    int tablica[4][4]; // tablica odpowiadajaca tablicy rect
    int x; // elementy wylosowane
    int y; // elementy wylosowane
    const int ile=4;
    vector<int>n;
public:
// hermatyzacja
void losuj(); // losowanie elementu z tablicy 4x4
void losuj_elementy(); // losowanie elementow od 1 do 15 z pominieciem wekora[x,y]
vector<string> tablica_elementow(); // elementy do wyswietlenia
pomocnicza get_wylosowane();
bool get_(pomocnicza,zamiana &);
void zamien(zamiana&);
};


#endif // LOGIC_HPP_INCLUDED
