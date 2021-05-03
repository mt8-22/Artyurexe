#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct car
{
	int id;
	char brand[10];
	char country[15];
	int cost;
	char color[10];
	char quality[10];
	int km;
	int repairs;
};

void find_used (struct car carpark[], int amount);
void print_table (struct car carpark[], int amount);
void russian_cars (struct car carpark[], int amount);
void sort_id (struct car carpark[], int amount);
void sort_cost (struct car carpark[], int amount);

int main(int argc, char const *argv[])
{
	int amount = 0;
	int memory = (sizeof(int) * 4) + (sizeof(char) * (10 + 15 + 10 + 10));
	printf("Введите количество автомобилей: ");
	scanf("%i",&amount);
	struct car* carpark = malloc (memory * amount);
	for (int i = 0; i < amount; ++i)
		{
			carpark[i].id = i + 1;
			printf("\nВведите данные для автомобиля №%i\n",(i + 1));
			printf("Марка: ");
			scanf("%s", carpark[i].brand);
			printf("Страна-производитель: ");
			scanf("%s", carpark[i].country);
			printf("Цена (тыс. $): ");
			scanf("%i", &carpark[i].cost);
			printf("Цвет: ");
			scanf("%s", carpark[i].color);
			printf("Состояние: ");
			scanf("%s", carpark[i].quality);
			printf("Пробег (тыс. км): ");
			scanf("%i", &carpark[i].km);
			printf("количество ремонтов: ");
			scanf("%i", &carpark[i].repairs);
		}	
	int n = 0;
	while (n < 7)
		{
			printf("Выберите функцию, которую хотите выполнить:\n");
			printf("1 - Список всех автомобилей\n");
			printf("2 - Поиск БУ автомобиля\n");
			printf("3 - Список отчечественных автомобилей\n");
			printf("4 - Отсортировать список по id\n");
			printf("5 - Отсортировать список по цене\n");
			printf("6 - Отделить новые автомобили от БУ\n");
			printf("7 - Закончить работу\n");
			scanf("%i", &n);
			switch(n)
			{
				case 1:
				{
					print_table (carpark, amount);
				}
				case 2:
				{
					find_used (carpark, amount);
				}
				case 3:
				{
					russian_cars (carpark, amount);
				}
				case 4:
				{
					sort_id (carpark, amount);
				}
				case 5:
				{
					sort_cost (carpark, amount);
				}
				case 6:
				{
									
				}
				case 7:
				{
					break;
				}
			}

		}
	free (carpark);
	return 0;
}

void print_table (struct car carpark[], int amount)
{
	printf("_______________________________________________________________________________________\n");
	printf("| id |  Марка   |Страна-производитель| Цена |   Цвет   | Состояние | Пробег | Ремонты |\n");
	printf("_______________________________________________________________________________________\n");
	for (int i = 0; i < amount; ++i)
	{
		printf("|%-4i|%-10s|%-15s     |%-6i|%-10s|%-10s |%-5i   |%-5i    |\n", carpark[i].id, carpark[i].brand,
		carpark[i].country, carpark[i].cost, carpark[i].color, carpark[i].quality, carpark[i].km, carpark[i].repairs);
		printf("_______________________________________________________________________________________\n");
	}
}

void find_used(struct car carpark[], int amount)
{
	int mincost = 0;
	int maxcost = 0;
	char brand[20];
	printf("Необходимая марка машины: ");
	scanf("%s", brand);
	printf("Минимальная цена (тыс. $): ");
	scanf("%i", &mincost);
	printf("Максимальная цена (тыс. $): ");
	scanf("%i", &maxcost);
	printf("\nСписок БУ автомобилей с выбраной марки в необходимом ценовом диапазоне с отсутсвием ремонтов:\n");
	printf("_______________________________________________________________________________________\n");
	printf("| id |  Марка   |Страна-производитель| Цена |   Цвет   | Состояние | Пробег | Ремонты |\n");
	printf("_______________________________________________________________________________________\n");
	for (int i = 0; i < amount; ++i)
	{
		if (strcmp (carpark[i].quality, "БУ") == 0 && strcmp (carpark[i].brand, brand) == 0 && 
		carpark[i].cost > mincost && carpark[i].cost < maxcost && carpark[i].repairs == 0)
		{
			for (int i = 0; i < amount; ++i)
				{
					printf("|%-4i|%-10s|%-15s     |%-6i|%-10s|%-10s |%-5i   |%-5i    |\n", carpark[i].id, carpark[i].brand,
					carpark[i].country, carpark[i].cost, carpark[i].color, carpark[i].quality, carpark[i].km, carpark[i].repairs);
					printf("_______________________________________________________________________________________\n");
				}
		}
	}
}

void russian_cars (struct car carpark[], int amount)
{
	printf("_______________________________________________________________________________________\n");
	printf("| id |  Марка   |Страна-производитель| Цена |   Цвет   | Состояние | Пробег | Ремонты |\n");
	printf("_______________________________________________________________________________________\n");
	for (int i = 0; i < amount; ++i)
	{
		if (strcmp(carpark[i].country,"Россия") == 0)
		{
			printf("|%-4i|%-10s|%-15s     |%-6i|%-10s|%-10s |%-5i   |%-5i    |\n", carpark[i].id, carpark[i].brand,
			carpark[i].country, carpark[i].cost, carpark[i].color, carpark[i].quality, carpark[i].km, carpark[i].repairs);
			printf("_______________________________________________________________________________________\n");
		}
	}
}

void sort_id (struct car carpark[], int amount)
{
	int n = 0;
	struct car k;
	bool flag = true;
	printf("Выберите как отсоритровать список:\n");
	while (n > 2 && n < 1)
	{
		printf("1 - по убыванию\n");
		printf("2 - по возрастанию\n");
		scanf("%i", &n);
	}
	if (n == 1)
	{
		while (flag == true)
		{
			flag = false;
			for (int i = 0; i < amount - 1; ++i)
			{
				if (carpark[i].id > carpark[i + 1].id)
				{
					flag = true;
					k = carpark[i];
					carpark[i] = carpark[i + 1];
					carpark[i + 1] = k;
				}
			}
		}
	}
	else
	{
		while (flag == true)
		{
			flag = false;
			for (int i = 0; i < amount - 1; ++i)
			{
				if (carpark[i].id < carpark[i + 1].id)
				{
					flag = true;
					k = carpark[i];
					carpark[i] = carpark[i + 1];
					carpark[i + 1] = k;
				}
			}
		}
	}
}

void sort_cost (struct car carpark[], int amount)
{
	int n = 0;
	struct car k;
	bool flag = true;
	printf("Выберите как отсоритровать список:\n");
	while (n > 2 && n < 1)
	{
		printf("1 - по убыванию\n");
		printf("2 - по возрастанию\n");
		scanf("%i", &n);
	}
	if (n == 1)
	{
		while (flag == true)
		{
			flag = false;
			for (int i = 0; i < amount - 1; ++i)
			{
				if (carpark[i].cost > carpark[i + 1].cost)
				{
					flag = true;
					k = carpark[i];
					carpark[i] = carpark[i + 1];
					carpark[i + 1] = k;
				}
			}
		}
	}
	else
	{
		while (flag == true)
		{
			flag = false;
			for (int i = 0; i < amount - 1; ++i)
			{
				if (carpark[i].cost < carpark[i + 1].cost)
				{
					flag = true;
					k = carpark[i];
					carpark[i] = carpark[i + 1];
					carpark[i + 1] = k;
				}
			}
		}
	}
}