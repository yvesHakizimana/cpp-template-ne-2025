// what does pragma once means in c++?
// pragma once is a preprocessor directive in C++ that ensures a header file is included only once in a single compilation.
// This prevents multiple inclusions of the same header file, which can lead to redefinition errors and increased compilation time.
// It is a modern alternative to traditional include guards (using #ifndef, #define, and #endif).
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


// Patient Class.
class Patient {
    private: 
        string id;
        string name;
        string contact;
        string medicalHistory;
    
    public:
       
        // Helps to optimize the compiler by showing it directly being the default constructor.
        Patient() = default;
        
        Patient(const string& id, const string& name, const string& contact): id(id), name(name), contact(contact) {}

        // Const keyword to indicate that the function is the accessor function.
        string getId() const {return id;}
        string getName() const {return name;}
        string getContact() const {return contact;}
        string getMedicalHistory() const {return medicalHistory;}


        // Like here we const string& history to pass the reference  
        void setMedicalHistory(const string& history){
            medicalHistory = history;
        }

        void display() const {
            cout 
            << "ID: " << id 
            << "\nName: " << name 
            << "\nContact: " << contact 
            << "\nMedical History: " << medicalHistory << endl;
        }
};


class Doctor  {
    private:
        string id;
        string name;
        string specialization;
        string contact;

    public:
        Doctor() = default;
        
        Doctor(const string& id, const string& name, const string& specialization, const string& contact): id(id), name(name), specialization(specialization), contact(contact) {}

        string getId() const {return id;}
        string getName() const {return name;}
        string getSpecialization() const {return specialization;}
        string getContact() const {return contact;}    
        
        void display() const {
            cout << "ID: " << id
                 << "\nName:  " << name 
                 << "\nContact: "<< contact 
                 << "\nSpecialization "<< specialization << endl; 
        }
};

class Appointment {
    private:
        string id;
        string patientId;
        string doctorId;
        string date;
        string time;
        string status;
    public:
        Appointment() = default;
        
        Appointment(const string& id, const string& patientId,
            const string& doctorId, const string& date, 
            const string& time , const string& status
        ): id(id), patientId(patientId), doctorId(doctorId), date(date), time(time), status(status){}

        string getId() const {return id;}
        string getPatientId() const {return patientId;}
        string getDoctorId() const {return doctorId;}
        string getDate() const {return date;}
        string getTIme() const {return time;}
        string getStatus() const {return status;}

        void setStatus(const string& newStatus) {
            status = newStatus;
        } 

        void display() const {
            cout << "ID: " << id 
                 << "\nPatientId: " << patientId
                 << "\nDoctorId: " << doctorId
                 << "\nDate: " << date
                 << "\nTime: " << time
                 << "\nStatus: " << status << endl;     
        }
};
