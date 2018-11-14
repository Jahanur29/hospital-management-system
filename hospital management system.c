
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
//#include<bios.h>

#define RETURNTIME 15

char catagories[][15]={"Orthopedics","Liver","Gastro logy","Neuro","Medicine","Surgery","Gynae","Dental"};
char catagories2[][25]={"Prapairol","Hexisol","Savelon","Bandage","Antibiotic","Antacid","Histacin","B-50 fort"};
void returnfunc(void);
void mainmenu(void);
void addpatient(void);
void patientinformation(void);
//void deletepatient(void);
void medicine(void);
void editmedicine(void);
void searchmedicine(void);
void viewmedicinelist(void);
void doctor(void);
void editdoctor(void);
void viewdoctorlist(void);
void closeapplication(void);
int  getdata();
int  getdata2();
int  getdata3();
int  checkid(int);
int  checkid2(int);
int  checkid3(int);
int t(void);
//void show_mouse(void);
void Password();
//void issuerecord();
//void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char abouthospital;
char password[10]={"t"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};
struct hospital
{
int id;
char stname[20];
char name[20];
char age[20];
char sex[20];
char blood[20];
char phone[20];
char address[80];
char disease[100];
char bed[20];
int count;
//int rackno;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};
struct hospital a;
struct medicine
{
int id;
char stname[40];
char name[40];
int quantity;
float Price;
int count;
int rackno;
char *cat2;
struct meroDate issued;
struct meroDate duedate;
};
struct medicine b;
struct doctor
{
int id;
char stname[40];
char name[40];
int room_no;
char *cat3;
struct meroDate issued;
struct meroDate duedate;
};
struct doctor l;
int main()
{
Password();
getch();
return 0;

}
void mainmenu()
{
//loaderanim();
system("cls");
//    textbackground(13);
int i;
gotoxy(20,3);
printf(">>>>>>>>>>>>>>>>>>>>> MAIN MENU <<<<<<<<<<<<<<<<<<<<<<<<");
//    show_mouse();
//gotoxy(20,5);
//printf("\xDB\xDB\xDB\xDB\xB2 1. Department   ");
gotoxy(20,7);
printf("\xB2\xB2\xB2\xB2\xB6 A. Add Patient");
gotoxy(20,9);
printf("\xB2\xB2\xB2\xB2\xB6 B. Patient Information");
gotoxy(20,11);
printf("\xB2\xB2\xB2\xB2\xB6 C. Medicine entry");
gotoxy(20,13);
printf("\xB2\xB2\xB2\xB2\xB6 D. Edit Medicine list");
gotoxy(20,15);
printf("\xB2\xB2\xB2\xB2\xB6 E. Search Medicine");
gotoxy(20,17);
printf("\xB2\xB2\xB2\xB2\xB6 F. view medicine list");
gotoxy(20,19);
printf("\xB2\xB2\xB2\xB2\xB6 G. Doctor entry");
gotoxy(20,21);
printf("\xB2\xB2\xB2\xB2\xB6 H. Edit doctor list");
gotoxy(20,23);
printf("\xB2\xB2\xB2\xB2\xB6 I. View doctor");
gotoxy(20,25);
printf("\xB2\xB2\xB2\xB2\xB6 J. Close Application");
gotoxy(20,27);
printf("===================================================");
gotoxy(20,29);
t();
gotoxy(20,31);
printf("Enter your choice:");
switch(getch())
{
case 'A':
addpatient();
break;
case 'B':
patientinformation();
break;
case 'C':
medicine();
break;
case 'D':
editmedicine();
break;
case 'E':
searchmedicine();
break;
case 'F':
viewmedicinelist();
break;
case 'G':
doctor();
break;
case 'H':
editdoctor();
break;
case 'I':
viewdoctorlist();
break;
case 'J':
{
system("cls");
gotoxy(16,3);
printf("\tHospital Management System");
gotoxy(16,4);
printf("\tMini Project in C code");
gotoxy(16,6);
printf("\tCreated by group 6 ");
gotoxy(16,8);
printf("===========Our group members: ==========");
gotoxy(16,10);
printf("\t1. Shardar Md. Al-Amin.");
gotoxy(16,12);
printf("\t2. Jahanur Alam.");
gotoxy(16,14);
printf("\t3. Taushi Alam Tazni.");
gotoxy(16,16);
printf("\t4. Sumaiya Bari.");
gotoxy(10,19);
printf("Exiting in 3 second...........>");
//flushall();
Sleep(3000);
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}
void addpatient(void)    //funtion that add books
{
system("cls");
int i;
gotoxy(20,5);
printf("\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2 Select Catagories \xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB6 1. Orthopedics");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB6 2. Liver");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB6 3. Gastro logy");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB6 4. Neuro");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB6 5. Medicine");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB6 6. Surgery");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB6 7. Gynae");
gotoxy(20,21);
printf("\xDB\xDB\xDB\xDB\xB6 8. Dental");
gotoxy(20,23);
printf("\xDB\xDB\xDB\xDB\xB6 9. Back to main menu");
gotoxy(20,25);
printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
gotoxy(20,27);
printf("Enter your choice:");
scanf("%d",&s);
if(s==9)

mainmenu() ;
system("cls");
fp=fopen("Bibek.dat","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,17);
printf("The record is sucessfully saved");
gotoxy(21,18);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
//department();
addpatient();
}
} //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

