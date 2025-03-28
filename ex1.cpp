#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Etudiant {
    string nom;
    string prenom;
    int CNE;
    double notes[5];

    // M�thode pour cr�er un �tudiant
    void creer(const string& nom, const string& prenom, int CNE, const double* notesArray) {
        this->nom = nom;
        this->prenom = prenom;
        this->CNE = CNE;
        for (int i = 0; i < 5; ++i) {
            notes[i] = notesArray[i];
        }
    }

    // M�thode pour obtenir la plus grande note
    double getMaxNote() {
        double max = notes[0];
        for (int i = 1; i < 5; ++i) {
            if (notes[i] > max) {
                max = notes[i];
            }
        }
        return max;
    }

    // M�thode pour obtenir la plus petite note
    double getMinNote() {
        double min = notes[0];
        for (int i = 1; i < 5; ++i) {
            if (notes[i] < min) {
                min = notes[i];
            }
        }
        return min;
    }

    // M�thode pour obtenir la moyenne des notes
    double getMoyenneNote() {
        double somme = 0;
        for (int i = 0; i < 5; ++i) {
            somme += notes[i];
        }
        return somme / 5;
    }

    // M�thode pour afficher les d�tails de l'�tudiant
    void affiche() {
        cout << "Nom: " << nom << endl;
        cout << "Pr�nom: " << prenom << endl;
        cout << "CNE: " << CNE << endl;
        cout << "Plus grande note: " << getMaxNote() << endl;
        cout << "Plus petite note: " << getMinNote() << endl;
        cout << "Moyenne: " << setprecision(2) << fixed << getMoyenneNote() << endl;
        cout << "Quota de notes >= 10: " << getQuota() << "%" << endl;
    }

    // M�thode pour obtenir le quota des notes >= 10
    double getQuota() {
        int count = 0;
        for (int i = 0; i < 5; ++i) {
            if (notes[i] >= 10) {
                count++;
            }
        }
        return (count / 5.0) * 100;
    }
};

int main() {
    const int NB_ETUDIANTS = 3;
    Etudiant etudiants[NB_ETUDIANTS]; // Cr�er un tableau de 3 �tudiants

    // Remplir le tableau d'�tudiants
    for (int i = 0; i < NB_ETUDIANTS; ++i) {
        cout << "Entrer les informations pour l'�tudiant " << (i + 1) << ":" << endl;

        string nom, prenom;
        int CNE;
        double notes[5];

        cout << "Nom: ";
        cin >> nom;

        cout << "Pr�nom: ";
        cin >> prenom;

        cout << "CNE: ";
        cin >> CNE;

        cout << "Entrer 5 notes:" << endl;
        for (int j = 0; j < 5; ++j) {
            cout << "Note " << (j + 1) << ": ";
            cin >> notes[j];
        }

        // Cr�er l'�tudiant
        etudiants[i].creer(nom, prenom, CNE, notes);
    }

    // Afficher les d�tails de tous les �tudiants
    cout << "\nD�tails des �tudiants:" << endl;
    for (const auto& etudiant : etudiants) {
        etudiant.affiche();
        cout << "---------------------------" << endl;
    }

    return 0;
}
