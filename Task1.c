#include <stdio.h>

void calculate_tax(float *gross_salary, float *tax) {
    if (*gross_salary <= 100) {
        *tax = 0;
    } else if (*gross_salary <= 300) {
        *tax = *gross_salary * 0.20;
    } else {
        *tax = *gross_salary * 0.28;
    }
}

void calculate_medication_insurance(float *gross_salary, float *med_insurance) {
    *med_insurance = *gross_salary * 0.05;
}

void calculate_maternity_leave(float *gross_salary, float *maternity) {
    *maternity = *gross_salary * 0.003;
}

void calculate_social_security(float *gross_salary, float *social_security) {
    *social_security = *gross_salary * 0.03;
}

void calculate_net_salary(float gross_salary, float *net_salary, char onLeave) {
    float tax, med_insurance, maternity = 0, social_security;
    
    calculate_tax(&gross_salary, &tax);
    calculate_medication_insurance(&gross_salary, &med_insurance);
    
    
    if (onLeave == 'y' || onLeave == 'Y') {
        calculate_maternity_leave(&gross_salary, &maternity);
    }
    
    calculate_social_security(&gross_salary, &social_security);
    
    *net_salary = gross_salary - (tax + med_insurance + maternity + social_security);
}

int main() {
    float gross_salary, net_salary;
    char onleave;
    
    printf("Enter the gross salary: ");
    scanf("%f", &gross_salary);
    
   
    while (getchar() != '\n');
    
    printf("On maternity leave? Enter 'y' for yes, any other key for no: ");
    onleave = getchar();
    
    calculate_net_salary(gross_salary, &net_salary, onleave);
    
    printf("Net Salary: %.2f\n", net_salary);
    
    return 0;
}