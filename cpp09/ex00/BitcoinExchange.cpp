#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	(void)obj;
	return *this;
}

// Metodo privato di supporto per verificare se un file esiste e non è vuoto
void BitcoinExchange::checkFileValidity(const std::string &nomeFile)
{
    std::ifstream file(nomeFile.c_str());
    if (!file)
        throw std::runtime_error("Error: " + nomeFile + " is missing.");
    if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: " + nomeFile + " is empty.");
    file.close();
}

void BitcoinExchange::loadDBExchangeRates()
{
	std::ifstream file("data.csv");
	std::string riga;
	std::string data;
	std::string tassoCambio;
	double tasso;
	std::getline(file, riga);

	while (std::getline(file, riga)) {
		std::stringstream ss(riga);
		std::getline(ss, data, ',');
		std::getline(ss, tassoCambio);
		// Converte tassoCambio in double
		std::istringstream iss(tassoCambio);
        if (!(iss >> tasso) || !iss.eof()) {
            std::cerr << "Warning: tasso di cambio non valido in data.csv alla riga: \"" << riga << "\"" << std::endl;
            continue; // Salta questa voce non valida
        }
		// Salva il tasso nella mappa
		_datacsv.insert(std::pair<std::string, double>(data, tasso));
	}
	file.close();
}

// Parsea una data in formato YYYY-MM-DD in un array di int
// Estrae anno, mese, giorno dalla stringa data e li memorizza in un array di int
int *getdate(std::string data)
{
	int *dateArr = new int[3];
	std::string anno = data.substr(0, 4);
	std::string mese = data.substr(5, 2);
	std::string giorno = data.substr(8, 2);
	dateArr[0] = std::atoi(anno.c_str());
	dateArr[1] = std::atoi(mese.c_str());
	dateArr[2] = std::atoi(giorno.c_str());
	return dateArr;
}

// Valida il formato e l'intervallo della data
// Controlla se la data è nel formato YYYY-MM-DD e se è valida e nell'intervallo 2009-2022
// Se non valida, stampa un messaggio di errore e ritorna 1 e cancella l'array data
// Se valida, ritorna 0
int checkDate(std::string data)
{
	if (data.length() != 10)
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 1;
	}
	if (data[4] != '-' || data[7] != '-')
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 1;
	}

	int *dateArr = getdate(data);
	if (dateArr[0] < 2009 || dateArr[0] > 2022)
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 	delete[] dateArr, 1;
	}
	if (dateArr[1] < 1 || dateArr[1] > 12)
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 	delete[] dateArr, 1;
	}
	if (dateArr[2] < 1 || dateArr[2] > 31)
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 	delete[] dateArr, 1;
	}
	if (dateArr[1] == 2 && dateArr[2] > 29)
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 	delete[] dateArr, 1;
	}
	if ((dateArr[1] == 4 || dateArr[1] == 6 || dateArr[1] == 9 || dateArr[1] == 11) && dateArr[2] > 30)
	{
		std::cout << "Error: bad input => " << data << std::endl;
		return 	delete[] dateArr, 1;
	}

	delete[] dateArr;
	return 0;
}

// Trova una corrispondenza esatta della data o la data precedente più vicina nel database (floor date)
// Calcola e mostra rate * tasso_di_cambio
// Stampa il risultato data => valore
void BitcoinExchange::calculateAndPrintBitcoinValues(std::string const &data, double const valore)
{
	std::multimap<std::string, double>::iterator it;
	for (it = _datacsv.begin(); it != _datacsv.end(); ++it)
	{
		if (it->first == data)
		{
			std::cout << data << " => " << std::fixed << std::setprecision(2) << valore * it->second << std::endl;
			return;
		}
	}
	std::string dataPiuVicina;
	double tassoPiuVicino;

	for (it = _datacsv.begin(); it != _datacsv.end(); ++it)
	{
		if (it->first < data)
		{
			dataPiuVicina = it->first;
			tassoPiuVicino = it->second;
		}
		else
			break;
	}
	std::cout << data << " => " << std::fixed << std::setprecision(2) << valore * tassoPiuVicino << std::endl;
}

void BitcoinExchange::parseInput(std::string const &nomeFile)
{
	std::ifstream file(nomeFile.c_str());
	std::string riga;
	std::string data;
	std::string valoreStr;
	double valore;

	std::getline(file, riga);
	// Controllo formato header
	if (riga != "date | value")
		throw std::runtime_error("Error: bad header line format.");

	while (std::getline(file, riga))
	{
		if (riga.empty()) // salta righe vuote
			continue;
		if (riga.find('|') == std::string::npos) // controlla se | è presente nella riga
			std::cout << "Error: bad input => " << riga << std::endl;
		else
		{
			std::stringstream ss(riga);
			std::getline(ss, data, '|');
			std::getline(ss, valoreStr);
			// controlla il formato della data e se è valida. Se non valida, stampa errore
			data.erase(0, data.find_first_not_of(" \n\r\t")); // rimuove spazi iniziali
			data.erase(data.find_last_not_of(" \n\r\t") + 1); // rimuove spazi finali
			if (checkDate(data) == 1)
				continue;

			// Converte valore in double
			std::istringstream iss(valoreStr);

            if (!(iss >> valore) || !iss.eof())
            {
                std::cout << "Error: invalid value format: \"" << riga << "\"" << std::endl;
                continue;
            }

			// controlla valore:  0 <= valore <= 1000
			if (valore < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (valore > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			calculateAndPrintBitcoinValues(data, valore);
		}
	}
	file.close();
}

void BitcoinExchange::start(std::string const &nomeFile)
{
	try
	{
        checkFileValidity("data.csv");
        checkFileValidity(nomeFile);
		loadDBExchangeRates();
		parseInput(nomeFile);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
}
