# 01-nommage des variables
| #   | Déclaration (et contexte)                                                    | Conforme ? | Recommandation / meilleur nom                                                               |
| --- | ---------------------------------------------------------------------------- | ---------- | ------------------------------------------------------------------------------------------- |
| 1   | `int nNbEtudiants = 25;`                                                     | nok        | Pas spécifié le type de la variable dans son nom<br>`nbStudents`                            |
| 2   | `double surface = largeur * hauteur;`                                        | ok         |                                                                                             |
| 3   | `const int NB_MAX_ETUDIANTS = 100;`                                          | nok        | On garde un nom en uppercase complet pour les macros<br>`nb_max_students`<br>`max_students` |
| 4   | `int nombreTotalDeBouteillesDansUnPack = 6;`                                 | nok        | trop long pour ce que c'est<br>`bottlesInPack`<br>`bottlesPerPack`                          |
| 5   | `double x = 13.2 * nb_bouteilles; // poids du pack en grammes`               | nok        | pas nommé, on privilégie un bon nom de variable à du commentaire<br>`packWeight`            |
| 6   | `int nbPacks, nb_bouteilles, PrixUnitaire;`                                  | nok        | pas la même norme de nommage<br>`nbPacks, nbBottles, unitPrice`                             |
| 7   | `double dblPrix = 2.5;`                                                      | nok        | Pas spécifié le type<br>`price`                                                             |
| 8   | `int a = 4, b = 12;` (utilisées 40 lignes plus loin, dans un calcul de prix) | nok        | pas nommé et emplacement peu utile                                                          |
| 9   | `double volume_canette_l = 0.33;`                                            | ~ok        | Peut être raccourci<br>`vol_canette_l`                                                      |
| 10  | `int INT = 3;`                                                               | nok        | Nom pas significatif et peut induire des bugs à long terme                                  |

# 02-déclaration de variables
1. 
```c++
 int n = 1;
 n = 1 - 2 * n;
 n = n + 1;
 --
 n: 0
```
2. 
```c++
int n = 1;
n = n + 1;
int n = 1 - 2 * n;
--
error n already declared
```
3. 
```c++
int n = 1, p = 2;
n = (n + 1) * (n - k);
--
error k is not declared
```
4. 
```c++
int n, m = 0;
n = 2 * n - 1;
m = n + 1;
--
error n is not initialized
```
5. 
```c++
int n = 5, m = 0;
const int nb_produit = 10;
m = n * nb_produit - 1;
--
m=49
```
6. 
```c++
int n = 5, m = 0;
const int nb_produit = 10;
nb_produit -= 1;
m = n * nb_produit;
--
error const is already declared
```

# 03-type de variable

| #   | Déclaration                | Type   |
| --- | -------------------------- | ------ |
| 1   | `??? var1 = 10;`           | int    |
| 2   | `??? var2 = 1.;`           | double |
| 3   | `??? var3 = '1';`          | char   |
| 4   | `??? var4 = 0.5;`          | double |
| 5   | `??? var5 = 'r';`          | char   |
| 6   | `??? var6 = true;`         | bool   |
| 7   | `??? var7 = 25.0;`         | double |
| 8   | `??? var8 = 3;`            | int    |
| 9   | `??? var9 = var1 / var8;`  | int    |
| 10  | `??? var10 = var1 / var4;` | double |
> [!NOTE]
> Pour le 9 et 10
> Le type du résultat dépend du type des variables utilisés.
> Si uniquement des `int` sont utilisés alors le résultat est arrondi en `int`.


