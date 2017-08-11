#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<winsock2.h>
#include<time.h>
#include<conio.h>
#include<string.h>
 
#pragma comment(lib,"ws2_32.lib")
SOCKET s, new_socket;
char*message, server_reply[2000], menu_reply[2000],ch;
char TheData[256];
int recv_size;
int menu_size;
struct sockaddr_in server, client;
int c;
 size_t nRead, nSent;
 FILE *fp;
FILE * ideaPtr;//pointer to client.txt
FILE *file_p;
char desc[500];//description
char uname[20];

int send_data()
{
	if(nRead <= 0){
			printf("ERROR reading file");
			return 1;
		}
		while(nRead > 0){
			//send information to the server
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
		return 0;
}

int contribution()//function for sending contribution
{
char amount[20];
		
		char lastname[20];
		char date[20];
		
		
		#define FILE_NAME "client.txt"
		FILE* contPtr;//pointer to client.txt
		//open file and write to it
         contPtr = fopen("client.txt","w");

        printf("ENTER USERNAME:");
        scanf("%s", uname);
	     
        printf("ENTER AMOUNT:");
        scanf("%s", amount);

        printf("ENTER DATE OF CONTRIBUTION:....(yyyy/mm/dd):");
        scanf("%s", date);

        fprintf(contPtr, "------------CONTRIBUTION------------\n");

         fprintf(contPtr, "USERNAME:\n");
         fprintf(contPtr, "%s\n" ,uname);
         
       fprintf(contPtr, "AMOUNT:\n");
        fprintf(contPtr, "%s\n" ,amount);

       fprintf(contPtr, "DATE OF CONTRIBUTION:....(yyyy/mm/dd)\n");
       fprintf(contPtr, "%s\n" ,date);

       fclose(contPtr);
	printf("Sending file to server.............\n");
	printf("FILE SENT.....");
	
	contPtr = fopen("client.txt", "r");
	
	//exit if file does not exist 
	if(contPtr == NULL){
		printf("The file you want to send was not found");
		return 1;
	        }
	else{
	
	while(!feof(contPtr))
	{
		 //transfer data from client.txt to TheData
		nRead = fread(TheData, sizeof(char), 256, contPtr);
		send_data();
		
	}	
	}
 return 0;	
}

int submit_idea()//function for submitting idea
{        
       char initial[20];
		char idea[20];
		char capital[20];
		   
		   //opens file
        ideaPtr = fopen("client.txt","w");
		
		printf("---------SUBMIT IDEA--------\n");
		fprintf(ideaPtr, "------------IDEA-----------\n");
		
		
		printf("DETAILS\n");
		fflush(stdout);
		fgets(initial,20,stdin);
		fprintf(ideaPtr, "Details%s\n", initial);
		 printf("BUSINESS CAPITAL:");
		 fgets(capital,20,stdin);
		 fprintf(ideaPtr, "Capital:%s\n", capital);
		 
		printf("BUSINESS IDEA: ");
		fgets(idea,20,stdin);
		fprintf(ideaPtr, "Idea Name:%s\n" ,idea);
		
		
		int k =0;
		printf("\tENTER BUSINESS DESCRIPTION\n");
		fgets(desc,500,stdin);
		fprintf(ideaPtr, "Description:%s" ,desc);
		fclose(ideaPtr);//close file
		
		printf("Sending file to server.............\n");
	printf("FILE SENT.....");
	
	ideaPtr = fopen("client.txt", "r");
	if(ideaPtr == NULL){
		printf("The file you want to send was not found");
		return(1);
	}
	else{
	
	while(!feof(ideaPtr))
	{
		nRead = fread(TheData, sizeof(char), 256, ideaPtr);
		send_data();
	}
		
	}
		
	return 0;
} 
 
 int loan_request()
 {
char loan[20];
		
		FILE* file_point; 
       file_point = fopen("client.txt","w");
         
		 printf("USERNAME:\n");
        scanf("%s",&uname);
		 
		printf("AMOUNT:\n");
        scanf("%s",&loan);
       fprintf(file_point, "---------LOAN REQUEST--------\n");
       
	   fprintf(file_point, "USERNAME:\n");
       fprintf(file_point, "%s\n" ,uname);
	   
      fprintf(file_point, "AMOUNT:\n");
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
		send_data();
	}	
	}	  
 }

int main(int argc , char *argv[]){
	
	
    WSADATA wsa;      /* Structure for WinSock setup communication */
     
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)   /* Load Winsock 2.0 DLL */
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
     
    printf("Initialised.\n");
	
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET) /* Create a reliable, stream socket using TCP */
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
 
    printf("Socket created.\n");
 
     server.sin_addr.s_addr = inet_addr("127.0.0.1"); /*Server IP address */
    server.sin_family = AF_INET;    /* Internet address family */
    server.sin_port = htons( 81 );  /*Server port */
 
    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    puts("Connected");
        
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
		contribution();//call to the contribution function
		exit(0);
	}
else if(strcmp(choice,"Contribution check")==0){
	
	printf("------CONTRIBUTION CHECK-------");
}
	else if(strcmp(choice,"Loan request")==0){
		
		printf("------- REQUEST FOR A LOAN------");
		loan_request();//call to the request_loan function
	}
	
	else if(strcmp(choice,"Loan status")==0){
		printf("--------LOAN STATUS-------");
		
	}
	
	else if(strcmp(choice,"Submit Idea")==0){
		submit_idea();//call to the submit_idea function
	}
	
	else{
		printf("ENTER A VALID CHOICE");
	}
	
    return 0;
}