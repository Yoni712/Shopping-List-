#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<stdlib.h> // For malloc() and free()
void addItem(struct ShoppingList* list)
{
	//kolla om allokeringen  r null�
	float amount = 0;
	int bruh = list->length + 1;

	list->itemList = (struct GrocaryItem*)realloc(list->itemList, sizeof(struct GrocaryItem) * bruh);

	getchar();
	printf("Enter name: ");
	gets(list->itemList[list->length].productName);
	while (amount <= 0) {
		printf("Enter amount: ");
		scanf("%f", &amount);
		if (amount < 0)
		{
			printf("Invalid\n");
		}
		else
		{
			(list->itemList[list->length].amount) = amount;
		}
	}
	getchar();
	printf("Enter unit: ");
	gets(list->itemList[list->length].unit);
	
	int category = 0;
	
	printf("\nThere are 3 categorys you can chose from by entering the respective number:\n\n1.Fruit&Vedge\n2.Fridge&Freezer\n3.Pantry");    //EXAMINATION
	printf("\n\nWhich category does the item belong to?: ");  //EXAMINATION
	scanf("%d", &category);         //EXAMINATION

	list->itemList[list->length].category = category;  //EXAMINATION


	list->length++;

	
}
void printList(struct ShoppingList* list) //EXAMINATION
{
	int i = 0;
	printf("\nYour list contains %d items:\n\n", list->length);
	printf("The categorys the items belongs to is shown by number on the right that are between 1-3:\n\n1.Fruit&Vedge\n2.Fridge&Freezer\n3.Pantry\n\n");
	
	printf("Fruits & Vegetables\n");
	for (i = 0; i < list->length; i++) {
		if (list->itemList[i].category == 1) {
			printf("%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}

	printf("\nFridge & Freezer\n");
	for (i = 0; i < list->length; i++) {
		if (list->itemList[i].category == 2) {
			printf("%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}

	printf("\nPantry\n");
	for (i = 0; i < list->length; i++) {
		if (list->itemList[i].category == 3) {
			printf("%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}
	/*for (i = 0; i < list->length; i++) {
		if (list->itemList[i].category == 1) {
			fprintf(fileName, "%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}

	fprintf(fileName, "\nFridge & Freezer\n");
	for (i = 0; i < list->length; i++) {
		if (list->itemList[i].category == 2) {
			fprintf(fileName, "%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}

	fprintf(fileName, "\nPantry\n");
	for (i = 0; i < list->length; i++) {
		if (list->itemList[i].category == 3) {
			fprintf(fileName, "%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}*/
	/*for (i = 0; i < list->length; i++)
	{
		printf("%d. %-10s%-10.2f%-10s%-10d\n", i + 1, list->itemList[i].productName,
			list->itemList[i].amount, list->itemList[i].unit, list->itemList[i].category);
	}*/
}
void removeItem(struct ShoppingList* list)
{
	int ans = 1000000;
	while (ans > list->length || ans <= 0) {
		if (list->length == 0) {
			printf("There is nothing in the item list.");
			return;
		}
		printf("Which item do you want to remove? ");
		scanf("%d", &ans);
		if (ans > list->length || ans <= 0) {
			printf("The list only containes %d items!\n", list->length);
		}
	}
	for (int i = 0; i < list->length; i++) {
		list->itemList[ans - 1] = list->itemList[ans];
		ans++;
	}
	list->length--;
	printf("\nThe item has been removed.");
}

void editCategory(struct ShoppingList* list) {		//EXAMINATION
	int item = 10000;
	int newCategory = 4;
	
	if (list->length == 0) {
		printf("\nThere are no items!");
		return;
	}
	while (item <= 0 || item > list->length) {
		printf("Which item do you want to change the category of: ");
		scanf("%d", &item);

		if (item <= 0 || item > list->length) {
			printf("Invalid! Try again.\n");
			return;
		}

		else {
			break;
		}
	}
	
	while (newCategory <= 0 || newCategory > 3) {
		printf("What Category do you want to change the item to?: ");
		scanf("%d", &newCategory);

		if (newCategory <= 0 || newCategory > 3) {
			printf("Invalid! Try again.\n");
			return;
		}
		else {
			list->itemList[item-1].category = newCategory;
			break;
		}
	}

}

void editItem(struct ShoppingList* list)
{
	int answer = 1000000;
	float newTry = 0;
	while (answer > list->length || answer <= 0) {
		if (list->length == 0) {
			printf("There is nothing in the item list.");
			return;
		}
		printf("Which item do you want to change? ");
		scanf("%d", &answer);
		if (answer > list->length || answer <= 0) {
			printf("The list only containes %d items!\n", list->length);
		}
	}
	printf("Current amount: %f\t%s\n", list->itemList[answer - 1].amount, list -> itemList[answer - 1].unit);
	while (newTry <= 0) {
		printf("\nEnter new amount: ");
		scanf("%f", &newTry);
		if (newTry > 0) {
			list->itemList[answer - 1].amount = newTry;
		}
		else {
			printf("Invalid!");
			newTry = 0;
		}
	}
}

void saveList(struct ShoppingList* list) //EXAMINATION
{
	char ThefileName[100];
	int i = 0;
	FILE* fileName;

	if (list->length > 0) {
		printf("Choose a file name please: ");
		scanf("%s", &ThefileName);
		fileName = fopen(ThefileName, "w");

		fprintf(fileName, "%d\n", list->length);

		fprintf(fileName, "Fruits & Vegetables\n");
		for (i = 0; i < list->length; i++) {
			if (list->itemList[i].category == 1) {
				fprintf(fileName, "%d %s %f %s\n",i +1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
			}
		}

		fprintf(fileName, "\nFridge & Freezer\n");
		for (i = 0; i < list->length; i++) {
			if (list->itemList[i].category == 2) {
				fprintf(fileName, "%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
			}
		}

		fprintf(fileName, "\nPantry\n");
		for (i = 0; i < list->length; i++) {
			if (list->itemList[i].category == 3) {
				fprintf(fileName, "%d %s %f %s\n", i + 1, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
			}
		}

		/*for (i = 0; i < list->length; i++)
		{
			if (fileName != NULL) {
				if (list->itemList[i].category == 1) {

				}

				if (list->itemList[i].category == 2) {

				}

				if (list->itemList[i].category == 3) {

				}

				if (fileName != NULL) {
					fprintf(fileName, "%s %f %s\n", list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
				}


			}
			
		}*/
		fclose(fileName);
	}

	else {
		printf("There is nothing in the item list!");
	}
}
void loadList(struct ShoppingList* list)
{
	char ThefileName[100];
	int i = 0;
	FILE* File;
	printf("Enter the file name you want to upload: ");
	scanf("%s", ThefileName);
	File = fopen(ThefileName, "r");
	if (File == NULL) {
		printf("Sorry, but there is no file with that name!");
		return;
	}
	fscanf(File, "%d\n", &list->length);
	list->itemList = (struct GrocaryItem*)realloc(list->itemList, sizeof(struct
		GrocaryItem) * list->length);
	for (i = 0; i < list->length; i++)
	{
		fscanf(File, "%s %f %s\n", list->itemList[i].productName, &list -> itemList[i].amount, list->itemList[i].unit);
	}
	fclose(File);
}