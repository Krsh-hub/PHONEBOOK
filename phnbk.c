#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define NAME_LENGTH 100
#define NUMBER_LENGTH 15  // Support for international numbers

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

// Case-insensitive comparison
int strcasecmp_custom(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2))
            return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// Merge Sort
void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    Contact temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (strcasecmp_custom(contacts[i].name, contacts[j].name) <= 0)
            temp[k++] = contacts[i++];
        else
            temp[k++] = contacts[j++];
    }
    while (i <= mid)
        temp[k++] = contacts[i++];
    while (j <= right)
        temp[k++] = contacts[j++];

    for (int l = 0; l < k; l++)
        contacts[left + l] = temp[l];
}

void mergeSort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

// Add contact
void addContact(const char* name, const char* number) {
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp_custom(contacts[i].name, name) == 0 && strcmp(contacts[i].number, number) == 0) {
            printf("Contact already present\n");
            return;
        }
    }
    strcpy(contacts[contactCount].name, name);
    strcpy(contacts[contactCount].number, number);
    contactCount++;
    mergeSort(0, contactCount - 1);
    printf("Contact added successfully\n");
}

// Delete by name
void deleteByName(const char* name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp_custom(contacts[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++)
                contacts[j] = contacts[j + 1];
            contactCount--;
            printf("Contact deleted successfully\n");
            return;
        }
    }
    printf("No contacts found\n");
}

// Delete by number
void deleteByNumber(const char* number) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].number, number) == 0) {
            for (int j = i; j < contactCount - 1; j++)
                contacts[j] = contacts[j + 1];
            contactCount--;
            printf("Contact deleted successfully\n");
            return;
        }
    }
    printf("No contacts found\n");
}

// Search by name
void searchContactByName(const char* name) {
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp_custom(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].number);
            return;
        }
    }
    printf("No contacts found\n");
}

// Search by number
void searchContactByNumber(const char* number) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].number, number) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].number);
            return;
        }
    }
    printf("No contacts found\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];

    while (1) {
        printf("\nPhoneBook Menu:\n");
        printf("1: Add contact\n");
        printf("2: Delete contact\n");
        printf("3: View contact\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the name of the new contact: ");
                while (getchar() != '\n');
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter the phone number: ");
                scanf("%s", number);

                addContact(name, number);
                break;

            case 2: {
                int delChoice;
                printf("1: Delete by name\n");
                printf("2: Delete by number\n");
                if (scanf("%d", &delChoice) != 1) {
                    printf("Invalid choice\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');
                if (delChoice == 1) {
                    printf("Enter the name: ");
                    fgets(name, NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    deleteByName(name);
                } else if (delChoice == 2) {
                    printf("Enter the number: ");
                    scanf("%s", number);
                    deleteByNumber(number);
                } else {
                    printf("Invalid choice\n");
                }
                break;
            }

            case 3: {
                int viewChoice;
                printf("1: View contact by name\n");
                printf("2: View contact by number\n");
                if (scanf("%d", &viewChoice) != 1) {
                    printf("Invalid choice\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');
                if (viewChoice == 1) {
                    printf("Enter the name: ");
                    fgets(name, NAME_LENGTH, stdin);
                    name[strcspn(name, "\n")] = '\0';
                    searchContactByName(name);
                } else if (viewChoice == 2) {
                    printf("Enter the number: ");
                    scanf("%s", number);
                    searchContactByNumber(number);
                } else {
                    printf("Invalid choice\n");
                }
                break;
            }

            case 4:
                printf("Exiting PhoneBook\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
