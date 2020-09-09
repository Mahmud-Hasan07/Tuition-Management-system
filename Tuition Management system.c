#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct TeacherListing{
 char name[40];
 char place[40];
 char subject[50];
 char qualification[50];
 int salary;
 int experience_year;
 char phone[50];
};




int main(){

    system("cls");
    header();
    printf("\n\tUser Login\n\t********************\n");
    printf("\tEnter Your Password:  ");
    switch(loginpanel()){
        case '1':
            teacherlist();
            break;
        case '2':
            studentlist();
            break;
        default:
            system("taskkill/IM cb_console_runner.exe");
        }

    return 0;
}

int header(){
    printf("\n*******Tuition Management System*******\n\n");
    return 1;
}

int loginpanel(){
    return getch();
}



void teacherlist(){
    system("cls");
    header();
    printf("\tTeachers' Panel\n\t********************\n\n");
    printf("\t1. View List of Teachers\n");
    printf("\t2. Add Teacher\n");
    printf("\t3. Edit Teacher\n");
    printf("\t4. Delete Teacher\n");
    printf("\t5. Return to Main Menu\n");
    printf("\t6. Exit!\n");
    printf("\n\tSelect Your Option:  ");
    switch(loginpanel()){
        case '1':
            view();
            break;
        case '2':
            add();
            break;
        case '3':

            printf("Under Work!");
            return teacherlist();
            break;
        case '4':
            delete();
            break;
        case '5':
            main();
            break;
        case '6':
        default:
            system("taskkill/IM cb_console_runner.exe");
        }

}

void view(){
    system("cls");
    header();
    printf("\tViewing List of Teachers!\n\t********************\n\n");

    struct TeacherListing add1;
    FILE *file;
    file = fopen("teachers.dat", "r");
    printf("****************************************\n");
    while(fread(&add1, sizeof(add1), 1, file)==1){
        printf("\tName: %s\n", add1.name);
        printf("\tPlace: %s\n", add1.place);
        printf("\tSubject: %s\n", add1.subject);
        printf("\tQualification: %s\n", add1.qualification);
        printf("\tSalary: %d\n", add1.salary);
        printf("\tEx.year: %d\n", add1.experience_year);
        printf("\tPhone: %s\n", add1.phone);
        printf("****************************************\n");
    }
    fclose(file);
    printf("Return press any key ");
        char ch = getch();
        if(ch){
            return teacherlist();
        }
}


void add(){
    system("cls");
    header();
    printf("\tAdd Teachers!\n\t********************\n\n");

    struct TeacherListing add1;
    FILE *file;
    file = fopen("teachers.dat", "a");

    while(1){
        printf("Enter Name: ");
        scanf("%s", &add1.name);
        printf("Enter Place: ");
        scanf("%s", &add1.place);
        printf("Enter Subject: ");
        scanf("%s", &add1.subject);
        printf("Enter Qualification: ");
        scanf("%s", &add1.qualification);
        printf("Enter Salary: ");
        scanf("%d", &add1.salary);
        printf("Enter Experience Year: ");
        scanf("%d", &add1.experience_year);
        printf("Enter Phone: ");
        scanf("%s", &add1.phone);
        fwrite(&add1,sizeof(add1),1,file);
        printf("Continue (Y/N) ");
        char ch = getch();
        if(ch == 'N' || ch == 'n'){
            fclose(file);
            return teacherlist();
        }
        printf("\n");

    }

}


void delete(){
    struct TeacherListing add1;
    FILE *fs;
    FILE *temp,*t1;

    int a=1;
    char chkphone[50],c='y';
    while(c=='y'||c=='Y'){
        system("cls");
        header();
        printf("\tDeleting Teachers!\n\t********************\n");

        int a=1;
        printf("\n\tEnter Contact of Teacher to Delete: ");
        fflush(stdin);
        scanf("%s",chkphone);
        fs=fopen("teacher.dat","rb");
        temp=fopen("tempfile.dat","wb");
        while (fread(&add1,sizeof(add1),1,fs)==1){
            if (strcmp(add1.phone,chkphone)==0){
                a=0;
                continue;
            }
            else{
                fwrite(&add1,sizeof(add1),1,temp);
            }
        }

        if(a==1)
            printf("\n\tError! Record Not Found");
        else
            printf("\n\tRecord Successfully Deleted");
        printf("\n");

        fflush(stdin);

        fclose(fs);
        fclose(temp);
        system("del teachers.dat");
        system("ren tempfile.dat, teachers.dat");
        printf("\n\tContinue(Y)\tClose(N)\n");
        char re = getch();
        if(re == 'n' || re == 'N'){
            return teacherlist();
        }
        else{
            fflush(stdin);
            c=getch();
        }
    }
    getch();
}




void studentlist(){
    struct TeacherListing add1;
    FILE *fs;
    char chksub[50],c='y';
    while(c=='y'||c=='Y'){
        system("cls");
        header();
        printf("\tStudents' Panel\n\t********************\n");
        int a=1;
        printf("\n\tEnter Name of Subject: ");
        fflush(stdin);
        scanf("%s",chksub);
        printf("\n");
        fs=fopen("teachers.dat","r");
        while (fread(&add1,sizeof(add1),1,fs)==1){
            if (strcmp(add1.subject,chksub)==0){
                printf("****************************************\n");
                printf("\tName: %s\n", add1.name);
                printf("\tPlace: %s\n", add1.place);
                printf("\tSubject: %s\n", add1.subject);
                printf("\tQualification: %s\n", add1.qualification);
                printf("\tSalary: %d\n", add1.salary);
                printf("\tEx.year: %d\n", add1.experience_year);
                printf("\tPhone: %s\n", add1.phone);
            }
        }
        fclose(fs);
        printf("****************************************\n");
        printf("\n\tContinue(Y)\tClose(N)\n");
        char re = getch();
        if(re == 'n' || re == 'N'){
            return main();
        }
        else{
            fflush(stdin);
            c=getch();
        }
    }
    getch();
}
