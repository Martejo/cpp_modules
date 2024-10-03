#include "BitcoinExchange.hpp"

// Fonction pour vérifier le nombre d'arguments
void checkNbArgs(int ac) {
    if(ac != 2)
        throw(std::runtime_error("Error: ./btc needs 1 argument. Usage: ./btc <input_file>"));
}

// Fonction pour ouvrir un fichier
std::ifstream& extractFile(std::ifstream& filestream, const char *filename)
{
    filestream.open(filename);
    if (!filestream)
        throw(std::runtime_error(std::string("Error: ") + filename + " can't be opened"));
    return filestream;
}

bool    isValidDate(std::tm &tm)
{
    
    // std::cout << "tm avant :"<< tm.tm_year <<" "<< tm.tm_mon <<" "<< tm.tm_mday<< std::endl;
    //dates negatives ou nulles
    if(tm.tm_year < 1 || tm.tm_mon < 1 || tm.tm_mon > 12 || tm.tm_mday < 1)
        return (false);

    //annees normales et bissextiles
    if((tm.tm_mon == 1 && tm.tm_mday > 31)
        || (tm.tm_mon == 2 && tm.tm_mday > 29)
        || (tm.tm_mon == 3 && tm.tm_mday > 31)
        || (tm.tm_mon == 4 && tm.tm_mday > 30)
        || (tm.tm_mon == 5 && tm.tm_mday > 31)
        || (tm.tm_mon == 6 && tm.tm_mday > 30)
        || (tm.tm_mon == 7 && tm.tm_mday > 31)
        || (tm.tm_mon == 8 && tm.tm_mday > 31)
        || (tm.tm_mon == 9 && tm.tm_mday > 30)
        || (tm.tm_mon == 10 && tm.tm_mday > 31)
        || (tm.tm_mon == 11 && tm.tm_mday > 30)
        || (tm.tm_mon == 12 && tm.tm_mday > 31))
        {
            return (false);
        }

    //annees non bissextiles
    if(tm.tm_year % 4 != 0 && tm.tm_mon == 2 && tm.tm_mday == 29)
        return (false);
    return (true);
}

// Fonction pour parser une date au format "YYYY-MM-DD" en std::tm
std::tm parseDate(const std::string& date)
{
    std::tm tm;
    ::memset(&tm, 0, sizeof(std::tm));

    //utiliser scanf (scan format) mais sur une str
    if (sscanf(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) != 3) {
        throw std::runtime_error(std::string("Error: bad input => ") + date);
    }

    if (!isValidDate(tm)){
        throw std::runtime_error(std::string("Error: bad input => ") + date);
    }
    // std::cout << "tm :"<< tm.tm_year <<" "<< tm.tm_mon <<" "<< tm.tm_mday<< std::endl;
    return tm;
}

// Fonction pour lire et mapper les taux de change depuis le fichier CSV
std::map<std::tm, float, tmCompare> mapExchangeRate(std::ifstream &dataFile)
{
    std::map<std::tm, float, tmCompare> exchangeRates;
    std::string line;
    while (std::getline(dataFile, line))
    {
        std::istringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate)
        {
            try{
                std::tm tm = parseDate(date);
                exchangeRates[tm] = rate;
            }
            catch(const std::runtime_error &e)
            {
                std::cerr << "Error: impossible to parse data.csv" << std::endl;
                throw e;
            }
        }
    }
    return exchangeRates;
}


bool isValidValue(const std::string& valueStr, float& value) {
    std::istringstream ss(valueStr);

    ss >> value;
	double valueTest = 	static_cast<double>(value);

    // Vérifier si la conversion a échoué ou si la valeur est négative
    if (ss.fail() || valueTest < 0 || valueStr[0] == '-') {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    // Vérifier si la valeur dépasse INT_MAX
    if (valueTest > static_cast<double>(INT_MAX)) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

void checkHeaderInFile(std::string firstLine)
{
    std::istringstream ss(firstLine);
    std::string dateStr, valueStr;
    if (std::getline(ss >> std::ws, dateStr, '|') && std::getline(ss >> std::ws, valueStr)) 
	{
        // std::cout << "'" << dateStr << "'" << !std::strncmp(dateStr.c_str(),"date", 4) << valueStr << "'" << std::endl; //test
        if(std::strncmp(dateStr.c_str(),"date", 4) || std::strncmp(valueStr.c_str(),"value", 5))
            throw std::runtime_error("Error: bad headers in input file \nUsage: first line of input file must be exactly <date | value>");
    }
    else
    {
        throw std::runtime_error("Error: bad format in input file");
    }
}

void displayRates(std::string &line, std::ifstream &inputFile, const std::map<std::tm, float, tmCompare>& exchangeRates)
{
    //tant que le fichier contient des lignes, getline met a jour le buffer line
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, valueStr;

        if (std::getline(ss, dateStr, '|') && std::getline(ss >> std::ws, valueStr)) 
		{
            try {
                std::tm tm = parseDate(dateStr);
                float value;
                if (isValidValue(valueStr, value)) {
                    //rechercher dans la map, l' elem stocke dont la date est > ou == a la date de l' index
                    std::map<std::tm, float, tmCompare>::const_iterator it = exchangeRates.lower_bound(tm);
                    //si l' elem trouve est > a la date recherchee, on va sur la valeur inferieure stockee (ou on declenche une erreur si aucune date ne corresp aux criteres)
                    if (it == exchangeRates.end() || it->first.tm_year != tm.tm_year || 
                        it->first.tm_mon != tm.tm_mon || it->first.tm_mday != tm.tm_mday) {
                        if (it != exchangeRates.begin()) {
                            --it;
                        } else {
                            throw std::runtime_error("Error: date out of range.");
                        }
                    }
                    float result = value * it->second;
                    std::cout << dateStr << " => " << value << " = " << result << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } 
        //Quand la ligne est mal formatee
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

// Fonction pour afficher les résultats
void displayExchangeRate(const std::map<std::tm, float, tmCompare>& exchangeRates, std::ifstream &inputFile) {
    std::string line;

    try{
        std::getline(inputFile, line);
        //Si la 1re ligne est mal formatee, un err est throw
        checkHeaderInFile(line);
        displayRates(line, inputFile, exchangeRates);
    }
    catch (const std::exception& e) {std::cerr << e.what() << std::endl;}
}