#include <iostream>
#include <cmath>
using namespace std ;

// Aufgabe 2 Ikeda Map

void ikeda_map(double &E1, double &E2);

int main ()
{
        double 
        E1 = 0.2, // Realteil
        E2 = 3.1 // Imaginärteil
        ;
        
        // Formel E = A +B*E*exp(i*|E|^2) E ist komplex 
        for (int i = 0; i < 1000; i++)// Schleife für E1, E2 Werte
        {
            ikeda_map(E1, E2);
            //if (i >= 140)
                cout << E1 << ' ' << E2 << endl;
        }
}

void ikeda_map(double &E1, double &E2)
{
    double 
        A = 8.,
        B = 0.8,
        phi = atan(E2/E1),
        E_Betrag = sqrt(E1*E1+E2*E2)
        ;
    E1 = A + B*E_Betrag*(cos(phi)*cos(E_Betrag*E_Betrag)-sin(phi)*sin(E_Betrag*E_Betrag));
    E2 = B*E_Betrag*(cos(phi)*sin(E_Betrag*E_Betrag)+sin(phi)*cos(E_Betrag*E_Betrag));
};
/*

*/
