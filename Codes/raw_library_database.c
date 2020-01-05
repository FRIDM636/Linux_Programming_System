#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include<string.h>


#define MAX_DATA 512
#define MAX_ROWS 100
struct Book{
	int ISDN;
	char author[MAX_DATA];
	char title[MAX_DATA];
};

struct User {
        int id;
        int set;
        int q;
        char name[MAX_DATA];
        char mail[MAX_DATA];
        struct Book book[7];
        
};

struct Database {
	struct User rows[MAX_ROWS];
};

struct Connection{
	FILE * file;
	struct Database *db;
};

void quit(const char * message){
	if(errno)
		perror(message);
	else
		printf("Error: %s\n",message);
	exit(1);
}

void User_print(const struct User * user){
	printf("ID: %d\nNAME: %s\nMAIL: %s\n",user->id, user->name, user->mail);

	printf("Books:\n title:%s\n Author:%s\n ISDN:%d\n",(*(user->book)).title, (*(user->book)).author, (*(user->book)).ISDN);
	
}


void Database_load(const struct Connection *connection){

	if(fread(connection->db, sizeof(struct Database),1,connection->file) != 1)
		quit("Error loading database");
}

struct Connection * Database_open(const char *file_name, const char mode){

		struct Connection * connection = malloc(sizeof(struct Connection));

		if(!connection)
			quit("Memory allocation error for connection");

		connection->db = malloc(sizeof(struct Database));

		if(!connection)
			quit("Memory allocation error for database");

		if(mode == 'c')
			connection->file = fopen(file_name, "w");
		else{
			connection->file = fopen(file_name, "r+");
			if(connection->file)
				Database_load(connection);
			}
		if(!connection->file)
			quit("Error making a connection");

	return connection;
}

void Database_close(struct Connection *connection)
{
    if(connection){
        if(connection->file)
            fclose(connection->file);
        if(connection->db)
            free(connection->db);
        free(connection);
    }
}

void Database_write(struct Connection *connection){
    rewind(connection->file);
    if(fwrite(connection->db, sizeof(struct Database), 1, connection->file) != 1)
        quit("Error writing to database");
    if(fflush(connection->file) == -1)
        quit("Error flushing file");
}

void Database_create(struct Connection *connection){

    int i = 0;
    for(i = 0; i< MAX_ROWS; ++i){
        struct User user = {.id=i, .set = 0};
        connection->db->rows[i] = user;
    }
}

void Database_set(struct Connection *connection, int id, char name[], char mail[], char title[], char author[],int ISDN){
	
	struct User *user = &connection->db->rows[id];
	if(user->set == 1)
		quit("Already set");
	else
		user->set = 1;

	if(!strncpy(user->name, name, MAX_DATA))
		quit("Failed to set name");
	if(!strncpy(user->mail, mail, MAX_DATA))
		quit("Failed to set mail1");
		
	if(!strncpy((*(user->book)).title, title, MAX_DATA))
		quit("Failed to set book title");
	if(!strncpy((*(user->book)).author, author, MAX_DATA))
		quit("Failed to set book author");
	(*(user->book)).ISDN = ISDN;
}

void Database_get(struct Connection * connection, int id){
	
	struct User * user = &connection->db->rows[id];
	if(user->set)
		User_print(user);
	else
		quit("Data doesn\'t exist");
}

void Database_delete(struct Connection * connection, int id){
	
	struct User user = {.id=id, .set=0};
	connection->db->rows[id] = user;
}
	
void Database_list(struct Connection *connection){
		int id = 0;
		struct Database *database = connection->db;
		while(++id < MAX_ROWS)
			if(database->rows[id].set) 
				User_print(&database->rows[id]);
}


int main(int argc, char ** argv)
{
	if(argc < 3)
		quit("Usage app filename action [options]");
	char action = argv[2][0];
	char * file_name = argv[1];
	struct Connection * connection = Database_open(file_name, action);
	int id = 0;
	
	
	if(argc > 3)
		id = atoi(argv[3]);
	if(id >=MAX_ROWS)
		quit("Database is FULL!");
	
	switch(action){
		case 'c':
			Database_create(connection);
			Database_write(connection);
			break;
		case 'g':
			if(argc != 4)
				quit("Need an ID");
			Database_get(connection,id);
			break;
		case 's':
			if(argc != 9)
				quit("Need ID, Name and Mail, book title, author and ISDN  to set");
			Database_set(connection,id,argv[4],argv[5], argv[6], argv[7], atoi(argv[8]));
			Database_write(connection);
			break;
		case 'd':
			if(argc != 4)
				quit("Need ID to delete");
			Database_delete(connection,id);
			Database_write(connection);
			break;
		case 'l':
			Database_list(connection);
			break;
		default:
			quit("Invalid action c: create, s: set, g:get, d: delete, l:list");
			break;
	}
	
	Database_close(connection);

    return 0;
}
