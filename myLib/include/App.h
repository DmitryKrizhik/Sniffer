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
#include "PacketStats.h"
#include <map>
#include <algorithm>
//#include "version.h"
//#include "path.h"


class App
{
	public:
	//pcpp::HttpRequestLayer* httpRequestLayer;
	
	std::string str;
	std::map<std::string, size_t> countURL; 
	static void onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
	static bool onPacketArrivesBlockingMode(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);
	std::string getProtocolTypeAsString(pcpp::ProtocolType protocolType);
	std::string printHttpMethod(pcpp::HttpRequestLayer::HttpMethod httpMethod);
	std::string printTcpOptionType(pcpp::TcpOptionType optionType);
	std::string printTcpFlags(pcpp::TcpLayer* tcpLayer);
	void PrintURLcount();
	//static void printVersion();
	//static void printPath();
};


#endif
