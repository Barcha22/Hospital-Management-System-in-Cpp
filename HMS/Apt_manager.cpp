#include <iostream>
#include "patient_manager.h"
#include "Apt_manager.h"

using namespace std;
// Queue implementation
//  doctors name
const string doctors[MAX_DOCTORS] = {"Dr.Ali", "Dr.Hamid", "Dr.Haniya"};

// constructors of aptmanager
aptManager::aptManager()
{
    front = rear = NULL;
}
// constructors for node
Node2::Node2()
{
    next = NULL;
}
Node2::Node2(string doctor_name, string date, string time, double patient_id, string patient_name)
{
    this->doctor_name = doctor_name;
    this->date = date;
    this->time = time;
    this->patient_id = patient_id;
    this->patient_name = patient_name;
    next = NULL;
}

// getters
string Node2::getDoctor()
{
    return this->doctor_name;
}
string Node2::getDate()
{
    return date;
}
string Node2::getTime()
{
    return time;
}
double Node2::getID()
{
    return patient_id;
}
string Node2::getPatient()
{
    return patient_name;
}

// functoin to display doctor names
void aptManager::Doctors()
{
    for (int i = 0; i < MAX_DOCTORS; i++)
    {
        cout << i + 1 << ". " << doctors[i] << "\n";
    }
}

// function to set an appointment
void aptManager::enqueueApt(Patient &p, double id)
{
    Node *patient = p.findPatient(id);
    if (!patient)
    {
        cout << "Patient not found\n";
        return;
    }
    string doctorName, time, date;
    cout << "Enter your name (doctor): ";
    cin.ignore();
    getline(cin, doctorName);
    bool Found = false; // checking for doctor
    for (string doc : doctors)
    {
        if (doc == doctorName)
        {
            Found = true;
        }
    }
    if (!Found)
    {
        cout << "\033[1;31mError! Doctor named " << doctorName << " does not exist.\033[0m\n";
        return;
    }
    cout << "Enter the date to set appointment : ";
    getline(cin, date);
    cout << "Enter the time : ";
    getline(cin, time);

    Node2 *newnode = new Node2(doctorName, date, time, patient->getID(), patient->getPatient());
    if (front == NULL)
    {
        front = rear = newnode;
        cout << "\033[1;32mAppointment set.\033[0m\n";
        return;
    }
    rear->next = newnode;
    rear = newnode;
    cout << "\033[1;32mAppointment set.\033[0m\n";
}
// function to display appointments
void aptManager::peekApts()
{
    if (front == NULL)
    {
        cout << "No appointments currently set.\n";
        return;
    }
    int count = 1;
    Node2 *temp = front;
    while (temp != NULL)
    {
        cout << count << ". " << "Doctor Name : " << temp->getDoctor() << "\n   Patient ID : " << temp->getID() << "\n   Patient Name : " << temp->getPatient() << "\n   Date : " << temp->getDate() << "\n   Time : " << temp->getTime() << "\n";
        temp = temp->next;
        count++;
    }
}
// function to check if a patient has appointment
bool aptManager::patient_apt(double id, Patient &p)
{
    Node *Patient = p.findPatient(id);
    if (!Patient)
    {
        cout << "No patient with such id\n";
        return false;
    }
    Node2 *temp = front;
    while (temp != NULL)
    {
        if (temp->getID() == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// function to cancel an upcoming appointment
void aptManager::dequeueApt()
{
    if (front == NULL)
    {
        cout << "No appointments found for cancelletion.\n";
        return;
    }
    Node2 *temp = front;
    front = front->next;
    cout << "\033[1;32mCancelled the upcoming appointment.\033[0m\n";
    cout << "Doctor Name : " << temp->getDoctor() << "\nPatient ID : " << temp->getID() << "\nPatient Name : " << temp->getPatient() << "\nDate : " << temp->getDate() << "\nTime : " << temp->getDate() << "\n";
    delete temp;
}
