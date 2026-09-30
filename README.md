# -tsp-solver-cpp-
Résolution du problème du voyageur de commerce (TSP) en C++ à l'aide d'heuristiques constructives (AllStartPPV, Meilleure Insertion).
# TSP Solver - Heuristiques Constructives en C++

Moteur de résolution du **Problème du Voyageur de Commerce (TSP)** développé en C++. Ce programme permet de charger une liste de coordonnées de villes et de calculer un circuit via des heuristiques constructives.

## 🚀 Fonctionnalités
* **Parsing et traitement** : Chargement de fichiers d'instances et calcul automatique de la matrice de distances inter-villes.
* **Algorithmes d'optimisation** :
  * **AllStartPPV** : Recherche du Plus Proche Voisin appliquée à partir de chaque ville de départ pour identifier le meilleur parcours global.
  * **Meilleure Insertion** : Construction progressive de la tournée par insertion optimale des villes.
* **Interface CLI** : Menu en ligne de commande pour tester et comparer les heuristiques.

## 🛠️ Compilation et Exécution

### Compilation
```bash
g++ -std=c++11 programme.cpp Fonctions.cpp -o tsp_solver



