#include <iostream>

/**
 * <iostream> : Cette bibliothèque C++ est utilisée pour les entrées et sorties standard,
 * comme la lecture de l'entrée du clavier avec std::cin ou l'affichage de texte à l'écran avec std::cout.
*/

/**
 * std::cout : C'est l'objet de sortie standard. Il est utilisé pour envoyer des données vers la sortie standard (généralement l'écran).
 * std::endl : C'est un manipulateur de flux qui insère un caractère de nouvelle ligne ('\n') et vide le tampon de sortie.
 * Ceci assure que tout ce qui a été envoyé à la sortie standard est effectivement affiché.
*/

/**
 * L'opérateur << : C'est l'opérateur d'insertion de flux. Il est utilisé pour envoyer des données vers des objets de flux, comme std::cout.
 * Par exemple, std::cout << "Hello, World!"; envoie la chaîne de caractères "Hello, World!" à la sortie standard.
 * Différence entre std:: et cout/endl : std:: est l'espace de noms standard en C++. cout et endl sont définis dans cet espace de noms.
 * L'utilisation de std:: avant cout et endl indique que ces objets proviennent de l'espace de noms standard.
*/

/**
 * L'opérateur ::, connu sous le nom d'opérateur de résolution de portée, est utilisé pour accéder à des membres spécifiques 
 * (variables, fonctions, classes imbriquées) dans un contexte donné, tel qu'une classe, un espace de noms ou une énumération.
 * Par exemple pour std::cout, nous pouvons resumer ca en "Va chercher dans std l'objet cout"
*/

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			if (i < argc - 1)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}
