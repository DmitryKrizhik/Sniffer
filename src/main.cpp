#pragma once
#include "App.h"




// int main(int argc, char* argv[])
// {
// 	// IPv4 address of the interface we want to sniff
// 	std::string interfaceIPAddr = "10.0.2.15";

// 	// find the interface by IP address
// 	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr);
// 	if (dev == NULL)
// 	{
// 		std::cerr << "Cannot find interface with IPv4 address of '" << interfaceIPAddr << "'" << std::endl;
// 		return 1;
// 	}

// 	// Get device info
// 	// ~~~~~~~~~~~~~~~

// 	// before capturing packets let's print some info about this interface
// 	std::cout
// 		<< "Interface info:" << std::endl
// 		<< "   Interface name:        " << dev->getName() << std::endl // get interface name
// 		<< "   Interface description: " << dev->getDesc() << std::endl // get interface description
// 		<< "   MAC address:           " << dev->getMacAddress() << std::endl // get interface MAC address
// 		<< "   Default gateway:       " << dev->getDefaultGateway() << std::endl // get default gateway
// 		<< "   Interface MTU:         " << dev->getMtu() << std::endl; // get interface MTU

// 	if (dev->getDnsServers().size() > 0)
// 		std::cout << "   DNS server:            " << dev->getDnsServers().at(0) << std::endl;

// 	// open the device before start capturing/sending packets
// 	if (!dev->open())
// 	{
// 		std::cerr << "Cannot open device" << std::endl;
// 		return 1;
// 	}

// 	// create the stats object
// 	PacketStats stats;


// 	// Async packet capture with a callback function
// 	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 	std::cout << std::endl << "Starting async capture..." << std::endl;

// 	// start capture in async mode. Give a callback function to call to whenever a packet is captured and the stats object as the cookie
// 	dev->startCapture(App::onPacketArrives, &stats);

// 	// sleep for 10 seconds in main thread, in the meantime packets are captured in the async thread
// 	pcpp::multiPlatformSleep(10);

// 	// stop capturing packets
// 	dev->stopCapture();

// 	// print results
// 	std::cout << "Results:" << std::endl;
// 	stats.printToConsole();

// 	// clear stats
// 	stats.clear();


// 	// Capturing packets in a packet vector
// 	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 	std::cout << std::endl << "Starting capture with packet vector..." << std::endl;

// 	// create an empty packet vector object
// 	pcpp::RawPacketVector packetVec;

// 	// start capturing packets. All packets will be added to the packet vector
// 	dev->startCapture(packetVec);

// 	// sleep for 10 seconds in main thread, in the meantime packets are captured in the async thread
// 	pcpp::multiPlatformSleep(10);

// 	// stop capturing packets
// 	dev->stopCapture();

// 	// go over the packet vector and feed all packets to the stats object
// 	for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
// 	{
// 		// parse raw packet
// 		pcpp::Packet parsedPacket(*iter);

// 		// feed packet to the stats object
// 		stats.consumePacket(parsedPacket);
// 	}

// 	// print results
// 	std::cout << "Results:" << std::endl;
// 	stats.printToConsole();

// 	// clear stats
// 	stats.clear();


// 	// Capturing packets in blocking mode
// 	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 	std::cout << std::endl << "Starting capture in blocking mode..." << std::endl;

// 	// start capturing in blocking mode. Give a callback function to call to whenever a packet is captured, the stats object as the cookie and a 10 seconds timeout
// 	dev->startCaptureBlockingMode(App::onPacketArrivesBlockingMode, &stats, 10);

// 	// thread is blocked until capture is finished

// 	// capture is finished, print results
// 	std::cout << "Results:" << std::endl;
// 	stats.printToConsole();

// 	stats.clear();


// 	// Sending single packets
// 	// ~~~~~~~~~~~~~~~~~~~~~~

// 	std::cout << std::endl << "Sending " << packetVec.size() << " packets one by one..." << std::endl;

// 	// go over the vector of packets and send them one by one
// 	for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
// 	{
// 		// send the packet. If fails exit the application
// 		if (!dev->sendPacket(**iter))
// 		{
// 			std::cerr << "Couldn't send packet" << std::endl;
// 			return 1;
// 		}
// 	}
// 	std::cout << packetVec.size() << " packets sent" << std::endl;


// 	// Sending batch of packets
// 	// ~~~~~~~~~~~~~~~~~~~~~~~~

