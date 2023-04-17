#pragma once
#include "App.h"


int main(int argc, char* argv[])
{

	App App;
	std::string interfaceIPAddr = "10.0.2.15";
	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr);
	App.IPv4Check(interfaceIPAddr, dev);
	App.PrintAboutInterface(dev);
	App.DevOpeningCheck(dev);
	PacketStats stats; // create the stats object
	std::cout << std::endl << "Starting capture with packet vector..." << std::endl;
	pcpp::RawPacketVector packetVec; // create an empty packet vector object
	dev->startCapture(packetVec); // start capturing packets. All packets will be added to the packet vector
	pcpp::multiPlatformSleep(10); // sleep for 10 seconds in main thread, in the meantime packets are captured in the async thread
	dev->stopCapture(); // stop capturing packets
	App.CollectStatistics(App::countURL, packetVec, stats); //collection of statistics
	//App.CollectInOutStatistics(App::InOut, packetVec);
	//std::cout << App::InOut.first << "\t" << App::InOut.second << std::endl;


App.PrintURLcount(App::countURL);
stats.printToConsole();
dev->close();
}
	




	
