#ifndef SUMMARY_H
#define SUMMARY_H
#include "patient_manager.h"
#include "Apt_manager.h"
#include "billing.h"
#include <string>
using namespace std;

class Node3
{
private:
    string patient_name;
    double patient_id;
    int patient_age;
    bool appointment;
    float bill;
    Node3 *next;

public:
    Node3(string pn, double pi, int pa, bool App, float b);
    string getNAME();
    double getID();
    int getAGE();
    bool getAPP();
    float getBILL();
    friend class Details;
};
class Details
{
private:
    Node3 *top;

public:
    Details();
    void push(Patient &p, aptManager &apt, GenerateBill &b);
    void Display();
    void clear();
};

#endif