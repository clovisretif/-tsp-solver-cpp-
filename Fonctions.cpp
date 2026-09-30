#include "structure.hpp"

TSPData Parser(string fichier){
    ifstream ouverture(fichier);
    TSPData Ville;
    int Numero_Ville;
    if(ouverture){    
        ouverture >> Ville.taille >> ws;
        Ville.coord.resize(Ville.taille);
        for(int i=0; i<Ville.taille;++i){
            ouverture >> Numero_Ville >> ws;
            ouverture >> Ville.coord[i].x >> ws;
            ouverture >> Ville.coord[i].y >> ws;
        }
    }else{
        cout << "Problème d'ouverture" << endl;
        exit(0);
    }
    cout << endl;
    ouverture.close();
    return Ville;
}

TSPData ComputeDistance(TSPData Ville){
    int distance;
    Ville.distances.resize(Ville.taille, vector<int>(Ville.taille));
    for(int i=0; i<Ville.taille; ++i){
        for(int j=0; j<Ville.taille; ++j){
            if(i==j){
                Ville.distances[i][j] = 2147483647;
            }else{
                distance = int(sqrt((Ville.coord[j].x - Ville.coord[i].x)*(Ville.coord[j].x - Ville.coord[i].x)+(Ville.coord[j].y - Ville.coord[i].y)*(Ville.coord[j].y - Ville.coord[i].y))+0.5);
                Ville.distances[i][j] = distance;
            }
        }
    }
    return Ville;
}

TSPSolution PlusProcheVoisin(TSPData Ville, int V0) {
    TSPSolution Solution;
    Solution.visite.push_back(V0);
    vector<bool> visite(Ville.taille, false);
    visite[V0] = true;

    int coût = 0;
    int villeActuelle = V0;

    for (int i = 1; i < Ville.taille; ++i) {
        int minDistance = 2147483647;
        int prochaineVille = -1;

        for (int j = 0; j < Ville.taille; ++j) {
            if (!visite[j] and Ville.distances[villeActuelle][j] < minDistance) {
                minDistance = Ville.distances[villeActuelle][j];
                prochaineVille = j;
            }
        }

        Solution.visite.push_back(prochaineVille);
        visite[prochaineVille] = true;
        coût += minDistance;
        villeActuelle = prochaineVille;
    }

    // Retour à la ville de départ
    coût += Ville.distances[villeActuelle][V0];
    Solution.coût = coût;
    return Solution;
}

TSPSolution AllStartPPV(TSPData Ville){
    TSPSolution Solution, meilleureSolution;
    meilleureSolution.coût = 2147483647;
    for(int i=0; i<Ville.taille; ++i){
        Solution = PlusProcheVoisin(Ville , i);
        meilleureSolution = Solution<meilleureSolution;
    }
    return meilleureSolution;
}

TSPSolution MeilleureInsertion(TSPData Ville){
    TSPSolution solution;
    int n = Ville.taille;
    vector<bool> visite(n, false);

    // Étape 1 : initialisation avec 0 et son plus proche voisin0

    int plusProche1,plusProche2 = -1;
    int minDistance = 2147483647;
    for (int i = 0; i < n; i++) {
        for (int j= i+1;j<n;j++){
            if (Ville.distances[0][i]) {
                minDistance = Ville.distances[0][i];
                plusProche1 = i;
                plusProche2 = j;
            }
        }
    }

    solution.visite.push_back(plusProche1);
    solution.visite.push_back(plusProche2);
    visite[plusProche1] = true;
    visite[plusProche2] = true;

    // On boucle pour former un circuit
    solution.coût = Ville.distances[plusProche1][plusProche2];

    // Étape 2 : insérer les points restants
    for (int i=2; i<n; i++){
        int meilleurPoint = -1;
        int meilleurePosition = -1;
        int augmentationMin = 2147483647;

        for (int i=0; i<n; i++){
            if (visite[i] == false){
                for (int j=0; j<solution.visite.size()-1; j++){
                    int a = solution.visite[j];
                    int b = solution.visite[j + 1];
                    int augmentation = Ville.distances[a][i] + Ville.distances[i][b] - Ville.distances[a][b];

                    if (augmentation < augmentationMin) {
                        augmentationMin = augmentation;
                        meilleurPoint = i;
                        meilleurePosition = j + 1;
                    }
                }
            }
        }

        // Insertion manuelle : décaler à droite à partir de meilleurePosition
        solution.visite.resize(solution.visite.size()+1);
        for (int i = solution.visite.size() - 1; i > meilleurePosition; i--){
            solution.visite[i] = solution.visite[i-1];
        }
        solution.visite[meilleurePosition] = meilleurPoint;
        visite[meilleurPoint] = true;
        solution.coût += augmentationMin;
    }

    return solution;
}