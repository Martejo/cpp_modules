#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts++;
	this->_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount" << _amount << ";created" << std::endl;
}



void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:";
	std::cout << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:";
	std::cout << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:";
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *const info = std::localtime(&t);

	std::cout << "[" << 1900 + info->tm_year;
	if (info->tm_mon + 1 < 10)
		std::cout << "0" << info->tm_mon + 1;
	else
		std::cout << info->tm_mon + 1;
	if (info->tm_mday < 10)
		std::cout << "0" << info->tm_mday << "_";
	else
		std::cout << info->tm_mday << "_";
	if (info->tm_hour < 10)
		std::cout << "0" << info->tm_hour;
	else
		std::cout << info->tm_hour;
	if (info->tm_min < 10)
		std::cout << "0" << info->tm_min;
	else
		std::cout << info->tm_min;
	if (info->tm_sec < 10)
		std::cout << "0" << info->tm_sec;
	else
		std::cout << info->tm_sec;
	std::cout << "] ";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}