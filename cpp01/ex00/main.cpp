/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:30:59 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/27 15:01:22 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Lo stack è una regione di memoria utilizzata per archiviare variabili locali e informazioni sulla chiamata di funzione.
// L'allocazione e la deallocazione della memoria nello stack sono gestite automaticamente dal compilatore.
// Le variabili nello stack hanno una durata e uno scope limitati, di solito legati alla durata di una chiamata di funzione.
// Lo stack è più veloce per allocare e deallocare memoria rispetto all'heap.

// L'heap è una regione di memoria utilizzata per l'allocazione dinamica della memoria, dove è possibile allocare e deallocare manualmente la memoria durante l'esecuzione del programma.
// L'allocazione e la deallocazione della memoria sull'heap sono controllate dal programmatore.
// Le variabili sull'heap hanno una durata potenzialmente più lunga e possono essere accessibili da diverse parti del programma.
// Gestire la memoria sull'heap richiede attenzione per evitare perdite di memoria (non liberare la memoria allocata) e puntatori "dangling" (puntatori che puntano a posizioni di memoria non valide).

int main()
{
    Zombie *zombie1 = newZombie("ruggi");
    	zombie1->announce();

    Zombie *zombie2 = newZombie("eugi");
    	zombie2->announce();

    randomChump("flavio");
    
    delete zombie2;    
    delete zombie1;
}