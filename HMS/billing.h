#ifndef BILLING_H
#define BILLING_H

#include <string>
#include "patient_manager.h"

const float BILLperDAY = 80; // in dollars
const int BILLSCOUNT = 100;

class Bills
{
    double patient_id;
    string patient_name;
    float bill;

public:
    Bills();
    Bills(string pn, double id, float bill);
    string getPatient();
    double getID();
    friend class GenerateBill;
};

class GenerateBill
{
private:
    Bills b[BILLSCOUNT];
    int count = 0;

public:
    GenerateBill();
    void CalculateBill(Patient &p, double id);
    void generateBill(Patient &p, double id);
    void DeleteBill(Patient &p, double id);
    float getBill(double id);
};
#endif