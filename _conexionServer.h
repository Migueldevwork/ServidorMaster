//Creo estructura para guardar ip, puerto y estado en los arrays del main.

//Creo estructura servidor para introducir los parametros de un socket
typedef struct{
  	WSADATA wsaData;
  	SOCKET comm_socket[10];
  	SOCKET conn_socket;
  	struct sockaddr_in server;
  	struct sockaddr_in client;
  	struct hostent *hp;
  	int response,stsize;
	int contSock;
	Position ps;
	Lista ls;
}ConexionServer;

typedef struct {
	char ip[12];
	unsigned short port;
	unsigned short state;
	Lista * lA;
	Lista * lD;		
}Lista;

typedef struct {
	Lista * pInit;
	Lista * pLast;
}Position;

int initDll ();
ConexionServer conection(int port);
void waiting(ConexionServer * con1);
void waitingServer(ConexionServer * con1);
void waitingClient(ConexionServer * con1);
void guardarServidor(ConexionServer * con1);

//char guardarServidor(ConexionServer * con);


