#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>

//Структура, описывающая студента

struct Student
{
	char lastname[30];
	char group[10];
};

//Функция формирует строковый массив фамилий студентов, содержащихся в структуре "students", которsе учатся в группе group и их фамилии начинаются на букву "С"

void surname(Student students[], int N, char group[10], char c)
{
  //Посчитаем кол-во студентов, которое нужно будет вывести. Это будет число k

	int k = 0;

	for (int i = 0; i < N; i++)
	{
		//Если группа i-го студента равна group и первая буква его фамилии равна "C", то k++

		if ((strcmp(students[i].group, group) == 0) && (students[i].lastname[0] == c))
		{
			k++;
		}
	}

	//Создадим массив под k фамилий

	char** lastNames = (char**)malloc(k * sizeof(char*));

	k = 0;

	//Занесём в массив "lastNames" все подходящие фамилии

	for (int i = 0; i < N; i++)
	{
		if ((strcmp(students[i].group, group) == 0) && (students[i].lastname[0] == c))
		{
			lastNames[k++] = students[i].lastname;
		}
	}

	//Выведем их в консоль

	for (int i = 0; i < k; i++)
	{
		printf("%s\n", lastNames[i]);
	}

	//Освободим память из под массива lastNames
	
	free(lastNames);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	//Объявим массив структур и инициализируем его данными

	Student students[6] = {
		"Ivanov","21vv-4",
		"Savkin","21vv-4",
		"Savostin","21vv-4",
		"Snegirev","21vv-4",
		"Petrov","21vv-4",
		"Dugerenko","21vv-4",
	};

	//Сюда сохраним название группы из консоли

	char group[10];

	//Читаем название группы из консоли

	printf("Введите название группы \n");

	gets_s(group);

	printf("Введите первую букву фамилии студента \n");

	//Читаем из консоли первую букву фамилии


	char c = getchar();

	//Вызываем саму функцию

	surname(students, 6, group, c);
}