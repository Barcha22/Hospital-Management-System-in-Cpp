#include "patient_manager.h"
#include "Apt_manager.h"
#include "billing.h"
#include "Records.h"
#include <iostream>
using namespace std;

int main()
{
    int choice;
    Patient p;
    aptManager apt;
    GenerateBill b;
    Details d;

    do
    {
        cout << "\t\t========================\n";
        cout << "\t\t==\033[1;34mWELCOME TO MAIN MENU\033[0m==\n";
        cout << "\t\t========================\n";
        cout << "1. Patients Management\n";
        cout << "2. Appointments Managment\n";
        cout << "3. Bills Mangement\n";
        cout << "4. Records\n";
        cout << "5. Exit\n";
        cout << "\033[1;30mPlease Enter your choice : \033[0m";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int choice_2;
            string name;
            int age;
            char Admit;
            bool admit;
            double id;
            do
            {
                cout << "\n1. Add Patient\n";
                cout << "2. Search Patient\n";
                cout << "3. Edit Patient\n";
                cout << "4. Delete Patient Details\n";
                cout << "5. Display All Patients\n";
                cout << "6. Main menu\n";
                cout << "\033[1;30mPlease Enter your choice:\033[0m";
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                {
                    cout << "Enter Patient Name : ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Patient ID : ";
                    cin >> id;
                    cout << "Enter Patient Age : ";
                    cin >> age;
                    cout << "Does patient need to be admitted?(y/n) : ";
                    cin >> Admit;
                    if (Admit == 'y' || Admit == 'Y')
                    {
                        admit = true;
                    }
                    else if (Admit == 'n' || Admit == 'N')
                    {
                        admit = false;
                    }
                    else
                    {
                        cout << "\033[1;31mError please try again.Enter (Y/N)\033[0m\n";
                        break;
                    }
                    p.insert(name, id, age, admit);
                    cout << "\033[1;32mPatient added to record successfully.\033[0m\n\n";
                    break;
                }
                case 2:
                {
                    cout << "Enter Patient ID:\n";
                    cin >> id;
                    Node *temp = p.findPatient(id);
                    if (temp == NULL)
                    {
                        cout << "Patient with id " << id << " not found.\n";
                        cout << "\n";
                        break;
                    }

                    p.displayPatient(id);
                    cout << "\n";
                    break;
                }
                case 3:
                {
                    if (!p.empty())
                    {
                        cout << "Enter Patient ID:\n";
                        cin >> id;
                        p.editRecords(id);
                        cout << "\n";
                    }
                    else
                    {
                        cout << "No patients found.\n";
                    }
                    break;
                }
                case 4:
                {
                    if (!p.empty())
                    {
                        cout << "Enter Patient ID:\n";
                        cin >> id;
                        p.deletion(id);
                        cout << "\n";
                    }
                    else
                    {
                        cout << "No patients found\n";
                    }
                    break;
                }
                case 5:
                {
                    if (!p.empty())
                    {
                        cout << "Displaying all patients:\n";
                        p.displayAllPatients();
                        cout << "\n";
                    }
                    else
                    {
                        cout << "No patients found.\n";
                    }
                    break;
                }
                case 6:
                {
                    cout << "Returning to main menu.\n";
                    cout << "\n";
                    break;
                }
                default:
                {
                    cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
                    cout << "\n";
                    break;
                }
                }
            } while (choice_2 != 6);
            break;
        }
        case 2:
        {
            int choice_3;
            double id;
            do
            {
                cout << "\n1. Add an appointment.\n";
                cout << "2. View all appointments.\n";
                cout << "3. Cancel an appointment.\n";
                cout << "4. List of Doctors\n";
                cout << "5. Main Menu\n";
                cout << "\033[1;30mPlease enter a choice : \033[0m";
                cin >> choice_3;
                switch (choice_3)
                {
                case 1:
                {
                    cout << "Enter the id of patient to set an appointment : ";
                    cin >> id;
                    apt.enqueueApt(p, id);
                    break;
                }
                case 2:
                {
                    apt.peekApts();
                    break;
                }
                case 3:
                {
                    apt.dequeueApt();
                    break;
                }
                case 4:
                {
                    cout << "=====\033[1;36mDoctors\033[0m====== :\n";
                    apt.Doctors();
                    break;
                }
                case 5:
                {
                    cout << "Returning to main menu...\n";
                    break;
                }
                default:
                {
                    cout << "\033[1;31mIncorrect choice please try again!\033[0m\n";
                    break;
                }
                }
            } while (choice_3 != 5);
            break;
        }
        case 3:
        {
            int choice_3;
            int id;
            do
            {
                cout << "\n1. Calculate bill for a patient.\n";
                cout << "2. Print Bill of a patient\n";
                cout << "3. Delete bill for a patient\n";
                cout << "4. Main Menu\n";
                cout << "\033[1;30mEnter your choice : \033[0m";
                cin >> choice_3;
                switch (choice_3)
                {
                case 1:
                {
                    cout << "Enter id of the patient:";
                    cin >> id;
                    b.CalculateBill(p, id);
                    break;
                }
                case 2:
                {
                    cout << "Enter the id of patient:";
                    cin >> id;
                    b.generateBill(p, id);
                    break;
                }
                case 3:
                {
                    cout << "Enter the id of patient:";
                    cin >> id;
                    b.DeleteBill(p, id);
                    break;
                }
                case 4:
                {
                    cout << "Returning to main menu....\n";
                    break;
                }
                default:
                {
                    cout << "\033[1;31mIncorrect choice please try again!\033[0m\n";
                    break;
                }
                }
            } while (choice_3 != 4);
            break;
        }
        case 4:
        {
            int choice_4;
            do
            {
                cout << "1. Update History(auto updates)\n";
                cout << "2. View Records\n";
                cout << "3. Delete All Records\n";
                cout << "4. Main Menu\n";
                cout << "Enter your choice : ";
                cin >> choice_4;
                switch (choice_4)
                {
                case 1:
                {
                    d.push(p, apt, b);

                    break;
                }
                case 2:
                {
                    cout << "================\033[1;36mRECORDS\033[0m====================\n";
                    d.Display();
                    break;
                }
                case 3:
                {
                    char choice;
                    cout << "Are you sure?(y/n)\n";
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y')
                    {
                        d.clear();
                        break;
                    }
                    break;
                }
                case 4:
                {
                    cout << "Returning to main menu.....\n";
                    break;
                }
                default:
                {
                    cout << "\033[1;31mInvalid choice please try again.\033[0m\n";
                    break;
                }
                }
            } while (choice_4 != 4);
            break;
        }
        case 5:
        {
            cout << "\nExiting .....\n";
            break;
        }
        default:
        {
            cout << "\n\033[1;31mWrong choice please try again!\033[0m";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}