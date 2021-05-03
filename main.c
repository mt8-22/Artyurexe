#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void find_used(struct car carpark[], int amount);
void print_table(struct car carpark[], int amount);

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
	int i = 0;
	while (i<6)
		{
			printf("Выберите функцию, которую хотите выполнить:\n");
			printf("1 - Список всех автомобилей\n");
			printf("2 - Поиск БУ автомобиля\n");
			printf("3 - Список отчечественных автомобилей\n");
			printf("4 - Отсортировать список по id\n");
			printf("5 - Отсортировать список по цене\n");
			printf("6 - Отделить новые автомобили от БУ\n");
			printf("7 - Закончить работу\n");
			scanf("%i", &i);
			switch(i)
			{
				case 1:
				{
					print_table(carpark, amount);
				}
				case 2:
				{
					find_used(carpark, amount);
				}
				case 3:
				{

				}
				case 4:
				{

				}
				case 5:
				{

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

void find_used(struct car carpark[], int amount);
	{
		char brand[20];
		printf("Необходимая марка машины: ");
		scanf("%s", &brand);
		printf("Минимальная цена: ");
		scanf("%i", &mincost);
		printf("Максимальная цена: ");
		scanf("%i", &maxcost);
		printf("\nСписок БУ автомобилей с выбраной марки в необходимом ценовом диапазоне с отсутсвием ремонтов:\n");
		printf("_______________________________________________________________________________________\n");
		printf("| id |  Марка   |Страна-производитель| Цена |   Цвет   | Состояние | Пробег | Ремонты |\n");
		printf("_______________________________________________________________________________________\n");
		for (int i = 0; i < amount; ++i)
		{
			if (strcmp (carpark[i].quality, "БУ") == 0) && (strcmp (carpark[i].brand, brand) == 0) && 
				(carpark[i].cost > mincost) && (carpark[i].cost < maxcost) && (carpark[i].repairs == 0)
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
