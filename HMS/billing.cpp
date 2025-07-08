#include <string>
#include "patient_manager.h"
#include "billing.h"
#include <iostream>
using namespace std;

// constructor
Bills::Bills() {}
Bills::Bills(string pn, double id, float bill)
{
    this->patient_name = pn;
    this->patient_id = id;
    this->bill = bill;
}
GenerateBill::GenerateBill() {}

// getters
string Bills::getPatient()
{
    return patient_name;
}
double Bills::getID()
{
    return patient_id;
}

// function to calculate the bill
void GenerateBill::CalculateBill(Patient &p, double id)
{
    Node *patient = p.findPatient(id);
    if (!patient)
    {
        cout << "Patient with that id doesnot exist.\n";
        return;
    }
    string Bed = p.Bed(patient);
    if (Bed == "Yes" || Bed == "yes")
    {
        int days;
        cout << "Enter the number of days the patient was on bed:";
        cin >> days;
        cout << "\033[1;33mGenrating Bill.....\033[0m\n";
        b[count++] = Bills(patient->getPatient(), id, BILLperDAY * days);
    }
    else
    {
        cout << "\033[1;33mThe patients checkup was free, since the patient did not acquire any bed.\033[0m\n";
        return;
    }
    cout << "\033[1;32mBill calculated for patient with id '" << id << "'\033[0m\n";
}
// function to display bill for a patient
void GenerateBill::generateBill(Patient &p, double id)
{
    Node *patient = p.findPatient(id);
    if (!patient)
    {
        cout << "No patient with such id found.\n";
        return;
    }

    bool Found = false;
    for (int i = 0; i < count; i++)
    {
        if (b[i].getID() == id)
        {
            string Bed = p.Bed(patient);
            if (Bed == "Yes")
            {
                Found = true;
                cout << "=======\033[1;36m Bill Details\033[0m=======\n";
                cout << "Patient Name : " << b[i].getPatient() << endl;
                cout << "Patient ID   : " << b[i].getID() << endl;
                cout << "Total Bill   : " << b[i].bill << "$" << endl;
                return;
            }
            else
            {
                cout << "\033[1;33mThe patient did not acquire a bed so the checkup was free.\033[0m\n";
                return;
            }
        }
    }
    if (!Found)
    {
        cout << "Bill not calculated for patient, calculate first.\n";
        return;
    }
}
void GenerateBill::DeleteBill(Patient &p, double id)
{
    Node *patient = p.findPatient(id);
    if (!patient)
    {
        cout << "Patient not found.\n";
        return;
    }
    bool FoundBill = false;
    for (int i = 0; i < count; i++)
    {
        if (b[i].getID() == id)
        {
            FoundBill = true;
            for (int j = i; j < count - 1; j++)
            {
                b[j] = b[j + 1];
            }
            count--;
            cout << "\033[1;32mBill deleted.\033[0m\n";
            return;
        }
    }
    if (!FoundBill)
    {
        cout << "Bill not found for the patient\n";
        return;
    }
}

float GenerateBill::getBill(double id)
{
    for (int i = 0; i < count; i++)
    {
        if (b[i].getID() == id)
        {
            return b[i].bill;
        }
    }
    return 0.0;
}
