#### 01-test-equivalent
Les deux extraits de code suivants sont-ils équivalents ? Justifiez votre réponse.

```c++
if (prixActuel > 100) {
   nouveauPrix = prixActuel - 20;
} else {
   nouveauPrix = prixActuel - 10;
}
```

```c++
if (prixActuel < 100) {
   nouveauPrix = prixActuel - 10;
} else {
   nouveauPrix = prixActuel - 20;
}
```

**Réponse** : Non, si `prixActuel=100`, sinon similaire dans les autres résultats


#### 02-ternary-operator
Réécrivez les extraits de code suivants en une seule ligne en utilisant un ou des opérateurs ternaires
```c++
if (a > 0) {
   b += a;
} else {
   b -= 2*a; 
}
--
b += a>0 ? a : -2*a
```

```c++
if (d == 0.) {
   r = 1e100;
} else {
   r = n/d; 
}
--
r = d==0. ? 1e100 : n/d;
```

```c++
if (a > 0) {
   b += 1;
} else if (a == 0) {
   b = 0;
} else {
   b *= 2;
}
--
b = a>0 ? b+1 : (a==0 ? 0 : b*2)
```

#### 03-ternary-operator2
Réécrivez les extraits de code suivants en n'utilisant pas d'opérateur ternaire mais uniquement `if ... else`

```c++
a = a >= 1 ? 42 : a * a;
--
if (a>=1) {
	a=42;
} else {
	a*=a;
}
```

```c++
b = a == 2 ? 32 : ( a < 5 ? 12 : 23 );
--
if (a==2) {
	b = 32;
} else if (a<5) {
	b=12;
} else {
	b=23;
}
```

```c++
c = a < 0 ? ( b < 0 ? a : -a ) : ( b < 5 ? a + b : a - b );
--
if (a<0) {
	if (b<0) {
		c=a;
	} else {
		c=-a;
	}
} else {
	if (b<5) {
		c=a+b;
	} else {
		c=a-b;
	}
}
```


#### 04-switch
Soit le programme suivant

```c++
#include <iostream>
using namespace std;

int main() {
   int n; cin >> n;
   
   switch (n) {
      case 0:  cout << "A";
      case 1:
      case 2:  cout << "B";
               break;
      case 3:
      case 4:
      case 5:  cout << "C";
      default: cout << "D";
   }
}
```

Que va-t-il afficher lorsque l'utilisateur entre comme valeur

```c++
0
--
AB
```

```c++
1
--
B
```

```c++
2
--
B
```

```c++
4
--
CD
```

```c++
6
--
D
```

```c++
-1
--
D
```


#### 05-switch2
Réécrivez les extraits de code suivants en remplaçant le `switch` par des instructions `if else`. Notez que la variable `a` est de type `int`.

```c++
switch (a) {
    case 0 : cout << "A"; break;
    case 1 : cout << "Z"; break;
    case 2 : cout << "a"; break; 
    default : cout << "b"; break;
}
--
if (a==0) {
	cout << "A";
} else if (a==1) {
	cout << "Z";
} else if (a==2) {
	cout << "a";
} else {
	cout << "b";
}
```

```c++
switch (a) {
   case 0 : cout << "0"; 
   default : cout << "D"; break;
}
--
if (a==0) {
	cout << "0";
}
cout << "D";
```

```c++
switch (a) {
   case 0 : 
   case 1 : 
   case 2 : 
   case 3 : 
   case 4 : 
   case 5 : cout << "A"; break;
   case 6 : cout << "3"; 
   case 7 : cout << "4"; break; 
   default : cout << "D"; 
}
--
if (a>=0&&a<=5) {
	cout << "A";
} else if (a==6) {
	cout << "3";
} else if (a==6||a==7) {
	cout << "4";
} else {
	cout << "D";
}
```


#### 06-switch2
```c++
if (a == 1) {
   cout << "A";
} else if (a == 4) {
   cout << "C"; 
} else if (a == 2) {
   cout << "E";
} else {
   cout << "BA";
}
--
switch (a) {
	case 1: cout << "A"; break;
	case 2: cout << "E"; break;
	case 4: cout << "C"; break;
	default: cout << "BA";
}
```

