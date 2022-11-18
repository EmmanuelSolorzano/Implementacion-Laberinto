#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Labyrinth
{
public:
    int startCoordinates[2];
    int endCoordinates[2];
    vector< vector<int> > labyrinthMatrix;
    vector< vector<int> > solutionMatrix;
    Labyrinth(string problem);
    void printLabyrinth();
    void printSolution();
    void createGuiCsv();
    void solution();
    void defineStartEnd(int startC[2], int endC[2]);
};

Labyrinth::Labyrinth(string problem){
    ifstream archivo(problem);
    string linea;
    char delimitador = ',';
    while (getline(archivo, linea)){     
        stringstream stream(linea);
        vector<int> aux;
        string celda;
        while(getline(stream, celda, delimitador)){
            int celdaInt = stoi(celda);
            aux.push_back(celdaInt);
        }
        labyrinthMatrix.push_back(aux);
    }
    archivo.close();

    for (int i = 0; i < labyrinthMatrix.size(); i++){
        vector<int> aux;
        for (int k = 0; k < labyrinthMatrix[i].size(); k++){
            aux.push_back(0);
        }
        solutionMatrix.push_back(aux);
    }

}


void Labyrinth::printLabyrinth(){
    cout<<"<- X ->"<<endl;
    for (int i = 0; i < labyrinthMatrix.size(); i++){
        for (int k = 0; k < labyrinthMatrix[i].size(); k++){
            cout<<labyrinthMatrix[i][k]<<" ";
        }
        cout<<endl;
    }
}

void Labyrinth::printSolution(){
    for (int i = 0; i < solutionMatrix.size(); i++){
        for (int k = 0; k < solutionMatrix[i].size(); k++){
            cout<<solutionMatrix[i][k]<<" ";
        }
        cout<<endl;
    }
}

//TO DO
void Labyrinth::solution(){
    
}

void Labyrinth::createGuiCsv(){
    ofstream fich("GUI_CSV/problem.csv");
    for (int i = 0; i < labyrinthMatrix.size(); i++){
        for (int k = 0; k < labyrinthMatrix[i].size(); k++){
            fich << labyrinthMatrix[i][k];
            if (k != labyrinthMatrix.size()-1){
                fich << ",";
            }
        }
        fich << endl;
    }
    ofstream fichTwo("GUI_CSV/solution.csv");
    for (int i = 0; i < solutionMatrix.size(); i++){
        for (int k = 0; k < solutionMatrix[i].size(); k++){
            fichTwo << solutionMatrix[i][k];
            if (k != solutionMatrix.size()-1){
                fichTwo << ",";
            }
        }
        fichTwo << endl;
    }
}

void Labyrinth::defineStartEnd(int startC[2], int endC[2]){
    for (int i = 0; i < 2; i++){
        startCoordinates[i] = startC[i];
        endCoordinates[i] = endC[i];
    }
    labyrinthMatrix[startCoordinates[0]][startCoordinates[1]] = 2;
    labyrinthMatrix[endCoordinates[0]][endCoordinates[1]] = 2;
}

#endif
