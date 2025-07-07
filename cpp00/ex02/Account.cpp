#include "Account.hpp"

#include <ctime>
#include <iostream>

# define TIME_BUFFER 80

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = checkAmount();

	++_nbDeposits;
	++_totalNbDeposits;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << checkAmount() << ";"
	<< "nb_deposits:" << _nbDeposits
	<< std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:refused"
		<< std::endl;
		return (false);
	}
	else
	{
		int	p_amount = checkAmount();

		++_totalNbWithdrawals;
		++_nbWithdrawals;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << checkAmount() << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "amount:" << checkAmount() << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_totalAmount += checkAmount();

	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "created"
	<< std::endl;
}

Account::Account(void)
{
	_amount = 0;
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "created"
	<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "closed"
	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	raw_time;
	tm		*timeinfo;
	char	buffer[TIME_BUFFER];

	raw_time = std::time(0);
	timeinfo = std::gmtime(&raw_time);
	std::strftime(buffer, TIME_BUFFER, "[%G%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}