// 	std::cout << std::endl << "Sending " << packetVec.size() << " packets..." << std::endl;

// 	// send all packets in the vector. The returned number shows how many packets were actually sent (expected to be equal to vector size)
// 	int packetsSent = dev->sendPackets(packetVec);

// 	std::cout << packetsSent << " packets sent" << std::endl;


// 	// Using filters
// 	// ~~~~~~~~~~~~~

// 	// create a filter instance to capture only traffic on port 80
// 	pcpp::PortFilter portFilter(80, pcpp::SRC_OR_DST);

// 	// create a filter instance to capture only TCP traffic
// 	pcpp::ProtoFilter protocolFilter(pcpp::TCP);

// 	// create an AND filter to combine both filters - capture only TCP traffic on port 80
// 	pcpp::AndFilter andFilter;
// 	andFilter.addFilter(&portFilter);
// 	andFilter.addFilter(&protocolFilter);

// 	// set the filter on the device
// 	dev->setFilter(andFilter);

// 	std::cout << std::endl << "Starting packet capture with a filter in place..." << std::endl;

// 	// start capture in async mode. Give a callback function to call to whenever a packet is captured and the stats object as the cookie
// 	dev->startCapture(App::onPacketArrives, &stats);

// 	// sleep for 10 seconds in main thread, in the meantime packets are captured in the async thread
// 	pcpp::multiPlatformSleep(10);

// 	// stop capturing packets
// 	dev->stopCapture();

// 	// print results - should capture only packets which match the filter (which is TCP port 80)
// 	std::cout << "Results:" << std::endl;
// 	stats.printToConsole();


