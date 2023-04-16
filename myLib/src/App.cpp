#pragma once
#ifndef _APP_1
#define _APP_1
#include <iostream>
#include "App.h"
	

	/**
	 * A callback function for the async capture which is called each time a packet is captured
	 */
	void App::onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
	{
		// extract the stats object form the cookie
		PacketStats* stats = (PacketStats*)cookie;

		// parsed the raw packet
		pcpp::Packet parsedPacket(packet);

		// collect stats from packet
		stats->consumePacket(parsedPacket);
	}


	/**
	 * a callback function for the blocking mode capture which is called each time a packet is captured
	 */
	bool App::onPacketArrivesBlockingMode(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
	{
		// extract the stats object form the cookie
		PacketStats* stats = (PacketStats*)cookie;

		// parsed the raw packet
		pcpp::Packet parsedPacket(packet);

		// collect stats from packet
		stats->consumePacket(parsedPacket);

		// return false means we don't want to stop capturing after this callback
		return false;
	}
	std::string App::getProtocolTypeAsString(pcpp::ProtocolType protocolType)
	{
	    switch (protocolType)
	    {
	    case pcpp::Ethernet:
		return "Ethernet";
	    case pcpp::IPv4:
		return "IPv4";
	    case pcpp::TCP:
		return "TCP";
	    case pcpp::HTTPRequest:
	    case pcpp::HTTPResponse:
		return "HTTP";
	    default:
		return "Unknown";
	    }
	}
	std::string App::printHttpMethod(pcpp::HttpRequestLayer::HttpMethod httpMethod)
	{
	    switch (httpMethod)
	    {
	    case pcpp::HttpRequestLayer::HttpGET:
		return "GET";
	    case pcpp::HttpRequestLayer::HttpPOST:
		return "POST";
	    default:
		return "Other";
	    }
	}
	std::string App::printTcpOptionType(pcpp::TcpOptionType optionType)
	{
	    switch (optionType)
	    {
	    case pcpp::PCPP_TCPOPT_NOP:
		return "NOP";
	    case pcpp::PCPP_TCPOPT_TIMESTAMP:
		return "Timestamp";
	    default:
		return "Other";
	    }
	}
	std::string App::printTcpFlags(pcpp::TcpLayer* tcpLayer)
{
    std::string result = "";
    if (tcpLayer->getTcpHeader()->synFlag == 1)
        result += "SYN ";
    if (tcpLayer->getTcpHeader()->ackFlag == 1)
        result += "ACK ";
    if (tcpLayer->getTcpHeader()->pshFlag == 1)
        result += "PSH ";
    if (tcpLayer->getTcpHeader()->cwrFlag == 1)
        result += "CWR ";
    if (tcpLayer->getTcpHeader()->urgFlag == 1)
        result += "URG ";
    if (tcpLayer->getTcpHeader()->eceFlag == 1)
        result += "ECE ";
    if (tcpLayer->getTcpHeader()->rstFlag == 1)
        result += "RST ";
    if (tcpLayer->getTcpHeader()->finFlag == 1)
        result += "FIN ";

    return result;
}
	std::map<std::string, size_t> countURL = {}; 
	std::string str = "";	
	void App::PrintURLcount()
	{
		//std::map<std::string, size_t>::iterator it = App::countURL.begin();
		// for (std::map<std::string, size_t>::iterator &el : App.countURL)
		// {
		// 	std::cout << std::endl << el->first << " : " << el->second << std::endl;
		// }
		for (auto &el : App::countURL)
		{
			std::cout << std::endl << el.first << " : " << el.second << std::endl;
		}
	}	
	//pcpp::HttpRequestLayer* App::httpRequestLayer = pcpp::parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();





/*void printVersion()
 {
 	std::cout << "Version: " << g_version1 << std::endl;
 }
 void printPath()
 {
 	std::cout << "Path to source of project: " << g_source_path1 << std::endl;
 	std::cout << "Path to binary of project: " << g_binary_path1 << std::endl;
 }*/
#endif
