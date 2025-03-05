#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int totalStudents = 10;
    int finalStudentCount = 6;

    char *emailArray = (char *)malloc(totalStudents * sizeof(char *));

    if (emailArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    char *emails[10] = {
        "aubin.saiba23@alu.com",
        "kenny.cyusa23@alu.com",
        "colette.asingizwe23@alu.com",
        "kellia.muzira23@alu.com",
        "aaron.mugisha23@alu.com",
        "divine.uwase23@alu.com",
        "eric.nshimyumuremyi23@alu.com",
        "sandrine.uwera23@alu.com",
        "jean.bosco23@alu.com",
        "grace.iradukunda23@alu.com"
    };
    for (int i = 0; i < totalStudents; i++) {
        emailArray[i] = (char *)malloc(50 * sizeof(char));  
        if (emailArray[i] == NULL) {
            printf("Memory allocation failed for email %d\n", i);
            return 1;
        }
        strcpy(emailArray[i], emails[i]); 
    }

    printf("Initial list of student emails:\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%s\n", emailArray[i]);
    }
    emailArray = (char **)realloc(emailArray, finalStudentCount * sizeof(char *));
    
    if (emailArray == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    printf("\nShrunk list of student emails (only 6 students):\n");
    for (int i = 0; i < finalStudentCount; i++) {
        printf("%s\n", emailArray[i]);
    }

    for (int i = 0; i < finalStudentCount; i++) {
        free(emailArray[i]);
    }
    free(emailArray);

    return 0;
}
