### Pseudocode
1. Définir les constantes que l'application utilise (s1, s2, dy, dx)
2. Récupérer la première longueur depuis l'entrée utilisateur (en bonus)
3. Calculer le temps passé sur la route : L1/s1 ($\frac{L_1}{s_1}$)
4. Calculer la longueur direct restante jusqu'à l'objet avec la théorie du triangle rectangle : $L_2=\sqrt{(dy-L_1)^2+(dx)^2}$
5. Calculer le temps passé sur le terrain rocheux : L2/s2 ($t_2=\frac{L_2}{s_2}$)
6. Calculer le temps total et l'afficher : t1+t2 ($t_{tot}=t_1+t_2$)