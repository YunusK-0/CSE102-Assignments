#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct table
{
	char **field;
	char **type;
	bool *isNull;
	bool *isKey;
	char table_name[50]; // table nameler burada tutuluyor.
	int num_of_field; // number of the fields .
} table;

typedef struct tables
{
	table *t;
	struct tables *next;
} tables;

typedef struct database
{
	tables *tList;
	int n;
	char *name;
} database;
/*
create database komutu database oluşturuyor.
insert komutu yeni bir table oluşturuyor.
show komutu ise spesifik bir tableyi bulup gösteriyor.
*/

database* create_database(char *name);
void show_table(database* d);
void desc_table(database *d,table *t);
void insert_table(database *d,table *t);
void remove_table(database *d,char *name);
//void insert_key(database *d, table *t,)

int main()
{
	char file_name[20];
	char user_command[100];
	database * all_data; // bütün dataların olduğu struct burada.
	int i;
	int times = 0;
	char c;
	do
	{
	
		printf("Please enter operation (in order to see the command please enter\n");
		scanf("%[^\n]%*c",user_command);
		if(strcmp(user_command,"create database") == 0)
		{
			printf("Please enter database name\n");
			scanf("%[^\n]%*c",file_name);
			all_data = create_database(file_name);
		}
		else if(strcmp(user_command,"insert") == 0)
		{
			insert_table(all_data,all_data->tList->t);
			while((c=getchar()) != '\n');
		}
		else if(strcmp(user_command,"show") == 0)
		{
			show_table(all_data);
			while((c=getchar()) != '\n');
		}

	}while(strcmp(user_command,"-999") !=0 ); // bitirme komutudur.
}


database * create_database(char *name)
{ // program başlangıç aşamasında create database komutu ile yer açıyor.
	database *db =(database*)calloc(1,sizeof(database));
	if(db != NULL)
	{
		db->tList = (tables*)calloc(1,sizeof(tables));
		db->tList->t = (table*)calloc(1,sizeof(table));
		db->tList->next = NULL;
		return db;
	}
}
void insert_table(database *d,table *t)
{
	int i;
	char c;
	tables *temp = d->tList;
	while(temp->next != NULL)// en sonuna kadar ilerliyor.
		temp = temp->next;// en sonuna kadar ilerliyor.
	printf("enter how many field do you wanna have?\n");
	//while((c=getchar()) != '\n');
	scanf("%d",&temp->t->num_of_field);
	//printf("\n\ndsfsdf\n\n");
	temp->t->isNull= (bool *)calloc(temp->t->num_of_field,sizeof(bool));
	temp->t->field = (char **)calloc(temp->t->num_of_field,sizeof(char*));
	temp->t->type = (char **)calloc(temp->t->num_of_field,sizeof(char*));
	for(i =0;i<temp->t->num_of_field;i++)
	{
		temp->t->field[i] = (char *)calloc(50,sizeof(char));
		temp->t->type[i] = (char *)calloc(50,sizeof(char));
	}
	printf("Enter name of the table\n");
	scanf("%s",temp->t->table_name);
	for(i = 0;i< temp->t->num_of_field; i++)
	{
		temp->t->isNull[i] = true;
		printf("Enter %d. field\n",i+1);
		scanf("%s",temp->t->field[i]);
		printf("Enter %d. type of the field\n",i+1);
		scanf("%s",temp->t->type[i]);
		//printf("%s ---- %s\n",temp->t->field[i],temp->t->type[i]);
	}
	temp->next = (tables*)calloc(1,sizeof(tables)); // bir sonraki input için yeni yer açıyor.
	temp = temp->next; // bir sonraki input için yeni yer açıyor.
	temp->t = (table*)calloc(1,sizeof(table)); // bir sonraki input için yeni yer açıyor.
	temp->next = NULL; // bir sonraki input için yeni yer açıyor.
}
void show_table(database* d)
{
	database *cp;
	cp = d;
	char input[50];
	printf("enter the name of the table\n");
	scanf("%s",input);
	while(cp != NULL)
	{
		if(strcmp(cp->tList->t->table_name,input) == 0) // gelen inputu arıyor ve printliyor.
		{
			printf("---------------------------------\n");
			printf("|Field            || Type                ||NULL        || KEY  ||\n");
			for(int i = 0;i< d->tList->t->num_of_field;i++)
				printf("|%s|%s|YES|      \n",d->tList->t->field[i],d->tList->t->type[i]);
			break;
		}
		else
			cp->tList = cp->tList->next;
	}
}
