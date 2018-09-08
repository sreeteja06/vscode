#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<iomanip>
int student_count = 0;
using namespace std;
int search(string input_name);
class ADMIN
{
	protected:
		string student_name[20], student_num[20], student_depart[20], student_course[20];
		float student_attendance[20];
	public:
		ADMIN()
		{
			int i;
			ifstream student_file;
			student_file.open("student_details.txt");
			student_file >> student_count;
			for(i=0;i<student_count;i++)
			{
				student_file >> student_name[i] >> student_num[i] >> student_depart[i] >> student_course[i] >> student_attendance[i];
			}
			student_file.close();
		}
		friend int search(string input_name);
		void edit()
		{
			char ch;
			string input_name;
			int search_number, switch_number;
			cout << "ENTER THE NAME OF THE STUDENT:";
			cin >> input_name;
			search_number = search(input_name);
			if(search_number == -1)
			{
				cout<<"STUDENT NOT FOUND !!!!";
				cout<<"\n DO U WANNA CREATE ONE?[y/n]";
				ch = getch();
				if(ch=='y')
				{
					this->new_student();
				}
				exit(1);
			}
			else
			{
				cout << "WHAT DO YOU WANNA new_student ABOUT THIS STUDENT:";
				cout << "\n1---STUDENT NAME(present name:"<<this->student_name[search_number]<<")\n";
				cout << "\n2---STUDENT ENROLLMENT(present name:"<<this->student_num[search_number]<<")\n";
				cout << "\n3---STUDENT DEPARTMENT(present name:"<<this->student_depart[search_number]<<")\n";
				cout << "\n4---STUDENT COURSE(present name:"<<this->student_course[search_number]<<")\n";
				cout << "\n5---STUDENT ATTENDANCE(present name:"<<this->student_attendance[search_number]<<")\n";
				cin >> switch_number;
				system("CLS");
				switch(switch_number)
				{
					case 1:
						cout<<"STUDENT NAME:";
						cin >> student_name[search_number];
						break;
					case 2:
						cout<<"STUDENT ENROLLMENT NUMBER:";
						cin >> student_num[search_number];
						break;
					case 3:
						cout<<"STUDENT DEPARTMENT:";
						cin >> student_depart[search_number];
						break;
					case 4:
						cout<<"MANAGE COURSE:";
						cin >> student_course[search_number];
						break;
					case 5:
						cout<<"MANAGE ATTENDANCE:";
						cin >> student_attendance[search_number];
						break;
					default:
						cout<<"wrong option dhuh!!";
						break;
					getch();
					this->write_to_studentinfo();
			}
			}
			getch();
			this->write_to_studentinfo();
		}
		void new_student()
		{
			int i;
			student_count+=1;
			cout << "ADD STUDENT DETAILS"<<endl;
			cout << "STUDENT NAME:";
			cin >> student_name[student_count-1];
			cout << "STUDENT ENROLLMENT NUMBER:";
			cin >> student_num[student_count-1];
			cout << "ADD DEPARTMENT:";
			cin >> student_depart[student_count-1];
			cout << "ADD COURSE:";
			cin >> student_course[student_count-1];
			cout << "MANAGE ATTENDANCE:";
			cin >>student_attendance[student_count-1];
			this->write_to_studentinfo();
		}
		void delete_student()
		{
			int i,search_number;
			string input_name;
			cout << "ENTER THE STUDENT NAME TO BE DELETED:";
			cin >> input_name;
			search_number = search(input_name);
			if(search_number==-1)
			{
				cout<<"STUDENT NOT FOUND";
			}
			else
			{
				for(i = search_number;i<student_count;i++)
				{
					this->student_name[i] = this->student_name[i+1];
					this->student_num[i] = this->student_num[i+1];
					this->student_depart[i] = this->student_depart[i+1];
					this->student_course[i] = this->student_course[i+1];
					this->student_attendance[i] = this->student_attendance[i+1];
				}
				student_count -= 1;
				cout << "STUDENT DELETED";
			}
			this->write_to_studentinfo();
			getch();
		}
		void write_to_studentinfo()
		{
    		int j;
    		ofstream WriteFile; //funtion for writing data into the file
    		WriteFile.open("student_details.txt");
    		WriteFile << student_count;
    		for (j = 0; j < student_count; j++)
    		{
        		WriteFile << " " << student_name[j] << " " << student_num[j] << " " << student_depart[j] << " " << student_course[j] << " " << student_attendance[j];
    		}
    		WriteFile.close();
		}
};

class STUDENT:public ADMIN{
public:
	STUDENT()
	{
		int i;
			ifstream student_file;
			student_file.open("student_details.txt");
			student_file >> student_count;
			for(i=0;i<student_count;i++)
			{
				student_file >> student_name[i] >> student_num[i] >> student_depart[i] >> student_course[i] >> student_attendance[i];
			}
			student_file.close();
	}
	void show_all_student()
	{
		int i;
		cout << setw(15) << left << "NAME" << setw(15) << left << "ENROLL" << setw(15) << left << "DEPART" << setw(15) << left << "COURSE" << setw(15) << left << "ATTENDANCE";
		for(i=0;i<student_count;i++)
		{
			cout << endl << setw(15) << left << student_name[i] << setw(15) << left << student_num[i] << setw(15) << left << student_depart[i] << setw(15) << left << student_course[i] << setw(15) << left << student_attendance[i];
		}
	}
	void show_specific_student()
	{
		string input_name;
		int search_number;
		cout << "ENTER THE NAME:";
		cin >> input_name;
		search_number = search(input_name);
		if(search_number == -1)
		{
			cout << "NO STUDENT FOUND";
		}
		else{
			cout << setw(15) << left << "NAME" << setw(15) << left << "ENROLL" << setw(15) << left << "DEPART" << setw(15) << left << "COURSE" << setw(15) << left << "ATTENDANCE";
			cout << endl << setw(15) << left << student_name[search_number] << setw(15) << left << student_num[search_number] << setw(15) << left << student_depart[search_number] << setw(15) << left << student_course[search_number] << setw(15) << left << student_attendance[search_number];
		}
	}
};

int search(string input_name)
{
	int i;
	ADMIN friend_object;
	for(i=0;i<student_count;i++)
	{
		if(input_name == friend_object.student_name[i])
			return i;
	}
	return -1;
}
int main()
{
	STUDENT object;
	string name;
	int switch_number, x;
	cout << "\n SELECT ANY ONE \n1.ADMIN\n2.STUDENT\n";
	cin >> switch_number;
	system("CLS");
	switch(switch_number)
	{
		case 1:
			cout << "Search for the student\n";
			cin >> name;
			x = search(name);
			if(x == -1)
			{
				cout << "NO STUDENT FOUND";
			}
			break;
		case 2:
			cout << "GO TO STUDENT PAGE\n";
			break;
		default:
			cout << "ENTER A VALID NUMBER\n";
			break;
	}
	object.show_specific_student();
	getch();
}