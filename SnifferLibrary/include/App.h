
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
#include "Log.h"
#include <exception>


class PacketStats;
class App
{

public:

	static std::string URL;
	static bool IPv4Check(std::string interfaceIPAddr, pcpp::PcapLiveDevice* dev);
	void PrintAboutInterface(pcpp::PcapLiveDevice* dev);
	static bool DevOpeningCheck(pcpp::PcapLiveDevice* dev);
	static std::map<std::string, std::size_t> countURL; 
	void CollectStatistics(std::map<std::string, std::size_t> &countURL, pcpp::RawPacketVector packetVec, PacketStats &stats, std::pair<int,int> &InOut,
	std::string URL);
	static void PrintURLcount(std::map<std::string, std::size_t> countURL, std::pair<int,int> InOut);
	static std::pair<int,int> InOut;
	App(int timer, std::string interfaceIPAddr);
	App();
	static void SetTimer(std::size_t timer);
	static std::size_t GetTimer();
	static std::string interfaceIPAddr;
	static void IP_Check(std::string interfaceIPAddr);

private:


	static std::size_t timer;
	void PrintDetailedStatistics(pcpp::Packet parsedPacket, std::string URL, std::pair<int,int> &InOut);
	void URL_StatisticCount(PacketStats stats, pcpp::RawPacketVector::ConstVectorIterator iter, std::string URL, std::map<std::string, size_t> countURL,
	pcpp::Packet parsedPacket);
	static std::string getProtocolTypeAsString(pcpp::ProtocolType protocolType);
	
};


#endif
