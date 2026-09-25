#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

static void displayTicket(const std::string &name, const int accountNbr, const double amount, const double change, const double cost, const double balance) {
    std::cout << "+-------------------------------+" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "| " << name << std::endl;
    std::cout << "| " << accountNbr << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "| Somme Euro             : " << amount << std::endl;
    std::cout << "| 1 CHF en Euro          : " << change << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "| Somme CHF              : " << std::round(amount/change * 100.0) / 100.0 << std::endl; //round to hundredth
    std::cout << "| Frais                  : " << cost << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "| Solde Compte           : " << std::round((balance-amount/change-cost) * 100.0) / 100.0 << std::endl; //round to hundredth
    std::cout << "|" << std::endl;
    std::cout << "+-------------------------------+" << std::endl;
}

int main() {
    int accountNbr;
    std::string familyName;
    double balance = 1000;
    double amount = 0;
    constexpr double change = 1.024;
    constexpr double cost = 5;

    std::cout << "Quel est votre numero de compte ?" << std::endl;
    std::cin >> accountNbr;
    std::cout << "Quel est votre nom de famille ?" << std::endl;
    std::cin >> familyName;
    std::cout << "Solde de votre compte CHF :\t" << balance << std::endl;
    std::cout << "Taux de change : 1 CHF = " << change << " Euro" << std::endl;
    std::cout << "Frais pour une operation : " << cost << " CHF" << std::endl;
    std::cout << "Entrez la somme souhaitee en Euro :" << std::endl;
    std::cin >> amount;
    std::cout << "Somme CHF : " << std::round(amount/change * 100.0) / 100.0 << ", Solde compte : " << std::round((balance-amount/change-cost) * 100.0) / 100.0 << std::endl; //round to hundredth

    displayTicket(familyName, accountNbr, amount, change, cost, balance);
    balance -= amount/change-cost; //not stored in memory but still done
}
