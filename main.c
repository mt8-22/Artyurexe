#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct car
{
	int id;
	char brand[15];
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
void divide_by_quality (struct car carpark[], int amount);

int main(int argc, char const *argv[])
{
	int amount = 0;
	int memory = (sizeof(int) * 4) + (sizeof(char) * (15 + 15 + 10 + 10));
	printf("Enter the amount of cars: ");
	scanf("%i",&amount);
	struct car* carpark = malloc (memory * amount);
	for (int i = 0; i < amount; ++i)
		{
			carpark[i].id = i + 1;
			printf("\nEnter data for car №%i\n",(i + 1));
			printf("Brand: ");
			scanf("%s", carpark[i].brand);
			printf("Producing country: ");
			scanf("%s", carpark[i].country);
			printf("Cost (thousands of $): ");
			scanf("%i", &carpark[i].cost);
			printf("Color: ");
			scanf("%s", carpark[i].color);
			printf("Quality: ");
			scanf("%s", carpark[i].quality);
			printf("Mileage (km): ");
			scanf("%i", &carpark[i].km);
			printf("Amount of repairs: ");
			scanf("%i", &carpark[i].repairs);
		}	
	int n = 0;
	while (n < 7)
		{
			printf("\nSelect required function:\n");
			printf("1 - List of cars\n");
			printf("2 - Find used car\n");
			printf("3 - List of Russian cars\n");
			printf("4 - Sort by id\n");
			printf("5 - Sort by cost\n");
			printf("6 - Divide used cars from new\n");
			printf("7 - Finish program\n");
			scanf("%i", &n);
			switch(n)
			{
				case 1:
				{
					print_table (carpark, amount);
					break;
				}
				case 2:
				{
					find_used (carpark, amount);
					break;
				}
				case 3:
				{
					russian_cars (carpark, amount);
					break;
				}
				case 4:
				{
					sort_id (carpark, amount);
					break;
				}
				case 5:
				{
					sort_cost (carpark, amount);
					break;
				}
				case 6:
				{
					divide_by_quality (carpark, amount);
					break;					
				}
			}
		}
	free (carpark);
	return 0;
}

void print_table (struct car carpark[], int amount)
{
	printf("____________________________________________________________________________________________\n");
	printf("|id  |Brand          |Producing country   |Cost  |Color     |Quality    |Mileage |Repairs  |\n");
	printf("____________________________________________________________________________________________\n");
	for (int i = 0; i < amount; ++i)
	{
		printf("|%-4i|%-10s|%-15s     |%-6i|%-10s|%-10s |%-5i   |%-5i    |\n", carpark[i].id, carpark[i].brand,
		carpark[i].country, carpark[i].cost, carpark[i].color, carpark[i].quality, carpark[i].km, carpark[i].repairs);
		printf("____________________________________________________________________________________________\n");
	}
}

void find_used(struct car carpark[], int amount)
{
	int mincost = 0;
	int maxcost = 0;
	char brand[20];
	printf("\nRequired car brand: ");
	scanf("%s", brand);
	printf("Minimal cost (thousands of $): ");
	scanf("%i", &mincost);
	printf("Maximal cost (thousands of $): ");
	scanf("%i", &maxcost);
	printf("\nList of used cars without repairs of required brand in chosen price range:\n");
	printf("____________________________________________________________________________________________\n");
	printf("|id  |Brand          |Producing country   |Cost  |Color     |Quality  |Mileage   |Repairs  |\n");
	printf("____________________________________________________________________________________________\n");
	for (int i = 0; i < amount; ++i)
	{
		if (strcmp(carpark[i].quality, "Used") == 0 && strcmp (carpark[i].brand, brand) == 0 && 
		carpark[i].cost >= mincost && carpark[i].cost <= maxcost && carpark[i].repairs == 0)
		{
			for (int i = 0; i < amount; ++i)
				{
					printf("|%-4i|%-10s|%-15s     |%-6i|%-10s|%-10s |%-5i   |%-5i    |\n", carpark[i].id, carpark[i].brand,
					carpark[i].country, carpark[i].cost, carpark[i].color, carpark[i].quality, carpark[i].km, carpark[i].repairs);
					printf("____________________________________________________________________________________________\n");
				}
		}
	}
}

void russian_cars (struct car carpark[], int amount)
{
	printf("____________________________________________________________________________________________\n");
	printf("|id  |Brand          |Producing country   |Cost  |Color     |Quality  |Mileage   |Repairs  |\n");
	printf("____________________________________________________________________________________________\n");
	for (int i = 0; i < amount; ++i)
	{
		if (strcmp (carpark[i].country,"Russia") == 0)
		{
			printf("|%-4i|%-10s|%-15s     |%-6i|%-10s|%-10s |%-5i   |%-5i    |\n", carpark[i].id, carpark[i].brand,
			carpark[i].country, carpark[i].cost, carpark[i].color, carpark[i].quality, carpark[i].km, carpark[i].repairs);
			printf("____________________________________________________________________________________________\n");
		}
	}
}

void sort_id (struct car carpark[], int amount)
{
	int n = 0;
	struct car k;
	bool flag = true;
	printf("Choose how to sort:\n");
	while (n != 2 && n != 1)
	{
		printf("1 - descending\n");
		printf("2 - ascending\n");
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
	struct car car;
	bool flag = true;
	printf("Choose how to sort:\n");
	while (n != 2 && n != 1)
	{
		printf("1 - descending\n");
		printf("2 - ascending\n");
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
					car = carpark[i];
					carpark[i] = carpark[i + 1];
					carpark[i + 1] = car;
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
					car = carpark[i];
					carpark[i] = carpark[i + 1];
					carpark[i + 1] = car;
				}
			}
		}
	}
}

void divide_by_quality (struct car carpark[], int amount)
{
	int memory = (sizeof(int) * 4) + (sizeof(char) * (15 + 15 + 10 + 10));
	struct car* carpark1 = malloc (memory * amount);
	struct car car;
	int j = -1;
	for (int i = 0; i < amount; ++i)
	{
		if (strcmp(carpark[i].quality,"New") == 0)
		{
			j = j + 1;
			carpark1[j] = carpark[i];	
		}
	}
	for (int i = 0; i < amount; ++i)
	{
		if (strcmp(carpark[i].quality,"Used") == 0)
		{
			j = j + 1;
			carpark1[j] = carpark[i];	
		}
	}
	for (int i = 0; i < amount; ++i)
	{
		carpark[i] = carpark1[i];
	}
	free(carpark1);
}