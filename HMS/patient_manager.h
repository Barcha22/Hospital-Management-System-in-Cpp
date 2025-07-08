#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;
// Linked List implementation
class Node
{
private:
    string name;
    double id;
    int age;
    bool admit;
    Node *next;
    Node *previous;

public:
    Node(string name, double id, int age, bool admit);
    double getID();
    string getPatient();
    int getAge();
    friend class Patient;
    friend class aptManager;
    friend class Details;
};
class Patient
{
private:
    Node *head;

public:
    Patient();
    // get header for records
    Node *getHead()
    {
        return head;
    };
    // function to insert patient details
    void insert(string name, double id, int age, bool admit);

    // function to find patient using id number
    Node *findPatient(double id);

    // function to display a patient's details
    Node *displayPatient(double id);

    // function to edit a patient details
    void editRecords(double iD);

    // function to delete a patient details
    void deletion(double ID);

    // function to display all patients
    void displayAllPatients();

    // function to check of there is no patient
    bool empty();

    // function to check if patient requires a bed
    string Bed(Node *node);
    // destructor
    ~Patient();
};

#endif