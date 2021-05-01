#include <stdio.h>
#include <stdlib.h>
struct car
{
	int id;
	char brand[20];
	char country[20];
	int cost;
	char color[15];
	char quality[10];
	int km;
	int repairs;
};

int main(int argc, char const *argv[])
{
	int amount = 0;
	int memory = (sizeof(int) * 4) + (sizeof(char) * (20 + 20 + 15 + 10));
	printf("Введите количество автомобилей: ");
	scanf("%i",&amount);
	struct car* carpark = malloc (memory * amount);
	for (int i = 0; i < amount; ++i)
		{
			carpark[i].id = i + 1;
			printf("Введите данные для автомобиля №%i\nМарка: ",(i + 1));
			scanf("%s",carpark[i].brand);
			printf("\nСтрана-производитель: ");
			scanf("%s",carpark[i].country);
			printf("\nЦена: ");
			scanf("%i",&carpark[i].cost);
			printf("\nЦвет: ");
			scanf("%s",carpark[i].color);
			printf("\nСостояние: ");
			scanf("%s",carpark[i].quality);
			printf("\nПробег: ");
			scanf("%i",&carpark[i].km);
			printf("\nколичество ремонтов: ");
			scanf("%i",&carpark[i].repairs);
		}	
	free(carpark);
	return 0;
}