# 04-type_numerique
1. Donnez le nom des 5 types entiers signés du C++, du plus court au plus long
- `signed char | short | int | long | long long`
2. Idem pour les 5 types entiers non signés
- `unsigned char | unsigned short | unsigned int | unsigned long | unsigned long long`
3. Le type int est-il signé ou non signé par défaut ?
- Signé
4. Le domaine de définition des entiers est-il fixé par la norme ou dépend-il de l'environnement utilisé
- Il dépend de l'environnement
> [!NOTE]
> Différence selon l'architecture où encore le compilateur utilisé
> [integer - What does the C++ standard say about the size of int, long? - Stack Overflow](https://stackoverflow.com/questions/589575/what-does-the-c-standard-say-about-the-size-of-int-long)
> [Fundamental types - cppreference.com](https://en.cppreference.com/cpp/language/types?utm_source=chatgpt.com)

# 05-taille des entiers
**solution**
```c++
void sizeVar() {  
    using type = unsigned int;  
  
    int bytes = sizeof(type);  
    bool isSigned = std::numeric_limits<type>::is_signed;  
    int bits = std::numeric_limits<type>::digits + isSigned;  
    /*
    digits get the bits used and is_signed add one if
    used for the sign  
    else sizeof(type) * CHAR_BIT but not permitted on this
    exercise
    */
    std::cout << "Taille : " << bytes <<
    " bytes = " << bits << " bits.\n";
    
    int min = std::numeric_limits<type>::min();  
    unsigned long long max = std::numeric_limits<type>::max();  
    //unsigned long long to be sure to not have an overflow  
    std::cout << "Plage de valeurs : " << min
    << " -> " << max << std::endl;  
    
    std::cout << "Signe : " << std::boolalpha
    << isSigned;  
}
```

### 06-entiers littéraux
Pour chacun des entiers littéraux suivants, indiquez son type et sa valeur.

| #   | Littéral              | Type               | Valeur        |
| --- | --------------------- | ------------------ | ------------- |
| 1   | `12u`                 | unsigned int       | 12            |
| 2   | `1L`                  | long               | 1             |
| 3   | `255ULL`              | unsigned long long | 255           |
| 4   | `1'000'000`           | int                | 1000000       |
| 5   | `3ul`                 | unsigned long      | 3             |
| 6   | `42LL`                | long long          | 42            |
| 7   | `7U`                  | unsigned int       | 7             |
| 8   | `1'000'000'000'000LL` | long long          | 1000000000000 |


### 07-reels-litteraux
Pour chacun des littéraux suivants, indiquez s'il est valide et, si oui, son type et ce qu'affiche `cout << littéral << endl;`.

| #   | Littéral | Valide | Type        | Affichage |
| --- | -------- | ------ | ----------- | --------- |
| 1   | `1.5`    | ok     | double      | 1.5       |
| 2   | `1E3`    | ok     | double      | 1000      |
| 3   | `12.0u`  | nok    |             |           |
| 4   | `1.0L`   | ok     | long double | 1.0       |
| 5   | `.5`     | ok     | double      | 0.5       |
| 6   | `5.`     | ok     | double      | 5         |
| 7   | `2.5f`   | ok     | float       | 2.5       |
| 8   | `3e-2`   | ok     | double      | 0.03      |

### 08-mantisse
**solution**
```c++
void mantis() {  
    double r = 0;  
    double m = 0;  
    int b = 0;  
    int e = 0;  
  
    std::cout << "Entrez un nombre reel : ";  
    std::cin >> r;  
  
    b = 10;  
    e = std::floor(std::log(r)/std::log(b));  
    m = r/std::pow(b,e);  
    std::cout << r << " = " << m << " * " << b << "^" << e << std::endl;  
  
    b = 2;  
    e = std::floor(std::log(r)/std::log(b));  
    m = r/std::pow(b,e);  
    std::cout << r << " = " << m << " * " << b << "^" << e << std::endl;  
    //question complementaire : 1 <= m < b donc 1 <= m < 2 si on a une base 2  
}
```


### 09-float-limit
1. Quel est le plus petit entier positif qui n'est pas représentable exactement en `float` ? Raisonnez avec le nombre de chiffres significatifs, puis écrivez l'expression C++ qui le calcule à partir de `numeric_limits<float>::digits` et de `pow`.
> On a donc $2^{24}$ qui nous donne un float rempli de 1 dans le stockage (24 fois 1), si on fait +1 on ne peut plus le représenter donc : **solution=**$2^{24}+1$ est le plus petit entier qui n'est pas représenté correctement en float.
> Je sais que `numeric_limits<float>::digits` devrait renvoyer 24 donc :
```c++
std::pow(2,std::numeric_limits<float>::digits)
```
2. Vérifiez avec le programme ci-dessous, puis expliquez pourquoi le test 2 affiche `true` alors que le test 3 affiche `false`.
```c++
int n = 16777217;
cout << boolalpha << setprecision(10);
cout << "1) " << static_cast<float>(n) << endl;
cout << "2) " << (static_cast<float>(n) == n) << endl;
cout << "3) " << (static_cast<int>(static_cast<float>(n)) == n) << endl;
```
**La comparaison est effectué en float** Dans le cas 2 l'entier est transformé en float explicitement mais du coup aussi implicitement, pour effectuer la comparaison, ce qui fait `16777216=16777216`.
**La comparaison est effectué en int** Dans le cas 3 l'entier est converti explicitement en float ce qui change sa valeur de `16777217` en `16777216` puis il est retransformé en int mais cela ne change pas sa valeur qui est désormais `16777216` et cela est comparé à `16777217`
3. Même question pour le type `double` (`numeric_limits\double>\:\:digits` vaut 53) : quel est le plus petit entier positif non représentable, et dans quel type entier faut-il le stocker pour faire la vérification ?
```c++
std::pow(2,std::numeric_limits<double>::digits)+1
--
2^{53}+1=9'007'199'254'740'993
```


### 10-operateur-logique
On suppose disposer de deux entiers x et y. Ecrire la condition permettant de tester :
1. que nos deux entiers valent 0
```c++
return x==0&&y==0;
```
2. qu'au moins l'un de nos deux entiers vaut 0
```c++
return x==0||y==0;
```
3. qu'un seul de nos deux entiers vaut 0
```c++
return (x==0&&y!=0)||(x!=0&&y==0);
return (x == 0) != (y == 0); //also
```
4. qu'au moins un de nos deux entiers ne vaut pas 0
```c++
return x!=0||y!=0;
return !(x == 0 && y == 0); //also (De Morgan)
```


### 11-division-integer-real
Soient les déclarations suivantes :
```c++
int i = 5, j = 11;
double x = 5, y = 11;

double m = 0;
```
Que vaut la variable m dans chacun des cas ci-dessous ?

| #   | Expréssion           | m   |
| --- | -------------------- | --- |
| 1   | `m = j / i;`         | 2.0 |
| 2   | `m = y / x;`         | 2.2 |
| 3   | `m = j / i + 1.0;`   | 3.0 |
| 4   | `m = y / x + 1;`     | 3.2 |
| 5   | `m = y / x + j / i;` | 4.2 |
| 6   | `m = i + y / x;`     | 7.2 |
| 7   | `m = x + j / i;`     | 7.0 |


### 12-modulo
Soient les déclarations suivantes :
```c
int i = 5, j = 11, n = 10;
double x = 5, y = 11;
```
Quel est le résultat d'évaluation des expressions suivantes ?  
En cas d'erreur, indiquez la raison.  
**NB** : les questions sont indépendantes les unes des autres.

| #   | Expression | Résultat |
| --- | ---------- | -------- |
| 1   | `j % i`    | 1        |
| 2   | `n % i`    | 0        |
| 3   | `y % x`    | **Err**  |
| 4   | `y % i`    | **Err**  |
| 5   | `-j % i`   | -1       |


### 13-operation-char
Que va afficher le programme C++ suivant ?
```c++
char x = 'A'; // 65
char y = '0'; // 48
char z; //random

z = x + 4; //z=69='E'
cout << "1. " << z << endl;
z += 1; //z=70='F'
cout << "2. " << z << endl;

z = x + 0; //z=65='A'
cout << "3. " << z << endl;

z = x + '0'; //z='A'+'0'=65+48=113='q' (used an ASCII table)
cout << "4. " << z << endl;
---
1. E
2. F
3. A
4. q
```


### 14-operator-priority
Ajouter toutes les parenthèses aux expressions suivantes pour exprimer explicitement l'ordre d'évaluation de l'expression qui existe implicitement en vertu de l'ordre de priorité des opérateurs.
Par exemple, l'expression
```c++
a + b * c; 
```

doit être ré-écrite
```c++
(a + (b * c)); 
```

puisque la multiplication est prioritaire sur l'addition. De même, l'expression
```c++
a / b * c; 
```
doit être ré-écrite
```c++
((a / b) * c); 
```

Les opérateurs `/` et `*` de même priorité étant évalués de gauche à droite. Vous pouvez vous aider de la page [C++ Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence) de cppreference.com

---

```c++
1 * 2 + 3 / 4 * 2
```
Devient
```c++
((1 * 2) + ((3 / 4) * 2))
```

```c++
a + b < c * d + e or f - g + h == i
```
Devient
```c++
(((a + b) < ((c * d) + e)) or (((f - g) + h) == i)
```

```c++
a == b < c
```
Devient
```c++
(a == (b < c))
```

```c++
a < b or c == d and e > b
```
Devient
```c++
((a < b) or ((c == d) and (e > b)))
```

```c++
a * b % c + d % e / f - g
```
Devient
```c++
((((a * b) % c) + ((d % e) / f)) - g)
```

```c++
a - b or c == d > e < f and g
```
Devient
```c++
((a - b) or ((c == ((d > e) < f)) and g))
```


### 15-inversion-implicite
Soient les déclarations suivantes :
```c
char c = 'A';
int n = 7;
float x = 1.25f;
double z = 5.5;
```
Pour chacune des expressions suivantes, indiquez :
- combien de conversions implicites sont mises en œuvre et lesquelles
- ce qu'elle vaut et quel est son type (c'est-à-dire le type à déclarer pour une variable `r1` … `r3` qui la stockerait sans conversion)

```c
2 * x + c                          // r1
static_cast<char>(n) + c           // r2
static_cast<float>(z) + n / 2      // r3
--
float r1 = 67.5; //3 conversions implicite (2 en 2f) ('A' en 65 puis 65 en 65f)
int r2 = 72; //2 conversions implicite ('A' en 65 et (char)n en 7 pour faire l'addition)
float r3 = 8.5f; //1 conversion implicite (3 en 3.f)
```

### 16-evaluate-expression
Soient les déclarations suivantes :
```c++
int i = 5, j = 11; 

double x1 = static_cast<double>(j) / i;
double x2 = static_cast<double>(j / i);
double x3 = j / i + .5;
double x4 = static_cast<double>(j) / i + .5;
double x5 = static_cast<int>(j + .5) / i;
```
Que valent les variables x1 à x5 ?
```c++
double x1 = 2.2;
double x2 = 2.0;
double x3 = 2.5;
double x4 = 2.7;
double x5 = 2.0;
```


### 17-evaluate-expression
**TODO - bon exo révision**
Que va afficher le programme ci-dessous ? Expliquer les résultats obtenus.
```c++
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
   cout << fixed << setprecision(0);
   cout << "1) " << 3 * 1000 * 1000 * 1000 << endl; //int 3'000'000'000
   cout << "2) " << 3.0 * 1000 * 1000 * 1000 << endl; //double 3'000'000'000
   cout << "3) " << 100000 * 100000 * 100000.0 << endl;
   cout << "4) " << 100000.0 * 100000 * 100000 << endl;
   cout << "5) " << 1E7 + 1.0 << endl;
   cout << "6) " << 1E7f + 1.f << endl;
   cout << "7) " << 1E8 + 1.0 << endl;
   cout << "8) " << 1E8f + 1.f << endl;
}
--
1) //3'000'000'000 en int donc "-qqch" si un int est de 32bits
2) 3000000000 //en double
3) //10'000*10'000 en int peut déborder, ce qui est ensuite multiplier par un double, donc "(-)qqch" de grand en double ou du moins un resultat aleatoire 
4) 1'000'000'000'000'000
5) 10'000'001
6) 10'000'001
7) 100'000'001
8) 100'000'000 //24bits de precision
```

