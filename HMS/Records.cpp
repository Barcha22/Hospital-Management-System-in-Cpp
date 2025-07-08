#include "patient_manager.h"
#include "Apt_manager.h"
#include "billing.h"
#include "Records.h"
#include <iostream>

// stack implementation
using namespace std;

// constructors
Node3::Node3(string pn, double pi, int pa, bool App, float b)
{
    this->patient_name = pn;
    this->patient_id = pi;
    this->patient_age = pa;
    this->appointment = App;
    this->bill = b;
    next = NULL;
}
Details::Details()
{
    top = NULL;
}

// getters
string Node3::getNAME()
{
    return patient_name;
}
double Node3::getID()
{
    return patient_id;
}
int Node3::getAGE()
{
    return patient_age;
}
bool Node3::getAPP()
{
    return appointment;
}
float Node3::getBILL()
{
    return bill;
}

// push patient data into stack
void Details::push(Patient &p, aptManager &apt, GenerateBill &b)
{
    clear();
    if (p.empty())
    {
        cout << "No patients found to add to records.\n";
        return;
    }
    Node *current = p.getHead();
    while (current != NULL)
    {
        cout << "appointment : " << current->getID();
        cout << apt.patient_apt(current->getID(), p);

        Node3 *newnode = new Node3(current->getPatient(), current->getID(), current->getAge(), apt.patient_apt(current->getID(), p), b.getBill(current->getID()));
        newnode->next = top;
        top = newnode;

        current = current->next;
    }
    cout << "\033[1;32mRecords successfully updated.\033[0m\n";
}

// Display Data
void Details::Display()
{
    if (top == NULL)
    {
        cout << "No Records found\n\n";
        return;
    }
    int count = 1;
    Node3 *temp = top;
    while (temp)
    {
        cout << count << ". " << "Patient Name   : " << temp->getNAME() << "\n";
        cout << "  Patient Age    : " << temp->getAGE() << "\n";
        cout << "  Patient ID     : " << temp->getID() << "\n";
        if (temp->getAPP())
        {
            cout << "  Appointments   : Pending" << "\n";
        }
        else
        {
            cout << " Appointments   : No Appointments" << "\n";
        }
        cout << "  Total Bill     : " << temp->getBILL() << "$\n";
        count++;
        temp = temp->next;
    }
}
void Details::clear()
{
    if (top == NULL)
    {
        cout << "No records to delete.\n";
        return;
    }
    Node3 *temp;
    while (top != NULL)
    {
        temp = top;
        top = top->next;
        delete temp;
    }
    cout << "\033[1;32mRecords Deleted Successfully.\033[0m\n";
}