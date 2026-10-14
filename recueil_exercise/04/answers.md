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


#### 04-bissextile-year
Ecrire un programme C++ affichant à l'écran si les années 1900, 2000, 2010 et 2020 sont bissextiles ou non.

Pour ce faire, écrire une **fonction booléenne** _estBissextile_ (donc, ne pas utiliser des `if`) prenant en paramètre l'année à tester.
**code** :
```c++
bool isLeapYear(int year) {  
    return (year%4==0 && year%100!=0) || year%400==0;  
}
```


#### 05-list-char
Ecrire une fonction qui prend 2 paramètres de type _char_ et qui affiche, sur une même ligne, tous les caractères non accentués compris entre deux paramètres _debut_ et _fin_, bornes comprises.  
Rien n'est affiché si _debut_ > _fin_.

Exemples
- listerCaracteres('A', 'A') => A
- listerCaracteres('A', 'C') => ABC
- listerCaracteres('B', 'A') =>
- listerCaracteres('0', '9') => 0123456789
- listerCaracteres(65, 67) => ABC
La fonction retourne un booléen indiquant si des caractères ont été affichés.
**code** :
```c++
bool listChar(const char a, const char b) {  
    if (a>b) {  
        return false;  
    }  
    for (char i = a; i <= b; i++) {  
        std::cout << i;  
    }  
    return true;  
}
```


#### 06-correct-error
Quelles modifications faut-il apporter au programme ci-dessous pour le rendre correct ?  
**NB** Aucune ligne de code ne doit être ajoutée !

```c
#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
   f;
   g(1, 2.0);
   h(64, 65);

   return EXIT_SUCCESS;
}

void f {
   cout << "Appel de f\n";
}

//------------------------------------------------------------
void g(int i, j) {
   cout << "Appel de g avec i = " << i << " et j = " << j << "\n";
}

//------------------------------------------------------------
void h(int i; char c) {
   cout << "Appel de h avec i = " << i << " et c = '" << c << "'\n";
}
--

void f() {
   cout << "Appel de f\n";
}

//------------------------------------------------------------
void g(int i, int j) {
   cout << "Appel de g avec i = " << i << " et j = " << j << "\n";
}

//------------------------------------------------------------
void h(int i, char c) {
   cout << "Appel de h avec i = " << i << " et c = '" << c << "'\n";
}

int main() {
   f();
   g(1, 2); //not mandatory but better
   h(64, 65);

   return EXIT_SUCCESS;
}
```


#### 07-mystery
Déterminer "à la main" ce que va afficher, à l'exécution, le programme ci-dessous.

```c++
#include <cstdlib>
#include <iostream>

using namespace std;
void mystere(int& a, int& b);

int main() {
   int x = 3, y = 4;
   mystere(x, y);
   cout << "x = " << x << " " << "y = " << y << endl;
   return EXIT_SUCCESS;
}

void mystere(int& a, int& b) {
   a = a - b;
   b = b + a;
   a = b - a;
}
--
x = 4 y = 3
```


#### 08-permutation
Ecrire un programme C++ qui met à disposition une fonction sans valeur de retour et prenant 3 paramètres de type double permettant d'effectuer une permutation circulaire droite de ces 3 valeurs.
**code** :
```c++
void permutation(double& a, double& b, double& c) {  
    double temp = a;  
    a = b;  
    b = c;  
    c = temp;  
}
```


