#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    float x;
    float y;

    // Fonction pour saisir les coordonn�es d'un point
    void saisie(float a, float b) {
        x = a;
        y = b;
    }

    // Fonction pour d�placer le point
    void depacer(float a, float b) {
        x += a;
        y += b;
    }

    // Fonction pour obtenir l'abscisse
    float abscisse() {
        return x;
    }

    // Fonction pour obtenir l'ordonn�e
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

    // Fonction pour afficher les coordonn�es du point
    void affiche() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1, p2, p3;

    // Saisir les coordonn�es des points
    p1.saisie(3.0, 4.0);
    p2.saisie(6.0, 8.0);
    p3.saisie(3.0, 4.0); // p3 a les m�mes coordonn�es que p1

    // Afficher les coordonn�es
    cout << "Point P1: ";
    p1.affiche();
    cout << endl;

    cout << "Point P2: ";
    p2.affiche();
    cout << endl;

    cout << "Point P3: ";
    p3.affiche();
    cout << endl;

    // Calculer la distance de P1 � l'origine
    Point origine = {0, 0};
    cout << "Distance de P1 � l'origine: " << p1.calcule(origine) << endl;

    // Calculer la distance entre P1 et P2
    cout << "Distance entre P1 et P2: " << p1.calcule(p2) << endl;

    // D�placer P2 par (20, 13)
    p2.depacer(20, 13);
    cout << "P2 apr�s d�placement: ";
    p2.affiche();
    cout << endl;

    // V�rifier si P1 et P3 co�ncident
    if (p1.comparer(p3)) {
        cout << "P1 et P3 co�ncident." << endl;
    } else {
        cout << "P1 et P3 ne co�ncident pas." << endl;
    }

    // V�rifier les points les plus proches
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
