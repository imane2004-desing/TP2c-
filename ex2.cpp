#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    float x;
    float y;

    // Fonction pour saisir les coordonnées d'un point
    void saisie(float a, float b) {
        x = a;
        y = b;
    }

    // Fonction pour déplacer le point
    void depacer(float a, float b) {
        x += a;
        y += b;
    }

    // Fonction pour obtenir l'abscisse
    float abscisse() {
        return x;
    }

    // Fonction pour obtenir l'ordonnée
    float ordonnee() {
        return y;
    }

    // Fonction pour comparer deux points
    bool comparer(Point p) {
        return (x == p.x && y == p.y);
    }

    // Fonction pour calculer la distance entre deux points
    float calcule(Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

    // Fonction pour afficher les coordonnées du point
    void affiche() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1, p2, p3;

    // Saisir les coordonnées des points
    p1.saisie(3.0, 4.0);
    p2.saisie(6.0, 8.0);
    p3.saisie(3.0, 4.0); // p3 a les mêmes coordonnées que p1

    // Afficher les coordonnées
    cout << "Point P1: ";
    p1.affiche();
    cout << endl;

    cout << "Point P2: ";
    p2.affiche();
    cout << endl;

    cout << "Point P3: ";
    p3.affiche();
    cout << endl;

    // Calculer la distance de P1 à l'origine
    Point origine = {0, 0};
    cout << "Distance de P1 à l'origine: " << p1.calcule(origine) << endl;

    // Calculer la distance entre P1 et P2
    cout << "Distance entre P1 et P2: " << p1.calcule(p2) << endl;

    // Déplacer P2 par (20, 13)
    p2.depacer(20, 13);
    cout << "P2 après déplacement: ";
    p2.affiche();
    cout << endl;

    // Vérifier si P1 et P3 coïncident
    if (p1.comparer(p3)) {
        cout << "P1 et P3 coïncident." << endl;
    } else {
        cout << "P1 et P3 ne coïncident pas." << endl;
    }

    // Vérifier les points les plus proches
    float distanceP1P2 = p1.calcule(p2);
    float distanceP1P3 = p1.calcule(p3);
    float distanceP2P3 = p2.calcule(p3);

    cout << "Les distances entre les points:" << endl;
    cout << "P1 et P2: " << distanceP1P2 << endl;
    cout << "P1 et P3: " << distanceP1P3 << endl;
    cout << "P2 et P3: " << distanceP2P3 << endl;

    // Trouver les points les plus proches
    if (distanceP1P2 < distanceP1P3 && distanceP1P2 < distanceP2P3) {
        cout << "Les points les plus proches sont P1 et P2." << endl;
    } else if (distanceP1P3 < distanceP1P2 && distanceP1P3 < distanceP2P3) {
        cout << "Les points les plus proches sont P1 et P3." << endl;
    } else {
        cout << "Les points les plus proches sont P2 et P3." << endl;
    }

    return 0;
}
