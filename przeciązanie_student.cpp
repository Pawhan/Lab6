#include<iostream>
#include<string>
#include<vector>
using namespace std;
class StudyYear
{
	int year;
	public:
	explicit StudyYear(int y=0)
	{
		year=y;
	}
	friend class Student;
	StudyYear & operator++(int)
	{
		year++;
		return *this;
	}
	StudyYear & operator--(int)
	{
		year--;
		return *this;
	}
	bool operator ==(const StudyYear &y)
	{
		return year==y.year;
	}
	bool operator <(const StudyYear &y)
	{
		return year<y.year;
	}
	friend ostream & operator <<(ostream &out, const StudyYear &y)
	 {
        out<<y.year;
        return out;
    }
    friend istream& operator >>(istream &in, StudyYear &y) 
	{
        in>>y.year;
        return in;
	}
	int wypisz()
	{
		return year;
	}
};
class Student
{
	string id;
	string first_name;
	string last_name;
	string program;
	StudyYear *year;
	public:
	explicit Student(const string &id, const string &f, const string &l, const string &p, StudyYear *y) {
            this->id = id;
            first_name = f;
            last_name = l;
            program = p;
            year = y;
        }
        bool operator==(Student &s) {
            return id==s.id or first_name==s.first_name or last_name==s.last_name or program==s.program or year->wypisz()==s.year->wypisz();
        }
        friend ostream& operator<<(ostream &out, Student &s) {
            out<<"Student {id: ,,"<<s.id<<"\", first_name: ,,"<<s.first_name<<"\", last_name: ,,"<<s.last_name<<"\", program: ,,"<<s.program<<"\", year: "<<s.year->wypisz()<<" }";
            return out;
        }
        friend istream& operator>>(istream &in, Student &s) 
		{
            in>>s.id;
            return in;
		}	
};
class StudentRepository{
    private:
        vector<Student*> studentRepository;
    public:
        void addStudent(Student *student)
		 {
            studentRepository.push_back(student);
         }
        friend ostream& operator<<(ostream &out, StudentRepository &rep)
		 {
            out<<"[ ";
            for (auto &s: rep.studentRepository)
			{
                cout<<*s<<", ";
            }
            out<<"]"<<endl;
            return out;
        }
        bool operator==(StudentRepository &rep) 
		{
            for(int i=0;i<rep.studentRepository.size();i++)
			 {
                if (studentRepository[i]==rep.studentRepository[i])
                    continue;
                else
                    return false;
            }
            return true;
        }
        Student& operator[](int iterator)
		{
            return *this->studentRepository[iterator];
        }
};
int main()
{
	StudyYear rok = StudyYear(4);
	StudyYear rok2 = StudyYear(6);
	Student s1 = Student("303109", "Pawel","Hanzlik","infa",&rok);
	Student s2 = Student("303108", "Pawel","Hazlik","inf",&rok2);
	StudentRepository repository;
	cout<<rok++<<endl;
	cout<<rok--<<endl;
	cout<<rok.wypisz()<<endl;
	if(rok<rok2)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	cout<<s1<<endl;
	if(s1==s2)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	repository.addStudent(&s1);
	cout<<repository;
	return 0;
}
