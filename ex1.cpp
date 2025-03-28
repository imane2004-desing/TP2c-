#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Etudiant {
    string nom;
    string prenom;
    int CNE;
    double notes[5];

  
    void creer(const string& nom, const string& prenom, int CNE, const double* notesArray) {
        this->nom = nom;
        this->prenom = prenom;
        this->CNE = CNE;
        for (int i = 0; i < 5; ++i) {
            notes[i] = notesArray[i];
        }
    }


    double getMaxNote() {
        double max = notes[0];
        for (int i = 1; i < 5; ++i) {
            if (notes[i] > max) {
                max = notes[i];
            }
        }
        return max;
    }


    double getMinNote() {
        double min = notes[0];
        for (int i = 1; i < 5; ++i) {
            if (notes[i] < min) {
                min = notes[i];
            }
        }
        return min;
    }


    double getMoyenneNote() {
        double somme = 0;
        for (int i = 0; i < 5; ++i) {
            somme += notes[i];
        }
        return somme / 5;
    }

    void affiche() {
        cout << "Nom: " << nom << endl;
        cout << "Prénom: " << prenom << endl;
        cout << "CNE: " << CNE << endl;
        cout << "Plus grande note: " << getMaxNote() << endl;
        cout << "Plus petite note: " << getMinNote() << endl;
        cout << "Moyenne: " << setprecision(2) << fixed << getMoyenneNote() << endl;
        cout << "Quota de notes >= 10: " << getQuota() << "%" << endl;
    }

   
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
    Etudiant etudiants[NB_ETUDIANTS];

    for (int i = 0; i < NB_ETUDIANTS; ++i) {
        cout << "Entrer les informations pour l'étudiant " << (i + 1) << ":" << endl;

        string nom, prenom;
        int CNE;
        double notes[5];

        cout << "Nom: ";
        cin >> nom;

        cout << "Prénom: ";
        cin >> prenom;

        cout << "CNE: ";
        cin >> CNE;

        cout << "Entrer 5 notes:" << endl;
        for (int j = 0; j < 5; ++j) {
            cout << "Note " << (j + 1) << ": ";
            cin >> notes[j];
        }

       
        etudiants[i].creer(nom, prenom, CNE, notes);
    }

    cout << "\nDétails des étudiants:" << endl;
    for (const auto& etudiant : etudiants) {
        etudiant.affiche();
        cout << "---------------------------" << endl;
    }

    return 0;
}
