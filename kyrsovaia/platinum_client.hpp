#ifndef PLATINUM_CLIENT_HPP
#define PLATINUM_CLIENT_HPP
#include <string>
#include "client.hpp"

class PlatinumClient : public Client {
public:
    PlatinumClient(string id, string name);
    double calculateCommission(double amount) const override;
    double getMaxTransactionLimit() const override;
    string getClientType() const override;
    string getBenefits() const;
    ~PlatinumClient() override {}
};
#endif