```c++
if (a < 0 or a >= 5) {
   cout << "D";
} else if (a < 3) {
   cout << "A";
} else {
   cout << "B";
}
--
switch(a) {
	case 0:
	case 1:
	case 2: cout << "A"; break;
	case 3: 
	case 4: cout << "B"; break;
	default: cout << "D";
}
```


#### 07-no-if-no-switch
```c++
if (i < 1) {
   b = true;
} else {
   b = i > 2;
}
--
b = (i<1) || (i>2);
```

```c++
if (j == 0) {
   b = true;
} else {
   if (i / j < k) {
      b = false;
   } else {
      b = true;
   }
}
--
b = (j==0) || !(i/j<k)
```

```c++
if (j == 0) {
   b = false;
} else {
   if (i / j < k) {
      b = true;
   } else {
      b = false;
   }
}
--
b = !(j==0) && (i/j<k)
```


#### 08-shipping-costs
Une société suisse tarife ses frais de livraison comme suit :
- 5.00 CHF si livraison en Suisse, à l'exception des cantons des Grisons et du Tessin où les frais de livraison se monte à 7.00 CHF
- 7.00 CHF si livraison au Liechtenstein.
- 10.00 CHF partout ailleurs dans le monde

Complétez le programme qui suit pour qu'il détermine et affiche le tarif de livraison. Il ne peut poser que des questions auxquelles l'utilisateur répond que par "O" (oui) ou "N" (non)

```c++
#include <iostream>

using namespace std;

int main() {
   cout << "Livraison en Suisse ? (O/N) ";
   char reponse1; cin >> reponse1;
   
   if (response1=='O') {
	   cout << "Livraison aux Grisons ou au Tessin ? (O/N)";
	   char response2; cin >> response2;
	   if (response2 == 'O') {
		   cout << "Tarif de livraison : 7.00CHF";
	   } else {
		   cout << "Tarif de livraison : 5.00CHF";
	   }
	   return;
   }
   
   cout << "Livraison au Liechtenstein ? (O/N)";
   char response3; cin >> response3;
   
   if (response3=='O') {
	   cout << "Tarif de livraison : 7.00CHF";
   } else {
	   cout << "Tarif de livraison : 10.00CHF";
   }
}
```


#### 09-day-in-month
Compléter le programme C++ ci-dessous pour qu'il affiche combien le mois choisi (1 pour janvier, 2 pour février, etc) compte de jours. Si l'utilisateur entre la valeur 2, le programme doit répondre : "Ce mois comporte 28 ou 29 jours"

```c++
std::cout << "Entrez un no de mois (1-12) : ";  
short no_mois; std::cin >> no_mois;  
std::unordered_map<short,short> map = {  
    {1,31},  
    {3, 31},  
    {4, 30},  
    {5, 31},  
    {6, 30},  
    {7, 31},  
    {8, 31},  
    {9, 30},  
    {10, 31},  
    {11, 30},  
    {12, 31},  
};  
  
std::cout << "Ce mois comporte ";  
  
if (no_mois == 2) {  
    std::cout << "28 ou 29";  
} else {  
    std::cout << map.at(no_mois);  
}
 
std::cout << " jours." << std::endl;
```


#### 10-ECTS
L'université de Genève utilise le barème suivant pour convertir ses notes au quart de point entre 0 et 6 en notes ECTS entre F et A.

|Note UNIGE|Note ECTS|
|---|---|
|5.25 - 6.00|A|
|4.75 - 5.00|B|
|4.50|C|
|4.25|D|
|4.00|E|
|0.00 - 3.75|F|

Ecrire un programme qui demande la note à convertir à l'utilisateur, la stocke dans une variable de type `double`, et indique la note ECTS équivalente

- si l'utilisateur entre une note en dehors de la plage 0-6, il faut signaler une erreur.
- si l'utilisateur entre une note qui n'est pas arrondie au quart de point, on la considère comme la note arrondie au quart de point inférieur. Par exemple, si l'utilisateur entre la note 4.60, on indique une note ECTS de C.

