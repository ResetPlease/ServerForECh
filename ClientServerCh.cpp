#include <mysql.h>
#include <stdio.h>
#include "ClientServerCh.h" //rename Client.h
ClientServerCh::ClientServerCh(int usrip, int id_u){
        con = mysql_init(NULL);
        CreateConnection();
        CreateQuery(id_u, (char*)"test");
        MYSQL_ROW row;
        ipaddres = usrip;
        row = mysql_fetch_row(result);
        printf("%s\t%s\n",row[0], row[1]);
        getDestruct();
}

void ClientServerCh::getDestruct(){
        mysql_free_result(result);
        mysql_close(con);
}

void ClientServerCh::CreateConnection(){
        if( mysql_real_connect(con,"localhost", "setevoy", "p@ssw0rd", "testdb", 0, NULL, 0) == NULL)
        {
                printf("%s\n", mysql_error(con));
                mysql_close(con);
                return;
        }
}

void ClientServerCh::CreateQuery(char *foo, char field[]){
        char query[100];
        sprintf(query, "SELECT %s FROM %s", foo, field);
        if(mysql_query(con, query)) {
                printf("%s\n", mysql_error(con));
                mysql_close(con);
                return;
        }
        result = mysql_store_result(con);
}

void ClientServerCh::CreateQuery(int dbobj, char field[]){
        char query[100];
        sprintf(query, "SELECT %d FROM %s", dbobj, field);
        if(mysql_query(con, "SELECT * FROM test")) {
                printf("%s\n", mysql_error(con));
                mysql_close(con);
                return;
        }
        result = mysql_store_result(con);
}

ClientServerCh::~ClientServerCh(){
        mysql_free_result(result);
        mysql_close(con);
}
