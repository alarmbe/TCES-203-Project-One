/* Author: Larry John & 
    project_one.c */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 20
#define MAX_SIZE 10

void addDrone(int a[], char b[][MAX_LEN], float c[], float d[][2]);
bool strCompare(char str1[], char str2[]);
void displayDrones(int a[], char b[][MAX_LEN], float c[], float d[][2]);
void calculateAverageBattery(int batteries[]);

void addDrone(int ids[], char models[][MAX_LEN], float batteries[], float positions[][2])
{

int freeID = 0;
int free_char = 0;
int free_battery = 0;
int free_position = 0;

// Find the nearest empty index for each array (if there is any)

for(int i = 0; i < MAX_SIZE; i++)
{

    if(ids[i] == 0)
    {
        freeID = i; break;
    }

}

// Find the first empty string index
for(int j = 0; j < MAX_SIZE; j++)
{

    if(strCompare(models[j], "0"))
    {
        free_char = j; break;
    }

}

// Find first empty battery slot
for(int k = 0; k < MAX_SIZE; k++)
{

    if(batteries[k] == 200.0)
    {
        free_battery = k;
    }

}

// Find a free empty position
for(int p = 0; p < MAX_SIZE; p++)
{

    if(positions[p][0] == -1 && positions[p][1] == -1)
    {
        free_position = p;
    }

}

// Prompt the user for drone information
printf("Please give ID number: ");
scanf("%d", &ids[freeID]);

printf("Please give model name: ");
scanf("%s", models[free_char]);

printf("Please battery level: ");
scanf("%f", &batteries[free_battery]);

printf("Please give position(x,y): ");
scanf("%f %f", &positions[free_position][0], &positions[free_position][1]);

printf("\n");

}

int main(void)
{

int ids[MAX_SIZE] = {0};
char models[MAX_SIZE][MAX_LEN] = {"0"};
float batteries[MAX_SIZE] = {200.0};
float positions[MAX_SIZE][2] = {-1, -1};

//addDrone(ids, models, batteries, positions);

//displayDrones(ids, models, batteries, positions);

// Establish key variables and gameplay loop
int choice, game_on = true;

while(game_on == true)
{

    choice = 0;

    printf("Please choose an option: \n");
    printf("1. Add drone\n2. Display drones\n3. Calculate battery average\n4. Exit");
    scanf("%d", &choice);

    if(choice == 4)
    {
        printf("Exiting program...");
        game_on = false;
    } else if(choice == 3)
    {
        calculateAverageBattery(batteries);
    }else if(choice == 1)
    {
        printf("Adding drone...\n");
        addDrone(ids, models, batteries, positions);
    } else if(choice == 2)
    {
        printf("Displaying drones...\n");
        displayDrones(ids, models, batteries, positions);
    } else{
        printf("Please enter a valid option.\n\n");
        continue;
    }

}

}

// Funciton to determine whether two strings are equal
bool strCompare(char str1[], char str2[])
{

    // Determine the size of the strings
    int one_size = 0;
    int two_size = 0;

    while(str1[one_size] != '\0')
    {
        one_size++;
    }
    while(str2[two_size] != '\0')
    {
        two_size++;
    }

    // Start a counter to determine whether the two strings are equal
    int one_counter = 0;
    int two_counter = 0;

    bool is_equal;

    if(one_size < two_size || one_size > two_size)
    {
       is_equal = false;
    } else{

        // Since each character is treated as an, int add each string up
        for(int i = 0; i < one_size; i++)
        {
            one_counter += str1[i];
            two_counter += str2[i];
        }

        // Now compare the sums
        if(one_counter == two_counter)
        {
            is_equal = true;
        } else{
            is_equal = false;
        }

    }

    return is_equal;

}

void displayDrones(int ids[],char models[][MAX_LEN],float batteries[],float positions[][2])
{

printf("ID | Model | Battery | X | Y \n");

for(int i = 0; i < MAX_SIZE; i++)
{

    if(ids[i] == 0)
    {
        break;
    }

    printf("%2d  %s\t%4.2f  %3.2f  %3.2f\n",ids[i],models[i],batteries[i],positions[i][0],positions[i][1]);

}

printf("\n");

}
// A method for calcualting the average battery level
void calculateAverageBattery(float batteries[])
{

    float average = 0.0;

    // Check if there are any batteries at all
    if(batteries[0] == 200.0)
    {
        printf("No drones available.");
    }  else{

        for(int i = 0; i < MAX_SIZE; i++)
        {

            if(batteries[i] == 200.0)
            {
                average += batteries[i];
                continue;
            } else{
                break;
            }

        }

        printf("The average battery level: %.2f", average);

    }

}
