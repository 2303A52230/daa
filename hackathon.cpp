#include <stdio.h>
#include <string.h>

#define MAX_ALUMNI 100

typedef struct {
    char name[50];
    char email[50];
    char graduationYear[10];
    char fieldOfStudy[50];
    char location[50];
    char jobTitle[50];
    char successStory[200];
    float donations;
} Alumni;

Alumni alumniDatabase[MAX_ALUMNI];
int alumniCount = 0;

void registerAlumni() {
    if (alumniCount >= MAX_ALUMNI) {
        printf("Alumni database is full.\n");
        return;
    }

    Alumni a;

    printf("Enter name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter email: ");
    scanf(" %[^\n]", a.email);

    printf("Enter graduation year: ");
    scanf(" %[^\n]", a.graduationYear);

    printf("Enter field of study: ");
    scanf(" %[^\n]", a.fieldOfStudy);

    printf("Enter location: ");
    scanf(" %[^\n]", a.location);

    printf("Enter job title: ");
    scanf(" %[^\n]", a.jobTitle);

    printf("Enter your success story: ");
    scanf(" %[^\n]", a.successStory);

    a.donations = 0.0f;

    alumniDatabase[alumniCount++] = a;
    printf("Alumni registered successfully!\n");
}

void makeDonation() {
    char email[50];
    float amount;
    int found = 0;

    printf("Enter email: ");
    scanf(" %[^\n]", email);

    for (int i = 0; i < alumniCount; i++) {
        if (strcmp(alumniDatabase[i].email, email) == 0) {
            printf("Enter donation amount: ");
            scanf("%f", &amount);
            alumniDatabase[i].donations += amount;
            printf("Thank you for your donation of %.2f!\n", amount);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Alumni not found.\n");
    }
}

void searchAlumni() {
    char field[50];
    int found = 0;

    printf("Enter field of study to search: ");
    scanf(" %[^\n]", field);

    for (int i = 0; i < alumniCount; i++) {
        if (strcmp(alumniDatabase[i].fieldOfStudy, field) == 0) {
            printf("Name: %s | Email: %s | Job: %s | Location: %s\n", 
                alumniDatabase[i].name,
                alumniDatabase[i].email,
                alumniDatabase[i].jobTitle,
                alumniDatabase[i].location);
            found = 1;
        }
    }

    if (!found) {
        printf("No alumni found in this field.\n");
    }
}

void viewSuccessStories() {
    for (int i = 0; i < alumniCount; i++) {
        printf("Name: %s\nStory: %s\n\n", alumniDatabase[i].name, alumniDatabase[i].successStory);
    }
}

void menu() {
    int choice;

    do {
        printf("\n--- Alumni Association Platform ---\n");
        printf("1. Register Alumni\n");
        printf("2. Make a Donation\n");
        printf("3. Search Alumni by Field\n");
        printf("4. View Success Stories\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerAlumni();
                break;
            case 2:
                makeDonation();
                break;
            case 3:
                searchAlumni();
                break;
            case 4:
                viewSuccessStories();
                break;
            case 5:
                printf("Exiting platform.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);
}

int main() {
    menu();
    return 0;
}

