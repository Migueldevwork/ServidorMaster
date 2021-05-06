#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#include <pthread.h> 
#include "_conexionClient.h"

ConexionClient conectionC(){
	 //Inicializamos la DLL de sockets
	 ConexionClient conect;
  conect.resp=WSAStartup(MAKEWORD(1,0),&conect.wsaData);
  if(conect.resp){
    printf("Error al inicializar socket\n");
    getchar();
  }

  //Obtenemos la IP del servidor... en este caso
  // localhost indica nuestra propia máquina...
  conect.hp=(struct hostent *)gethostbyname("192.168.0.5");

  if(!conect.hp){
    printf("No se ha encontrado servidor...\n");
    getchar();WSACleanup();
  }

  // Creamos el socket...
  conect.conn_socket=socket(AF_INET,SOCK_STREAM, 0);
  if(conect.conn_socket==INVALID_SOCKET) {
    printf("Error al crear socket\n");
    getchar();WSACleanup();
  }
   
  memset(&conect.server, 0, sizeof(conect.server)) ;
  memcpy(&conect.server.sin_addr, conect.hp->h_addr, conect.hp->h_length);
  conect.server.sin_family = conect.hp->h_addrtype;
  conect.server.sin_port = htons(3000);
  
  
  //server.sin_addr.s_addr=inet_addr("127.0.0.1"); // La ip estará en formato long
  conect.server.sin_addr.s_addr=inet_addr("192.168.0.5"); // ip del SERVIDOR,  La ip estará en formato long
  
  
 /***************/
 
  // Nos conectamos con el servidor...
  if(connect(conect.conn_socket,(struct sockaddr *)&conect.server,sizeof(conect.server))==SOCKET_ERROR){          //CONECTAR con connect
    printf("Fallo al conectarse con el servidor\n");
    closesocket(conect.conn_socket);
    WSACleanup();getchar();
  }
  printf("Conexión establecida con: %s\n", inet_ntoa(conect.server.sin_addr));
  return conect;
}
