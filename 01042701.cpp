#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
protected:
	string name;
	string surname;
	string date_of_birth;
	string school;
	string group;
	int mark;

public:
	Student() : name(""), surname(""), date_of_birth(""), school(""), group(""), mark() {}

	Student(string name, string surname, string date_of_birth, string school, string group, int mark)
	{
		this->name = name;
		this->surname = surname;
		this->date_of_birth = date_of_birth;
		this->school = school;
		this->group = group;
		this->mark = mark;
	}

	~Student() {}

	static bool max_mark(const Student& a, const Student& b)
	{
		return a.mark < b.mark;
	}

	string getName() const
	{
		return name;
	}
	string getSname() const
	{
		return surname;
	}
	int getMark() const
	{
		return mark;
	}
	void show_info()
	{
	
		cout << endl << "Ім'я                 : " << name;
		cout << endl << "Прізвище             : " << surname;
		cout << endl << "Дата народження      : " << date_of_birth;
		cout << endl << "Навчальний заклад    : " << school;
		cout << endl << "Група                : " << group;
		cout << endl << "Середній бал         : " << mark << endl;
		cout << "---------------------------------------------------";
	}
};

int main()
{
	system("chcp 1251>nul");

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Ця програма відображає список студентів, шукає серед них студента з максимальним середнім балом та виводить його ім'я та прізвище і середній бал." << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	vector<Student> students;

	students.emplace_back(Student("Кирило", "Мельник", "11.10.2000", "Itea", "C++ Pro", 86));
	students.emplace_back(Student("Петро", "Сидоров", "03.07.2001", "Itea", "C++ Pro", 80));
	students.emplace_back(Student("Марія", "Гончар", "17.12.2001", "Itea", "C++ Pro", 93));
	students.emplace_back(Student("Анастасія", "Антонюк", "23.02.2000", "Itea", "C++ Pro", 90));
	students.emplace_back(Student("Андрій", "Балагура", "01.03.2002", "Itea", "C++ Pro", 91));

	cout << "                  Список студентів: " << endl;
	cout << "---------------------------------------------------";

	for (Student& student : students)
	{
		student.show_info();
	}

	auto maxMarkStudent = max_element(students.begin(), students.end(), Student::max_mark);

	if (maxMarkStudent != students.end())
	{
		cout << "---------------------------------------------------------------------";
		cout << endl << "Студент з найвищим середнім балом: " << maxMarkStudent->getName() << " " << maxMarkStudent->getSname() << " Її середній бал: " << maxMarkStudent->getMark() << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------";
	}

	return 0;
}
