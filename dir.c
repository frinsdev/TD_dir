#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
struct phoneBook{
   int id_num;
   char name[20];
   int phone_number;
} phoneB;

struct EnglishDictionary {
   int id_num;
   char terms[50];
   char definitions[200];
} engD;

// Global variables
int ID_PD = 1;
int ID_ED = 1;
char *name_search;

// User defined functions declaration
void phoneDirectory();
void englishDictionary();

//Phone directory declaration
void addnewPD();
void addnewPDSuccess();
void viewAll_PD();
void deleteData_PD();
int id_available_PD();
int isEmpty_PD();
void search_PD();

// English dictionary declaration
void addnewED();
void addnewEDSuccess();
void viewAll_ED();
void deleteData_ED();
int id_available_ED();
int isEmpty_ED();
void search_ED();

void main() {
   int choice;
   system("clear");
   printf("Welcome to directory\n");
   printf("\nPlease choose: \n");
   printf("\n[1]: Telephone Directory\n[2]: English Dictionary\n[3]: Exit\n");
   printf("\nChoose: ");
   scanf("%d", &choice);
   
   if(choice == 1) {
      return phoneDirectory();
   }
   else if(choice == 2) {
      return englishDictionary();
   }
   else if(choice == 3) {
      system("clear");
      printf("Thank youc come again!\n");
   }else{
      return main();
   }
}

void phoneDirectory() {
   int choice, empty;

   system("clear");
   // Generate a file for the data, this is important for isEmpty_PD function
   system("touch Phonebook");
   printf("Welcome to Phone Directory!\n\n");  
   printf("MENU: \n[1]: Add\n[2]: Delete\n[3]: Search\n[4]: View all\n[5]: Back to Menu\n[6]: Exit Application\n\nChoose: ");
   scanf("%d", &choice);

   if(choice == 1) {
      return addnewPD();
   }
   else if(choice == 2) {
      return deleteData_PD();
   }
   else if(choice == 3) {
      return search_PD();
   }
   else if(choice == 4) {
      empty = isEmpty_PD();

      system("clear");
      if(empty == 0) {
         printf("No data available!\n");
         printf("\nOption:\n[1]: Add new\n[2]: Back to menu\n\nChoose: ");
         scanf("%d", &choice);
         if(choice == 1) {
            return addnewPD();
         }
         else if(choice == 2) {
            return phoneDirectory();
         }else{
            return phoneDirectory();
         }
      }else{
         return viewAll_PD();
      }
   }
   else if(choice == 5) {
      return main();
   }
   else if(choice == 6) {
      system("clear");

      // This will remove the file and data when the program exit
      system("rm Phonebook Temp_phonebook Dictionary Temp_dictionary");
      system("clear");
      printf("Thank you, please come again!\n");
   }
}

// English dictionary
void englishDictionary() {
   int choice, empty;

   system("clear");  
   // Generate a file for the data, this is important for isEmpty_PD function
   system("touch Dictionary");
   printf("Welcome to English Dictionary!\n\n");  
   printf("MENU: \n[1]: Add\n[2]: Delete\n[3]: Search\n[4]: View all\n[5]: Back to Menu\n[6]: Exit Application\n\nChoose: ");
   scanf("%d", &choice);

   if(choice == 1) {
      return addnewED();
   }
   else if(choice == 2) {
      return deleteData_ED();
   }
   else if(choice == 3) {
      return search_ED();
   }
   else if(choice == 4) {
      empty = isEmpty_ED();
      system("clear");
      if(empty == 0) {
         printf("No data available!\n");
         printf("\nOption:\n[1]: Add new\n[2]: Back to menu\n\nChoose: ");
         scanf("%d", &choice);
         if(choice == 1) {
            return addnewED();
         }
         else if(choice == 2) {
            return englishDictionary();
         }else{
            return englishDictionary();
         }
      }else{
         return viewAll_ED();
      }
   }
   else if(choice == 5) {
      return main();
   }
   else if(choice == 6) {
      system("clear");

      // This will remove the file and data when the program exit
      system("rm Phonebook Temp_phonebook Dictionary Temp_dictionary");
      system("clear");
      printf("Thank you, please come again!\n");
   }
}

