typedef struct{
	SOCKET comm_socket;
	int estate;
}_Socket;

typedef struct{
  	WSADATA wsaData;
  	_Socket SocketState[10];
  	SOCKET conn_socket;
  	struct sockaddr_in server;
  	struct sockaddr_in client;
  	struct hostent *hp;
  	int response,stsize;
  	char ip[12];
  	int port;
  	int esCliente;
}ConexionServer;

int initDll ();
ConexionServer conection();
void waiting(ConexionServer * con1, int contSock);


