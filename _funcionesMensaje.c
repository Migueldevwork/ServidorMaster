#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#include "_conexionServer.h"

//Envia un mensaje por el socket asociado.
void sending(SOCKET * _socket, char * SendBuff){
	
	SOCKET *socket = (SOCKET *) _socket;
	
  	scanf("%s", SendBuff);
	printf("Enviando Mensaje... \n");
  	send(*socket,SendBuff,sizeof(SendBuff),0);                        //función send  para envia mensaje al servidor
  	printf("Datos enviados: %s \n", SendBuff);
  	
};


//Escucha el mensaje enviado al servidor por el socket asociado. 
char receiving(void* _socket){
	SOCKET *socket = (SOCKET *)_socket;
	char RecvBuff[512];
	
	printf("Recibiendo Mensaje... \n");
  	recv(*socket,RecvBuff, sizeof(RecvBuff), 0);                     //recv para recibir mensajes enviados por el servidor
  	printf("ENVIADO DESDE SERVIDOR: %s \n", RecvBuff);
  	
  	return *RecvBuff;
};

// le pasas una estructura Server y te lista todos los servidores guardados por el master con id, ip, puerto y estado
void getServers(Server server){
	int i;
	for(i = 0; i <= 10; i++ ){
		printf("id: %i, Ip: %s, Puerto: %i, Estado: %s. ", i+1, server.ip, server.port, server.state);
	}	
};


//Funcion que maneja el comando escrito por consola y le asigna una tarea.
void getComando(ConexionServer server){
	char comando[512];
	printf("Inserte comando: ");
	scanf(comando);
	if (!strcmp(comando, "SERVERSINFO")){ //el comando SERVERSINFO llama a la funcion getServers();
		getServers(server.ip);
	}
}