void patientinformation()
{
system("cls");
int d;
printf("     >>>>>>>>>>>>>>>>>>>>>>>>>Patient Information<<<<<<<<<<<<<<<<<<<<<<<<<<<");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Search By ID");
gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("Bibek.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("........Search patient By Id........");
gotoxy(20,5);
printf("Enter the Patient id:");
scanf("%d",&d);
gotoxy(20,7);
printf("The Patient is not available");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The patient is available");
gotoxy(20,8);
printf("\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
gotoxy(20,9);
printf("\xB9 ID:%d",a.id);gotoxy(47,9);printf("\xB9");
gotoxy(20,10);
printf("\xB9 Name:%s",a.name);gotoxy(47,10);printf("\xB9");
gotoxy(20,11);
printf("\xB9 Age:%s",a.age);gotoxy(47,11);printf("\xB9");
gotoxy(20,12);
printf("\xB9 Sex:%s ",a.sex);gotoxy(47,12);printf("\xB9");
gotoxy(20,13);
printf("\xB9 Blood group:%s",a.blood);gotoxy(47,13);printf("\xB9");
gotoxy(20,14);
printf("\xB9 Phone no.:%s ",a.phone);gotoxy(47,14);printf("\xB9"); //gotoxy(47,11);printf("\xB9");
gotoxy(20,15);
printf("\xB9 Address:%s",a.address);gotoxy(47,15);printf("\xB9");
gotoxy(20,16);
printf("\xB9 Disease name:%s",a.disease);gotoxy(47,16);printf("\xB9");
gotoxy(20,17);
printf("\xB9 Bed no.:%s",a.bed);gotoxy(47,17);printf("\xB9");
gotoxy(20,18);
printf("============================");
abouthospital='t';
}

}
if(abouthospital!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,9);
printf("\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9");
gotoxy(20,10);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,11);
printf("\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9\xB9");
gotoxy(22,10);printf("\aNo Record Found");
}
gotoxy(20,22);
printf("Try another search?(Y/N)");
if(getch()=='y')
patientinformation();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("####Search Patient By Name####");
gotoxy(20,5);
printf("Enter Patient Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The patient is available");
gotoxy(20,8);
printf("\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Age:%s",a.age);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Sex:%s",a.sex);gotoxy(47,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Blood Group:%s",a.blood);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Phone no.:%s",a.phone);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2 Address:%s",a.address);gotoxy(47,15);printf("\xB2");
gotoxy(20,16);
printf("\xB2 Disease name:%s",a.disease);gotoxy(47,16);printf("\xB2");
gotoxy(20,17);
printf("\xB2 Bed no:%s",a.bed);gotoxy(47,17);printf("\xB2");
gotoxy(20,18);
printf("\xB2 ");gotoxy(47,18);printf("\xB2");
gotoxy(20,19);
printf("\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
d++;
}

}
if(d==0)
{
gotoxy(20,9);
printf("\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
gotoxy(20,10);printf("\xB2");  gotoxy(38,10);printf("\xB2");
gotoxy(20,11);
printf("\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6\xB6");
gotoxy(22,10);printf("\aNo Record Found");
}
gotoxy(20,23);
printf("Try another search?(Y/N)");
if(getch()=='y')
patientinformation();
else
mainmenu();
break;
}
default :
getch();
patientinformation();
}
fclose(fp);
} //8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
void medicine(void)    //funtion that add books
{
system("cls");
int i;
gotoxy(20,5);
printf("\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2 Select Catagories \xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB6 1. Prapairol");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB6 2. Hexisol");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB6 3. Savelon");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB6 4. Bandage");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB6 5. Antibiotic");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB6 6. Antacid");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB6 7. Histacin");
gotoxy(20,21);
printf("\xDB\xDB\xDB\xDB\xB6 8. B-50 fort");
gotoxy(20,23);
printf("\xDB\xDB\xDB\xDB\xB6 9. Back to main menu");
gotoxy(20,26);
printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::");
gotoxy(20,28);
printf("Enter your choice:");
scanf("%d",&s);
if(s==9)

