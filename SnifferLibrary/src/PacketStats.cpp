#include "PacketStats.h"

	 

void PacketStats::clear() 
	{ 
	LOG_INFO("clear<Method started>");
	ethPacketCount = 0; ipv4PacketCount = 0; ipv6PacketCount = 0; 
	tcpPacketCount = 0; udpPacketCount = 0;  tcpPacketCount = 0; 
	dnsPacketCount = 0; httpPacketCount = 0; sslPacketCount = 0; 
	}


PacketStats::PacketStats() { clear(); } //Constructor PacketStats


void PacketStats::consumePacket(pcpp::Packet& packet) //Collect stats from a packet
	{
		//LOG_INFO("consumePacket<Method started>");
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


void PacketStats::printToConsole() //Print stats to console
	{
		LOG_INFO("printToConsole<Method started>");
		std::cout << "Results:" << std::endl
			<< "Ethernet packet count: " << ethPacketCount << std::endl
			<< "IPv4 packet count:     " << ipv4PacketCount << std::endl
			<< "IPv6 packet count:     " << ipv6PacketCount << std::endl
			<< "TCP packet count:      " << tcpPacketCount << std::endl
			<< "UDP packet count:      " << udpPacketCount << std::endl
			<< "DNS packet count:      " << dnsPacketCount << std::endl
			<< "HTTP packet count:     " << httpPacketCount << std::endl
			<< "SSL packet count:      " << sslPacketCount << std::endl;
	}
	


	



