#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#include "_funcionesMensaje.h"

char sending(void* _socket){
	
	SOCKET *socket = (SOCKET *)_socket;
	 
	char SendBuff[512];
	
  	scanf("%s", SendBuff);
	printf("Enviando Mensaje... \n");
  	send(*socket,SendBuff,sizeof(SendBuff),0);                        //función send  para envia mensaje al servidor
  	printf("Datos enviados: %s \n", SendBuff);
  	
  	return *SendBuff;
};

char receiving(void* _socket){
	SOCKET *socket = (SOCKET *)_socket;
	char RecvBuff[512];
	
	printf("Recibiendo Mensaje... \n");
  	recv(*socket,RecvBuff, sizeof(RecvBuff), 0);                     //recv para recibir mensajes enviados por el servidor
  	printf("ENVIADO DESDE SERVIDOR: %s \n", RecvBuff);
  	
  	return *RecvBuff;
};
