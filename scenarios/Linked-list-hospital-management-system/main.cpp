#include <iostream>
#include <string>


using namespace std;


struct Patient {
    int id;
    string name;
    int age;
    string medical_history;
    Patient* next;
};

struct Doctor {
    int id;
    string name;
    string specialization;
    Doctor* next;
};

struct Appointment {
    int id;
    int patientId;
    int doctorId;
    string dateTime;
    string purpose;
    Appointment* next;
};

class HospitalSystem { 
    private:
        Patient* patientHead;
        Doctor* doctorHead;
        Appointment* appointmentHead;
        int patientCounter;
        int doctorCounter;
        int appointmentCounter;

    public:
        HospitalSystem() {
            patientHead = nullptr;
            doctorHead = nullptr;
            appointmentHead = nullptr;
            patientCounter = 1;
            doctorCounter = 1;
            appointmentCounter = 1;
        }

        ~HospitalSystem(){
            clearDoctors();
            clearPatients();
            clearAppointments();
        }

        void addPatient(const string& name, int age, const string& medical_history){
            Patient* patient = new Patient{patientCounter++,name, age, medical_history, nullptr};
            // Preventing the segmentation is essential like this Patient* patient
            // patient->name = name;
            // patient->age = age;
            // patient->medical_history = medical_history;
            if(!patientHead)
                patientHead = patient;
            else {
                Patient* current = patientHead;
                while(current->next){
                    current = current->next;
                }
                current->next = patient;
            }
            cout << "Successfully added the new Patient " << patient->id << endl;
        }

        void displayAllPatients(){
            Patient* current = patientHead;

            if (current == nullptr){
                cout << "No Patients currently registred in the System " << endl;
                return;
            }

            // please check that all patients are atleast available, .. as the same of doctors and also patients and appointments

            while(current != nullptr){
                cout << "Name:  " << current->name << " "
                     << "Age: "  << current->age << " "
                     << "Medical History" << current->medical_history << " "
                     << endl;
                current = current->next;
            }

            cout << "Finished Displaying all patients " << endl;
        }

        Patient* findPatientById(int id){
            Patient* current = patientHead;

            while(current != nullptr){
                if(current->id == id){
                    cout << "Name:  " << current->name << " "
                     << "Age: "  << current->age << " "
                     << "Medical History" << current->medical_history << " "
                     << endl;
                }
                current = current->next;
            }

            return nullptr;
        }

        void addDoctor(const string& name, const string& specialization){
            Doctor* doctor = new Doctor{doctorCounter++, name, specialization, nullptr};
            // please prevent the segmentation faults.
            // doctor->name = name;
            // doctor->specialization = specialization;
            if(!doctorHead)
                doctorHead = doctor;
            else {
                Doctor* current = doctorHead;
                while(current->next){
                    current = current->next;
                }
                current->next = doctor;
            }
            cout << "Successfully added the a new Doctor " << doctor->id << endl;
        }

        void displayAllDoctors(){
            Doctor* current = doctorHead;

            if (current == nullptr){
                cout << "No Doctors currently registred in the System " << endl;
                return;
            }

            while(current != nullptr){
                cout << "Name:  " << current->name << " "
                     << "Specialization: "  << current->specialization << " "
                     << endl;
                current = current->next;
            }

            cout << "Finished Displaying all doctors " << endl;
        }

        Doctor* findDoctorById(int id){
            Doctor* current = doctorHead;

            while(current != nullptr){
                if(current->id == id){
                    cout << "Name:  " << current->name << " "
                     << "Specialization: "  << current->specialization << " "
                     << endl;
                }
                current = current->next;
            }

            return nullptr;
        }

