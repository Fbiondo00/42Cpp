/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:51:28 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/09 20:07:35 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

int     Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int     Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int     Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp( void )
{
	time_t t = time(0);
	struct tm *lt = localtime(&t);

	std::cout << "[" << std::setfill('0');
	std::cout << std::setw(4) << lt->tm_year + 1900; // year
	std::cout << std::setw(2) << lt->tm_mon + 1; // month
	std::cout << std::setw(2) << lt->tm_mday << "_"; // day
	std::cout << std::setw(2) << lt->tm_hour; // hour
	std::cout << std::setw(2) << lt->tm_min; // minutes
	std::cout << std::setw(2) << lt->tm_sec << "] "; // seconds
	//std::cout << "[19920104_091532] ";
	return ;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount <<
	";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
}

void displayTimestamp() {
        std::time_t currentTime = std::time(NULL);
        std::string timestamp(30, '\0');

        std::strftime((char *)timestamp.data(), timestamp.size(), "%Y%m%d_%H%M%S", std::localtime(&currentTime));
        std::cout << '[' << timestamp << "] ";
    }

Account::Account(int initial_deposit) {
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    Account::_nbAccounts++;
    std::cout << "constructor has benn called!" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    if (deposit > 0) {
    	int p_amount = _amount;
		_amount += deposit;
		Account::_totalNbDeposits += 1;
		_nbDeposits += 1;
		Account::_totalAmount += deposit;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
				  << ";deposit:" << deposit << ";amount:" << _amount
				  << ";nb_deposits:" << _nbDeposits << std::endl;
	}
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	return ;
}
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount << ";deposits:";
	std::cout << Account::_totalNbDeposits << ";withdrawals:";
	std::cout << Account::_totalNbWithdrawals << std::endl;
	return ;
}

bool Account::makeWithdrawal( int withdrawal ) {
	if (_amount < withdrawal) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:" << "refused"
			<< std::endl;
		return false;
	} else {
		_totalAmount -= withdrawal;
	   _totalNbWithdrawals++;

	   _amount -= withdrawal;
	   _nbWithdrawals++;

	   _displayTimestamp();
	   std::cout << "index:" << _accountIndex
		   << ";p_amount:" << _amount + withdrawal
		   << ";withdrawal:" << withdrawal
		   << ";amount:" << _amount
		   << ";nb_withdrawals:" << _nbWithdrawals
		   << std::endl;
	   return true;
	}
}

// void	Account::makeDeposit( int deposit )
// {
// 	this->_amount += deposit;
// 	this->_nbDeposits += 1;
// 	Account::_displayTimestamp();
// 	std::cout << "index:" << this->_accountIndex << ";p_amount:";
// 	std::cout << this->_amount - deposit << ";deposit:" << deposit;
// 	std::cout << ";amount:" << this->_amount << ";nb_deposits:";
// 	std::cout << this->_nbDeposits << std::endl;
// 	Account::_totalAmount += deposit;
// 	Account::_totalNbDeposits += 1;
// 	return ;
// }