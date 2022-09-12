#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
using namespace std;
struct STUDENT
{
	string name;
	int group;
	float ses[5];
};

int main()
{
	const int size = 5;
	STUDENT stud1[size];
	int i, j;
	int n = 0;
	int count = 0;
 //-------------------------------------------------------------------------------------
 #define N 4
 #define M 5

	setlocale(LC_ALL, "RUS");

	srand(time(NULL));

	int k;
	printf("Введите размер массива ");

	scanf_s("%d", &k);

	int* arr = (int*)malloc(k * sizeof(int));// размер первого массива
	int min, max, razn;

	//------------------------------------------------------------------------

	int sum_r[N] = { 0, 0, 0, 0 };
	int sum_c[M] = { 0, 0, 0, 0, 0 };
	int** matr;
	int g, h;
	matr = (int**)malloc(N * M * sizeof(int*));

	for (int i = 0; i < k; i++)
	{
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < k; i++)
	{
		printf("\n%d", arr[i]);
	}

	min = arr[0], max = arr[0];

	for (int i = 0; i < k; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}

		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	razn = max - min;
	printf("\nРазница между максимальным и минимальным элементом массива = %d\n", razn);

	//----------------------------------------------------------------------------------

	for (g = 0; g < N; ++g)
		matr[g] = (int*)malloc(M * sizeof(int));
	for (g = 0; g < N; ++g)
		for (h = 0; h < M; ++h)
			matr[g][h] = rand() % 50;

	printf("2D Массив:\n");

	for (g = 0; g < N; ++g)
	{
		for (h = 0; h < M; ++h)
		{
			printf("%d ", matr[g][h]);
		}
		printf("\n");
	}

	for (g = 0; g < N; ++g)
		for (h = 0; h < M; ++h)
			sum_r[g] += +matr[g][h];

	for (g = 0; g < M; ++g)
		for (h = 0; h < N; ++h)
			sum_c[g] = sum_c[g] + matr[h][g];
	for (g = 0; g < N; ++g)
		printf("Сумма %d строки: %d\n", g + 1, sum_r[g]);
	printf("\n");

	for (g = 0; g < M; ++g)
		printf("Сумма %d столбца: %d\n", g + 1, sum_c[g]);

	for (g = 0; g < N; ++g)
		free(matr[g]);
	free(matr); // освобождение пвмяти
	return 0;

	//-------------------------------------------------------------------------------

	for (i = 0; i < size; i++)
	{
		printf("Введите фамилию студента");
		scanf_s("%c",stud1[n].name);
		printf("Введите номер группы ");
		scanf_s("%c",stud1[n].group);
		printf("Введите 5 оценок ");
		for (int i = 0; i < 5; i++)
			scanf_s("%d",stud1[n].ses[i]);
		n++;
	}
	float sum = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 5; j++)
			sum += stud1[i].ses[j];

		if (sum / 5 > 4.0)
		{
			printf("\nСтуденты средний балл которых больше 4: %c\n ",stud1[i].name);
			printf("%d",stud1[i].group);
			printf("%d",sum / 5);
		}
		else
			count++;
		sum = 0;
	}
	if (count == size)
		printf("Такие студенты отсутствуют ");
	system("Pause");
	return 0;
}