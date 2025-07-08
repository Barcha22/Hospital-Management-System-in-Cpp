#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "patient_manager.h"
#include <string>

const int MAX_DOCTORS = 3;
const int MAX_APT = 10;

class Node2
{
private:
    string doctor_name;
    string date;
    string time;
    double patient_id;
    string patient_name;
    Node2 *next;

public:
    Node2();
    Node2(string doctor_name, string date, string time, double patient_id, string patient_name);
    string getDoctor();
    string getDate();
    string getTime();
    double getID();
    string getPatient();
    friend class aptManager;
};
class aptManager
{
private:
    Node2 *front;
    Node2 *rear;

public:
    aptManager();
    static void Doctors();
    void enqueueApt(Patient &p, double id);
    void peekApts();
    bool patient_apt(double id, Patient &p);
    void dequeueApt();
};
#endif