// Phone Directory options

// Add new
void addnewPD() {
   int choice, emp;

   system("clear");
   printf("Add new number to directory!\n\n");
   printf("Option: \n[1]: Add new\n[2]: Back to menu\n\nChoose: ");
   scanf("%d", &choice);

      if(choice == 1) {
         FILE *fp;
         fp = fopen("Phonebook", "a");
         
         system("clear");
         printf("Add new: \n\n");
         phoneB.id_num = ID_PD;
         ID_PD = ID_PD + 1;
         printf("Name: ");
         scanf(" %[^\n]s", phoneB.name);
         printf("Tel No.: ");
         scanf("%d", &phoneB.phone_number);
         fwrite(&phoneB, sizeof(phoneB), 1, fp);
         fclose(fp);

         return addnewPDSuccess();
      }
      else if(choice == 2) {
         return phoneDirectory();
      }else{
         return addnewPD();
      }
}
void addnewPDSuccess() {
   int choice, name_var;

   system("clear");
   printf("Data successfully added!\n\n");
   printf("Add new number to directory!\n\n");
   printf("Option: \n[1]: Add new\n[2]: Back to menu\n\nChoose: ");
   scanf("%d", &choice);

      if(choice == 1) {
         FILE *fp;
         fp = fopen("Phonebook", "a");

         system("clear");
         printf("Add new: \n\n");
         phoneB.id_num = ID_PD;
         ID_PD = ID_PD + 1;
         printf("Name: ");
         scanf(" %[^\n]s", phoneB.name);
         printf("Tel No.: ");
         scanf("%d", &phoneB.phone_number);
         fwrite(&phoneB, sizeof(phoneB), 1, fp);
         fclose(fp);

         return addnewPDSuccess();
      }
      else if(choice == 2) {
         return phoneDirectory();
      }else{
         return addnewPD();
      }
}

// View All
void viewAll_PD() {
   int choice, empty;

   FILE *fp1;
   fp1 = fopen("Phonebook", "r");

   system("clear");
   empty = isEmpty_PD();
   printf("List of saved numbers: \n\n");
   if(empty == 0) {
      printf("No data available!\n");
   }
   while(fread(&phoneB, sizeof(phoneB), 1, fp1)) {
      printf("ID: %d \nName: %s\nTel no.: %d\n\n", phoneB.id_num, phoneB.name, phoneB.phone_number);
   }
   printf("\n[1]: Add New\n[2]: Delete\n[3]: Back\n\nChoose: ");
      scanf("%d", &choice);

      if(choice == 1) {
         return addnewPD();
      }
      else if(choice == 2) {
         return deleteData_PD();
      }
      else if(choice == 3) {
         return phoneDirectory();
      }else{
         return viewAll_PD();
      }
   fclose(fp1);
}

//Delete
void deleteData_PD() {
   FILE *fpo;
   FILE *fpt;
   FILE *fp1;
   fp1 = fopen("Phonebook", "r");
   int r, s, choose;

   system("clear");
   printf("List of saved numbers: \n\n");
   while(fread(&phoneB, sizeof(phoneB), 1, fp1))
   printf("ID: %d \nName: %s\nTel no.: %d\n\n", phoneB.id_num, phoneB.name, phoneB.phone_number);
   fclose(fp1);

   printf("Note: Input the ID of the data that you want to delete.\n\nID: ");
   scanf("%d", &r);

   if(id_available_PD(r) == 0) {
      system("clear");

      printf("No ID %d found on the directory!\n\n", r);
      printf("Option:\n[1]: Delete\n[2]: Back to menu\n\nChoose: ");
      scanf("%d", &choose);

      if(choose == 1) {
         return deleteData_PD();
      }
      else if(choose == 2) {
         return phoneDirectory();
      }else{
         return deleteData_PD();
      }
   }else{
      fpo = fopen("Phonebook", "r");
      fpt = fopen("Temp_phonebook", "w");
      while(fread(&phoneB, sizeof(phoneB), 1, fpo)) {
         s = phoneB.id_num;
         if(s != r) {
            fwrite(&phoneB, sizeof(phoneB), 1, fpt);
         }
      }
      fclose(fpo);
      fclose(fpt);
      fpo = fopen("Phonebook", "w");
      fpt = fopen("Temp_phonebook", "r");
      while(fread(&phoneB, sizeof(phoneB), 1, fpt)) {
         fwrite(&phoneB, sizeof(phoneB), 1, fpo);
      }
   }
   fclose(fpo);
   fclose(fpt);

   system("clear");
   printf("Deleted successfuly!\n\n");

   printf("Option:\n[1]: Delete new data\n[2]: View all\n[3]: Back to menu\n\nChoose: ");
   scanf("%d", &choose);

   if(choose == 1) {
      return deleteData_PD();
   }
   else if(choose == 2) {
      return viewAll_PD();
   }
   else if(choose == 3) {
      return phoneDirectory();
   }
   else{
      return deleteData_PD();
   }
}

