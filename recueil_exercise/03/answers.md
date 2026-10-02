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