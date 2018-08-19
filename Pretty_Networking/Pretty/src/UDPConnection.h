#pragma once

#include <pretty_sdl\sdl.h>
#include <pretty_sdl\SDL_net.h>

class UDPConnection {

public:
	UDPConnection();
	~UDPConnection() {}
	static bool InitializeSDL();
	static bool InitializeSDLNetwork();
	
	bool OpenPort(uint32_t port = 0);
	bool Connect(const std::string& destinationIP, uint32_t destinationPort);
	bool AllocatePacket(int32_t packetSize);
	bool Send(const std::string &str);
	bool Receive();

	void Shutdown();

	bool HasQuit() { return m_Quit; }

private:
    bool GetSendee(IPaddress* ipAddress, UDPpacket* packet);

    std::string ConvertIP(uint32_t ipData);

	bool m_Quit;
	UDPsocket	m_Socket;
	UDPpacket*	m_Packet;
	IPaddress	m_ServerIP;
};