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


