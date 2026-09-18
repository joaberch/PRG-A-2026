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