Evitez absolument de dupliquer les tests.
**Code** :
```c++
std::cout << "Entrez la note UNIGE : ";  
double input; std::cin >> input;  
if (input > 6 || input < 1) {  
    std::cout << "Erreur";  
}  
  
char note = 'G';  
if (input >= 5.25) {  
    note = 'A';  
} else if (input >= 4.75) {  
    note = 'B';  
} else if (input >= 4.5) {  
    note = 'C';  
} else if (input >= 4.25) {  
    note = 'D';  
} else if (input >= 4) {  
    note = 'E';  
} else {  
    note = 'F';  
}  
  
std::cout << "La note ECTS est : " << note;
```


#### 11-equations
Complétez le programme suivant qui demande à l'utilisateur les paramètres a, b et c d'une équation du second degré pour qu'il en affiche toutes les solutions réelles s'il y en a.

Prenez soin d'envisager tous les cas possibles pour les paramètres a, b, et c.
```c++
std::cout << "Donnez les valeurs de a, b, et c de l'equation a*x^2+b*x+c : ";  
double a, b, c;  
std::cin >> a >> b >> c;  
  
double delta = b*b-4*a*c;  
if (delta < 0) {  
    std::cout << "Aucune solution";  
    return;  
}  
if (delta > 0) {  
    double s1 = (-b+std::sqrt(delta))/(2*a);  
    double s2 = (-b-std::sqrt(delta))/(2*a);  
    std::cout << "2 solutions : " << s1 << " et " << s2 << std::endl;  
} else {  
    if (std::isnan(-b/(2*a))) {  
        std::cout << "x = R";  
    }  
    std::cout << "1 solution : " << -b/(2*a) << std::endl;  
}
```


#### 12-while
Que va afficher à l'exécution chacun des groupes d'instructions ci-dessous ?
```c++
// 1
int i = 0;
while (i - 10) {
   i += 2; cout << i << " ";
}
--
2 4 6 8 10
```

```c++
// 2
int i = 0;
while (i - 10)
   i += 2; cout << i << " ";
--
10
```

```c++
// 3
int i = 0;
while (i < 11) {
   i += 2; cout << i << " ";
}
--
2 4 6 8 10 12
```

```c++
// 4
int i = 11;
while (i--) {
   cout << i-- << " ";
}
--
10 8 6 4 2 0 -2 -4 -6 ...
```

```c++
//5
int i = 12;
while (i--) {
   cout << --i << " ";
}
--
10 8 6 4 2 0
```

```c++
// 6	
int i = 0;
while (i++ < 10) {
   cout << i-- << " ";
}
--
1 1 1 1 1 1 ...
```

```c++
// 7	
int i = 1;
while (i <= 5) {
   cout << 2 * i++ << " ";
}
--
2 4 6 8 10
```

```c++
// 8
int i = 1;
while (i != 9) {
   cout << (i = i + 2) << " ";
}
--
3 5 7 9
```



#### 13-while2
Que va afficher à l'exécution chacun des groupes d'instructions ci-dessous ?

```c++
// 1
int i = 0;
while (i <= 5) 
   i++;
cout << i;
--
6
```

```c++
// 2
int i = 0, j = 0;
while (i <= 5) 
   i += j++;
cout << i << ' ' << j;
--
6 4
```

```c++
// 3
int i = 0, j = 0;
while (i <= 5) 
   i += ++j;
cout << i << ' ' << j;
--
6 3
```

```c++
// 4
int i = 0, j = 0;
while (j <= 5) 
   i += j++;
cout << i << ' ' << j;
--
15 6
```

```c++
//5
int i = 0, j = 0;
while (j <= 5)
   i += ++j;
cout << i << ' ' << j;
--
21 6
```

```c++
// 6
int i = 0, j = 0;
while (i <= 5) i += 2; j++;
cout << i << ' ' << j;
--
6 1
```


