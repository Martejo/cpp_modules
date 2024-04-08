#include <fstream>  // Pour std::ifstream
#include <iostream> // Pour std::cerr
#include <sstream>  // Pour std::stringstream
#include <string>   // Pour std::string


std::string const ft_sed(std::string const &buffer, std::string const &from, std::string const &to)
{
	std::string newStr;
	std::size_t      pos = 0;
	std::size_t      last = 0;

	//pour eviter que la taille de std::string newStr soit sans cesse reallouee
	//on lui indique une taille initiale proche de la taille finale
	newStr.reserve(buffer.length());

	//avancer dans buffer jusqu'a ce qu' on ne trouve plus aucune occurence de from
	while((pos = buffer.find(from, last)) != std::string::npos)
	{
		//on ajoute la sub situee avant l'occurence de from detectee par find()
		newStr.append(buffer, last, (pos - last));
		//on ajoute la nouvelle sub
		newStr.append(to);
		//on avance dans le buffer pour ignorer les chars de from
		last = pos + from.length();
	}
	//on ajoute la sub finale (copie de last jusqu'a la fin de buffer)
	newStr.append(buffer.substr(last));
	return (newStr);
}

int main(int ac, char *av[]) 
{
	if (ac != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		std::cerr << "usage : <file> <old_word> <new_word>" << std::endl;
		return (1);
	}

	// Ouvrir le fichier en mode lecture
	std::ifstream infile(av[1]);

	// Vérifier si le fichier a été ouvert correctement
	if (!infile.is_open()) {
		std::cout << "Error: " << av[1] << ":" 
		<< " infile can't be opened" << std::endl;
		return 1;
	}

	// Utiliser un stringstream pour lire le contenu du fichier
	std::stringstream buffer;
	buffer << infile.rdbuf(); // Transférer tout le contenu du fichier dans le buffer
	infile.close();

	// Creer le nom du nouveau fichier
	std::string newFileName = std::string(av[1]) + ".replace";

	// acceder a la const char * contenue dans le type std::string car std::ofstream ne contient pas de constructeur(std::string&)
	std::ofstream outfile(newFileName.c_str());
	if (!outfile.is_open()) {
		std::cout << "Error: " << newFileName << ":" 
		<< " outfile can't be opened or created" << std::endl;
		return 1;
	}
	outfile << ft_sed(buffer.str(), av[2], av[3]);
	outfile.close();
	// Le programme se termine avec succès
	return 0;
}