#ifndef CLIENT_H
#define CLIENT_H

#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
class ClientServerCh{
public:
        int id;
        char name[20];
        char login[20];
        char password[20];
        int ipaddres;
        bool status;
        MYSQL *con;
        MYSQL_RES *result;
        ClientServerCh(int usrip, int id_u);
        void getDestruct();
        void CreateConnection();
        void CreateQuery(char foo[], char field[]);
        void CreateQuery(int dbobj, char field[]);
        ~ClientServerCh();
};
#endif
