#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <pthread.h> 
#include "_conexionClient.h"
#include "_conexionServer.h"
#include "_funcionesMensaje.h"
#define MAX_SERV 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int portServidor = 4000;            //Variable que define el puerto por donde entran los servidores.
	int portCliente = 3000;             //Variable que define el puerto por donde entran los clientes.
	char ip[MAX_SERV][20];              //Array para guardar las ip de los servidores auxiliares.
	int port[MAX_SERV];                 //Array para guardar los puertos de los servidores auxiliares.
	char state [MAX_SERV][20];          //Array para guardar los estados de los servidores auxiliares.
	
	
	ConexionServer conS = conection(portServidor); //Configuro el soquet para Servidores
	conS.contSock = 0;
	  //waiting(&conS);
	ConexionServer conC = conection(portCliente); //Configuro el soquet para Clientes
	
	//Asocio los punteros de las estructuras con los arrays para guardar ip, puerto y estado de los servidores.
	/*conC.ip.ip = (char**)&ip;
	conS.ip.ip = (char**)&ip;
	conC.ip.port = (int*)&port;
	conS.ip.port = (int*)&port;
	conC.ip.state = (char**)&state;
	conS.ip.state = (char**)&state;*/
	


	    		pthread_t thread1; 														//Abro un hilo 1
	  	pthread_create(&thread1, NULL, (void *)waitingServer, (void *)&conS); 	//Le paso la funcion de escucha de servidores al hilo 1.
	  	pthread_t thread2;														//Abro un hilo 2
	 	pthread_create(&thread2, NULL, (void *)waitingClient, (void *)&conC);
		  		
		
			//Le paso la funcion de escucha de clientes al hilo 2 S.
		/*pthread_t thread3;
	 	pthread_create(&thread3, NULL, (void *)getComando, (void *)&conS);
  		
	  /*pthread_t thread1; 
	  pthread_create(&thread1, NULL, (void *)sending, (void *)&conS1.SocketState[contSock]);*/
	  
	  

	getchar();            

  //closesocket(conS1.SocketState[contSock].comm_socket);                  //CIERRA - Socket primera escucha                  //<--- Cambiado de posición
  
  // Cerramos liberia winsock
  WSACleanup();
  return (EXIT_SUCCESS);
}
