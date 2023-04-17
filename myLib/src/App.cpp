#pragma once
#ifndef _APP_1
#define _APP_1
#include <iostream>
#include "App.h"
	
	bool App::IPv4Check(std::string interfaceIPAddr, pcpp::PcapLiveDevice* dev)
	{
	if (dev == NULL)
		{
			std::cerr << "Cannot find interface with IPv4 address of '" << interfaceIPAddr << "'" << std::endl;
			return false;
		}
		return true;
	}

	bool App::DevOpeningCheck(pcpp::PcapLiveDevice* dev)
	{
		if (!dev->open())
		{
			std::cerr << "Cannot open device" << std::endl;
			return false;
		}
	}



std::string App::getProtocolTypeAsString(pcpp::ProtocolType protocolType)
{
	if(protocolType == pcpp::HTTPRequest) {return "HTTPRequest";}
	if(protocolType == pcpp::HTTPResponse) {return "HTTPResponse";}
	else {return "Unknown";}
}
std::pair<int,int> App::InOut = std::make_pair(0,0);
void App::CollectStatistics(std::map<std::string, std::size_t> &countURL, pcpp::RawPacketVector packetVec, PacketStats &stats, std::pair<int,int> &InOut)
	{
		std::cout << "Detailed statistics: " << std::endl;
		std::string str = "";
		
		for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
	{
	    pcpp::Packet parsedPacket(*iter); // parse raw packet
	    stats.consumePacket(parsedPacket); // feed packet to the stats object
		// pcpp::RawPacket rawPacket;
		// pcpp::Packet parsedPacket(&rawPacket);
		if (parsedPacket.isPacketOfType(pcpp::HTTPRequest)) 
		{ 
			pcpp::Layer *ptrLayer = parsedPacket.getLayerOfType(pcpp::HTTPRequest); 
			pcpp::HttpRequestLayer* ptrHttpLayer = dynamic_cast<pcpp::HttpRequestLayer*>(ptrLayer); 
		
			if (ptrHttpLayer != NULL) 
			{ 
				
				str = ptrHttpLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue(); 
				
				std::map<std::string, std::size_t>::iterator it = countURL.find(str);
				
				if(it != countURL.end()) 
				{
				
				countURL[str] += 2;}

				else{ countURL[str] = 2;}
			} 
		}
		
		for (pcpp::Layer* curLayer = parsedPacket.getFirstLayer(); curLayer != NULL; curLayer = curLayer->getNextLayer())
	{
		if (App::getProtocolTypeAsString(curLayer->getProtocol()) == "HTTPRequest"){
		std::cout
			<< "URL: " << str << "  "
			<< "Layer type: " << App::getProtocolTypeAsString(curLayer->getProtocol()) << "; " // get layer type
			<< "Total data: " << curLayer->getDataLen() << " [bytes]; " // get total length of the layer
			<< "Layer data: " << curLayer->getHeaderLen() << " [bytes]; " // get the header length of the layer
			<<"Layer payload: " << curLayer->getLayerPayloadSize() << " [bytes]" // get the payload length
			<< std::endl;
			InOut.second++;
		}
		else if(App::getProtocolTypeAsString(curLayer->getProtocol()) == "HTTPResponse")
		{
			std::cout
			<< "URL: " << str << "  "
			<< "Layer type: " << App::getProtocolTypeAsString(curLayer->getProtocol()) << "; " // get layer type
			<< "Total data: " << curLayer->getDataLen() << " [bytes]; " // get total length of the layer
			<< "Layer data: " << curLayer->getHeaderLen() << " [bytes]; " // get the header length of the layer
			<< "Layer payload: " << curLayer->getLayerPayloadSize() << " [bytes]" // get the payload length
			<< std::endl;
			InOut.first++;
		}
		
	}
		
	}
	}
	std::map<std::string, size_t> App::countURL = {}; 	
	void App::PrintURLcount(std::map<std::string, std::size_t> countURL, std::pair<int,int> InOut)
	{
		std::cout << std::endl;
		for (auto &el : countURL)
		{
			std::cout << el.first << " : " << el.second << std::endl;
		}
		std::cout << "HTTPRequests: " << InOut.first << "\t" << "HTTPResponse: " << InOut.second << std::endl;
	}	

	void App::PrintAboutInterface(pcpp::PcapLiveDevice* dev)
	{
		std::cout
		<< "Interface info:" << std::endl
		<< "   Interface name:        " << dev->getName() << std::endl 
		<< "   Interface description: " << dev->getDesc() << std::endl 
		<< "   MAC address:           " << dev->getMacAddress() << std::endl 
		<< "   Default gateway:       " << dev->getDefaultGateway() << std::endl 
		<< "   Interface MTU:         " << dev->getMtu() << std::endl 
		<< "   Interface IP:          " << dev->getIPv4Address() << std::endl; 
		if (dev->getDnsServers().size() > 0){
		std::cout << "   DNS server:            " << dev->getDnsServers().at(0) << std::endl;}

	}


	
	// void App::CollectInOutStatistics(std::pair<int,int> &InOut, pcpp::RawPacketVector packetVec)
	// {
	// 	for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++){
	// 		pcpp::Packet parsedPacket(*iter);
	// 		for (pcpp::Layer* curLayer = parsedPacket.getFirstLayer(); curLayer != NULL; curLayer = curLayer->getNextLayer())
	// 			{
	// 				if(App::getProtocolTypeAsString(curLayer->getProtocol()) == "OUT") {InOut.second++;}
	// 				if(App::getProtocolTypeAsString(curLayer->getProtocol()) == "IN") {InOut.first++;}
	// 			}
	// }
	// }


	/**
	 * a callback function for the blocking mode capture which is called each time a packet is captured
	 */
	// bool App::onPacketArrivesBlockingMode(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
	// {
	// 	// extract the stats object form the cookie
	// 	PacketStats* stats = (PacketStats*)cookie;

	// 	// parsed the raw packet
	// 	pcpp::Packet parsedPacket(packet);

	// 	// collect stats from packet
	// 	stats->consumePacket(parsedPacket);

	// 	// return false means we don't want to stop capturing after this callback
	// 	return false;
	// }
	
	// std::string App::printHttpMethod(pcpp::HttpRequestLayer::HttpMethod httpMethod)
	// {
	//     switch (httpMethod)
	//     {
	//     case pcpp::HttpRequestLayer::HttpGET:
	// 	return "GET";
	//     case pcpp::HttpRequestLayer::HttpPOST:
	// 	return "POST";
	//     default:
	// 	return "Other";
	//     }
	// }
	// std::string App::printTcpOptionType(pcpp::TcpOptionType optionType)
	// {
	//     switch (optionType)
	//     {
	//     case pcpp::PCPP_TCPOPT_NOP:
	// 	return "NOP";
	//     case pcpp::PCPP_TCPOPT_TIMESTAMP:
	// 	return "Timestamp";
	//     default:
	// 	return "Other";
	//     }
// 	// }
// 	std::string App::printTcpFlags(pcpp::TcpLayer* tcpLayer)
// {
//     std::string result = "";
//     if (tcpLayer->getTcpHeader()->synFlag == 1)
//         result += "SYN ";
//     if (tcpLayer->getTcpHeader()->ackFlag == 1)
//         result += "ACK ";
//     if (tcpLayer->getTcpHeader()->pshFlag == 1)
//         result += "PSH ";
//     if (tcpLayer->getTcpHeader()->cwrFlag == 1)
//         result += "CWR ";
//     if (tcpLayer->getTcpHeader()->urgFlag == 1)
//         result += "URG ";
//     if (tcpLayer->getTcpHeader()->eceFlag == 1)
//         result += "ECE ";
//     if (tcpLayer->getTcpHeader()->rstFlag == 1)
//         result += "RST ";
//     if (tcpLayer->getTcpHeader()->finFlag == 1)
//         result += "FIN ";

//     return result;
// }
	


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
