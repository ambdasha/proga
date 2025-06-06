#ifndef GOLD_CLIENT_HPP
#define GOLD_CLIENT_HPP
#include <string>
#include "client.hpp"

class GoldClient : public Client {
public:
    GoldClient(string id, string name);
    double calculateCommission(double amount) const override;
    double getMaxTransactionLimit() const override;
    string getClientType() const override;
    string getBenefits() const;
    ~GoldClient() override {}
};
#endif