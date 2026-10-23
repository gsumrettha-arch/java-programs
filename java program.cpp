
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Project {
public:
    int id;
    string projectName, clientName, status;
    double budget, paid;

    void addProject(int projectId) {
        id = projectId;

        cin.ignore();

        cout << "Enter Project Name: ";
        getline(cin, projectName);

        cout << "Enter Client Name: ";
        getline(cin, clientName);

        cout << "Enter Project Budget: ";
        cin >> budget;

        cout << "Enter Payment Received: ";
        cin >> paid;

        if (budget <= 0 || paid < 0 || paid > budget) {
            cout << "Invalid budget or payment!\n";
            budget = 0;
            paid = 0;
            return;
        }

        int choice;
        cout << "\n1. Pending";
        cout << "\n2. In Progress";
        cout << "\n3. Completed";
        cout << "\nEnter Project Status: ";
        cin >> choice;

        switch (choice) {
            case 1: status = "Pending"; break;
            case 2: status = "In Progress"; break;
            case 3: status = "Completed"; break;
            default: status = "Pending";
        }

        cout << "\nProject Added Successfully!\n";
    }

    void display() {
        cout << "\nProject ID: " << id;
        cout << "\nProject Name: " << projectName;
        cout << "\nClient Name: " << clientName;
        cout << "\nProject Budget: Rs. " << budget;
        cout << "\nPayment Received: Rs. " << paid;
        cout << "\nPayment Pending: Rs. " << budget - paid;
        cout << "\nProject Status: " << status;
        cout << "\n-----------------------------\n";
    }
};

int main() {
    Project p[100];
    int count = 0;
    int choice;

    do {
        cout << "\n====================================";
        cout << "\n FREELANCER PROJECT MANAGEMENT";
        cout << "\n====================================";
        cout << "\n1. Add Project";
        cout << "\n2. View All Projects";
        cout << "\n3. Update Payment";
        cout << "\n4. Payment Summary";
        cout << "\n5. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < 100) {
                    p[count].addProject(count + 1);
                    if (p[count].budget > 0)
                        count++;
                } else {
                    cout << "Project storage is full!\n";
                }
                break;

            case 2:
                if (count == 0) {
                    cout << "No Projects Available!\n";
                }
                for (int i = 0; i < count; i++) {
                    p[i].display();
                }
                break;

            case 3: {
                int id;
                double payment;
                bool found = false;

                cout << "Enter Project ID: ";
                cin >> id;

                for (int i = 0; i < count; i++) {
                    if (p[i].id == id) {
                        cout << "Enter Total Payment Received: ";
                        cin >> payment;

                        if (payment >= p[i].paid &&
                            payment <= p[i].budget) {
                            p[i].paid = payment;
                            cout << "Payment Updated Successfully!\n";
                        } else {
                            cout << "Invalid Payment Amount!\n";
                        }

                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Project Not Found!\n";

                break;
            }

            case 4: {
                double totalBudget = 0, totalPaid = 0;

                for (int i = 0; i < count; i++) {
                    totalBudget += p[i].budget;
                    totalPaid += p[i].paid;
                }

                cout << fixed << setprecision(2);
                cout << "\nTotal Projects: " << count;
                cout << "\nTotal Budget: Rs. " << totalBudget;
                cout << "\nTotal Received: Rs. " << totalPaid;
                cout << "\nTotal Pending: Rs. "
                     << totalBudget - totalPaid << "\n";
                break;
            }

            case 5:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}
