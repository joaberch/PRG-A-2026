#### 01-pass-by-value
Déterminer "à la main" ce que va afficher, à l'exécution, le programme ci-dessous.

```c++
#include <cstdlib>
#include <iostream>
using namespace std;

void f(int n) {
   n *= n + 1;
   cout << "B : n = " << n << endl;
}

int main() { 
   int n = 2;
   cout << "A : n = " << n     << endl;
   f(n);
   cout << "C : n = " << 2 * n << endl;
   return EXIT_SUCCESS;
}
--
A: n = 2
B: n = 6
C: n = 4
```


#### 2-func-call
Déterminer "à la main" ce que poduit ce code.

```c++
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

double k(double x) { return 2 * (x + 1);        }
double h(double x) { return x * x + k(x) - 1;   }
double g(double x) { return 4 * h(x);           }
double f(double x) { return g(x) + sqrt(h(x));  }

int main() {
    double x1 = f(2),
           x2 = g(h(2)),
           x3 = k(g(2) + h(2)),
           x4 = f(0) + f(1) + f(2),
           x5 = f(-1) + g(-1) + h(-1) + k(-1);
       
   cout << "x1 = " << x1 << endl;
   cout << "x2 = " << x2 << endl;
   cout << "x3 = " << x3 << endl;
   cout << "x4 = " << x4 << endl;
   cout << "x5 = " << x5 << endl;

   return EXIT_SUCCESS;
}
--
x1 = 39
x2 = 400
x3 = 92
x4 = 62
x5 = 0
```


#### 03-vol-pyramide
Ecrire un programme C++ mettant à disposition une fonction permettant de calculer le volume d'une pyramide à base rectangulaire.

Appliquer la fonction pour calculer le volume des 2 pyramides suivantes :
1. Pyramide 1 : base de longueur 10 et de largeur 3.5; hauteur = 12
2. Pyramide 2 : base de longueur 3.6 et de largeur 2.4; hauteur = 2.7
Afficher les résultats avec un chiffre après la virgule.
**code** :
```c++
void volPyramide(const double base, const double largeur, const double hauteur) {  
    double volume = base*largeur*hauteur/3.;  
    printf("Le volume de la pyramide de base %.f, largeur : %.f, hauteur : %.f est %.1f\n", base, largeur, hauteur, volume);  
}
```


