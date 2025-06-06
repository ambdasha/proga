#include "platinum_client.hpp"
#include <string>

PlatinumClient::PlatinumClient(string id, string name) : Client(id, name) {}

double PlatinumClient::calculateCommission(double amount) const {
    return amount * 0.02;
}

double PlatinumClient::getMaxTransactionLimit() const {
    return 5000.0;
}

string PlatinumClient::getClientType() const {
    return "Platinum";
}

string PlatinumClient::getBenefits() const {
    return "Bonus rewards, moderate commission";
}