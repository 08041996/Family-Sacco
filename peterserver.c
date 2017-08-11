#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
 #include <time.h>
 #include <conio.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
 
int main(int argc , char *argv[])
{
    WSADATA wsa;/* Structure for WinSock setup communication */
    SOCKET s , new_socket, file_socket;
    struct sockaddr_in server , client, receiver;
    int c;
    char *message, client_reply[2000], file_con[2000];
	int _size;
	char TheData[256];
	int recv_size;
	size_t nRecv, nWrite;
	FILE *fp;
 
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)/* Load Winsock 2.0 DLL */
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
     
    printf("Initialised.\n");
     
    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
 
    printf("Socket created.\n");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 81 );
     
    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
     
    puts("Bind done");
 
    //Listen to incoming connections
    listen(s , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
     
    c = sizeof(struct sockaddr_in);
     
    while( (new_socket = accept(s , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
    {
        puts("Connection accepted");
         
        //Reply to the client
        message = "WELCOME.... plesase type this commands as they are wrritten in the menu below\n\n";
        send(new_socket , message , strlen(message) , 0);

		fp = fopen("server.txt", "a+");
		if(fp == NULL){
			printf("file not found\n");
			return 1;
		}
		else{
			printf("Created file server.txt\n");
		}
		/* Receive message from client */
		nRecv = recv(new_socket, TheData, 256, 0);
		if(nRecv < 0){
			printf("ERROR reading from the socket",WSAGetLastError());
			break;
		}
		
		if(nRecv == 0){
			break;
		}
		while(nRecv > 0){
			printf("Ok");
			//write details in variable TheData to file represented by pointer fp
			nWrite = fwrite(TheData, sizeof(char), nRecv, fp);
			
			if(nWrite<=0){
				printf("Error writing to file");
			}
			nRecv -= nWrite;
		
		}
    }
     
    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d" , WSAGetLastError());
        return 1;
    }
    closesocket(s);
    WSACleanup();
    return 0;
}
