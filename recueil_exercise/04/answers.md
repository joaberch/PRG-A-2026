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


#### 09-withdraw-money
Ecrire un programme C++ mettant à disposition une fonction permettant de retirer un certain montant sur un compte bancaire.

La fonction :
- doit prendre 2 paramètres : le solde courant du compte et le montant du retrait (que l'on supposera tous deux ≥ 0)
- doit vérifier les contraintes métier suivantes :
    - le solde courant ne peut jamais être négatif
    - si le solde courant est insuffisant pour retirer l'intégralité du montant souhaité, seul le montant maximal possible est retiré
- doit retourner le montant du retrait effectif réalisé

Vérifier le bon fonctionnement de la fonction en appliquant le scénario de test suivant :

- Solde initial du compte = 500
- Premier retrait = 300
- Afficher le montant du retrait effectif et le solde courant du compte
- Deuxième retrait = 300
- Afficher le montant du retrait effectif et le solde courant du compte
**code** :
```c++
double withdraw(double solde, double withdrawal) {  
    if (solde < 0) {  
        return 0;  
    }  
    if (withdrawal > solde) {  
        std::cout << "Retrait de " << solde << " le solde est maintenant a 0." << std::endl;  
        return 0;  
    }  
    solde -= withdrawal;  
    std::cout << "Retrait de " << withdrawal << " le solde est maintenant a " << solde << std::endl;  
    return solde;  
}
```


#### 10-arithmetic-operation
Ecrire une fonction qui reçoit en paramètres d'entrée 2 nombres réels (de type double) et un caractère, et qui fournit en paramètre de sortie le résultat correspondant à l'une des 4 opérations appliquées à ses 2 premiers paramètres, en fonction de la valeur du troisième paramètre, à savoir : addition pour le caractère '+', soustraction pour '-', multiplication pour '$*$' et division pour '/'. Si l'un de ces 4 caractères est passé en argument, la fonction doit renvoyer true comme valeur (statut) de retour; dans le cas contraire, elle doit renvoyer false. Ne pas tenir compte des risques de division par zéro.

Ecrire aussi un petit programme (main) utilisant cette fonction pour effectuer les 4 opérations sur les 2 nombres fournis en entrée par l'utilisateur. Ne pas tenir compte des éventuelles erreurs de saisie utilisateur.
**code** :
```c++
bool arithmetic(double a, double b, char sign, double& output) {  
    switch (sign) {  
        case '-':  
            output = a-b;  
            break;  
        case '+':  
            output = a+b;  
            break;  
        case '/':  
            output = a/b;  
            break;  
        case '*':  
            output = a*b;  
            break;  
        default:  
            return false;  
            break;  
    }  
    return true;  
}  
  
int main () {  
    double output = 0; //base value  
    double a; std::cin >> a;  
    double b; std::cin >> b;  
    arithmetic(a, b, '+', output);  
    std::cout << output << std::endl;  
    arithmetic(a, b, '-', output);  
    std::cout << output << std::endl;  
    arithmetic(a, b, '*', output);  
    std::cout << output << std::endl;  
    arithmetic(a, b, '/', output);  
    std::cout << output << std::endl;  
}
```


#### 11-adresse-param
Que produit le code ci-dessous ?

```c
#include <iostream>
#include <cstdlib>
using namespace std;

void adresse(int* param) {

   *param += 1;            // param à l'adresse 0x16eea3648
                           // (cette valeur ne sera pas la même dans votre cas)

   cout << "param          : " <<  param << endl;
   cout << "adr param      : " << &param << endl;
   cout << "valeur pointee : " << *param << endl;
}

int main() {
   int entier = 17;        // entier à l'adresse 0x16eea3698
                           // (cette valeur ne sera pas la même dans votre cas)
   cout << "entier         : " <<  entier << endl;
   cout << "adr entier     : " << &entier << endl;

   adresse(&entier);

   cout << "entier         : " <<  entier << endl;
   cout << "adr entier     : " << &entier << endl;

   return EXIT_SUCCESS;
}
```

| Element        | Affichage   |
| -------------- | ----------- |
| entier         | 17          |
| adr entier     | 0x16eea3698 |
| param          | 0x16eea3698 |
| adr param      | 0x16eea3648 |
| valeur pointee | 18          |
| entier         | 18          |
| adr entier     | 0x16eea3698 |


#### 12-adresse-permutation
Reprendre l'exercice [02b-02 - permutation](https://github.com/HEIGVD-PRG1/PRG1_Recueil_Exercices/blob/main/04%20-%20Fonctions%20recursivite%20surcharge/08%20-%20permutation%20par%20reference.md) mais sans utiliser de référence `double& ref`
**code** :
```c++
void adressePermutation(double* a, double* b, double* c) {  
    const double temp = *a;  
    *a = *b;  
    *b = *c;  
    *c = temp;  
}  
  
int main () {  
    double a = 1, b = 2, c = 3;  
    adressePermutation(&a, &b, &c);  
    std::cout << a << " " << b << " " << c << std::endl;  
}
```


#### 13-value-reference
Le programme ci-dessous contient plusieurs erreurs :
1. Pour chaque ligne fautive, indiquez son numéro et précisez la nature de l'erreur
2. En admettant maintenant que les lignes fautives ont été supprimées du programme ci- dessous, déterminer "à la main" ce qu'il va afficher à l'exécution ?

```c++
1  #include <cstdlib>
2  #include <iostream>

3  using namespace std;
4
5  void f(double x);
6  void g(double& x);
7  void h(const double& x); 
9  int main() {
10
11    const int C = 1;
12    int n = C;
13    double x = C;
14   
15    f(C);
16    f(n);
17    f(x);
18    //g(C); //err const in ref
19    //g(n); //err invalid type
20    g(x); 
21    h(C);
22    h(n);
23    h(x);
24   
25    return EXIT_SUCCESS;
26 }
27   
28 void f(double x) {
29    x = x + 1;
30    cout << "x = " << x <<endl;
31 }
32 
33 void g(double& x) {
34    x = x + 1;
35    cout << "x = "<< x <<endl;
36 }
37 
38 void h(const double& x) {
39    //x = x + 1; //err editing const
40    cout << "x = " << x <<endl;
41 }
--
x = 2
x = 2
x = 2
x = 2
x = 1
x = 1
x = 2
```


#### 14-minimum
Écrire une fonction _min_ qui retourne le minimum de 3 valeurs reçues en paramètre.
Les instructions suivantes doivent être possibles:
```c++
int a = 5;
int b = 2;
int c = 9;

cout << min(a, b, c);
min(a, b, c) = 1;
int& d = min(a, b, c);
```
**NB** ne pas utiliser de `if`
**code**
```c++
int min(int a, int b, int c) {  
    int min = b<c ? b : c;  
    min = a<b && a<c ? a : min;  
    return min;  
}
```


#### 15-min-output
Que produit le code ci-dessous ?

| #   | a   | b   | c   | min | d   |
| --- | --- | --- | --- | --- | --- |
| 1)  | 12  | 7   | 9   | 7   | 7   |
| 2)  | 12  | 5   | 9   | 5   | 7   |
| 3)  | 12  | 3   | 9   | 3   | 3   |
| 4)  | 1   | 3   | 9   | 1   | 3   |
| 5)  | 0   | 3   | 9   | 0   | 3   |