// 	// close the device before application ends
// 	dev->close();
// }
int main(int argc, char* argv[])
{

	App App;
	
	// IPv4 address of the interface we want to sniff
	std::string interfaceIPAddr = "10.0.2.15";

	// find the interface by IP address
	
	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr);
	if (dev == NULL)
	{
		std::cerr << "Cannot find interface with IPv4 address of '" << interfaceIPAddr << "'" << std::endl;
		return 1;
	}
	
	// Get device info
	
	// before capturing packets let's print some info about this interface
	std::cout
		<< "Interface info:" << std::endl
		<< "   Interface name:        " << dev->getName() << std::endl // get interface name
		<< "   Interface description: " << dev->getDesc() << std::endl // get interface description
		<< "   MAC address:           " << dev->getMacAddress() << std::endl // get interface MAC address
		<< "   Default gateway:       " << dev->getDefaultGateway() << std::endl // get default gateway
		<< "   Interface MTU:         " << dev->getMtu() << std::endl // get interface MTU
		<< "   Interface IP:          " << dev->getIPv4Address() << std::endl; // get interface MTU


	if (dev->getDnsServers().size() > 0)
		std::cout << "   DNS server:            " << dev->getDnsServers().at(0) << std::endl;

	// open the device before start capturing/sending packets
	if (!dev->open())
	{
		std::cerr << "Cannot open device" << std::endl;
		return 1;
	}

	// create the stats object
	PacketStats stats;

	std::cout << std::endl << "Starting capture with packet vector..." << std::endl;

	// create an empty packet vector object
	pcpp::RawPacketVector packetVec;

	// start capturing packets. All packets will be added to the packet vector
	
	dev->startCapture(packetVec);
	pcpp::multiPlatformSleep(15);

	// stop capturing packets
	dev->stopCapture();

	for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
	{
	    // parse raw packet
	    pcpp::Packet parsedPacket(*iter);

	    // feed packet to the stats object
	    stats.consumePacket(parsedPacket);

		// pcpp::Packet parsedPacket(&rawPacket); 

		
	
	//for (pcpp::Layer* curLayer = parsedPacket.getFirstLayer(); curLayer != NULL; curLayer = curLayer->getNextLayer()){
	// {
	//     std::cout
	// 	<< "Layer type: " << App.getProtocolTypeAsString(curLayer->getProtocol()) << "; " // get layer type
	// 	<< "Total data: " << curLayer->getDataLen() << " [bytes]; " // get total length of the layer
	// 	<< "Layer data: " << curLayer->getHeaderLen() << " [bytes]; " // get the header length of the layer
	// 	<< "Layer payload: " << curLayer->getLayerPayloadSize() << " [bytes]" // get the payload length of the layer (equals total length minus header length)
	// 	<< std::endl;
	
	
	if (parsedPacket.isPacketOfType(pcpp::HTTPRequest) ) 
	{ 
		
		pcpp::Layer *ptrLayer = parsedPacket.getLayerOfType(pcpp::HTTPRequest); 
		pcpp::HttpRequestLayer* ptrHttpLayer = dynamic_cast<pcpp::HttpRequestLayer*>(ptrLayer); 
	
		if (ptrHttpLayer != NULL) 
		{ 
			
			App.str = ptrHttpLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue(); 
			
			std::map<std::string, std::size_t>::iterator it = App.countURL.find(App.str);
			
			if(it != App.countURL.end()) 
			{
			
			App.countURL[App.str] += 1;}

			else{ App.countURL[App.str] = 1;}
		} 
	}
	
	}
	// if (parsedPacket.isPacketOfType(pcpp::HTTPResponse) ) 
	// { 
		
	// 	pcpp::Layer *ptrLayer = parsedPacket.getLayerOfType(pcpp::HTTPResponse); 
	// 	pcpp::HttpResponseLayer* ptrHttpLayer = dynamic_cast<pcpp::HttpResponseLayer*>(ptrLayer); 
	
	// 	if (ptrHttpLayer != NULL) 
	// 	{ 
			
	// 		App.str = ptrHttpLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue(); 
			
	// 		std::map<std::string, std::size_t>::iterator it = App.countURL.find(App.str);
			
	// 		if(it != App.countURL.end()) 
	// 		{
			
	// 		App.countURL[App.str] += 1;}

	// 		else{ App.countURL[App.str] = 1;}
	// 	} 
		
	// }
	App.PrintURLcount();
	// print results
	
	std::cout << "Results:" << std::endl;
	stats.printToConsole();

	// std::cout << std::endl << "Sending " << packetVec.size() << " packets one by one..." << std::endl;

	// // go over the vector of packets and send them one by one
	
	// std::cout << std::endl << "Sending " << packetVec.size() << " packets..." << std::endl;

	// send all packets in the vector. The returned number shows how many packets were actually sent (expected to be equal to vector size)
	
	
	
	//stats.printToConsole();
	// close the device before application ends
	// use the IFileReaderDevice interface to automatically identify file type (pcap/pcap-ng)
	// and create an interface instance that both readers implement
	pcpp::IFileReaderDevice* reader = pcpp::IFileReaderDevice::getReader("1_http_packet.pcap");

	// verify that a reader interface was indeed created
	if (reader == NULL)
	{
	    std::cerr << "Cannot determine reader for file type" << std::endl;
	    return 1;
	}

	// open the reader for reading
	if (!reader->open())
	{
	    std::cerr << "Cannot open input.pcap for reading" << std::endl;
	    return 1;
	}

	// read the first (and only) packet from the file
	pcpp::RawPacket rawPacket;
	if (!reader->getNextPacket(rawPacket))
	{
	    std::cerr << "Couldn't read the first packet in the file" << std::endl;
	    return 1;
	}

	// close the file reader, we don't need it anymore


	// pcpp::Packet parsedPacket(&rawPacket); 
	// std::string str;
	
	
	// if ( parsedPacket.isPacketOfType(pcpp::HTTPRequest) ) 
	// { 
	// 	//std::cout << "AAA" << std::endl;
	// 	pcpp::Layer *ptrLayer = parsedPacket.getLayerOfType(pcpp::HTTPRequest); 
	// 	pcpp::HttpRequestLayer* ptrHttpLayer = dynamic_cast<pcpp::HttpRequestLayer*>(ptrLayer); 
	
	// 	if (ptrHttpLayer != NULL) 
	// 	{ 
	// 		//std::cout << "BBB" << std::endl;
	// 		str = ptrHttpLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue(); 
	// 		//str = "vk.com"; 
	// 		//auto it = find(std::begin(countURL), std::end(countURL), str);
			
	// 		std::map<std::string, std::size_t>::iterator it = App.countURL.find(str);
			
	// 		if(it != App.countURL.end()) 
	// 		{
	// 		//std::cout << "URL HAS BEEN ADDED" << std::endl;
	// 		App.countURL[str] += 1;}

	// 		else{ 
	// 			//std::cout << "CCC" << std::endl;
	// 			App.countURL[str] = 1;}
	// 		} 
	
	
	// }
	/**/
	//else 
	
	// App.countURL.insert(std::make_pair("100", 1));
	// //App.PrintURLcount();
	
	// 	//std::map<std::string, size_t>::iterator iter = App::countURL.begin();
	// 	for (auto el : App.countURL)
	// 	{
	// 		std::cout << std::endl << str << " : " << App.countURL[str];
	// 	}
	
	reader->close();
	

 
	//pcpp::Packet parsedPacket(&rawPacket); 
	
	

	
	//std::map<std::string, std::size_t> countURL; 
 

	
	
	
	/*
	//if (argv[0] == "1") {std::cout << "Hello" << std::endl;}
	//App.printVersion();
	//App.printPath();
	
	// IPv4 address of the interface we want to sniff
	std::string interfaceIPAddr = "127.0.0.1";

	// find the interface by IP address
	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr);
	if (dev == NULL)
	{
		std::cerr << "Cannot find interface with IPv4 address of '" << interfaceIPAddr << "'" << std::endl;
		return 1;
	}
	
	// Get device info
	
	// before capturing packets let's print some info about this interface
	std::cout
		<< "Interface info:" << std::endl
		<< "   Interface name:        " << dev->getName() << std::endl // get interface name
		<< "   Interface description: " << dev->getDesc() << std::endl // get interface description
		<< "   MAC address:           " << dev->getMacAddress() << std::endl // get interface MAC address
		<< "   Default gateway:       " << dev->getDefaultGateway() << std::endl // get default gateway
		<< "   Interface MTU:         " << dev->getMtu() << std::endl; // get interface MTU

	if (dev->getDnsServers().size() > 0)
		std::cout << "   DNS server:            " << dev->getDnsServers().at(0) << std::endl;

	// open the device before start capturing/sending packets
	if (!dev->open())
	{
		std::cerr << "Cannot open device" << std::endl;
		return 1;
	}

	// create the stats object
	PacketStats stats;

	// Async packet capture with a callback function
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	std::cout << std::endl << "Starting capture with packet vector..." << std::endl;

	// create an empty packet vector object
	pcpp::RawPacketVector packetVec;

	// start capturing packets. All packets will be added to the packet vector
	dev->startCapture(packetVec);
	pcpp::multiPlatformSleep(3);

	// stop capturing packets
	dev->stopCapture();

	for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
	{
	    // parse raw packet
	    pcpp::Packet parsedPacket(*iter);

	    // feed packet to the stats object
	    stats.consumePacket(parsedPacket);
	}
	// print results
	std::cout << "Results:" << std::endl;
	stats.printToConsole();

	std::cout << std::endl << "Sending " << packetVec.size() << " packets one by one..." << std::endl;

	// go over the vector of packets and send them one by one
	for (pcpp::RawPacketVector::ConstVectorIterator iter = packetVec.begin(); iter != packetVec.end(); iter++)
	{
	    // send the packet. If fails exit the application
	    if (!dev->sendPacket(**iter))
	    {
		std::cerr << "Couldn't send packet" << std::endl;
		return 1;
	    }
	}
	std::cout << std::endl << "Sending " << packetVec.size() << " packets..." << std::endl;

	// send all packets in the vector. The returned number shows how many packets were actually sent (expected to be equal to vector size)
	int packetsSent = dev->sendPackets(packetVec);
	std::cout << packetsSent << " packets sent" << std::endl;
	
	
	//stats.printToConsole();
	// close the device before application ends
	// use the IFileReaderDevice interface to automatically identify file type (pcap/pcap-ng)
	// and create an interface instance that both readers implement
	pcpp::IFileReaderDevice* reader = pcpp::IFileReaderDevice::getReader("1_http_packet.pcap");

	// verify that a reader interface was indeed created
	if (reader == NULL)
	{
	    std::cerr << "Cannot determine reader for file type" << std::endl;
	    return 1;
	}

	// open the reader for reading
	if (!reader->open())
	{
	    std::cerr << "Cannot open input.pcap for reading" << std::endl;
	    return 1;
	}

	// read the first (and only) packet from the file
	pcpp::RawPacket rawPacket;
	if (!reader->getNextPacket(rawPacket))
	{
	    std::cerr << "Couldn't read the first packet in the file" << std::endl;
	    return 1;
	}

	// close the file reader, we don't need it anymore
	reader->close();
	pcpp::Packet parsedPacket(&rawPacket);
	
	// first let's go over the layers one by one and find out its type, its total length, its header length and its payload length
	for (pcpp::Layer* curLayer = parsedPacket.getFirstLayer(); curLayer != NULL; curLayer = curLayer->getNextLayer())
	{
	    std::cout
		<< "Layer type: " << App.getProtocolTypeAsString(curLayer->getProtocol()) << "; " // get layer type
		<< "Total data: " << curLayer->getDataLen() << " [bytes]; " // get total length of the layer
		<< "Layer data: " << curLayer->getHeaderLen() << " [bytes]; " // get the header length of the layer
		<< "Layer payload: " << curLayer->getLayerPayloadSize() << " [bytes]" // get the payload length of the layer (equals total length minus header length)
		<< std::endl;
	}
	
	// now let's get the Ethernet layer
pcpp::EthLayer* ethernetLayer = parsedPacket.getLayerOfType<pcpp::EthLayer>();
if (ethernetLayer == NULL)
{
    std::cerr << "Something went wrong, couldn't find Ethernet layer" << std::endl;
    return 1;
}
// print the source and dest MAC addresses and the Ether type
std::cout << std::endl
    << "Source MAC address: " << ethernetLayer->getSourceMac() << std::endl
    << "Destination MAC address: " << ethernetLayer->getDestMac() << std::endl
    << "Ether type = 0x" << std::hex << pcpp::netToHost16(ethernetLayer->getEthHeader()->etherType) << std::endl;
	
	
	pcpp::IPv4Layer* ipLayer = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();
if (ipLayer == NULL)
{
    std::cerr << "Something went wrong, couldn't find IPv4 layer" << std::endl;
    return 1;
}
// print source and dest IP addresses, IP ID and TTL
std::cout << std::endl
    << "Source IP address: " << ipLayer->getSrcIPAddress() << std::endl
    << "Destination IP address: " << ipLayer->getDstIPAddress() << std::endl
    << "IP ID: 0x" << std::hex << pcpp::netToHost16(ipLayer->getIPv4Header()->ipId) << std::endl
    << "TTL: " << std::dec << (int)ipLayer->getIPv4Header()->timeToLive << std::endl;
    
    // let's get the TCP layer
pcpp::TcpLayer* tcpLayer = parsedPacket.getLayerOfType<pcpp::TcpLayer>();
if (tcpLayer == NULL)
{
    std::cerr << "Something went wrong, couldn't find TCP layer" << std::endl;
    return 1;
}

// print TCP source and dest ports, window size, and the TCP flags that are set in this layer
std::cout << std::endl
    << "Source TCP port: " << tcpLayer->getSrcPort() << std::endl
    << "Destination TCP port: " << tcpLayer->getDstPort() << std::endl
    << "Window size: " << pcpp::netToHost16(tcpLayer->getTcpHeader()->windowSize) << std::endl
    << "TCP flags: " << App.printTcpFlags(tcpLayer) << std::endl;
    
    
// go over all TCP options in this layer and print its type
std::cout << "TCP options: ";
for (pcpp::TcpOption tcpOption = tcpLayer->getFirstTcpOption(); tcpOption.isNotNull(); tcpOption = tcpLayer->getNextTcpOption(tcpOption))
{
    std::cout << App.printTcpOptionType(tcpOption.getTcpOptionType()) << " ";
}
std::cout << std::endl;





// let's get the HTTP request layer
pcpp::HttpRequestLayer* httpRequestLayer = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();
if (httpRequestLayer == NULL)
{
    std::cerr << "Something went wrong, couldn't find HTTP request layer" << std::endl;
    return 1;
}



// print HTTP method and URI. Both appear in the first line of the HTTP request
std::cout << std::endl
    << "HTTP method: " << App.printHttpMethod(httpRequestLayer->getFirstLine()->getMethod()) << std::endl
    << "HTTP URI: " << httpRequestLayer->getFirstLine()->getUri() << std::endl;
    
    

// print values of the following HTTP field: Host, User-Agent and Cookie
std::cout
    << "HTTP host: " << httpRequestLayer->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue() << std::endl
    << "HTTP user-agent: " << httpRequestLayer->getFieldByName(PCPP_HTTP_USER_AGENT_FIELD)->getFieldValue() << std::endl
    << "HTTP cookie: " << httpRequestLayer->getFieldByName(PCPP_HTTP_COOKIE_FIELD)->getFieldValue() << std::endl;
    
    
    // print the full URL of this request
std::cout << "HTTP full URL: " << httpRequestLayer->getUrl() << std::endl;
*/
dev->close();
	}