// If ID available
int id_available_PD(int id_no) {
   FILE *fp;
   int c = 0;
   fp = fopen("Phonebook", "r");

   while(!feof(fp)) {
      fread(&phoneB, sizeof(phoneB), 1, fp);

      if(id_no == phoneB.id_num) {
         fclose(fp);
         return 1;
      }
   }
   fclose(fp);
   return 0;
}

int isEmpty_PD() {
   int c = 0;
   FILE *fp;
   fp = fopen("Phonebook", "r");
   while(fread(&phoneB, sizeof(phoneB), 1, fp)) {
      c = 1;
   }
   fclose(fp);
   return c;
}

// Search
void search_PD() {
   FILE *fp2;
   char search_data_char;
   int id_search, search_data, isAvailable, name_av, choose;

   system("clear");
   printf("Search by:\n[1]: ID\n[2]: Name\n[3]: Back to menu\n\nChoose: ");
   scanf("%d", &choose);

   // ID search
   if(choose == 1) {
      system("clear");
      printf("Note: Input ID you want to search!\n\nID: ");
      scanf("%d", &id_search);

      isAvailable = id_available_PD(id_search);

      system("clear");
      printf("Result:\n");

      if(isAvailable == 0) {
         printf("No ID %d available!\n", id_search);
      }else{
         fp2 = fopen("Phonebook", "r");

         while(fread(&phoneB, sizeof(phoneB), 1, fp2)) {
            search_data = phoneB.id_num;
            if(search_data == id_search) {
               printf("\nID: %d\nName: %s\nTel no. %d", phoneB.id_num, phoneB.name, phoneB.phone_number);
            }
         }
         fclose(fp2);
      }
      printf("\n\nOption: \n[1]: Search again\n[2]: Back to menu\n\nChoose: ");
      scanf("%d", &choose);

      if(choose == 1) {
         return search_PD();
      }
      else if(choose == 2) {
         return phoneDirectory();
      }else{
         return search_PD();
      }
   }
   // Name search
   else if(choose == 2) {
      int flag = 0;
      FILE *fp;
      fp=fopen("Phonebook","r");
      char name[50], *result_s;

      system("clear");
      printf("Note: Input Name you want to search!\n\nName:");
      scanf(" %[^\n]s", name);

      while(fread(&phoneB, sizeof(phoneB), 1, fp) != 0) {
         if(strcmp(name, phoneB.name) == 0) {
            system("clear");
            printf("Name %s found!\n", name);
            result_s = phoneB.name;
            if(strcmp(result_s, name) == 0) {
               printf("\nID: %d\nName: %s\nTel no.: %d", phoneB.id_num, phoneB.name, phoneB.phone_number);
            }
            flag = 1;
         }
      }
      if(flag == 0) {
         system("clear");
         printf("Name %s not found!", name);
      }
      printf("\n\nOption: \n[1]: Search again\n[2]: Back to menu\n\nChoose: ");
      scanf("%d", &choose);

      if(choose == 1) {
         return search_PD();
      }
      else if(choose == 2) {
         return phoneDirectory();
      }else{
         return search_PD();
      }
   }
   else if(choose == 3) {
      return phoneDirectory();
   }else{
      return search_PD();
   }
}

