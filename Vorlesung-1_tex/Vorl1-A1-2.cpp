#include <iostream>
#include <cmath>
using namespace std ;

//logitische Funktion

int main ()
{
	float x,r, delta_r; // Kommentar
	r = 0.1;
        x = 0.3;
        delta_r = 0.01;
        
        for (r = 0.; r < 5.; r = r+delta_r)// erste Schleife für die r Werte
        {
            x = 0.3;
            for (int i = 0; i < 1000; i++)// zweite Schleife für die x Werte
            {
                x = r*x*(1-x);
                //cout << x << endl;
                if (i >= 900)
                {
                    cout << r << ' ' << x << endl;
                }
            }
        }
}
/*

*/
