
#include <iostream>
#include <pretty_sdl\SDL_net.h>
#include "UDPConnection.h"


/*
bool quit = false;
UDPpacket* packet = nullptr;
UDPsocket socket = nullptr;


bool Send(const std::string &str)
{
	// Set the data
	// UDPPacket::data is an Uint8, which is similar to char*
	// This means we can't set it directly.
	//
	// std::stringstreams let us add any data to it using << ( like std::cout ) 
	// We can extract any data from a std::stringstream using >> ( like std::cin )
	//
	//str
	std::cout << "Type a message and hit enter\n";
	std::string msg = "";
	std::cin.ignore();
	std::getline(std::cin, msg);

	memcpy(packet->data, msg.c_str(), msg.length());
	packet->len = msg.length();

	std::cout
		<< "==========================================================================================================\n"
		<< "Sending : \'" << str << "\', Length : " << packet->len << "\n";

	// Send
	// SDLNet_UDP_Send returns number of packets sent. 0 means error
	if (SDLNet_UDP_Send(socket, -1, packet) == 0)
	{
		std::cout << "\tSDLNet_UDP_Send failed : " << SDLNet_GetError() << "\n"
			<< "==========================================================================================================\n";
		return false;
	}

	std::cout << "\tSuccess!\n"
		<< "==========================================================================================================\n";

	if (str == "quit")
		quit = true;
	return true;
}


void CheckForData()
{
	std::cout
		<< "==========================================================================================================\n"
		<< "Check for data...\n";

	// Check t see if there is a packet wauting for us...
	if (SDLNet_UDP_Recv(socket, packet))
	{
		std::cout << "\tData received : " << packet->data << "\n";

		// If the data is "quit"
		if (strcmp((char *)packet->data, "quit") == 0)
			quit = true;
	}
	else
		std::cout << "\tNo data received!\n";

	std::cout << "==========================================================================================================\n";
}


bool WasQuit()
{
	return quit;
}



int main(int argc, char* argv[])
{

	//Init SDL NET
	if (SDLNet_Init() == -1)
	{
		std::cout << "couldn't init SDL NET";
	}

	int32_t localPort = 0;
	
	
	
	//struct - create a server IP
	IPaddress serverIP = {};
	std::string ipStr = "";
	int32_t remotePort = 0; //must have port for server (remote) as well as local port for client

	
	//Create a packet passing in the packet size we want (check if there is a way to query this) this allocates memory for packet
	int32_t packetSize = 512;
	std::cout << "Creating packet with size " << packetSize << "...\n";


	packet = SDLNet_AllocPacket(packetSize);

	if (packet == nullptr)
	{
		std::cout << "\tSDLNet_AllocPacket failed : " << SDLNet_GetError() << std::endl;
		return false;
	}
	

	std::cout
		<< "\n==========================================================================================================\n"
		<< "UDP connection - A simple test for UDP connections using SDL_Net!"
		<< "\n==========================================================================================================\n"
		<< "You'll be asked to enter the following :"
		<< "\n\tRemote IP   : The IP you want to connect to"
		<< "\n\tRemote Port : The port you want to connect to"
		<< "\n\tLocal port  : Uour port"
		<< "\nLocal port should be the same as remote port on the other instance of the application"
		<< "\n==========================================================================================================\n\n";

	std::cout << "Enter remote IP ( 127.0.0.1  for local connections ) : ";
	std::cin >> ipStr;
	std::cout << "...and remote port : ";
	std::cin >> remotePort;

	std::cout << "Enter local port : ";
	std::cin >> localPort;


	std::cout << "Setting IP ( " << ipStr.c_str() << " ) " << "and port ( " << remotePort << " )\n";

	// Set IP and port number with correct endianess
	if (SDLNet_ResolveHost(&serverIP, ipStr.c_str(), remotePort) == -1)
	{
		std::cout << "\tSDLNet_ResolveHost failed : " << SDLNet_GetError() << std::endl;
		return -1;
	}

	// Set the destination host and port for the SERVER
	// We got these from calling SDLNet_ResolveHost
	packet->address.host = serverIP.host;
	packet->address.port = serverIP.port;

	//Create UDP socket passing in port to open a local port.
	socket = SDLNet_UDP_Open(localPort);

	//check socket has opened successfully
	if (socket == nullptr)
	{
		std::cout << "\tSDLNet_UDP_Open failed : " << SDLNet_GetError() << std::endl;
		return -1;
	}


	uint8_t command = 0;

	while (!quit)
	{
		std::cout
			<< "Your command : "
			<< "\n\t0 : Send a message"
			<< "\n\t1 : Quit"
			<< "\n\t2 : Check for data"
			<< std::endl;

		std::cin >> command;

		if (command == '0')
			Send("This is a test");
		else if (command == '1')
			Send("quit");
		else if (command == '2')
			CheckForData();
		else
			std::cout << "Illegal command\n";
	}

	std::cin.get();


	return 0;
}
*/


int main(int argc, char* argv[])
{
	UDPConnection::InitializeSDL();
	UDPConnection::InitializeSDLNetwork();

    UDPConnection connection;

    /*SERVER TYPE CONNECTION
    connection.OpenPort(12321);

	
	uint8_t command = 0;

    while(!connection.HasQuit()){
        connection.Receive()
        
    }

    */

    //CLIENT SIDE
    connection.OpenPort();
    connection.Connect("192.168.1.72", 12321);

    connection.AllocatePacket(512);
    connection.Send("Sending A Message");

    while (!connection.Receive()) {

    }

    system("pause");



    //)//!connection.HasQuit())
	//{
		/*std::cout
			<< "Your command : "
			<< "\n\t0 : Send a message"
			<< "\n\t1 : Quit"
			<< "\n\t2 : Check for data"
			<< std::endl;

		std::cin >> command;

		if (command == '0')
			connection.Send("blah");
		else if (command == '1')
			connection.Send("quit");
		else if (command == '2')
			connection.Receive();
		else
			std::cout << "Illegal command\n";*/

	return 0;
}