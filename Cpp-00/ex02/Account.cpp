#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return _nbAccounts;
};

int Account::getTotalAmount()
{
	return _totalAmount;
};

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount =_totalAmount + initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex << ";amount:"<<_amount << ";created" << std::endl;
}
void Account::_displayTimestamp()
{
	time_t _time;
    _time = time(NULL);
    tm *_tm = localtime(&_time);
    char buffer[50];
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", _tm);
    std::cout << buffer;
	
}


void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex << ";amount:"<<_amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit)
{
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex << ";p_amount:"<<_amount - deposit 
	<< ";deposit:"<<deposit << ";amount:"<<_amount 
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	
}
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if(withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        _amount = _amount - withdrawal;
        _totalAmount = _totalAmount - withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;

        std::cout << "index:" << _accountIndex << ";p_amount:" 
                 << _amount + withdrawal << ";withdrawal:" << withdrawal 
                 << ";amount:" << _amount << ";nb_withdrawals:" 
                 << _nbWithdrawals << std::endl;
        return true;
    }
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex << ";amount:"<<_amount << ";closed" << std::endl;
}



