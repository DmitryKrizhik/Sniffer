#pragma once
#ifndef _APP_
#define _APP_
#include <iostream>
#include <ostream>
#include "stdlib.h"
#include "PcapLiveDeviceList.h"
#include "SystemUtils.h" 
#include "Packet.h" 
#include "EthLayer.h" 
#include "IPv4Layer.h" 
#include "TcpLayer.h" 
#include "HttpLayer.h" 
#include "PcapFileDevice.h"
//#include "version.h"
//#include "path.h"


struct App
{

	static void onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
	static bool onPacketArrivesBlockingMode(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
	std::string getProtocolTypeAsString(pcpp::ProtocolType protocolType);
	std::string printHttpMethod(pcpp::HttpRequestLayer::HttpMethod httpMethod);
	std::string printTcpOptionType(pcpp::TcpOptionType optionType);
	std::string printTcpFlags(pcpp::TcpLayer* tcpLayer);
	//static void printVersion();
	//static void printPath();
};
struct PacketStats
	{

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
