#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int server_socket;

	server_socket = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_address; //before connecting to another socket need to specify the address.
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(60000);
	server_address.sin_addr.s_addr = INADDR_ANY;
	int connection_status = connect(server_socket, (struct sockaddr *)&server_address , sizeof(server_address));
	if(connection_status == -1)
	{
		printf("there was an error in the creation of the socket");
	}
	char server_response[256];
	recv(server_socket,&server_response,sizeof(server_response),0);
	printf("the server sent the data %s",server_response);
	close(server_socket);
	return 0;
	}