```c++
#include <cstdlib>
#include <iostream>

using namespace std;

int& min(int& a, int& b, int& c) {
      return a < c ?
         a < b ? a : b :
         b < c ? b : c ;
}

int main() {

   int a = 12,
       b = 7,
       c = 9;

   cout << "1) a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   int& d = min(a, b, c);
   cout << "d:" << d << endl << endl;

   b=5;
   cout << "2) b = 5;" << endl;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   d=3;
   cout << "3) d = 3;" << endl;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   a=1;
   cout << "4) a = 1;" << endl;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   cout << "5) min(a, b, c) = 0;" << endl;
   min(a, b, c) = 0;
   cout << "a:" << a << " b:" << b << " c:" << c
        << " => min:" << min(a, b, c) << " ";
   cout << "d:" << d << endl << endl;

   return EXIT_SUCCESS;
}
```


#### 16-factorielle
La factorielle d'un nombre est décrite comme suit
`5! = 1 * 2 * 3 * 4 * 5`  
`6! = 1 * 2 * 3 * 4 * 5 * 6` ou `6! = 6 * 5!`  
Ainsi `n! = n * (n-1)!` avec `1! = 1` et `0! = 1` pour `n >= 0`
Ecrire une fonction récursive _facto_ qui retourne la valeur de `n!` pour _n_ reçu en paramètre (sans regarder l'exemple donné en cours ;-)).
**code**
```c++
int factorial(int n) {  
    if (n == 0) {  
        return 1;  
    }  
    return n*factorial(n-1);  
}
```


