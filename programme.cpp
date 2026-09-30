//Fait par Ewen CRETIN et Clovis RETIF
//(Au moment d'appeler la fonction après avoir on compiler, il faurt souvent faire plusieurs appels sinon la fonction ne renvoie rien)

#include "structure.hpp"

int main(int argc, char** argv){
    if(argc != 2){                              //On vérifie qu'il n'y a bien que deux fichiers en argument
        cout << "Problème de fichiers" << endl;         
        exit(0);
    }
    fstream ouverture(argv[1]);                 //On ouvre le fichier contenant les villes
    if(ouverture){
        TSPData Ville;                          //On définit une variable TSPData ville
        int choix;                              //On définit la variable choix qui permet à l'utilisateur de choisir l'heuristique qu'il veut
        while (choix!=0){                       //Le while permet à l'utilisateur de faire AllStartPPV et MeilleureInsertion sur le même appel de la fonction
            cout << "Choisissez l'heuristique que vous voulez: (1)AllStartPPV / (2)MeilleureInsertion ou  tapez (0) si vous voulez arrêter le programme: " ;
            cin >> choix;
            switch (choix){                     //On fait un switch pour répondre au choix de l'utilisateur
            case 0:
                cout << "on quitte le programme" << endl;
                exit(0);                        //Ce choix de l'utilisateur nous fait quitter le programme
            case 1: 
                Ville = Parser(argv[1]);
                Ville = ComputeDistance(Ville);     //On appel les fonctions Parser et ComputeDistance qui permettent à la variable ville d'intégrer des données sans lesquelles AllStartPPV ne peut pas marcher
                cout << "Résultat AllStartPPV: " << AllStartPPV(Ville) << endl;
                break;

            case 2:
                Ville = Parser(argv[1]);
                Ville = ComputeDistance(Ville);     //On appel les fonctions Parser et ComputeDistance qui permettent à la variable ville d'intégrer des données sans lesquelles MeilleureInsertion ne peut pas marcher
                cout << "Résultat MeilleureInsertion: " << MeilleureInsertion(Ville) << endl;
                break;
        
            default:
                cout << "Erreur" << endl;
                exit(0);                            //Si l'utilisateur ne saisit ni 0, ni 1,ni 2 le programme renvoie une erreur
            }
        }
    }else{
        cout << "Problème d'ouverture de fichiers" << endl;
        exit(0);                                    //Si le fichier ne peut pas se lire on renvoie une erreur
    }
    ouverture.close();
    return 0;
}
