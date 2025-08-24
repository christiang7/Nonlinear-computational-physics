#include <iostream>
#include <cmath>
using namespace std ;

//logitische Funktion

int main ()
{
	float // Kommentar
        x = 0.3,
        r = 0.4
        ;
        for (int i = 0; i < 50; i++)// Schleife für die x Werte
        {
            x = r*x*(1-x);
            cout << i << ' ' << x << endl;
            /*
                if (i >= 46)
                {
                    cout << r << ' ' << x << endl;
                }
                */
        }
}
/*

*/
