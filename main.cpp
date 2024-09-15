#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

// Fonction pour calculer le plus petit k tel que D^k >= N
int calculate_k(int D, int N) {
    int k = 1;
    while (pow(D, k) < N) {
        ++k;
    }
    return k;
}

// Fonction pour simuler un lancer de dé automatique (nombre aléatoire de 1 à D)
int roll_die(int D) {
    random_device rd;  // Générateur aléatoire de haute qualité
    mt19937 gen(rd()); // Générateur de nombre pseudo-aléatoire
    uniform_int_distribution<> distrib(1, D); // Distribution uniforme de 1 à D
    return distrib(gen);
}

// Fonction pour convertir une série de lancers en un nombre en base D
int convert_to_base_D(const vector<int>& rolls, int D) {
    int result = 0;
    for (long unsigned int i = 0; i < rolls.size(); ++i) {
        result = result * D + (rolls[i] - 1); // Conversion en base D, indexé à partir de 0
    }
    return result + 1; // Indexation à partir de 1 pour les humains
}

int main() {
    cout << "      Dice100              v1.0\n" << endl;
    cout << "Tirage au hasard outrapassant les limites matérielles.\n" << endl;
    cout << "On a un petit dé (tirant généralement de 1 à 6 : donc un dé avec D = 6)." << endl;
    cout << "On veut un grand nombre, généralement entre 1 et 100, donc avec N = 100." << endl;
    cout << "On va donc lancer plusieurs fois le dé." << endl;
    long unsigned int D = 0;
    long unsigned int N = 0;
    ;
    bool autoDice = true;
    // Récupérer les valeurs de D et N
    while (D<2){
    cout << "Entrez le nombre de faces du dé (D > 1) :" << endl;
    cin >> D;
}
    while (N<2){
    cout << "Entrez la valeur de N (N > 1) : " << endl;
    cin >> N;
    }
    cout << "Dois-je lancer le dé moi-même ? (1 = oui ; 0 = non.)" << endl;
    cin >> autoDice;

    // Calculer le nombre minimum de lancers k
    int k = calculate_k(D, N);
    cout << "Le nombre minimum de lancers nécessaires (k) est : " << k << endl;

    vector<int> rolls(k);  // Pour stocker les lancers
    int generated_number;

    // Boucle pour effectuer les lancers et vérifier si le nombre généré est acceptable
    do {
        cout << "Lancers du dé :\”";
        for (int i = 0; i < k; ++i) {
            if (autoDice) {
                rolls[i] = roll_die(D);
                cout << rolls[i] << " ";  // Afficher chaque lancer
            } else {
                cout << "Lancer numéro " << i+1 << " de cette série :" << endl;
                cin >> rolls[i];
            }
        }
        cout << endl;

        // Convertir les lancers en un nombre base D
        generated_number = convert_to_base_D(rolls, D);
        cout << "Nombre généré (via la base " << D << ") : " << generated_number << "." << endl;

        // Si le nombre dépasse N, on rejette et on recommence
        if (generated_number > N) {
            cout << generated_number << " > "<< N << " : nombre rejeté, nous devons recommencer la série..." << endl;
        }
    } while (generated_number > N);

    // Afficher le résultat final valide
    cout << "Nombre final valide (entre 1 et " << N << ") : " << generated_number << "." << endl;
    return 0;
}
