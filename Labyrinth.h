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
    void solution(int posX, int posY);
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
void Labyrinth::solution(int posX, int posY){
    vector< vector<int> > auxMatrix = solutionMatrix;
    bool canLeft,canRight,canUp,canDown;
    bool canRoadLeft,canRoadRight,canRoadUp,canRoadDown;
    int actualPosX = posX;
    int actualPosY = posY;

    while((actualPosX != endCoordinates[0]) && (actualPosY != endCoordinates[1])){
        if (actualPosX-1 != -1){
            canLeft = true;
        }
        if (actualPosX+1 != solutionMatrix[1].size()+1){
            canRight = true;
        }
        if (actualPosY-1 != -1){
            canUp = true;
        }
        if (actualPosY-1 != solutionMatrix.size()+1){
            canDown = true;
        }
        if (canDown){
            if (labyrinthMatrix[actualPosX][actualPosY+1] == 1){
                canRoadDown = true;
            }         
        }
        if (canUp){
            if (labyrinthMatrix[actualPosX][actualPosY-1] == 1){
                canRoadUp = true;
            }         
        }
        if (canRight){
            if (labyrinthMatrix[actualPosX+1][actualPosY] == 1){
                canRoadRight = true;
            }         
        }
        if (canLeft){
            if (labyrinthMatrix[actualPosX-1][actualPosY] == 1){
                canRoadLeft = true;
            }         
        }



        if (canRoadDown){
            auxMatrix[actualPosX][actualPosY] = 4;
            solution(actualPosX,actualPosY+1);
        }
        
        


        
    }
    

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
