#include <iostream>
#include <conio.h>
#include <cstdio>
#include <iomanip>
#include <unistd.h>
#include <time.h>
#include <fstream>
using namespace std;
int count;
int search();
void menu();
void write_to_studentinfo();
//Class which has fee for each sem and MODIFY, LIST modules
class FEE
{
  public:
    float semester_fee[9], bus_fee[9], sports_fee[9], examination_fee[9], total_fee[9];
    FEE()
    {
        ifstream infile;                                                                            //Reading fee structure frfom the file
        infile.open("temp.txt");
        int j;
        for (j = 1; j < 9; j++)
        {
            infile >> semester_fee[j] >> bus_fee[j] >> sports_fee[j] >> examination_fee[j] >> total_fee[j];
        }
        infile.close();
    }
    void modifysem(int mod_sem)
    {
        char ch;
        system("CLS");
        cout << "\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;                 //member function for modifing the fee structure
        cout << "\t|\t       SELECT THE FEE STRUCTURE        |" << endl;
        cout << "\t------------------------------------------------" << endl;
        cout << "\t|\t\t s:SEMESTER" << setw(21) << right << "|" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t|\t\t b:IFHE BUS" << setw(21) << right << "|" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t|\t\t p:SPORTS  " << setw(21) << right << "|" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t|\t\te:EXAMINATION" << setw(19) << right << "|" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ch = getch();
        switch (ch)
        {
        case 's':
            system("CLS");
            cout << "CURRENT SEM:" << mod_sem << " FEE : " << semester_fee[mod_sem] << endl
                 << endl;
            cout << "ENTER SEM:" << mod_sem << " MODIFIED FEE : ";
            cin >> semester_fee[mod_sem];
            break;
        case 'b':
            system("CLS");
            cout << "CURRENT SEM:" << mod_sem << " BUS FEE : " << bus_fee[mod_sem] << endl
                 << endl;
            cout << "ENTER SEM:" << mod_sem << " MODIFIED BUS FEE : ";
            cin >> bus_fee[mod_sem];
            break;
        case 'p':
            system("CLS");
            cout << "CURRENT SEM:" << mod_sem << " SPORTS FEE : " << sports_fee[mod_sem] << endl
                 << endl;
            cout << "ENTER SEM:" << mod_sem << " MODIFIED  SPORTS FEE : ";
            cin >> sports_fee[mod_sem];
            break;
        case 'e':
            system("CLS");
            cout << "CURRENT SEM:" << mod_sem << " EXAMINATION FEE : " << examination_fee[mod_sem] << endl
                 << endl;
            cout << "ENTER SEM:" << mod_sem << " MODIFIED EXAMINATION FEE : ";
            cin >> examination_fee[mod_sem];
            break;
        default:
            cout << "INVALID OPTION RETURN TO HOME";
            break;
        }
        total_fee[mod_sem] = semester_fee[mod_sem] + bus_fee[mod_sem] + sports_fee[mod_sem] + examination_fee[mod_sem];
    }
    void MODIFY();
    void LIST()
    {
        system("CLS");
        char date[9];
        _strdate(date);
        int i;
        cout << "\n\n\t*************************************" << endl; //for listing the total fee for all the semsters
        cout << "\t|\t   IFHE university" << setw(11) << "|" << endl
             << "\t|" << setw(36) << "|" << endl;
        cout << "\t|\t\t" << setw(12) << "DATE:" << date << "|";
        cout << "\n\t-------------------------------------" << endl;
        cout << "\t|" << setw(21) << "SEMESTER"
             << "|" << setw(13) << "TOTAL FEE"
             << "|" << endl;
        cout << "\t-------------------------------------" << endl;
        for (i = 1; i < 9; i++)
        {
            cout << "\t|" << setw(20) << i << ":"
                 << "|" << setw(13) << total_fee[i] << "|" << endl;
        }
        cout << "\t*************************************" << endl;
        getch();
        menu();
    }

} fee_struct; //creating the object (for displaying and modifing the fee structure)
void FEE::MODIFY()
{
    system("CLS");
    int mod_sem;
    cout << "\n\n\t************************************************" << endl;
    cout << "\t|\t    MODIFY THE FEE STRUCTURE           |" << endl;
    cout << "\t------------------------------------------------" << endl;
    cout << "\t|\t\t  1:SEM 1  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl; //member function to display the different semesters to modify the fee structure
    cout << "\t|\t\t  2:SEM 2  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t|\t\t  3:SEM 3  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t|\t\t  4:SEM 4  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t|\t\t  5:SEM 5  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t|\t\t  6:SEM 6  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t|\t\t  7:SEM 7  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t|\t\t  8:SEM 8  " << setw(21) << right << "|" << endl
         << "\t |" << setw(47) << right << "|" << endl;
    cout << "\t************************************************" << endl;
    cin >> mod_sem;
    fee_struct.modifysem(mod_sem);
    ofstream outfile; //writing the modified fee structure to the file for permanent storage of values
    outfile.open("temp.txt");
    int j;
    for (j = 1; j < 9; j++)
    {
        outfile << semester_fee[j] << " " << bus_fee[j] << " " << sports_fee[j] << " " << examination_fee[j] << " " << total_fee[j] << " ";
    }
    outfile.close();
    menu();
}
//class for displaying student fee slips and making fee payment
class Payment_class
{
  public:
    string student_name;
    int student_sem;
    float paid_semester_fee, paid_bus_fee, paid_sports_fee, paid_examination_fee, paid_total_fee;
    create_student(string StudentName, int stud_sem)
    {
        student_name = StudentName; //to create the student if the student dosent exist in the data
        student_sem = stud_sem;
        paid_semester_fee = 0;
        paid_bus_fee = 0;
        paid_sports_fee = 0;
        paid_examination_fee = 0;
        paid_total_fee = 0;
    }
    void FEE_SLIP()
    {
        system("CLS");
        char date[9];
        _strdate(date);
        cout << "\n\n\t************************************************" << endl; //member function to display the fee slip of the student
        cout << "\t|\t\tIFHE university" << setw(17) << "|" << endl
             << "\t|" << setw(47) << "|" << endl;
        cout << "\t|\t\t" << setw(23) << "DATE:" << date << "|";
        cout << "\n\t------------------------------------------------" << endl;
        cout << setw(40) << left << "\t|NAME:" << left << setw(8) << left << student_name << "|";
        cout << "\n\t------------------------------------------------" << endl;
        cout << "\t|\tPARTICULARS\t\t|\tAMOUNT |\n";
        cout << "\t------------------------------------------------" << endl;
        cout << "\t|" << setw(31) << left << "SEMESTER FEE"
             << "|" << setw(14) << paid_semester_fee << "|" << endl;
        cout << "\t|" << setw(31) << left << "BUS FEE"
             << "|" << setw(14) << paid_bus_fee << "|" << endl;
        cout << "\t|" << setw(31) << left << "EXAMINATION FEE"
             << "|" << setw(14) << paid_examination_fee << "|" << endl;
        cout << "\t|" << setw(31) << left << "SPORTS FEE"
             << "|" << setw(14) << paid_sports_fee << "|" << endl;
        cout << "\t------------------------------------------------" << endl;
        cout << "\t|" << setw(31) << right << "TOTAL FEE"
             << "|" << setw(14) << paid_total_fee << "|" << endl;
        cout << "\t|" << setw(31) << right << "TOTAL DUE"
             << "|" << setw(14) << (fee_struct.total_fee[this->student_sem]-paid_total_fee) << "|" << endl;
        cout << "\t------------------------------------------------" << endl;
        getch();
        menu();
    }
    void PAYMENT()
    {
        system("CLS");
        string name;
        int mod_sem, semfee = 0, busfee = 0, sportsfee = 0, examinationfee = 0;
        char ch;
        system("CLS"); //member funtion for the payment process of a student
        cout << "\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t|\t       SELECT THE FEE STRUCTURE         |" << endl;
        cout << "\t------------------------------------------------" << endl;
        cout << "\t|STUDENT NAME:"<< this->student_name <<setw(29) << "SEM:" << this->student_sem << "|" << endl;
        cout << "\t------------------------------------------------" << endl;
        cout << "\t|\t\t s:SEMESTER   (DUE:" <<fee_struct.semester_fee[this->student_sem]-paid_semester_fee<<")" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t|\t\t b:IFHE BUS   (DUE:"  <<fee_struct.bus_fee[this->student_sem]-paid_bus_fee<< ")" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t|\t\t p:SPORTS     (DUE:" << fee_struct.sports_fee[this->student_sem]-paid_sports_fee<< ")" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t|\t\te:EXAMINATION (DUE:" << fee_struct.examination_fee[this->student_sem]-paid_examination_fee<< ")" << endl
             << "\t |" << setw(47) << right << "|" << endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ch = getch();
        switch (ch)
        {
        case 's':
            system("CLS");
            cout << "CURRENT due:" << (fee_struct.semester_fee[student_sem] - paid_semester_fee) << endl
                 << endl;
            cout << "ENTER PAYMENT FEE : ";
            cin >> semfee;
            break;
        case 'b':
            system("CLS");
            cout << "CURRENT due BUS FEE : " << (fee_struct.bus_fee[student_sem] - paid_bus_fee) << endl
                 << endl;
            cout << "ENTER PAYMENT BUS FEE : ";
            cin >> busfee;
            break;
        case 'p':
            system("CLS");
            cout << "CURRENT SEM SPORTS FEE : " << (fee_struct.sports_fee[student_sem] - paid_sports_fee) << endl
                 << endl;
            cout << "ENTER SEM PAYMENT  SPORTS FEE : ";
            cin >> sportsfee;
            break;
        case 'e':
            system("CLS");
            cout << "CURRENT SEM EXAMINATION FEE : " << (fee_struct.examination_fee[student_sem] - paid_examination_fee) << endl
                 << endl;
            cout << "ENTER SEM:" << mod_sem << " PAYMENT EXAMINATION FEE : ";
            cin >> examinationfee;
            break;
        default:
            cout << "INVALID OPTION RETURN TO HOME";
            break;
        }
        paid_semester_fee += semfee;
        paid_bus_fee += busfee;
        paid_sports_fee += sportsfee;
        paid_examination_fee += examinationfee;
        paid_total_fee = paid_semester_fee + paid_bus_fee + paid_sports_fee + paid_examination_fee;
        menu();
    }
} student[20];

