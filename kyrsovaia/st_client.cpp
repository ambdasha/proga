#include "standard_client.hpp"
#include <string>

StandardClient::StandardClient(string id, string name) : Client(id, name) {}

double StandardClient::calculateCommission(double amount) const {
    return amount * 0.05;
}

double StandardClient::getMaxTransactionLimit() const {
    return 1000.0;
}

string StandardClient::getClientType() const {
    return "Standard";
}

string StandardClient::getBenefits() const {
    return "Standard access";
}