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


#### 02-access-element
Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

```c
// no 1
array<int, 5> a{1, 2, 3, 4, 5};
cout << a.front() << ' ' << a.back();
--
1 5
```

```c
// no 2
array<int, 5> a{1, 2, 3, 4, 5};
cout << a[1] << ' ' << a[3];
--
2 4
```

```c
// no 3
array<int, 5> a{1, 2, 3, 4, 5};
cout << a[5];
--
Comportement indéfini
```

```c
// no 4
array<int, 5> a{1, 2, 3, 4, 5};
cout << a.at(1) << ' ' << a.at(3);
--
2 4
```

```c
// no 5
array<int, 5> a{1, 2, 3, 4, 5};
cout << a.at(5);
--
Erreur à l exécution
```


#### 03-parcours
**TODO - bon pour révision**
Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à l'exécution, aie un comportement indéfini ou cause une boucle infinie. Indiquez-le_

```c
// no 1
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 1; i <= 3; ++i)
   cout << a.at(i) << ' ';
--
2 3 4
```

```c
// no 2
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = a.size()-1; i >= 0; --i)
   cout << a.at(i) << ' ';
--
5 4 3 2 1 Erreur à l'exécution
```

```c
// no 3
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 0; i < a.size(); ++i)
   cout << a.at(i) << ' ';
--
1 2 3 4 5 
```

```c
// no 4
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 3; i < a.size(); --i)
   cout << a.at(i) << ' ';
--
4 3 2 1
```

```c
// no 5
array<int, 5> a{1, 2, 3, 4, 5};
for(size_t i = 3; i > 0; --i)
   cout << a.at(i) << ' ';
--
4 3 2
```

```c
// no 6
array<int, 5> a{1, 2, 3, 4, 5};
for(int i : a)
   cout << i << ' ';
--
1 2 3 4 5   
```

```c
// no 7
array<int, 5> a{1, 2, 3, 4, 5};
for(int i : a)
   i *= i;
for(int i : a)
   cout << i << ' '; 
--
1 2 3 4 5
```

```c
// no 8
array<int, 5> a{1, 2, 3, 4, 5};
for(int& i : a)
   i *= i;
for(int i : a)
   cout << i << ' ';
--
1 4 9 16 25
```


#### 04-compare-arrays
**TODO - bon exo révision**
Indiquer ce que va afficher chacune des séquences d'instructions suivantes :

_Il se peut qu'une séquence provoque une erreur à la compilation ou à l'exécution, voire ait un comportement indéfini. Le cas échéant, répondez "Erreur à la compilation", "Erreur à l'exécution" ou "Comportement indéfini"_

```c
// no 1
array<int, 3> a{1, 2, 3};
array<int, 3> b{1, 3, 2};
cout << boolalpha << (a < b);
--
true
```

```c
// no 2
array<int, 3> a{1, 2, 3};
array<int, 4> b{1, 2, 3, 4};
cout << boolalpha << (a < b); 
--
Erreur à la compilation
```

```c
// no 2
array<int, 3> a{1, 2, 3};
array<short, 3> b{2, 3, 1};
cout << boolalpha << (a < b);
--
Erreur à la compilation
```

```c
// no 3
array<int, 4> a{1, 2, 3};
array<int, 4> b{1, 2, 3, -1};
array<int, 4> c{1, 2, 3, 1};
cout << boolalpha << (a < b) << endl 
     << (a < c) << endl
     << (b < c);
--
false
true
true
```


