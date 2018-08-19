#pragma once

#include <pretty_sdl\sdl.h>
#include <pretty_sdl\SDL_net.h>

class UDPConnection {

public:
	UDPConnection();
	~UDPConnection() {}
	static bool InitializeSDL();
	static bool InitializeSDLNetwork();
	
	bool OpenLocalHost();
	bool OpenServer();
	bool AllocatePacket(int32_t packetSize);
	bool Send(const std::string &str);
	void Receive();

	void Shutdown();

	bool HasQuit() { return m_Quit; }

private:
	bool m_Quit;
	UDPsocket	m_Socket;
	UDPpacket*	m_Packet;
	IPaddress	m_ServerIP;
};