int main()
{
    string studname;
    int studsem;
    float temp_semester_fee, temp_bus_fee, temp_sports_fee, temp_examination_fee, temp_total_fee; //main function
    int j;
    ifstream PaymentFile;
    PaymentFile.open("payment.txt"); //reading from data of payment imformation
    PaymentFile >> count;
    for (j = 0; j < count; j++)
    {
        PaymentFile >> studname >> studsem >> temp_semester_fee >> temp_bus_fee >> temp_sports_fee >> temp_examination_fee >> temp_total_fee;
        student[j].student_name = studname;
        student[j].student_sem = studsem;
        student[j].paid_semester_fee = temp_semester_fee;
        student[j].paid_bus_fee = temp_bus_fee;
        student[j].paid_sports_fee = temp_sports_fee;
        student[j].paid_examination_fee = temp_examination_fee;
        student[j].paid_total_fee = temp_total_fee;
    }
    PaymentFile.close();
    menu();
    write_to_studentinfo();
}
int search()
{
    int j;
    string name;
    system("CLS");
    cout << "ENTER THE NAME OF THE STUDENT:"; //searching for the student in the data
    cin >> name;
    for (j = 0; j < count + 1; j++)
    {
        if (student[j].student_name == name)
        {
            return j;
        }
    }
    system("CLS");
    cout << "STUDENT ID NOT FOUND";
    cout << endl
         << "DO YOU WANNA CREATE ONE?[y/n]";
    char ch;
    int semester;
    ch = getch();
    if (ch == 'y')
    {
        count += 1;
        cout << "\n"
             << count << "ENTER THE SEMESTER OF THE STUDENT:";
        cin >> semester;
        student[count].create_student(name, semester);
        write_to_studentinfo();
        cout << "\nSTUDET CREATED :)";
    }
    getch();
    menu();
}
void menu()
{
    system("CLS");
    char ch;
    cout << "\n\n\t************************************************" << endl; //interface
    cout << "\t|\t\tF: FEE SLIP" << setw(21) << right << "|" << endl
         << "\t|" << setw(47) << right << "|" << endl;
    cout << "\t|\t\tM: MODIFY  " << setw(21) << right << "|" << endl
         << "\t|" << setw(47) << right << "|" << endl;
    cout << "\t|\t\tL: LIST    " << setw(21) << right << "|" << endl
         << "\t|" << setw(47) << right << "|" << endl;
    cout << "\t|\t\tP: PAYMENT " << setw(21) << right << "|" << endl
         << "\t|" << setw(47) << right << "|" << endl;
    cout << "\t|\t\tQ: QUIT    " << setw(21) << right << "|" << endl
         << "\t|" << setw(47) << right << "|" << endl;
    cout << "\t************************************************" << endl;
    ch = getch();
    switch (ch)
    {
    case 'f':
        int s;
        s = search();
        student[s].FEE_SLIP();
        break;
    case 'm':
        fee_struct.MODIFY();
        break;
    case 'l':
        fee_struct.LIST();
        break;
    case 'p':
        s = search();
        student[s].PAYMENT();
        break;
    case 'q':
        
        break;
    default:
        break;
    }
}
void write_to_studentinfo()
{
    int j;
    ofstream PaymentWriteFile; //funtion for writing data into the file
    PaymentWriteFile.open("payment.txt");
    PaymentWriteFile << count << " ";
    for (j = 0; j < count; j++)
    {
        PaymentWriteFile << student[j].student_name << " " << student[j].student_sem << " " << student[j].paid_semester_fee << " " << student[j].paid_bus_fee << " " << student[j].paid_sports_fee << " " << student[j].paid_examination_fee << " " << student[j].paid_total_fee << " ";
    }
    PaymentWriteFile.close();
}