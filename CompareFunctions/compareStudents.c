#include <stdio.h>
#include <stdbool.h>

typedef struct student{
	char name[20];
	int age;
	float score;
}Student;

bool compareByAge(Student stu1, Student stu2)
{
	return stu1.age > stu2.age ? "YES" : "NO";
}

bool compareByScore(Student stu1, Student stu2)
{
	stu1.score > stu2.score ? "YES" : "NO";
}

void sortStudents(Student *array, int n, bool (*p)(Student, Student))
{
	Student temp;
	int flag = 0;
	for(int i =0; i < n - 1&&flag == 0; i++)
	{
		flag = 1;
		for(int j = 0; j < n - i - 1; j++)
		{
			if(p(array[j], array[j+1]))
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				flag = 0;
			}
		}
	}

	
}

int main()
{
	Student stu1 = {"Amir", 28, 98};
	Student stu2 = {"Arjun", 27, 100};
	Student stu3 = {"Brenda", 21, 100};
	Student stuArray[3] = {stu1, stu2, stu3};

	sortStudents(stuArray, 3, compareByScore);
	return 0;
}