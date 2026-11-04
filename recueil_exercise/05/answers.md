#### 01-array-declaration
Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

```c
// no 1
array<int,3> a;
for(int e : a) cout << e << ' ';
--
Comportement indéfini
```

```c
// no 2
array<int,3> a{1,2};
for(int e : a) cout << e << ' ';
--
1 2 0
```

```c
// no 3
array<int,3> a{1,2,3,4};
for(int e : a) cout << e << ' ';
--
Erreur à la compilation
```

```c
// no 4
array<int,3> a{};
for(int e : a) cout << e << ' ';
--
0 0 0
```

```c
// no 5
array<string,3> a;
for(const string & e : a) cout << e.size() << ' ';
--
0 0 0
```


