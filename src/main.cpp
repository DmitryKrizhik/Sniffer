
#include "App.h"

//#include "spdlog/spdlog.h"


int main(int argc, char* argv[])
{
	
	App App(20, "10.0.2.15"); //Creating an object of class APP
	 //Default running time

	//Choice of working time
	if( argc >= 2 && *argv[1] == '1' ) { App::SetTimer(10); std::cout << std::endl; LOG_INFO("Sniffer<Short mode>"); std::cout << std::endl;}
	if( argc >= 2 && *argv[1] == '2' ) { App::SetTimer(20); std::cout << std::endl; LOG_INFO("Sniffer<Standard mode>"); std::cout << std::endl;}
	if( argc >= 2 && *argv[1] == '3' ) { App::SetTimer(30); std::cout << std::endl; LOG_INFO("Sniffer<Long mode>"); std::cout << std::endl;}
	if( argc >= 3) {App::interfaceIPAddr = argv[2]; LOG_INFO("Sniffer<interfaceIPAddr = " + App::interfaceIPAddr + ">");}

	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(App::interfaceIPAddr);
	App.IPv4Check(App::interfaceIPAddr, dev);
	App.PrintAboutInterface(dev);
	App.DevOpeningCheck(dev);
	PacketStats stats; // Create the stats object
	LOG_INFO("Starting capture with packet vector...");
	pcpp::RawPacketVector packetVec; // Create an empty packet vector object
	dev->startCapture(packetVec); // Start capturing packets. All packets will be added to the packet vector
	pcpp::multiPlatformSleep(App::GetTimer()); // Sleep for {timer} seconds in main thread, in the meantime packets are captured in the async thread
	dev->stopCapture(); // Stop capturing packets
	App.CollectStatistics(App::countURL, packetVec, stats, App::InOut, App::URL); //Collection of statistics
	App.PrintURLcount(App::countURL, App::InOut);
	stats.printToConsole();
	LOG_INFO("Sniffer<dev->close()>");
	dev->close();
}
	




	
