#ifndef _APP_1
#define _APP_1
#include <iostream>
#include "App.h"
	

	std::string App::interfaceIPAddr = "";
	bool App::IPv4Check(std::string interfaceIPAddr, pcpp::PcapLiveDevice* dev)
	{
		LOG_INFO("IPv4Check<Method started>");
	if (dev == NULL)
		{	
			//LOG_ERROR("IPv4Check<ERROR: Cannot find the interface>");
			std::cerr << "Cannot find interface with IPv4 address of '" << interfaceIPAddr << "'" << std::endl;
			throw std::runtime_error("IPv4Check<ERROR: Cannot find the interface>");
			return false;
		}
		LOG_INFO("IPv4Check<Interface found>");
		return true;
	}

	bool App::DevOpeningCheck(pcpp::PcapLiveDevice* dev)
	{
		LOG_INFO("DevOpeningCheck<Method started>");
		if (!dev->open())
		{
			std::cerr << "Cannot open device" << std::endl;
			//LOG_ERROR("DevOpeningCheck<Cannot open device>");
			throw std::runtime_error("DevOpeningCheck<Cannot open device>");
			return false;
		}
		else 
			{LOG_INFO("DevOpeningCheck<Device opened successful>");	
			return true;}
	}

	std::string App::getProtocolTypeAsString(pcpp::ProtocolType protocolType)
	{
		//LOG_INFO("getProtocolTypeAsString<Method started>");
		if(protocolType == pcpp::HTTPRequest) {return "HTTPRequest";}
		if(protocolType == pcpp::HTTPResponse) {return "HTTPResponse";}
		else {return "Unknown";}
	}
	std::pair<int,int> App::InOut = std::make_pair(0,0);
	void App::CollectStatistics(std::map<std::string, std::size_t> &countURL, pcpp::RawPacketVector packetVec, PacketStats &stats, std::pair<int,int> &InOut)
		{
			LOG_INFO("CollectStatistics<Method started>");
			
			std::string str = "";
			for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
		{
			pcpp::Packet parsedPacket(*iter); // parse raw packet
			stats.consumePacket(parsedPacket); // feed packet to the stats object
			
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
		LOG_INFO("PrintURLcount<Method started>");
		std::cout << std::endl;
		for (auto &el : countURL)
		{
			std::cout << el.first << " : " << el.second << std::endl;
		}
		std::cout << std::endl << "HTTPRequests: " << InOut.first << "\t" << "HTTPResponse: " << InOut.second << std::endl << std::endl;
	}	

	void App::PrintAboutInterface(pcpp::PcapLiveDevice* dev)
	{
		LOG_INFO("PrintAboutInterface<Method started>");
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


#endif
