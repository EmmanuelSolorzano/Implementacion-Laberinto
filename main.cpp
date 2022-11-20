#include <iostream>
#include "Labyrinth.h"
#include <string>
using namespace std;

int main(){
    /*
    string path;
    cout<<"Introduzca el nombre del archivo CSV a resolver: (SUGERENCIA: problem.csv) "<<endl;
    cin>> path;
    Labyrinth labyrinth(path);*/
    Labyrinth labyrinth("problem.csv");
    int startCoordinates[2], endCoordinates[2];
    string aux;
    labyrinth.printLabyrinth();

    cout<<"Introduzca la coordenada en X del punto de entrada: "<<endl;
    cin>> aux;
    startCoordinates[1] = stoi(aux);
    cout<<"Introduzca la coordenada en Y del punto de entrada: "<<endl;
    cin>> aux;
    startCoordinates[0] = stoi(aux);

    cout<<"Introduzca la coordenada en X del objetivo: "<<endl;
    cin>> aux;
    endCoordinates[1] = stoi(aux);
    cout<<"Introduzca la coordenada en Y del objetivo: "<<endl;
    cin>> aux;
    endCoordinates[0] = stoi(aux);
    labyrinth.defineStartEnd(startCoordinates,endCoordinates);

    labyrinth.createGuiCsv();
    cout<<"Archivo \"index.HTML\" generado, dicho archivo contiene la solucion grafica."<<endl;
    return 0;
}