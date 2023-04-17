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
	void clear(); //Clear all stats
	PacketStats(); //Constructor
	void consumePacket(pcpp::Packet& packet); //Collect stats from a packet
	void printToConsole(); //Print stats to console
};
#endif
