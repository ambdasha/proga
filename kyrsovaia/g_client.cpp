#include "gold_client.hpp"
#include <string>

GoldClient::GoldClient(string id, string name) : Client(id, name) {}

double GoldClient::calculateCommission(double amount) const {
    return amount * 0.01;
}

double GoldClient::getMaxTransactionLimit() const {
    return 10000.0;
}

string GoldClient::getClientType() const {
    return "Gold";
}

string GoldClient::getBenefits() const {
    return "Priority processing, low commissions";
}