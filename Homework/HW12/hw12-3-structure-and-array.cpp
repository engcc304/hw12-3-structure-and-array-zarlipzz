/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[100];
    float salary;
    int duration;
};

int main() {
    struct Employee employees[100];
    int employeeCount = 0;

    while (1) {
        char addEmployee;
        printf("Do you want to Enter Employee Information? (y/n): ");
        scanf(" %c", &addEmployee);

        if (addEmployee != 'y') {
            break;
        }

        printf("Employee Name: ");
        scanf("%s", employees[employeeCount].name);
        printf("Salary (Bath/Month): ");
        scanf("%f", &employees[employeeCount].salary);
        printf("Duration (Year): ");
        scanf("%d", &employees[employeeCount].duration);
        
        employeeCount++;
    }

    float totalSalary = 0;
    for (int i = 0; i < employeeCount; i++) {
        totalSalary += employees[i].salary;
    }
    float averageSalary = totalSalary / employeeCount;
    float totalPayment = totalSalary;

    printf("Average of Salary: %.2f Bath\n", averageSalary);
    printf("Payment of every month: %.2f Bath\n", totalPayment);
    printf("----------------------------------------\n");

    struct Employee mostExperiencedEmployee = employees[0];
    for (int i = 1; i < employeeCount; i++) {
        if (employees[i].duration > mostExperiencedEmployee.duration) {
            mostExperiencedEmployee = employees[i];
        }
    }

    printf("** Most duration in this business **\n");
    printf("Name: %s (%d Years)\n", mostExperiencedEmployee.name, mostExperiencedEmployee.duration);
    printf("Salary: %.2f Bath\n", mostExperiencedEmployee.salary);

    return 0;
}