// English dictionary options

// Add new
void addnewED() {
   int choice;

   system("clear");
   printf("Add new term to dictionary!\n\n");
   printf("Option: \n[1]: Add new term\n[2]: Back to menu\n\nChoose: ");
   scanf("%d", &choice);

      if(choice == 1) {
         FILE *fp;
         fp = fopen("Dictionary", "a");
         
         system("clear");
         printf("Add new: \n\n");
         engD.id_num = ID_ED;
         ID_ED = ID_ED + 1;
         printf("Term: ");
         scanf(" %[^\n]s", engD.terms);
         printf("Definition: ");
         scanf(" %[^\n]s", engD.definitions);
         fwrite(&engD, sizeof(engD), 1, fp);
         fclose(fp);

         return addnewEDSuccess();
      }
      else if(choice == 2) {
         return englishDictionary();
      }else{
         return addnewED();
      }
}
void addnewEDSuccess() {
   int choice;

   system("clear");
   printf("Data successfully added!\n\n");
   printf("Add new term to dictionary!\n\n");
   printf("Option: \n[1]: Add new term\n[2]: Back to menu\n\nChoose: ");
   scanf("%d", &choice);

      if(choice == 1) {
         FILE *fp;
         fp = fopen("Dictionary", "a");

         system("clear");
         printf("Add new: \n\n");
         engD.id_num = ID_ED;
         ID_ED = ID_ED + 1;
         printf("Term: ");
         scanf(" %[^\n]s", engD.terms);
         printf("Definition: ");
         scanf(" %[^\n]s", engD.definitions);
         fwrite(&engD, sizeof(engD), 1, fp);
         fclose(fp);

         return addnewEDSuccess();
      }
      else if(choice == 2) {
         return englishDictionary();
      }else{
         return addnewED();
      }
}

// View All
void viewAll_ED() {
   int choice, empty;

   FILE *fp1;
   fp1 = fopen("Dictionary", "r");

   system("clear");
   empty = isEmpty_ED();
   printf("List of saved Terms: \n\n");
   if(empty == 0) {
      printf("No data available!\n");
   }
   while(fread(&engD, sizeof(engD), 1, fp1)) {
      printf("ID: %d \nTerm: %s\nDefinition: %s\n\n", engD.id_num, engD.terms, engD.definitions);
   }
   printf("\n[1]: Add New term\n[2]: Delete\n[3]: Back\n\nChoose: ");
      scanf("%d", &choice);

      if(choice == 1) {
         return addnewED();
      }
      else if(choice == 2) {
         return deleteData_ED();
      }
      else if(choice == 3) {
         return englishDictionary();
      }else{
         return viewAll_ED();
      }
   fclose(fp1);
}

//Delete
void deleteData_ED() {
   FILE *fpo;
   FILE *fpt;
   FILE *fp1;
   fp1 = fopen("Dictionary", "r");
   int r, s, choose;

   system("clear");
   printf("List of saved terms: \n\n");
   while(fread(&engD, sizeof(engD), 1, fp1))
   printf("ID: %d \nTerm: %s\nDefinition: %s\n\n", engD.id_num, engD.terms, engD.definitions);
   fclose(fp1);

   printf("Note: Input the ID of the data that you want to delete.\n\nID: ");
   scanf("%d", &r);

   if(id_available_ED(r) == 0) {
      system("clear");

      printf("No ID %d found on the dictionary!\n\n", r);
      printf("Option:\n[1]: Delete\n[2]: Back to menu\n\nChoose: ");
      scanf("%d", &choose);

      if(choose == 1) {
         return deleteData_ED();
      }
      else if(choose == 2) {
         return englishDictionary();
      }else{
         return deleteData_ED();
      }
   }else{
      fpo = fopen("Dictionary", "r");
      fpt = fopen("Temp_dictionary", "w");
      while(fread(&engD, sizeof(engD), 1, fpo)) {
         s = engD.id_num;
         if(s != r) {
            fwrite(&engD, sizeof(engD), 1, fpt);
         }
      }
      fclose(fpo);
      fclose(fpt);
      fpo = fopen("Dictionary", "w");
      fpt = fopen("Temp_dictionary", "r");
      while(fread(&engD, sizeof(engD), 1, fpt)) {
         fwrite(&engD, sizeof(engD), 1, fpo);
      }
   }
   fclose(fpo);
   fclose(fpt);

   system("clear");
   printf("Deleted successfuly!\n\n");

   printf("Option:\n[1]: Delete new data\n[2]: View all\n[3]: Back to menu\n\nChoose: ");
   scanf("%d", &choose);

   if(choose == 1) {
      return deleteData_ED();
   }
   else if(choose == 2) {
      return viewAll_ED();
   }
   else if(choose == 3) {
      return englishDictionary();
   }
   else{
      return deleteData_ED();
   }
}

