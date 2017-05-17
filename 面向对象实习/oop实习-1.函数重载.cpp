#include <bits/stdc++.h>
using namespace std;
double getEarning(double salary, int absenceDays);
double getEarning(double baseSalary, double salesSum, double rate);
double getEarning(int workPieces, double wagePerPiece);
double getEarning(double hours, double wagePerHour);

int main()
{
    int sel;
    double salary;int absenceDays;
    double baseSalary;double salesSum;double rate;
    int workPieces;double wagePerPiece;
    double hours;double wagePerHour;

    cout << "Please select..." << endl;
    cout << "1: Manager." << endl;
    cout << "2: Sales Man." << endl;
    cout << "3: Pieces Worker." << endl;
    cout << "4: Hour-Worker." << endl;
    cout << "Others: Quit" << endl;

    cin >> sel;
    switch(sel)
    {
    case 1:
        cin >> salary >> absenceDays;
        cout << getEarning(salary, absenceDays);
        break;
    case 2:
        cin >> baseSalary >> salesSum >> rate;
        cout << getEarning(baseSalary, salesSum, rate);
        break;
    case 3:
        cin >> workPieces >> wagePerPiece;
        cout << getEarning(workPieces, wagePerPiece);
        break;
    case 4:
        cin >> hours >> wagePerHour;
        cout << getEarning(hours, wagePerHour);
        break;
    default:
        return 0;
        break;
    }
    return 0;
}
double getEarning(double salary, int absenceDays)
{
    return salary - absenceDays*salary/22;
}
double getEarning(double baseSalary, double salesSum, double rate)
{
    return baseSalary + salesSum*rate;
}
double getEarning(int workPieces, double wagePerPiece)
{
    return workPieces*wagePerPiece;
}
double getEarning(double hours, double wagePerHour)
{
    return hours*wagePerHour;
}

