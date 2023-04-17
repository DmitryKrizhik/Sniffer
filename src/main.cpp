#pragma once
#include "App.h"
#include "spdlog/spdlog.h"


int main(int argc, char* argv[])
{
	std::string IP = "10.0.2.15";
	App App;
	int timer = 20;
	if( argc >= 2 && *argv[1] == '1' ) { timer = 10; std::cout << "Short mode" << std::endl << std::endl;}
	if( argc >= 2 && *argv[1] == '2' ) { timer = 20; std::cout << "Standard mode" << std::endl << std::endl;}
	if( argc >= 2 && *argv[1] == '3' ) { timer = 30; std::cout << "Long mode" << std::endl << std::endl;}
	if( argc >= 3) {IP = argv[2];}


	std::string interfaceIPAddr = IP;
	pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr);
	App.IPv4Check(interfaceIPAddr, dev);
	App.PrintAboutInterface(dev);
	App.DevOpeningCheck(dev);
	PacketStats stats; // create the stats object
	std::cout << std::endl << "Starting capture with packet vector..." << std::endl;
	pcpp::RawPacketVector packetVec; // create an empty packet vector object
	dev->startCapture(packetVec); // start capturing packets. All packets will be added to the packet vector
	pcpp::multiPlatformSleep(timer); // sleep for {timer} seconds in main thread, in the meantime packets are captured in the async thread
	dev->stopCapture(); // stop capturing packets
	App.CollectStatistics(App::countURL, packetVec, stats, App::InOut); //collection of statistics
	App.PrintURLcount(App::countURL, App::InOut);
	stats.printToConsole();
	dev->close();
	//auto Logger = spdlog::basic_logger_mt("Logger", "../../Logs.txt");

}
	




	
