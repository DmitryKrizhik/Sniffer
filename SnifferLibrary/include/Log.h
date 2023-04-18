#ifndef _LOGS_
#define _LOGS_
#include "spdlog/spdlog.h" 
#include "spdlog/async.h"  
#include "spdlog/sinks/basic_file_sink.h"

namespace Logs { 
//std::shared_ptr<spdlog::logger> logger;
#define LOG_INFO(...)       spdlog::info(__VA_ARGS__) 
#define LOG_WARN(...)       spdlog::warn(__VA_ARGS__) 
#define LOG_ERROR(...)      spdlog::error(__VA_ARGS__) 
#define LOG_CRITICAL(...)   spdlog::critical(__VA_ARGS__) 
}
#endif 