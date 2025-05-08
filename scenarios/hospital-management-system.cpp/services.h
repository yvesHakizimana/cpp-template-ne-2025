#pragma once
#include "models.h"
#include <map>
#include <stdexcept>
#include <iostream>

using namespace std;

class HospitalSystem {
    private:
        map<string, Patient> patients;
        map<string, Doctor> doctors;
        map<string, Appointment> appointments;

    public:
        void addPatient(const Patient& patient){
            if(patients.find(patient.getId()) != patients.end()){
                throw runtime_error("Patient with ID" + patient.getId() + " already exists");
            }
            patients[patient.getId()] = patient;
        }    

        bool patientExists(const string& id) const {
            return patients.find(id) != patients.end();
        }

        Patient& getPatient(const string& id){
            if(!patientExists(id)){
                throw runtime_error("Patient with ID " + id + "  is not found");
            }
            return patients[id];
        }

        void displayPatient(const string& id) const {
            auto it = patients.find(id);
            if (it == patients.end()){
                cout << "Patient With ID " + id + " not found " << endl;
                return;
            }
            it->second.display();
        }

        void displayAllPatients() const {
            if(patients.empty()){
                cout << "No Patients currently registered in the hospital" << endl;
                return;
            }

            cout << "\n===== All PAtients ======\n";
            for (const auto& pair : patients){
                pair.second.display();
                cout << "----------------\n";
            }
        }


        void addDoctor(const Doctor& doctor){
            if(doctors.find(doctor.getId()) != doctors.end()){
                throw runtime_error("Doctor with ID" + doctor.getId() + " already exists");
            }
            doctors[doctor.getId()] = doctor;
        }    

        bool doctorExists(const string& id) const {
            return doctors.find(id) != doctors.end();
        }

        Doctor& getDoctor(const string& id){
            if(!doctorExists(id)){
                throw runtime_error("Doctor with ID " + id + "  is not found");
            }
            return doctors[id];
        }

        void displayDoctor(const string& id) const {
            auto it = doctors.find(id);
            if (it == doctors.end()){
                cout << "Doctor With ID " + id + " not found " << endl;
                return;
            }
            it->second.display();
        }

        void displayAllPatients() const {
            if(doctors.empty()){
                cout << "No Doctors currently registered in the hospital" << endl;
                return;
            }

            cout << "\n==== All Doctors ======\n";
            for (const auto& pair : doctors){
                pair.second.display();
                cout << "----------------\n";
            }
        }        
         
        void addAppointment(const Appointment& appointment){
            if(appointments.find(appointment.getId()) != appointments.end()){
                throw runtime_error("Appointment with ID " + appointment.getId() + " already exists");
            }

            if(!patientExists(appointment.getPatientId()))
                throw runtime_error("Patient with ID " + appointment.getPatientId() + " not found.");

            if(!doctorExists(appointment.getDoctorId()))
                throw runtime_error("Doctor with ID " + appointment.getDoctorId() + " not found");
                
            appointments[appointment.getId()] = appointment;    
        }
        
        
        bool appointmentExists(const string& id ) const {
            return appointments.find(id) != appointments.end();
        }

        Appointment& getAppointment(const string& id) {
            if(!appointmentExists(id))
                throw runtime_error("Appointment with ID " + id + " not found");
            return appointments[id];
        }

        void displayAppointment(const string& id) const {
            auto it = appointments.find(id);
            if(it == appointments.end()){
                cout << "Appointment with this " + id + "is not found"  << endl;
                return;
            }
            it->second.display();
        }

        void displayAllAppointments() const {
            if(appointments.empty()){
                cout << "No appointments currently scheduled " << endl;
                return;
            }

            cout << "\n ==== All Appointments =====\n";
            for (const auto& pair: appointments){
                pair.second.display();
                cout << "----------------------------\n";
            }
        }
};