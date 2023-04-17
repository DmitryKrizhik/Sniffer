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

//#include "spdlog/spdlog.h"



//#include "Logger/spdlog"


class PacketStats;
class App
{
	public:
	bool IPv4Check(std::string interfaceIPAddr, pcpp::PcapLiveDevice* dev);
	void PrintAboutInterface(pcpp::PcapLiveDevice* dev);
	bool DevOpeningCheck(pcpp::PcapLiveDevice* dev);
	static std::map<std::string, std::size_t> countURL; 
	void CollectStatistics(std::map<std::string, std::size_t> &countURL, pcpp::RawPacketVector packetVec, PacketStats &stats,
	std::pair<int,int> &InOut);
	static std::string getProtocolTypeAsString(pcpp::ProtocolType protocolType);
	std::string printHttpMethod(pcpp::HttpRequestLayer::HttpMethod httpMethod);
	std::string printTcpOptionType(pcpp::TcpOptionType optionType);
	std::string printTcpFlags(pcpp::TcpLayer* tcpLayer);
	static void PrintURLcount(std::map<std::string, std::size_t> countURL, std::pair<int,int> InOut);
	static std::pair<int,int> InOut;
};


#endif
