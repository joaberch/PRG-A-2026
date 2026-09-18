# Labo 1
## 01-pseudo code
**Question :**
```Question
Le programme demandé doit

1. permettre la saisie d'un terme de Wallis (numérateur/dénominateur)
2. calculer l'approximation Pi/2 du 1er terme (2/1) jusqu'au terme saisi par l'utilisateur
3. afficher le résultat de l'approximation

Si le terme saisi n'était pas correct, le programme indiquerait le problème avant de terminer. Aucun calcul n'est effectué.

Sur cette base, proposer un pseudo-code par raffinement successif.
```

**Résultat :**
```pseudo code
input = entrée utilisateur
numerateur = 2
denominateur = 1
approx = 1

Pour le nombre d'input
	multiplier l'approximation par numérateur/dénominateur
	(approx *= numerateur/denominateur)
	
	si numerateur<denominateur
		ajouter 2 au denominateur
		(denominateur=numerateur+1)
	sinon
		ajouter 2 au numerateur
		(numerateur=denominateur+1)
Affiche "approximation de pi/2 : *approx* pour *input* itération"
```