#### 14-bank
Ecrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir
- un montant initial
- un montant cible
- un taux d'intérêt annuel (en %)
détermine et affiche combien d'années (entières) sont nécessaires pour atteindre ou dépasser le montant cible. Notons que
- Les saisies utilisateur sont supposées correctes
- Le taux d'intérêt annuel est supposé rester constant au cours du temps
**Code** :
```c++
double initial;  
double final;  
double interest;  
std::cout << "Entrez le montant initial > "; std:: cin >> initial;  
std::cout << "Entrez le montant cible > "; std:: cin >> final;  
std::cout << "Entrez le taux d'interet annuel en % > "; std:: cin >> interest;  
  
int year = 0;  
if (interest < 0) {  
    std::cout << "Impossible";  
}  
while (initial < final) {  
    year++;  
    initial = initial*(1+interest/100);  
}  
std::cout << "Le montant cible est atteint apres " << year << " ans.";
```



#### 15-for
Que va afficher à l'exécution chacun des groupes d'instructions ci-dessous ?

```c++
// 1
for (int i = 1; i < 10; ++i) {
   cout << i << " ";
}
--
1 2 3 4 5 6 7 8 9
```

```c
// 2
for (int i = 1; i < 10; i += 2) {
   cout << i << " ";
}
--
1 3 5 7 9
```

```c
// 3
for (int i = 10; i > 1; --i) {
   cout << i << " ";
}
--
10 9 8 7 6 5 4 3 2 
```

```c
// 4
for (int i = 0; i < 10; ++i) {
   cout << i << " ";
}
--
0 1 2 3 4 5 6 7 8 9
```

```c
// 5
for (int i = 1; i < 10; i = i * 2) {
   cout << i << " ";
}
--
1 2 4 8
```

```c
// 6
for (int i = 1; i < 10; ++i) {
   if (i % 2 == 0) {
      cout << i << " ";
   }
}
--
2 4 6 8
```


#### 16-for2
Pour chacun des cas ci-dessous, indiquer combien de fois la boucle est exécutée :

```c++
// 1
for (int i = 1; i < 10; ++i) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
9
```

```c++
// 2
for (int i = 1; i <= 10; ++i) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
10
```

```c++
// 3
for (int i = 0; i < 10; ++i) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
10
```

```c++
// 4
for (int i = 10; i > 0; --i) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
10
```

```c++
// 5
for (int i = -10; i <= 10; ++i) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
21
```

```c++
// 6
for (int i = -10; i <= 10; i += 2) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
11
```

```c++
// 7
for (int i = -10; i <= 10; i += 3) {
   // le corps de la boucle ne modifie pas i et ne saute pas
}
--
7
```


#### 17-bank2
Ecrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir
- un montant initial
- un taux d'intérêt annuel (en %)
- un nombre d'années

détermine et affiche le montant disponible sur le compte après ce nombre d'années
- Les saisies utilisateur sont supposées correctes
- Le taux d'intérêt annuel est supposé rester constant au cours du temps
**code** :
```c++
double initial;  
double interest;  
int year;  
std::cout << "Entrez le montant initial > "; std:: cin >> initial;  
std::cout << "Entrez le nombre d'annees > "; std:: cin >> year;  
std::cout << "Entrez les interets > "; std:: cin >> interest;  
  
double final = initial;  
for (int i = 0; i < year; i++) {  
    final = final*(1+interest/100);  
}  
  
std::cout << "Le montant cible est de " << final << " ans.";
```


#### 18-do-while
Que va afficher à l'exécution chacun des groupes d'instructions ci-dessous ?

```c++
// 1
int i = 1;
do {
   cout << i << " ";
   ++i;
} while (i < 10);
--
1 2 3 4 5 6 7 8 9
```

```c++
// 2
int i = 0;
do {
   cout << i << " ";
   ++i;
} while (i < 0);
--
0 
```

```c++
// 3
int i = 1;
do {
   cout << ++i << " ";
} while (i < 10);
--
2 3 4 5 6 7 8 9 10
```

```c++
// 4
int i = 20;
do {
   cout << i << " ";
   i /= 2;
} while (i > 0);
--
20 10 5 2 1
```

```c++
// 5
int i = 20;
do {
   cout << i << " ";
   i /= 2;
} while (i < 0);
--
20 
```

```c++
// 6
int i = 20;
do
   cout << i << " ";
   i /= 2;
while (i < 0);
--
err
```


