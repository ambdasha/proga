#ifndef STANDARD_CLIENT_HPP
#define STANDARD_CLIENT_HPP
#include <iostream>
#include <string>
#include "client.hpp"

class StandardClient : public Client {
public:
    StandardClient(string id, string name);
    double calculateCommission(double amount) const override;
    double getMaxTransactionLimit() const override;
    string getClientType() const override;
    string getBenefits() const;
    ~StandardClient() override {}
};
#endif