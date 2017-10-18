/*Define a STUDENT class with USN, Name, and Marks in 3 tests of a subject. Declare an        
array of 10 STUDENT objects. Using appropriate functions, find the average of the two       
better marks for each student. Print the USN, Name and the average marks of all the        
students.*/
#include<fstream>
#include<iostream>
using namespace std;
class STUDENT
{
public:
    string name;
    string enrollNo;
    int marks[3],i,avgMarks;
    void avg()
    {
        if(marks[0]>=marks[1]&&marks[2]>=marks[1])
        {
            avgMarks = (marks[0]+marks[2])/2;
        }
        else if(marks[0]>=marks[2]&&marks[1]>=marks[2])
        {
            avgMarks = (marks[0]+marks[1])/2;
        }
        if(marks[1]>=marks[0]&&marks[2]>=marks[0])
        {
            avgMarks = (marks[1]+marks[2])/2;
        }
    }
    void display()
    {
        cout<<"name      :"<<name<<endl<<"enrollNo  :"<<enrollNo<<endl;    
        cout<<"AvgMarks  :"<<avgMarks<<endl;
    }
};
int main()
{
    int i,j;
    STUDENT s[6];
    fstream FileName;
    FileName.open("data.dat",ios::app|ios::in|ios::out);
    for(i=0;i<6;i++)
    {
        FileName>>s[i].name;
        FileName>>s[i].enrollNo;
        for(j=0;j<3;j++)
        {
            FileName>>s[i].marks[j];
        }
        s[i].avg();
        s[i].display();
    }
}