// If ID available
int id_available_ED(int id_no) {
   FILE *fp;
   int c = 0;
   fp = fopen("Dictionary", "r");

   while(!feof(fp)) {
      fread(&engD, sizeof(engD), 1, fp);
      if(id_no == engD.id_num) {
         fclose(fp);
         return 1;
      }
   }
   fclose(fp);
   return 0;
}
int isEmpty_ED() {
   int c = 0;
   FILE *fp;
   fp = fopen("Dictionary", "r");
   while(fread(&engD, sizeof(engD), 1, fp)) {
      c = 1;
   }
   fclose(fp);
   return c;
}

// Search
void search_ED() {
   FILE *fp2;
   char search_data_char;
   int id_search, search_data, isAvailable, name_av, choose;

   system("clear");
   printf("Search by:\n[1]: ID\n[2]: Term\n[3]: Back to menu\n\nChoose: ");
   scanf("%d", &choose);

   // ID search
   if(choose == 1) {
      system("clear");
      printf("Note: Input ID you want to search!\n\nID: ");
      scanf("%d", &id_search);

      isAvailable = id_available_ED(id_search);

      system("clear");
      printf("Result:\n");

      if(isAvailable == 0) {
         printf("No ID %d available!\n", id_search);
      }else{
         fp2 = fopen("Dictionary", "r");

         while(fread(&engD, sizeof(engD), 1, fp2)) {
            search_data = engD.id_num;
            if(search_data == id_search) {
               printf("\nID: %d\nTerm: %s\nDefinition: %s", engD.id_num, engD.terms, engD.definitions);
            }
         }
         fclose(fp2);
      }
      printf("\n\nOption: \n[1]: Search again\n[2]: Back to menu\n\nChoose: ");
      scanf("%d", &choose);

      if(choose == 1) {
         return search_ED();
      }
      else if(choose == 2) {
         return englishDictionary();
      }else{
         return search_ED();
      }
   }
   // Name search
   else if(choose == 2) {
      int flag = 0;
      FILE *fp;
      fp=fopen("Dictionary","r");
      char term[50], *result_s;

      system("clear");
      printf("Note: Input Term you want to search!\n\nTerm:");
      scanf(" %[^\n]s", term);

      while(fread(&engD, sizeof(engD), 1, fp) != 0) {
         if(strcmp(term, engD.terms) == 0) {
            system("clear");
            printf("Term %s found!\n", term);
            result_s = engD.terms;
            if(strcmp(result_s, term) == 0) {
               printf("\nID: %d\nTerm: %s\nDefinition: %s", engD.id_num, engD.terms, engD.definitions);
            }
            flag = 1;
         }
      }
      if(flag == 0) {
         system("clear");
         printf("Term %s not found!", term);
      }

      printf("\n\nOption: \n[1]: Search again\n[2]: Back to menu\n\nChoose: ");
      scanf("%d", &choose);

      if(choose == 1) {
         return search_ED();
      }
      else if(choose == 2) {
         return englishDictionary();
      }else{
         return search_ED();
      }
   }
   else if(choose == 3) {
      return englishDictionary();
   }else{
      return search_ED();
   }
}