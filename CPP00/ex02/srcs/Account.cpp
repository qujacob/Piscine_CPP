#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void ) {
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (this->_amount - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int		Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}

int		Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp( void ) {
	char		buffer[19];
	const std::time_t t = std::time(NULL);
	struct tm *timeinfo = localtime(&t);

	strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
    // std::cout << "[19920104_091532] ";
}

int		Account::_nbAccounts = 0;

int		Account::_totalAmount = 0;

int		Account::_totalNbDeposits = 0;

int		Account::_totalNbWithdrawals = 0;
