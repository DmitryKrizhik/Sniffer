#pragma once
#ifndef _PACKET_
#define _PACKET_
#include "App.h"

class PacketStats
	{
	public:

	int ethPacketCount;
	int ipv4PacketCount;
	int ipv6PacketCount;
	int tcpPacketCount;
	int udpPacketCount;
	int dnsPacketCount;
	int httpPacketCount;
	int sslPacketCount;
	
	//Clear all stats
	void clear();
	
	//Constructor
	PacketStats();
	
	//Collect stats from a packet
	void consumePacket(pcpp::Packet& packet);
	
	//Print stats to console
	void printToConsole();
};
#endif