        void createAppointment(int patientId, int doctorId, const string& datetime, const string& purpose){
            if(findDoctorById(doctorId) == nullptr){
                cout << "No Doctor was found by that id you are returning:: " << endl;
                return;
            }


            if(findPatientById(patientId) == nullptr){
                cout << "No Patient was found by that id you are returning:: " << endl;
                return;
            }

            Appointment* appointment =  new Appointment{appointmentCounter++, patientId, doctorId, datetime, purpose, nullptr};
            // please prevent the segmentation faults.
            // appointment->patientId = patientId;
            // appointment->doctorId = doctorId;
            // appointment->dateTime = datetime;
            // appointment->purpose = purpose;

            if(!appointmentHead){
                appointmentHead = appointment;
            } else {
                Appointment* current = appointmentHead;
                while(current->next){
                    current = current->next;
                }
                current->next = appointment;
            }
        }

        void displayAppointments(){
            Appointment* current = appointmentHead;

            if(current == nullptr){
                cout << "No current appointments in the system " << endl;
                return;
            }

            while(current){
                cout << "Patient Id:  " << current->patientId << "\n "
                    << "Doctor Id:  " << current->doctorId  << "\n"
                    << "Date time of the purpose : " << current->dateTime << "\n"
                    <<  "Purpose of the appointment: " << current->purpose << endl;
                current = current->next;    
            }
        }

        void clearPatients(){
            Patient* current = patientHead;
            while(current){
                Patient* temp = current;
                current = current->next;
                delete temp;
            }
            patientHead = nullptr;
        }

        void clearDoctors(){
            Doctor* current = doctorHead;
            while(current){
                Doctor* temp = current;
                current = current->next;
                delete temp;
            }
            // set the doctor head to nullptr
            doctorHead = nullptr;
        }

        void clearAppointments(){
            Appointment* current = appointmentHead;
            while(current){
                Appointment* temp = current;
                current = current->next;
                delete temp;
            }
            // Set the appointmentHead to nullptr to destructure the object.
            appointmentHead = nullptr;
        }
};

int main(){
    HospitalSystem hospital;
    int choice;

    do {
        cout << "\n Hospital System managememt system " << endl;
        cout << "1. Add a patient " << endl;
        cout << "2. Add doctor " << endl;
        cout << "3. Schedule an appointment " << endl;
        cout << "4. Display all patients " << endl;
        cout << "5. Display all doctors " << endl;
        cout << "6. Exit " << endl;
        
        cout << "Enter your preferred choice : ";
        cin >> choice;
        // please remember to clear the buffer after using cin.
        cin.ignore();

        switch (choice) {
            case 1: {
                string name, medical_history;
                int age;
                cout << "Enter the patient name : " ;
                getline(cin, name);
                cout << "Enter the patient age : ";
                cin >> age;
                cin.ignore();
                cout << "Enter the patient medical history : ";
                getline(cin, medical_history);
                hospital.addPatient(name, age, medical_history);
                break;
            }

            case 2: {
                string name, specialization;
                cout << "Enter the doctor name : ";
                getline(cin, name);
                cout << "Enter the doctor specilization: ";
                getline(cin, specialization);
                hospital.addDoctor(name, specialization);
                break;
            }

            case 3: {
                int patientId, doctorId;
                string dateTime, purpose;
                cout << "Enter the patientId who want to schedule the appointment : ";
                cin >> patientId;
                cin.ignore();


                cout << "Enter the doctorId to whom you want to schedule the appointment with: ";
                cin >> doctorId;
                cin.ignore();

                cout << "Enter the datetime for the appointment request:  ";
                getline(cin, dateTime);


                cout << "Enter the purpose of the appointment:  ";
                getline(cin, purpose);

                hospital.createAppointment(patientId, doctorId, dateTime, purpose);
                break;
            }

            case 4: {
                cout << "Displaying all patients in our system " << endl;
                hospital.displayAllPatients();
                break;
            }

            case 5: {
                cout << "Displaying all doctors in our system " << endl;
                hospital.displayAllDoctors();
                break;
            }

            case 0: {
                cout << "Going to exit system, hope it was good for you see you later " << endl;
                // as above you had been using the while loop and it will loop infinitely until you say break.
                break;
            }

            default: {
                cout << "Inputed invalid choice, please try again, we need to serve you better" << endl;
            }
        }

    } while(choice != 0);
}