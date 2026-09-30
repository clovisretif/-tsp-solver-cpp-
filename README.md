# -tsp-solver-cpp-
Résolution du problème du voyageur de commerce (TSP) en C++ à l'aide d'heuristiques constructives (AllStartPPV, Meilleure Insertion).
# TSP Solver - Heuristiques Constructives en C++

Moteur de résolution du **Problème du Voyageur de Commerce (TSP)** développé en C++[span_2](start_span)[span_2](end_span)[span_3](start_span)[span_3](end_span). Ce programme permet de charger une liste de coordonnées de villes et de calculer un circuit via des heuristiques constructives[span_4](start_span)[span_4](end_span)[span_5](start_span)[span_5](end_span).

## 🚀 Fonctionnalités
* **Parsing et traitement** : Chargement de fichiers d'instances et calcul automatique de la matrice de distances inter-villes[span_6](start_span)[span_6](end_span)[span_7](start_span)[span_7](end_span).
* **Algorithmes d'optimisation** :
  * **AllStartPPV** : Recherche du Plus Proche Voisin appliquée à partir de chaque ville de départ pour identifier le meilleur parcours global[span_8](start_span)[span_8](end_span)[span_9](start_span)[span_9](end_span).
  * **Meilleure Insertion** : Construction progressive de la tournée par insertion optimale des villes[span_10](start_span)[span_10](end_span)[span_11](start_span)[span_11](end_span).
* **Interface CLI** : Menu en ligne de commande pour tester et comparer les heuristiques[span_12](start_span)[span_12](end_span).

## 🛠️ Compilation et Exécution

### Compilation
```bash
g++ -std=c++11 Programme.cpp -o tsp_solver
