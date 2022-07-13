#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string get_timeStamp() {
	std::string tmp;
	time_t now = time(nullptr);
	tm *tm = localtime(&now);
	tmp = std::to_string(tm->tm_year + 1900); //tm_year is year since 1900 so add 1900 to get real year
	if (tm->tm_mon < 10)
		tmp += "0";
	tmp += std::to_string(tm->tm_mon);
	tmp += std::to_string(tm->tm_mday);
	tmp += "_";
	tmp += std::to_string(tm->tm_hour);
	tmp += std::to_string(tm->tm_min);
	tmp += std::to_string(tm->tm_sec);
	return tmp;
}

void displayTimestamp() {
	std::cout << "[" << get_timeStamp() << "] ";
}

void displayCreation(int index, int amount) {
	displayTimestamp();
	std::cout
		<< "index:" << index
		<< ";amount:" << amount
		<< ";created" << std::endl;
}

Account::Account(int accountIndex,
				 int amount,
				 int nbDeposits,
				 int nbWithdrawals) :
				 _accountIndex(accountIndex),
				 _amount(amount),
				 _nbDeposits(nbDeposits),
				 _nbWithdrawals(nbWithdrawals) {
	Account::_totalAmount += _amount;
	Account::_totalNbDeposits += _nbDeposits;
	Account::_totalNbWithdrawals += _nbWithdrawals;
	Account::_nbAccounts++;
	displayCreation(_accountIndex, _amount);
}

Account::Account(int initial_deposit) :
				 _accountIndex(Account::_nbAccounts),
				 _amount(initial_deposit),
				 _nbDeposits(0),
				 _nbWithdrawals(0) {
	Account::_totalAmount += _amount;
	Account::_nbAccounts++;
	displayCreation(_accountIndex, _amount);
}

Account::Account() :
					_accountIndex(Account::_nbAccounts),
					_amount(0),
					_nbDeposits(0),
					_nbWithdrawals(0) {
	Account::_nbAccounts++;
	displayCreation(_accountIndex, _amount);
}

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout
			<< "accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::getTotalAmount()
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals()
			<< std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount;
	if (_amount - withdrawal < 0) {
		std::cout
				<< ";withdrawal:refused"
				<< std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::_displayTimestamp() {
	displayTimestamp();
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
