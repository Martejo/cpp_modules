#pragma once //Remplace ifndef define endif

template <typename T>
const T& max(const T& v1, const T& v2)
{
	return (v1 > v2 ? v1 : v2);
}

template <typename T>
const T& min(const T& v1, const T& v2)
{
	return (v1 < v2 ? v1 : v2);
}

template <typename T>
void swap(T& v1, T& v2)
{
	T tmp = v1;
	v1 = v2;
	v2 = tmp;
}




/*
Pourquoi utiliser des templates ?
Généricité : Vous n'avez pas besoin d'écrire des versions spécifiques 
pour différents types de données (int, float, etc.). 
Le même code fonctionne pour n'importe quel type.
Réutilisabilité : Le code est plus réutilisable et adaptable 
à différents types de données.
Efficacité : Les templates sont résolus à la compilation, 
ce qui signifie qu'ils n'ajoutent pas de surcharge à l'exécution.
*/
