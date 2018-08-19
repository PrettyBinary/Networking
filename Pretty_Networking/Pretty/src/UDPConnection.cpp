#include <iostream>
#include <string>
#include "UDPConnection.h"

UDPConnection::UDPConnection() : m_Quit(false)
{

}

bool UDPConnection::InitializeSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Couldn't initialize SDL!";
		return false;
	}
	return true;
}

bool UDPConnection::InitializeSDLNetwork()
{
	std::cout << "Initializing SDL_net...\n";

	if (SDLNet_Init() == -1)
	{
		std::cout << "\tSDLNet_Init failed : " << SDLNet_GetError() << std::endl;
		return false;
	}

	std::cout << "\tSuccess!\n\n";

	return true;
}

bool UDPConnection::OpenPort(uint32_t port)
{
	// Sets our sovket with our local port
	
	m_Socket = SDLNet_UDP_Open(port);

	if (m_Socket == nullptr)
	{
		std::cout << "\tSDLNet_UDP_Open failed : " << SDLNet_GetError() << std::endl;
		return false;
	}

	std::cout << "\tSuccess!\n\n";
	return true;
}

bool UDPConnection::Connect(const std::string& destinationIP, uint32_t destinationPort)
{

	// Set IP and port number with correct endianess
	Uint16 port = 0;
	
	if (SDLNet_ResolveHost(&m_ServerIP, destinationIP.c_str() , destinationPort) == -1)
	{
		std::cout << "\tSDLNet_ResolveHost failed : " << SDLNet_GetError() << std::endl;
		return false;
	}

	std::cout << "Setting IP ( " << destinationIP.c_str() << " ) " << "and port ( " << destinationPort << " )\n";
	std::cout << "\tSuccess!\n\n";

	return true;

}

bool UDPConnection::AllocatePacket(int32_t packetSize)
{
	std::cout << "Creating packet with size " << packetSize << "...\n";

	// Allocate memory for the packet
	m_Packet = SDLNet_AllocPacket(packetSize);

	if (m_Packet == nullptr)
	{
		std::cout << "\tSDLNet_AllocPacket failed : " << SDLNet_GetError() << std::endl;
		return false;
	}

	// Set the destination host and port
	// We got these from calling SetIPAndPort()
	m_Packet->address.host = m_ServerIP.host;
	m_Packet->address.port = m_ServerIP.port;

	std::cout << "\tSuccess!\n\n";
	return true;
	
}

bool UDPConnection::Send(const std::string &str)
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

	memcpy(m_Packet->data, msg.c_str(), msg.length());
	m_Packet->len = msg.length();

	std::cout
		<< "==========================================================================================================\n"
		<< "Sending : \'" << str << "\', Length : " << m_Packet->len << "\n";

	// Send
	// SDLNet_UDP_Send returns number of packets sent. 0 means error
	if (SDLNet_UDP_Send(m_Socket, -1, m_Packet) == 0)
	{
		std::cout << "\tSDLNet_UDP_Send failed : " << SDLNet_GetError() << "\n"
			<< "==========================================================================================================\n";
		return false;
	}

	std::cout << "\tSuccess!\n"
		<< "==========================================================================================================\n";

	if (str == "quit")
	{
		m_Quit = true;
	}

	return true;
}


bool UDPConnection::Receive()
{

    bool gotData = false;
	std::cout
		<< "==========================================================================================================\n"
		<< "Check for data...\n";

	// Check t see if there is a packet wauting for us...
	if (SDLNet_UDP_Recv(m_Socket, m_Packet) > 0)
	{
        gotData = true;
		std::cout << "\tData received : " << m_Packet->data << "\n";

		// If the data is "quit"
		if (strcmp((char *)m_Packet->data, "quit") == 0)
			m_Quit = true;
	}
	return gotData;
}

void UDPConnection::Shutdown()
{
	SDLNet_FreePacket(m_Packet);
	SDLNet_Quit();
}
