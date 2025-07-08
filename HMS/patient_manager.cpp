#include "Patient_manager.h"
#include <string>
#include <iostream>
using namespace std;
// Linked List implementation

Node::Node(string name, double id, int age, bool admit)
{
    this->name = name;
    this->id = id;
    this->age = age;
    this->admit = admit;
    next = previous = NULL;
}
// getters
double Node::getID()
{
    return id;
}
string Node::getPatient()
{
    return name;
}
int Node::getAge()
{
    return age;
}
// constructi]or
Patient::Patient()
{
    head = NULL;
}

bool Patient::empty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
// function to insert patient details
void Patient::insert(string name, double id, int age, bool admit)
{
    if (head == NULL)
    {
        Node *newnode = new Node(name, id, age, admit);
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(name, id, age, admit);
    temp->next = newnode;
    newnode->previous = temp;
}
// function to find patient using id number
Node *Patient::findPatient(double id)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    // cout << " \033[1;33mSearching id " << "\033[1;35m" << id << "\033[0m\n";
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// function to display a patient's details
Node *Patient::displayPatient(double id)
{
    Node *temp = findPatient(id);
    if (temp == NULL)
    {
        return NULL;
    }
    else
    {
        cout << "Patient found.\n";
        cout << "Name: " << temp->name << "\nID: " << temp->id << "\nAge: " << temp->age << "\nRequires Bed: " << Bed(temp) << "\n";
        return temp;
    }
}
// function to edit a patient details
void Patient::editRecords(double iD)
{
    string newName;
    double newid;
    int newage;
    Node *temp = head;
    int choice;
    if (head == NULL)
    {
        cout << "No patient found.\n";
        return;
    }
    temp = findPatient(iD);
    if (temp == NULL)
    {
        cout << "No patient found.\n";
        return;
    }
    else
    {
        // cout << "Patient found.\n";
        // displayPatient(iD);
        do
        {
            cout << "What do you want to change?\n";
            cout << "1. Name\n";
            cout << "2. ID\n";
            cout << "3. Age\n";
            cout << "4. Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "Enter new name\n";
                cin.ignore();
                getline(cin, newName);
                temp->name = newName;
                cout << "\033[1;32mName updated successfully.\033[0m\n";
                break;
            }
            case 2:
            {
                cout << "Enter new id\n";
                cin >> newid;
                temp->id = newid;
                cout << "\033[1;32mID updated successfully.\033[0m\n";
                break;
            }
            case 3:
            {
                cout << "Enter new age\n";
                cin >> newage;
                temp->age = newage;
                cout << "\033[1;32mAge updated successfully.\033[0m\n";
                break;
            }
            case 4:
            {
                cout << "Exiting\n";
                break;
            }
            default:
            {
                cout << "\033[1;31mWrong option please try again.\033[0m\n";
            }
            }

        } while (choice != 4);
    }
}

// function to delete a patient details
void Patient::deletion(double ID)
{
    Node *temp = findPatient(ID);
    if (temp)
    {
        displayPatient(ID);
        if (temp->previous != NULL)
            temp->previous->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->previous = temp->previous;

        delete temp;
        cout << "\033[1;32mDeletion process successful.\033[0m\n";
    }
    else
    {
        cout << "Patient with id '" << ID << "' not found.\n";
    }
}

// function for getting bed info
string Patient::Bed(Node *node)
{
    if (node == NULL)
        return NULL;
    return node->admit ? "Yes" : "No";
}
// function to display all patients
void Patient::displayAllPatients()
{
    if (head == NULL)
    {
        cout << "The patient list is empty.\n";
        return;
    }
    Node *temp = head;
    int count = 1;
    cout << "==========\033[1;36mPatient List\033[0m========\n";
    while (temp != NULL)
    {
        cout << "\n"
             << count << ". " << "Name: " << temp->name << "\nID: " << temp->id << "\nAge: " << temp->age << "\nRequires Bed:" << Bed(temp) << "\n";
        temp = temp->next;
        count++;
    }
}
Patient::~Patient()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
}