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

