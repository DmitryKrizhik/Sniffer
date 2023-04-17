#include "PacketStats.h"

	 

void PacketStats::clear() 
	{ 
	ethPacketCount = 0; ipv4PacketCount = 0; ipv6PacketCount = 0; 
	tcpPacketCount = 0; udpPacketCount = 0;  tcpPacketCount = 0; 
	dnsPacketCount = 0; httpPacketCount = 0; sslPacketCount = 0; 
	}

//Constructor
PacketStats::PacketStats() { clear(); }

//Collect stats from a packet
void PacketStats::consumePacket(pcpp::Packet& packet)
	{
		if (packet.isPacketOfType(pcpp::Ethernet)) {
			ethPacketCount++;}
		if (packet.isPacketOfType(pcpp::IPv4)) {ipv4PacketCount++;}
		if (packet.isPacketOfType(pcpp::IPv6)) {ipv6PacketCount++;}
		if (packet.isPacketOfType(pcpp::TCP)) {tcpPacketCount++;}
		if (packet.isPacketOfType(pcpp::UDP)) {udpPacketCount++;}
		if (packet.isPacketOfType(pcpp::DNS)) {dnsPacketCount++;}
		if (packet.isPacketOfType(pcpp::HTTP)) {httpPacketCount++;}
		if (packet.isPacketOfType(pcpp::SSL)) {sslPacketCount++;}
	}

//Print stats to console
void PacketStats::printToConsole()
	{
		
		std::cout << std::endl << "Results:" << std::endl
			<< "Ethernet packet count: " << ethPacketCount << std::endl
			<< "IPv4 packet count:     " << ipv4PacketCount << std::endl
			<< "IPv6 packet count:     " << ipv6PacketCount << std::endl
			<< "TCP packet count:      " << tcpPacketCount << std::endl
			<< "UDP packet count:      " << udpPacketCount << std::endl
			<< "DNS packet count:      " << dnsPacketCount << std::endl
			<< "HTTP packet count:     " << httpPacketCount << std::endl
			<< "SSL packet count:      " << sslPacketCount << std::endl;
	}
	


	



