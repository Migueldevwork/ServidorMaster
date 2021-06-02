//Creo estructura para guardar ip, puerto y estado en los arrays del main.
typedef struct{
	char ** ip;
	int * port;
	char ** state;
} Server;

//Creo estructura servidor para introducir los parametros de un socket
typedef struct{
  	WSADATA wsaData;
  	SOCKET comm_socket[10];
  	SOCKET conn_socket;
  	struct sockaddr_in server;
  	struct sockaddr_in client;
  	struct hostent *hp;
  	int response,stsize;
  	Server ip;
  	int port;
  	int valCliente;
	int contSock;
}ConexionServer;


int initDll ();
ConexionServer conection(int port);
void waiting(ConexionServer * con1);
void waitingServer(ConexionServer * con1);
void waitingClient(ConexionServer * con1);
void guardarServidor(ConexionServer * con1);

//char guardarServidor(ConexionServer * con);


