#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _straggler(-1), _dequeTime(0.0), _vectorTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
    if (this != &rhs) {
        _deque = rhs._deque;
        _vector = rhs._vector;
        _straggler = rhs._straggler;
        _dequeTime = rhs._dequeTime;
        _vectorTime = rhs._vectorTime;
    }
    return *this;
}

/**
 * Valida se una stringa rappresenta un intero positivo entro il range di INT_MAX.
 *
 * @param stringa La stringa da validare
 * @return true se la stringa è un intero positivo valido, false altrimenti
 */
bool PmergeMe::isPositiveInteger(const std::string &stringa) {
    // Controlla se la stringa è vuota
    if (stringa.empty())
        return false;

    // Verifica che tutti i caratteri siano cifre
    for (size_t indice = 0; indice < stringa.length(); ++indice) {
        if (!isdigit(stringa[indice]))
            return false;
    }

    // Converte in long per controllare overflow
    long valore;
    std::istringstream iss(stringa);
    iss >> valore;

    // Assicura che il valore sia positivo e nel range di INT_MAX
    return (valore > 0 && valore <= INT_MAX);
}

/**
 * Controlla se un valore esiste già nella sequenza per evitare duplicati.
 *
 * @param sequenza La sequenza su cui controllare
 * @param valore Il valore da cercare
 * @throws std::invalid_argument se il valore è un duplicato
 */
void PmergeMe::checkForDuplicates(const std::deque<int> &sequenza, int valore) {
    // Itera nella sequenza cercando valori uguali
    for (std::deque<int>::const_iterator it = sequenza.begin(); it != sequenza.end(); ++it) {
        if (*it == valore)
            throw std::invalid_argument("Error: Duplicate number detected: " + std::to_string(valore));
    }
}

/**
 * Parsea e valida gli argomenti da linea di comando, caricandoli nei contenitori.
 *
 * @param argc Numero di argomenti
 * @param argv Array di stringhe degli argomenti
 * @param deque Deque da riempire con interi validi
 * @param vector Vector da riempire con gli stessi interi
 * @throws std::invalid_argument se gli input non sono validi
 */
void PmergeMe::parseInput(int argc, char **argv, std::deque<int> &deque, std::vector<int> &vector) {
    // Controlla se sono stati forniti argomenti
    if (argc <= 1) {
        throw std::invalid_argument("Error: No input provided.");
    }

    // Elabora ogni argomento
    for (int indice = 1; indice < argc; ++indice) {
        std::string argomento(argv[indice]);

        // Valida che l'argomento sia un intero positivo
        if (!isPositiveInteger(argomento)) {
            throw std::invalid_argument("Error: Invalid input '" + argomento + "'. All elements must be positive integers and not exceed INT_MAX.");
        }

        int valore = std::atoi(argomento.c_str());

        // Verifica che non ci siano duplicati nell'input
        checkForDuplicates(deque, valore);

        // Aggiungi il valore valido a entrambi i contenitori
        deque.push_back(valore);
        vector.push_back(valore);
    }

    // Servono almeno due elementi per mostrare l'ordinamento
    if (deque.size() < 2) {
        throw std::invalid_argument("Error: At least two numbers are required for sorting.");
    }
}

void PmergeMe::loadSequence(const std::deque<int> &inputDeque, const std::vector<int> &inputVector) {
    _deque = inputDeque;
    _vector = inputVector;
    _straggler = -1;  // Reimposta il flag straggler

    // Mostra la sequenza non ordinata
    displaySequence("Before: ", _deque);
}

