#include <iostream>
#include <vector>
#include <string>

class Patient {
public:
    std::string name;
    int age;
    std::string medicalHistory;
    std::string medicinesPrescribed;
    double payment;

    Patient(const std::string& n, int a, const std::string& mh)
        : name(n), age(a), medicalHistory(mh), payment(0.0) {}

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age
                  << ", Medical History: " << medicalHistory
                  << ", Medicines Prescribed: " << medicinesPrescribed
                  << ", Payment: " << payment << "\n";
    }

    void editDetails() {
        std::cout << "Enter new medical history: ";
        std::cin.ignore(); // Consume the newline character in the buffer
        std::getline(std::cin, medicalHistory);
        std::cout << "Enter new medicines prescribed: ";
        std::getline(std::cin, medicinesPrescribed);
        std::cout << "Patient information updated.\n";
    }

    void makePayment(double amount) {
        payment += amount;
        std::cout << "Payment of " << amount << " made. Total payment is now " << payment << ".\n";
    }
};

class Doctor {
public:
    std::string name;
    std::string specialty;

    Doctor(const std::string& n, const std::string& s)
        : name(n), specialty(s) {}

    void editDetails() {
        std::cout << "Enter new specialty: ";
        std::cin >> specialty;
        std::cout << "Doctor information updated.\n";
    }
};

class HealthcareManagementSystem {
private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;

public:
    void addPatient(const std::string& name, int age, const std::string& medicalHistory) {
        Patient newPatient(name, age, medicalHistory);
        patients.push_back(newPatient);
    }

    void addDoctor(const std::string& name, const std::string& specialty) {
        Doctor newDoctor(name, specialty);
        doctors.push_back(newDoctor);
    }

    void displayPatients() const {
        if (patients.empty()) {
            std::cout << "No patients in the system.\n";
        } else {
            std::cout << "Patients in the system:\n";
            for (const auto& patient : patients) {
                patient.display();
            }
        }
    }

    void displayDoctors() const {
        if (doctors.empty()) {
            std::cout << "No doctors in the system.\n";
        } else {
            std::cout << "Doctors in the system:\n";
            for (const auto& doctor : doctors) {
                std::cout << "Name: " << doctor.name << ", Specialty: " << doctor.specialty << "\n";
            }
        }
    }

    void editPatient(int index) {
        if (index >= 0 && index < patients.size()) {
            Patient& patient = patients[index];
            std::cout << "Editing patient: " << patient.name << "\n";
            patient.editDetails();
        } else {
            std::cout << "Invalid patient index.\n";
        }
    }

    void editDoctor(int index) {
        if (index >= 0 && index < doctors.size()) {
            Doctor& doctor = doctors[index];
            std::cout << "Editing doctor: " << doctor.name << "\n";
            doctor.editDetails();
        } else {
            std::cout << "Invalid doctor index.\n";
        }
    }

    void makePayment(int index, double amount) {
        if (index >= 0 && index < patients.size()) {
            Patient& patient = patients[index];
            std::cout << "Making payment for patient: " << patient.name << "\n";
            patient.makePayment(amount);
        } else {
            std::cout << "Invalid patient index.\n";
        }
    }

    void prescribeMedicine(int index) {
        if (index >= 0 && index < patients.size()) {
            Patient& patient = patients[index];
            std::cout << "Prescribing medicine for patient: " << patient.name << "\n";
            std::cout << "Enter medicines prescribed: ";
            std::cin.ignore(); // Consume the newline character in the buffer
            std::getline(std::cin, patient.medicinesPrescribed);
            std::cout << "Medicines prescribed.\n";
        } else {
            std::cout << "Invalid patient index.\n";
        }
    }
};

int main() {
    HealthcareManagementSystem hms;
    int choice;

    do {
        std::cout << "1. Add Patient\n";
        std::cout << "2. Add Doctor\n";
        std::cout << "3. Display Patients\n";
        std::cout << "4. Display Doctors\n";
        std::cout << "5. Edit Patient\n";
        std::cout << "6. Edit Doctor\n";
        std::cout << "7. Make Payment\n";
        std::cout << "8. Prescribe Medicine\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, medicalHistory;
                int age;

                std::cout << "Enter patient details:\n";
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Age: ";
                std::cin >> age;
                std::cout << "Medical History: ";
                std::cin.ignore(); // Consume the newline character in the buffer
                std::getline(std::cin, medicalHistory);

                hms.addPatient(name, age, medicalHistory);
                break;
            }
            case 2: {
                std::string name, specialty;

                std::cout << "Enter doctor details:\n";
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Specialty: ";
                std::cin >> specialty;

                hms.addDoctor(name, specialty);
                break;
            }
            case 3: {
                hms.displayPatients();
                break;
            }
            case 4: {
                hms.displayDoctors();
                break;
            }
            case 5: {
                int index;
                std::cout << "Enter patient index: ";
                std::cin >> index;
                hms.editPatient(index);
                break;
            }
            case 6: {
                int index;
                std::cout << "Enter doctor index: ";
                std::cin >> index;
                hms.editDoctor(index);
                break;
            }
            case 7: {
                int index;
                double amount;
                std::cout << "Enter patient index: ";
                std::cin >> index;
                std::cout << "Enter payment amount: ";
                std::cin >> amount;
                hms.makePayment(index, amount);
                break;
            }
            case 8: {
                int index;
                std::cout << "Enter patient index: ";
                std::cin >> index;
                hms.prescribeMedicine(index);
                break;
            }
            case 0: {
                std::cout << "Exiting the system.\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 0);

    return 0;
}
