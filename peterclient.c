#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<winsock2.h>
#include<time.h>
#include<conio.h>
#include<string.h>
 
#pragma comment(lib,"ws2_32.lib")
SOCKET s, new_socket;
char*message, server_reply[2000], menu_reply[2000];
char TheData[256];
int recv_size;
int menu_size;
struct sockaddr_in server, client;
int c;
 size_t nRead, nSent;
 FILE *fp;
 
 

 
int main(int argc , char *argv[]){
	
	
    WSADATA wsa;
     
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
     
    printf("Initialised.\n");
	
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
 
    printf("Socket created.\n");
 
server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 81 );
 
    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    puts("Connected");
 
//message = "GET / HTTP/1.1\r\n\r\n";
  //  if( send(s , message , strlen(message) , 0) < 0)
    //{
    //    puts("Send failed");
     //   return 1;
   // }
    //puts("Data Send\n");

	if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }
     
    puts("Reply received\n");
	
 
    
    server_reply[recv_size] = '\0';
    puts(server_reply);
	
	
	char choice[20];
	printf("PLEASE ENTER THE COMMAND AS WRIITEN BELOW...... THANK YOU\n\n");
	printf("Contribution.....\nContribution check.....\nLoan request.......\nLoan staus......\nSubmit Idea.....\n\n");
	printf("Enter your request:");
scanf("%20[^\n]", choice);
	
	if(strcmp(choice,"Contribution")==0){
		printf("-------SUBMIT CONTRIBUTION------\n\n");
		
		char amount[20];
		char firstname[20];
		char lastname[20];
		char date[20];
		
		
		#define FILE_NAME "client.txt"
		FILE* file_pointer; 
file_pointer = fopen("client.txt","w");

printf("ENTER FIRST NAME:\n");
scanf("%s", firstname);

printf("ENTER LAST NAME:\n");
scanf("%s", lastname);

printf("ENTER AMOUNT:\n");
scanf("%s", amount);

printf("ENTER DATE OF CONTRIBUTION:....(yyyy/mm/dd)\n");
scanf("%s", date);

fprintf(file_pointer, "------------CONTRIBUTION------------\n");

fprintf(file_pointer, "ENTER FIRST NAME:\n");
fprintf(file_pointer, "%s\n" , firstname);

fprintf(file_pointer, "ENTER LAST NAME:\n");
fprintf(file_pointer, "%s\n" , lastname);

fprintf(file_pointer, "ENTER AMOUNT:\n");
fprintf(file_pointer, "%s\n" , amount);

fprintf(file_pointer, "ENTER DATE OF CONTRIBUTION:....(yyyy/mm/dd)\n");
fprintf(file_pointer, "%s\n" , date);

fclose(file_pointer);
		
		
	printf("Sending file to server.............\n");
	printf("FILE SENT.....");
	file_pointer = fopen("client.txt", "r");
	if(file_pointer == NULL){
		printf("The file you want to send was not found");
		return(1);
	}
	else{
	
	while(!feof(file_pointer))
	{
		nRead = fread(TheData, sizeof(char), 256, file_pointer);
		if(nRead <= 0){
			printf("ERROR reading file");
			return 1;
		}
		while(nRead > 0){
			nSent = send(s, TheData, nRead, 0);
			if(nSent < 0){
				printf("ERROR sending from socket", WSAGetLastError());
				return 1;
			}
			if (nSent == 0){
				printf("Disconnected writing to socket");
				return 1;
			}
		}
	}
		
	}		
				
	
	}
else if(strcmp(choice,"Contribution check")==0){
	
	printf("------CONTRIBUTION CHECK-------");
}
	else if(strcmp(choice,"Loan request")==0){
		
		printf("------- REQUEST FOR A LOAN------");
		
		char loan[20];
		
		FILE* file_point; 
file_point = fopen("client.txt","w");

		printf("ENTER AMOUNT:\n");
scanf("%s", loan);
fprintf(file_point, "---------LOAN REQUEST--------\n");

fprintf(file_point, "ENTER AMOUNT:\n");
fprintf(file_point, "%s\n" , loan);

fclose(file_point);
printf("Sending file to server.............\n");
	printf("FILE SENT.....");
	file_point = fopen("client.txt", "r");
	if(file_point == NULL){
		printf("The file you want to send was not found");
		return(1);
	}
	else{
	
	while(!feof(file_point))
	{
		nRead = fread(TheData, sizeof(char), 256, file_point);
		if(nRead <= 0){
			printf("ERROR reading file");
			return 1;
		}
		while(nRead > 0){
			nSent = send(s, TheData, nRead, 0);
			if(nSent < 0){
				printf("ERROR sending from socket", WSAGetLastError());
				return 1;
			}
			if (nSent == 0){
				printf("Disconnected writing to socket");
				return 1;
			}
		}
	}
		
	}
	}
	
	else if(strcmp(choice,"Loan status")==0){
		printf("--------LOAN STATUS-------");
		
	}
	
	else if(strcmp(choice,"Submit Idea")==0){
		
	
		/*char initiator[20];
		char idea[20];
		char str[50];
	  
		
		FILE* file_p; 
file_p = fopen("client.txt","w");
		
		printf("---------SUBMIT IDEA--------\n");
		fprintf(file_p, "------------IDEA-----------\n");
		
		printf("BUSINESS INITIATOR:\n");
		scanf("%s", initiator);
		fprintf(file_p, "%s\n", initiator);
		
		printf("BUSINESS IDEA:\n");
		scanf("%s", idea);
		fprintf(file_p, "%s\n" , idea);
		
		printf("BUSINESS DESCRIPTION:\n");
		fgets("str, sizeof(str), stdin");
		fprintf(file_p , "%s", str);
		
		fclose(file_p);
		
printf("Sending file to server.............\n");
	printf("FILE SENT.....");
	
	file_p = fopen("client.txt", "r");
	if(file_p == NULL){
		printf("The file you want to send was not found");
		return(1);
	}
	else{
	
	while(!feof(file_p))
	{
		nRead = fread(TheData, sizeof(char), 256, file_p);
		if(nRead <= 0){
			printf("ERROR reading file");
			return 1;
		}
		while(nRead > 0){
			nSent = send(s, TheData, nRead, 0);
			if(nSent < 0){
				printf("ERROR sending from socket", WSAGetLastError());
				return 1;
			}
			if (nSent == 0){
				printf("Disconnected writing to socket");
				return 1;
			}
		}
	}
		
	}
		
		*/
	}
	
	else{
		printf("ENTER A VALID CHOICE");
	}
	
	
	getchar();
 //mysql_close(&mysql);
//return 1;

 
    return 0;
	

}