void PmergeMe::displaySequence(const std::string &prefisso, const std::deque<int> &sequenza) const {
    std::cout << prefisso;
    for (std::deque<int>::const_iterator it = sequenza.begin(); it != sequenza.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/**
 * Ordina la sequenza usando l'implementazione Ford-Johnson su deque.
 *
 * Questo metodo avvia un timer, esegue l'ordinamento e registra il tempo trascorso.
 */
void PmergeMe::sortDeque() {
    // Avvia il timer per misurare le prestazioni
    std::clock_t inizio = std::clock();

    // Passo 1: Gestisce sequenze di lunghezza dispari rimuovendo l'ultimo elemento
    if (_deque.size() % 2 != 0) {
        _straggler = _deque.back();  // Salva l'ultimo elemento
        _deque.pop_back();           // Rimuovilo dalla sequenza
    }

    // Passo 2: Inizializza il contenitore di coppie per l'ordinamento ricorsivo
    std::deque<std::pair<int, int> > coppie;

    // Passo 3: Esegue l'ordinamento Ford-Johnson ricorsivo
    recursiveSortDeque(coppie);

    // Passo 4: Inserisce l'elemento straggler (se presente) nella sequenza ordinata
    if (_straggler != -1) {
        binaryInsert(_deque, _straggler);
    }

    // Passo 5: Ferma il timer e calcola il tempo trascorso in millisecondi
    std::clock_t fine = std::clock();
    _dequeTime = static_cast<double>(fine - inizio) / CLOCKS_PER_SEC * 1000;
}

/**
 * Implementa l'algoritmo ricorsivo Ford-Johnson per il contenitore deque.
 *
 * Segue questi passi:
 * 1. Raggruppa gli elementi in coppie
 * 2. Ordina ogni coppia internamente (minore prima, maggiore dopo)
 * 3. Ordina ricorsivamente gli elementi maggiori di ogni coppia
 * 4. Inserisce gli elementi minori usando la sequenza di inserimento Jacobsthal
 *
 * @param coppie Contenitore per le coppie durante l'ordinamento
 */
void PmergeMe::recursiveSortDeque(std::deque<std::pair<int, int> > &coppie) {
    // Passo 1: Raggruppa gli elementi in coppie
    for (size_t indice = 0; indice < _deque.size(); indice += 2) {
        coppie.push_back(std::make_pair(_deque[indice], _deque[indice + 1]));
    }
    _deque.clear(); // Svuota la sequenza originale, verrà ricostruita

    // Passo 2: Caso base - se resta solo una coppia, ordina e ritorna
    if (coppie.size() == 1) {
        if (coppie[0].first > coppie[0].second) {
            std::swap(coppie[0].first, coppie[0].second);
        }
        _deque.push_back(coppie[0].first);
        _deque.push_back(coppie[0].second);
        return;
    }

    // Passo 3: Ordina ogni coppia internamente (minore prima, maggiore dopo)
    for (std::deque<std::pair<int, int> >::iterator it = coppie.begin(); it != coppie.end(); ++it) {
        if (it->first > it->second) {
            std::swap(it->first, it->second);
        }
    }

    // Passo 4: Prepara la ricorsione - crea nuove coppie dagli elementi maggiori
    std::deque<std::pair<int, int> > nuoveCoppie;

    // Passo 5: Gestisce numero dispari di coppie
    if (coppie.size() % 2 != 0) {
        for (size_t indice = 0; indice < coppie.size() - 1; indice += 2) {
            nuoveCoppie.push_back(std::make_pair(coppie[indice].second, coppie[indice + 1].second));
        }
        nuoveCoppie.push_back(std::make_pair(coppie[coppie.size() - 1].first, coppie[coppie.size() - 1].second));
        coppie.erase(coppie.end() - 1);
    } else {
        for (size_t indice = 0; indice < coppie.size(); indice += 2) {
            nuoveCoppie.push_back(std::make_pair(coppie[indice].second, coppie[indice + 1].second));
        }
    }

    // Passo 6: Ordina ricorsivamente le nuove coppie (contenenti i maggiori)
    recursiveSortDeque(nuoveCoppie);

    // Passo 7: Raccogli gli elementi minori da inserire
    std::deque<int> elementiInAttesa;
    for (std::deque<std::pair<int, int> >::iterator it = coppie.begin(); it != coppie.end(); ++it) {
        elementiInAttesa.push_back(it->first);
    }

    // Passo 8: Genera la sequenza ottimale di inserimento usando Jacobsthal
    std::deque<int> jacobsthal = generateJacobsthalSequence<std::deque<int> >(elementiInAttesa.size());
    std::deque<int> sequenzaInserimento = generateInsertionSequence(jacobsthal, jacobsthal.size());

    // Passo 9: Inserisci gli elementi in attesa secondo l'ordine ottimale
    for (size_t indice = 0; indice < elementiInAttesa.size(); indice++) {
        binaryInsert(_deque, elementiInAttesa[sequenzaInserimento[indice]]);
    }
}

void PmergeMe::sortVector() {
    // Avvia il timer
    std::clock_t inizio = std::clock();

    // Controlla se la sequenza ha un numero dispari di elementi
    int straggler = -1;
    if (_vector.size() % 2 != 0) {
        straggler = _vector.back();
        _vector.pop_back();
    }

    // Crea le coppie per l'ordinamento
    std::vector<std::pair<int, int> > coppie;
    recursiveSortVector(coppie);

    // Inserisce lo straggler se presente
    if (straggler != -1) {
        binaryInsert(_vector, straggler);
    }

    // Ferma il timer e calcola il tempo
    std::clock_t fine = std::clock();
    _vectorTime = static_cast<double>(fine - inizio) / CLOCKS_PER_SEC * 1000; // Millisecondi
}

void PmergeMe::recursiveSortVector(std::vector<std::pair<int, int> > &coppie) {
    // Crea le coppie dalla sequenza
    for (size_t indice = 0; indice < _vector.size(); indice += 2) {
        coppie.push_back(std::make_pair(_vector[indice], _vector[indice + 1]));
    }
    _vector.clear();

    // Caso base: se c'è solo una coppia
    if (coppie.size() == 1) {
        if (coppie[0].first > coppie[0].second) {
            std::swap(coppie[0].first, coppie[0].second);
        }
        _vector.push_back(coppie[0].first);
        _vector.push_back(coppie[0].second);
        return;
    }

    // Ordina gli elementi all'interno di ogni coppia (minore prima, maggiore dopo)
    for (std::vector<std::pair<int, int> >::iterator it = coppie.begin(); it != coppie.end(); ++it) {
        if (it->first > it->second) {
            std::swap(it->first, it->second);
        }
    }

    // Crea nuove coppie per la ricorsione
    std::vector<std::pair<int, int> > nuoveCoppie;

    // Gestisce numero dispari di coppie
    if (coppie.size() % 2 != 0) {
        for (size_t indice = 0; indice < coppie.size() - 1; indice += 2) {
            nuoveCoppie.push_back(std::make_pair(coppie[indice].second, coppie[indice + 1].second));
        }
        nuoveCoppie.push_back(std::make_pair(coppie[coppie.size() - 1].first, coppie[coppie.size() - 1].second));
        coppie.erase(coppie.end() - 1);
    } else {
        for (size_t indice = 0; indice < coppie.size(); indice += 2) {
            nuoveCoppie.push_back(std::make_pair(coppie[indice].second, coppie[indice + 1].second));
        }
    }

    // Chiamata ricorsiva per ordinare gli elementi maggiori
    recursiveSortVector(nuoveCoppie);

    // Prepara gli elementi in attesa (i minori di ogni coppia)
    std::vector<int> elementiInAttesa;
    for (std::vector<std::pair<int, int> >::iterator it = coppie.begin(); it != coppie.end(); ++it) {
        elementiInAttesa.push_back(it->first);
    }

    // Genera la sequenza Jacobsthal per l'ordine ottimale di inserimento
    std::vector<int> jacobsthal = generateJacobsthalSequence<std::vector<int> >(elementiInAttesa.size());
    std::vector<int> sequenzaInserimento = generateInsertionSequence(jacobsthal, jacobsthal.size());

    // Inserisce gli elementi in attesa nell'ordine ottimale
    for (size_t indice = 0; indice < elementiInAttesa.size(); indice++) {
        binaryInsert(_vector, elementiInAttesa[sequenzaInserimento[indice]]);
    }
}

void PmergeMe::displayResults() const {
    // Mostra la sequenza ordinata
    displaySequence("After: ", _deque);

    // Mostra informazioni sui tempi con precisione in millisecondi
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << std::fixed
              << std::setprecision(5) << _dequeTime << " ms" << std::endl;

    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << std::fixed
              << std::setprecision(5) << _vectorTime << " ms" << std::endl;
}
