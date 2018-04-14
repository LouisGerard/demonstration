# Démonstrateur automatique de logique modale

Par Louis GERARD et Mehri GOLCHIN

Le démonstrateur permet de vérifier si une expression de logique modale est toujours vraie dans un système nommé. Dans le cas où l'expression n'est pas toujours vraie, il pourra aussi servir à trouver un contre exemple. Utilisé sans la négation, il pourra enfin trouver un modèle de l'expression. 

## Compilation

Prérequis : `g++`

Compilation avec la commande `make`

## Utilisation

Une fois le projet compilé, un exécutable `modal` sera créé. Après l'avoir lancé, une invite vous demandera dans quel système de règles vous voulez évaluer votre expression. Vous pourrez ensuite taper votre expression sous forme infixe et finissant par un point-virgule. 

### Syntaxe de l'expression

Les operandes sont tout caractere minuscule entre 'a' et 'z', les operateurs sont : 

* `#` : modalite []
* `%` : modalite <>
* `-` : negation
* `&` : et
* `|` : ou
* `>` : implique 

## Structure du projet

Le projet adopte une structure orientée objet avec deux bibliothèques : 

* `k` qui contient les fonctions utilisées par les règles pour controler l'arbre de résolution et qui les rassemble au sein de systèmes. 
* `infix2postfix`, écrit par Vincent Risch, qui permet de convertir une expression sous forme infixe en forme postfixe afin de faciliter la résolution. 

Les classes du projet sont :

* `Arbre` représente l'arbre de résolution. C'est lui qui contient la boucle principale dans la méthode `run()`. Il pourra être manipulé par les fonctions du système au moyen des méthodes suivantes :
	* `diviserArbre()` qui créer des fils gauche et droite qui représentent les deux possibilités d'un opérateur "ou".
	* `diviserExpression()` qui remplace l'expression courante par deux expressions à traiter pour satisfaire un "et". 
	* `remplacerExpression()` qui remplace l'expression courante par une autre, dans le cas d'une équivalence. 
	* `ajouterExpression()` qui ajoute une expression à la pile. 
	* `creerMonde()` qui créé un nouveau monde dans lequel l'expression donnée est vrai.
	* `contraindreMonde()` qui créé une `MondeContrainte` qui sera vérifiée immédiatement et à chaque fois qu'on voudra lier un nouveau monde. Si une contradiction est détectée, la `MondeContrainte` pourra arrêter la boucle de résolution par la méthode `setNope(true);`
* `Regle` est un fonctor qui contient un opérateur et une fonction à appliquer. Elle peut utiliser :
	* `is_appliquable()` pour vérifier que la `Regle` s'applique à l'expression.
	* l'opérateur `()` pour appliquer la fonction sur l'expression coupée en deux expressions pour les opérateurs binaires. Les fonctions des opérateurs unaires ont la même signature mais n'utiliseront pas l'expression de droite. 
* `Monde` représente un ensemble d'assignations d'opérandes et peut être lié à d'autres mondes. Les méthodes disponibles sont :
	* `contraindre()` pour ajouter une `MondeContrainte` qui sera vérifiée immédiatement et à chaque fois qu'on voudra lier un nouveau monde.
	* `lier()` pour lier un nouveau monde. On vérifiera aussi que toutes les contraintes sont respectées par cette nouvelle association.
	* `assigne()` pour assigner une opérande à une valeur booléenne. 
	* `is_assigne()` pour vérifier qu'une opérande est assignée à une certaine valeur. 
	* `print()` pour afficher les assignations d'un monde et celles des mondes qui lui sont liés.
* `MondeContrainte` représente une contrainte imposée par les opérateurs modaux. Elle a une profondeur qui est le nombre de connexions à parcourir avant de tester la satisfaisabilité de l'expression. C'est une classe relativement simple avec une seule méthodes :
	* `check()` qui vérifiera qu'une contrainte est respectée sur un monde donné à l'aide d'un nouvel arbre de résolution. 

## Etat du projet

La plupart du projet a été testé et marche correctement. Une partie reste néanmoins à corriger, il s'agit du système KT4. Pour l'instant, les fonctions finissants par Transitive sont des alternatives à la gestion des opérateurs modaux de manière transitive. Pour éviter les itérations infinies que causerait la règle $$, un père a été créé pour les mondes afin d'appliquer les contraintes aux mondes précédents. Toute fois, on ne pourra pas tester la propager aux mondes suivants, ce qui implique des erreurs sous ce système. 
