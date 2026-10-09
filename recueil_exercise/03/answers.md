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