mainmenu() ;
system("cls");
fp=fopen("Amin.dat","ab+");
if(getdata2()==1)
{
b.cat2=catagories2[s-1];
fseek(fp,0,SEEK_END);
fwrite(&b,sizeof(b),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
//department();
medicine();
}
} //zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

void editmedicine()  //edit information about book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("####Edit medicine Section####");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter medicine Id to be edited:");
scanf("%d",&d);
fp=fopen("Amin.dat","rb+");
while(fread(&b,sizeof(b),1,fp)==1)
{
if(checkid2(d)==0)
{
gotoxy(15,7);
printf("The medicine is availble");
gotoxy(15,8);
printf("The medicine ID:%d",b.id);
gotoxy(15,9);
printf("Enter new name:");scanf("%s",b.name);
gotoxy(15,10);
printf("Enter new quantity:");scanf("%d",&b.quantity);
gotoxy(15,11);
printf("Enter new price:");scanf("%f",&b.Price);
gotoxy(15,12);
printf("Enter new rackno:");scanf("%d",&b.rackno);
gotoxy(15,13);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(b),0);
fwrite(&b,sizeof(b),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
gotoxy(15,18);
returnfunc();
}  //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
void searchmedicine()
{
system("cls");
int d;
printf("*****************************Search Medicine*********************************");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Search By ID");
gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("Amin.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Medicine By Id****");
gotoxy(20,5);
printf("Enter the Medicine id:");
scanf("%d",&d);
gotoxy(20,7);
printf("Searching........");
while(fread(&b,sizeof(b),1,fp)==1)
{
if(b.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The Medicine is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",b.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",b.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Qantity:%d ",b.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Price:Rs.%.2f",b.Price);gotoxy(47,13);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Rack No:%d ",b.rackno);gotoxy(47,14);printf("\xB2");
gotoxy(20,14);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
abouthospital='t';
}

}
if(abouthospital!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchmedicine();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("****Search Medicine By Name****");
gotoxy(20,5);
printf("Enter Medicine Name:");
scanf("%s",s);
int d=0;
while(fread(&b,sizeof(b),1,fp)==1)
{
if(strcmp(b.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Medicine is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",b.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",b.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Qantity:%d",b.quantity);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Price:Rs.%.2f",b.Price);gotoxy(47,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Rack No:%d ",b.rackno);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchmedicine();
else
mainmenu();
break;
}
default :
getch();
searchmedicine();
}
fclose(fp);
}  //ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
void viewmedicinelist(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("*********************************Medicine List*****************************");
gotoxy(2,2);
printf(" CATEGORY    ID    Medicine NAME            Quantity   PRICE    Rack-No ");
j=4;
fp=fopen("Amin.dat","rb");
while(fread(&b,sizeof(b),1,fp)==1)
{
gotoxy(3,j);
printf("%s",b.cat2);
gotoxy(16,j);
printf("%d",b.id);
gotoxy(22,j);
printf("%s",b.name);
gotoxy(50,j);
printf("%d",b.quantity);
gotoxy(57,j);
printf("%.2f",b.Price);
gotoxy(69,j);
printf("%d",b.rackno);
printf("\n\n");
j++;
i=i+b.quantity;
}
gotoxy(3,25);
printf("Total Medicine =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}  //bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
void doctor(void)    //funtion that add books
{
system("cls");
int i;
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. Orthopedics");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. Liver");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. Gastro logy");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. Neuro");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. Medicine");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. Surgery");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB2 7. Gynae");
gotoxy(20,21);
printf("\xDB\xDB\xDB\xDB\xB2 8. Dental");
gotoxy(20,23);
printf("\xDB\xDB\xDB\xDB\xB2 9. Back to main menu");
gotoxy(20,25);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,27);
printf("Enter your choice:");
scanf("%d",&s);
if(s==9)

mainmenu() ;
system("cls");
fp=fopen("Tanzima.dat","ab+");
if(getdata3()==1)
{
l.cat3=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&l,sizeof(l),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
doctor();
}
}  //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm


