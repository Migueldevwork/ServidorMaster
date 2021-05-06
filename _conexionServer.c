#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <pthread.h> 
#include "_conexionServer.h"

int initDll (){
	ConexionServer conect;
	int resp;
	resp=WSAStartup(MAKEWORD(1,0),&conect.wsaData);
	return resp;
}

ConexionServer conection(){
	ConexionServer conect;
	conect.response = initDll();
  	if(conect.response){
    	printf("Error al inicializar socket\n");
    	getchar();
  	}
  	
 	/*printf("Inserta la ip:");
  	scanf("%s", conect.ip);
  	fflush(stdin);*/
  	conect.hp=(struct hostent *)gethostbyname("192.168.1.51");
  	if(!conect.hp){
    	printf("No se ha encontrado servidor...\n");
    	getchar();WSACleanup();
  	}
	conect.conn_socket=socket(AF_INET,SOCK_STREAM, 0);                                               //1- CREA SOCKET
  	if(conect.conn_socket==INVALID_SOCKET) {
    	printf("Error al crear socket\n");
  	  	getchar();
  	}
  
  	memset(&conect.server, 0, sizeof(conect.server)) ;
  	memcpy(&conect.server.sin_addr, conect.hp->h_addr, conect.hp->h_length);
  	conect.server.sin_family = conect.hp->h_addrtype;
  	conect.server.sin_port = htons(3000);
  
  	/*printf("Inserta el puerto:");
  	scanf("%d", &conect.port);
  	fflush(stdin);*/
  	conect.server.sin_addr.s_addr=inet_addr("192.168.1.51");
  
  	conect.response=bind(conect.conn_socket, (struct sockaddr *)&conect.server, sizeof(conect.server));                         //2- BIND
  	if(conect.response==SOCKET_ERROR){
    	printf("Error al asociar puerto e ip al socket\n");
    	closesocket(conect.conn_socket);WSACleanup();
    	getchar();
  	}

  	if(listen(conect.conn_socket, 1)==SOCKET_ERROR){                                                   //3- LISEN puerto 6000
    	printf("Error al habilitar conexiones entrantes\n");
    	closesocket(conect.conn_socket);WSACleanup();
    	getchar();
  	}
  	return conect;
}

void waiting(ConexionServer * con1, int contSock){
	printf("Esperando conexiones entrantes... \n");
	con1->stsize=sizeof(struct sockaddr);
	con1->SocketState[contSock].comm_socket=accept(con1->conn_socket,(struct sockaddr *)&con1->client,&con1->stsize);                        //4- ACCEPT - ACEPTA CONEXIONES ENTRANTES DE UN CLIENTE
	if(con1->SocketState[contSock].comm_socket==INVALID_SOCKET){
	    printf("Error al aceptar conexión entrante\n");
	    closesocket(con1->conn_socket);WSACleanup();
	    getchar();
	}
	printf("Conexión entrante desde: %s\n", inet_ntoa(con1->client.sin_addr));
}

char guardarServidor(ConexionServer * con){
 	char ip[20];
	 ip [20]= inet_ntoa(con->client.sin_addr);
 	return ip;
}




