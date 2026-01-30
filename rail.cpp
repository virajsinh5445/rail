#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int number;
    char name[50];
    char from[50];
    char to[50];
    char time[10];

    static int count;

public:

    Train() {
        number = 0;
        strcpy(name, "");
        strcpy(from, "");
        strcpy(to, "");
        strcpy(time, "");
        count++;
    }


    ~Train() {
        count--;
    }


    int getNumber() {
        return number;
    }

    void input() {
        cout << "Enter Train Number: ";
        cin >> number;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(name, 50);

        cout << "Enter Source: ";
        cin.getline(from, 50);

        cout << "Enter Destination: ";
        cin.getline(to, 50);

        cout << "Enter Train Time: ";
        cin.getline(time, 10);
    }

    void show() {
        cout << "Train Number: " << number << endl;
        cout << "Train Name: " << name << endl;
        cout << "Source: " << from << endl;
        cout << "Destination: " << to << endl;
        cout << "Train Time: " << time << endl;
    }
};

int Train::count = 0;


class Railway {
private:
    Train t[100];
    int total;

public:
    Railway() {
        total = 0;
    }

    void add() {
        t[total].input();
        total++;
        cout << "Train Added Successfully!\n";
    }

    void showAll() {
        if (total == 0) {
            cout << "No Train Record Found!\n";
            return;
        }

        for (int i = 0; i < total; i++) {
            cout << "\nTrain " << i + 1 << " Details:\n";
            t[i].show();
        }
    }

    void search(int no) {
        for (int i = 0; i < total; i++) {
            if (t[i].getNumber() == no) {
                cout << "\nTrain Found:\n";
                t[i].show();
                return;
            }
        }
        cout << "Train Not Found!\n";
    }
};


int main() {
    Railway r;
    int choice, no;

    do {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Add Train\n";
        cout << "2. Show All Trains\n";
        cout << "3. Search Train\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            r.add();
            break;

        case 2:
            r.showAll();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> no;
            r.search(no);
            break;

        case 4:
            cout << "Thank You! Program End.\n";
            break;

        default:
            cout << "Wrong Choice!\n";
        }
    } while (choice != 4);

    return 0;
}