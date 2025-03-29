#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    float x;
    float y;

public :
    point ( float a,float b)
    {
        x=a;
        y=b;
    }
    void afficher()
    {

        cout<<"Point ( "<<x <<";"<<y<<")"<< endl;
    }
    void deplacer(float a, float b)
    {
        x += a;
        y += b;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }
    void setX(float a)
    {
        x=a;
    }
    void setY(float b)
    {
        y=b;
    }
    bool comparer(Point p)
    {
        return (x == p.x && y == p.y);
    }
    float calculer(Point p)
    {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

int main()
{
    Point p1, p2;
    p1.x=3;
    p1.y=4;
    p2.x=6;
    p2.y=7;
    p1.afficher();
    p2.afficher();
    cout<<"\nApres le deplacement :"<< endl;
    p1.deplacer(2,2);
    p1.afficher();
    p2.deplacer(2,2);
    p2.afficher();
    cout<<"\nl'abscisse de chaque point  :"<< endl;
    cout<< p1.getX()<< endl;
    cout<< p2.getX()<< endl;
    cout<<"\nl'ordonnee de chaque point  :"<< endl;
    cout<< p1.getY()<< endl;
    cout<< p2.getY()<< endl;
    if (p1.comparer(p2))
    {
        cout <<"\np1 et p2 coincident." << endl;
    }
    else
    {
        cout <<"\np1 et p2 ne coincident pas." << endl;
    }
    float distanceP1P2 = p1.calculer(p2);
    cout <<"\nDistance de p1 a p2 : " << distanceP1P2 <<" cm"<< endl;
    return 0;
}