void editdoctor(void)  //edit information about book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("****Edit Doctor Section****");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Doctor Id to be edited:");
scanf("%d",&d);
fp=fopen("Tanzima.dat","rb+");
while(fread(&l,sizeof(l),1,fp)==1)
{
if(checkid3(d)==0)
{
gotoxy(15,7);
printf("The doctor is availble");
gotoxy(15,8);
printf("The doctor ID:%d",l.id);
gotoxy(15,9);
printf("Enter new name:");scanf("%s",l.name);
gotoxy(15,10);
printf("Enter new room no:");scanf("%d",&l.room_no);
gotoxy(15,11);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(l),0);
fwrite(&l,sizeof(l),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
gotoxy(15,18);
returnfunc();
} //kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
void viewdoctorlist()  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("*********************************Doctor List*****************************");
gotoxy(2,2);
printf(" CATEGORY    ID        Doctor NAME                     Room no ");
j=4;
fp=fopen("Tanzima.dat","rb");
while(fread(&l,sizeof(l),1,fp)==1)
{
gotoxy(3,j);
printf("%s",l.cat3);
gotoxy(16,j);
printf("%d",l.id);
gotoxy(26,j);
printf("%s",l.name);
gotoxy(57,j);
printf("%d",l.room_no);
printf("\n\n");
j++;
//i=i+l.quantity;
}
//gotoxy(3,25);
//printf("Total Doctor =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}

void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2");gotoxy(46,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2");gotoxy(46,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2");gotoxy(46,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2");gotoxy(46,15);printf("\xB2");

gotoxy(20,16);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Patient id:\t");
gotoxy(32,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,15);
printf("\aThe  id is already existed\a");
getch();
mainmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Patient Name:");gotoxy(34,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Patient Age:");gotoxy(33,8);
scanf("%s",&a.age);
gotoxy(21,9);
printf("Sex:");gotoxy(25,9);
scanf("%s",&a.sex);
gotoxy(21,10);
printf("Blood Group:");gotoxy(33,10);
scanf("%s",&a.blood);
gotoxy(21,11);
printf("Phone no.:");gotoxy(31,11);
scanf("%s",&a.phone);
gotoxy(21,12);
printf("Address:");gotoxy(29,12);
scanf("%s",&a.address);
gotoxy(21,13);
printf("Disease name:");gotoxy(34,13);
scanf("%s",&a.disease);
gotoxy(21,14);
printf("Bed no:");gotoxy(28,14);
scanf("%s",&a.bed);
return 1;
}  //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int getdata2()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories2[s-1]);
gotoxy(21,6);
printf("Medicine id:\t");
gotoxy(33,6);
scanf("%d",&t);
if(checkid2(t) == 0)
{
gotoxy(21,13);
printf("\aThe  id is already existed\a");
getch();
mainmenu();
return 0;
}
b.id=t;
gotoxy(21,7);
printf("Medicine Name:");gotoxy(35,7);
scanf("%s",b.name);
gotoxy(21,8);
printf("Medicine Quantity:");gotoxy(39,8);
scanf("%d",&b.quantity);
gotoxy(21,9);
printf("Price:");gotoxy(27,9);
scanf("%f",&b.Price);
gotoxy(21,10);
printf("Rackno:");gotoxy(28,10);
scanf("%d",&b.rackno);
return 1;
}
///////////////////////////////////////////////////////////////////////////////////
int getdata3()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Doctor id:\t");
gotoxy(31,6);
scanf("%d",&t);
if(checkid3(t) == 0)
{
gotoxy(21,13);
printf("\aThe  id is already existed\a");
getch();
mainmenu();
return 0;
}
l.id=t;
gotoxy(21,7);
printf("Doctor Name:");gotoxy(33,7);
scanf("%s",l.name);
gotoxy(21,8);
printf("Room no:");gotoxy(29,8);
scanf("%d",&l.room_no);
gotoxy(21,11);
printf("-----------");
return 1;
}

int checkid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}

int checkid2(int t)  //check whether the medicine is exist in library or not
{
rewind(fp);
while(fread(&b,sizeof(b),1,fp)==1)
if(b.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}

int checkid3(int t)  //check whether the medicine is exist in library or not
{
rewind(fp);
while(fread(&l,sizeof(l),1,fp)==1)
if(l.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}

int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}  //ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
/*void show_mouse(void) //show inactive mouse pointer in programme
{
union REGS in,out;
       in.x.ax = 0x1;
       int86(0x33,&in,&out);
}*/
void Password(void) //for password option
{

system("cls");
char d[25]="Enter Password";
char ch,pass[10];
int i=0,j;
//textbackground(WHITE);
//textcolor(RED);
gotoxy(10,4);
for(j=0;j<10;j++)
{
Sleep(50);
printf("><");
}
for(j=0;j<14;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<10;j++)
{
Sleep(50);
printf("><");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
//textcolor(BLINK);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}

