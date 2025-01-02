

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string.h>
#include <cstdlib> //library for convertion
#include <cctype> //to help me do checks for chars
#include <sstream> //to do the convertion in a styled way
#include <iomanip> //in this way i can print the numbers with the point more precisely

/*
Function for convertion
isprint(char) after conversion from ascii we can check if this char is part of
the ascii table and if it is printable

L'overflow deve rendere solamente la conversione impossibile
per il tipo di valore che non può sostenere il valore
non deve fermare il programma ne deve impedire agli altri valori
la loro conversione
*/

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		/*we keep the ortodoxical canonical form standard
		We won't use it because we don't use objects*/
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);

		static int		conInt;
		static float	conFloat;
		static double	conDouble;
		static char		conChar;

		/*methods*/
		static void convert(std::string value);

};

/*Static variables intialisation*/

/*
Note riguardo al casting per affrontare l'esercizio:
Parliamo di conversione esplicita quando dobbiamo eseguire una conversione
da un tipo all'altro dicendo noi in che tipo diventa uno specifico valore.
la notazione è la seguente:
static_cast<cast_type>(expression)
è possibile utilizzare il casting esplicito per convertire un char in un intero
o viceversa per riuscire ad interpretare il valore come si deve.
Posso usare anche i metodi di stream, che sono perfettamente nello standard 98 per
fare la conversione numerica base, è possibile utilizzare lo stream per fare la conversione e poi
usare lo static per applicarla in maniera coerente. a quanto pare

Piccola nota per la difesa:
	La tecnica utilizzata inizialmente per convertire il char in un valore numerico
	non è casting ma bensì una reinterpretazione dei bytes
*/
#endif
