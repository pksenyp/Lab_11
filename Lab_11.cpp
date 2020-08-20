#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Trains // the structure's announcement
{
    char station[100]; // structural elements
    int number;
    int hours;
    int minutes;
};

void swap(int* x, int* y) { // pass the addresses of two variables to the swap function
    int z = *x;
    *x = *y;
    *y = z;
}

int main()
{
    system("cls"); // Cleaning the console
    const int n = 6;
    int i, k = 0;
    int all_time[100];
    char path[100];
    Trains train[6];
	
	printf("Enter 6 trains:\n");
	
    for (i = 0; i < n; i++) // enter all the necessary data from the keyboard
    {
        printf("%d =================================================\n", i + 1);
        printf("Enter your destination: ");
        scanf("%s", &train[i].station, sizeof(struct Trains));
        printf("Enter train number: ");
        scanf("%d", &train[i].number);
        printf("Enter the departure time:\n");
        printf("Hours: ");
        scanf("%d", &train[i].hours);
        printf("Minutes: ");
        scanf("%d", &train[i].minutes);
    } 

    for (i = 0; i < n; i++) { // write the time into an array for more convenient sorting
        all_time[i] = train[i].hours * 3600 + train[i].minutes * 60;
    }

            for (i = 0; i < n; i++) { // sorting the array by time of departure 
                for (int j = i + 1; j < n; j++) {
                    if (all_time[i] > all_time[j])
                    {
                        swap(&train[i].hours, &train[j].hours);
                        swap(&train[i].minutes, &train[j].minutes);
                        swap(&all_time[i], &all_time[j]);
                    }
                }
            }

    printf("---------------------------------------------------"); // sorted array output
    for (int i = 0; i < n; i++) {
        printf("\nDestination: %s", train[i].station);
        printf("\nTrain number: %d", train[i].number);
        printf("\nThe departure time: %d:%d ", train[i].hours, train[i].minutes);
    }
    
    printf("\n---------------------------------------------------");
    printf("\nEnter your destination: ");
    scanf("%s\0", &path, sizeof(path)); // enter your destination
    for (i = 0; i < n; i++)
        if (strcmp (train[i].station, path) == 0) // compare the strings of each character bit by bit
        {
            printf("\nDestination: %s", train[i].station);
            printf("\nTrain number: %d", train[i].number);
            printf("\nThe departure time: %d:%d", train[i].hours, train[i].minutes);
            k = 1;
        }
    if (k == 0) { // If there's no match, we print the corresponding inscription
        printf("\nSorry, nothing was found on your request.");
    }
    printf("\n---------------------------------------------------\n\n");
    system("pause");
    return 0;
}