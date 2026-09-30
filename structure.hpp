//Fait par Ewen CREPIN et Clovis RETIF

#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>
#include<limits>
using namespace std;

struct Point{ //On créer une structure Point pour la réutiliser dans TSPData
    float x;
    float y;
};

struct TSPData{
    int taille;                     //Défini le nombre de villes qu'il y a dans notre TSPData
    vector<Point> coord;                //Défini les coordonnées de chaques villes
    vector<vector<int>> distances;          //On définit un vecteur de vecteur dans lequel il y ales distances entre chaques villes
};

struct TSPSolution{
    vector<int> visite;             //On définit un tableau qui donne l'ordre de visite des villes
    int coût;                       //Donne le coût de l'ordre de visite du tableau ci-dessus
};

inline TSPSolution operator<(TSPSolution s1, TSPSolution s2){
    if(s1.coût < s2.coût){
        return s1;                  // Permet de comparer les Solutions entre elles à partir de leur coût
    }else{
        return s2;
    }
}

inline ostream& operator<<(ostream& os, TSPSolution s){
    for(int i=0; i<s.visite.size(); ++i){
        os << s.visite[i] << endl;                  //Permet d'afficher les TSPSolutions
    }
    os << "le coût du trajet est: " << s.coût << endl;
    return os;
}

TSPData Parser(string fichier);
TSPData ComputeDistance(TSPData Ville);
TSPSolution PlusProcheVoisin(TSPData Ville, int V0);
TSPSolution AllStartPPV(TSPData Ville);
TSPSolution MeilleureInsertion(TSPData Ville);