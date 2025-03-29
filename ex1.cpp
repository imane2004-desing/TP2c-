#include <iostream>

using namespace std;

class Etudiant{
  int matricule;
  string nom;
  int nbrNotes;
  float* tabNotes;
  static int n;

  public :
      Etudiant(){
        matricule =0;
        nom ="";
        nbrNotes=0;
        tabNotes = new float[nbrNotes];
      }
      Etudiant(string nom, int nb){
        n++;
        matricule = n;
        this->nom =nom;
        this->nbrNotes=nb;
        tabNotes = new float(nbrNotes);
      }
      string getNom(){
        return nom;
      }
      int getMatricule(){
        return matricule;
      }
      string setNom(string nom1){
        return nom1;
      }
      int setMatricule(int mat){
        return mat;
      }

      void Saisie(){
        cout <<"Remplissage du tableau:"<< endl;
        for(int i=0;i<nbrNotes;i++){
          cout << "note "<<i+1 <<": "<<endl;
          cin>>tabNotes[i];
        }
      }
      void Affiche(){
        cout <<"les elements du tableau:"<< endl;
        cout << nom<< endl;
        for(int i=0;i<nbrNotes;i++){

          cout << "note"<<i+1<<":";
          cout <<tabNotes[i]<< endl;
        }
      }
      float Moyenne(){
        float s=0;
        for(int i=0;i<nbrNotes;i++){
            s+=tabNotes[i];
        }
        return s/nbrNotes;}

     bool estValide(int moyenne){
       if(moyenne >=10){
         return true;
       }else{
         return false ;
    }}
};
int Etudiant :: n=0;
int main()
{
     Etudiant E("Imane",4);
    cout << E.getNom() << endl;
    cout << E.getMatricule()<< endl;
    E.Saisie();
    E.Affiche();
    float m=E.Moyenne();
    cout<< "la moyenne est:"<< m<< endl;
    if(E.estValide(m)){
        cout<<"admis";
    }else{
        cout<<"Non admis";
    }


    return 0;
}
