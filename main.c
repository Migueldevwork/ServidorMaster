#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <pthread.h> 
#include "_conexionClient.h"
#include "_conexionServer.h"
#include "_funcionesMensaje.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ConexionServer conS1 = conection();
	char sendBuff[1024];
	char ip[10][20];
	
  	int contSock = 0; //Indice de cada socket asignado en un hilo          
  	while(1){

	waiting(&conS1,  contSock);
	
	if(conS1.esCliente){
		printf("Conexión entrante desde: %s\n", inet_ntoa(conS1.client.sin_addr), ". Conectado como Servidor.");
		printf("Introduce 'OK' para aceptar servidor y guardar IP.");
		sendBuff [1024]= sending(&conS1);
		if(sendBuff[1024] = "OK"){
			ip[1][20] = guardarServidor();
			printf("Servidor con IP ' %s\n", inet_ntoa(conS1.client.sin_addr), "' Guardado.");
		}
	}else{
		printf("Conexión entrante desde: %s\n", inet_ntoa(conS1.client.sin_addr), ". Conectado como Cliente.");
	}
	  pthread_t thread1; 
	  pthread_create(&thread1, NULL, (void *)sending, (void *)&conS1.SocketState[contSock]);
	  
	  
	  contSock++;
  }

	getchar();            

  closesocket(conS1.SocketState[contSock].comm_socket);                  //CIERRA - Socket primera escucha                  //<--- Cambiado de posición
  
  // Cerramos liberia winsock
  WSACleanup();
  return (EXIT_SUCCESS);
}
