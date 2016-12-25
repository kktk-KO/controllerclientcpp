#include <mujincontrollerclient/binpickingtask.h>
#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#undef GetUserName // clashes with ControllerClient::GetUserName
#endif // defined(_WIN32) || defined(_WIN64)


#ifndef MUJIN_TIME
#define MUJIN_TIME
#include <time.h>

#ifndef _WIN32
#if !(defined(CLOCK_GETTIME_FOUND) && (POSIX_TIMERS > 0 || _POSIX_TIMERS > 0))
#include <sys/time.h>
#endif // !(defined(CLOCK_GETTIME_FOUND) && (POSIX_TIMERS > 0 || _POSIX_TIMERS > 0))
#else
#include <sys/timeb.h>    // ftime(), struct timeb
inline void usleep(unsigned long microseconds) {
    Sleep((microseconds+999)/1000);
}
#endif  // _WIN32

#ifdef _WIN32
inline unsigned long long GetMilliTime()
{
    LARGE_INTEGER count, freq;
    QueryPerformanceCounter(&count);
    QueryPerformanceFrequency(&freq);
    return (unsigned long long)((count.QuadPart * 1000) / freq.QuadPart);
}

#else

inline void GetWallTime(unsigned int& sec, unsigned int& nsec)
{
#if defined(CLOCK_GETTIME_FOUND) && (POSIX_TIMERS > 0 || _POSIX_TIMERS > 0)
    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);
    sec  = start.tv_sec;
    nsec = start.tv_nsec;
#else
    struct timeval timeofday;
    gettimeofday(&timeofday,NULL);
    sec  = timeofday.tv_sec;
    nsec = timeofday.tv_usec * 1000;
#endif //defined(CLOCK_GETTIME_FOUND) && (POSIX_TIMERS > 0 || _POSIX_TIMERS > 0)
}

inline unsigned long long GetMilliTime()
{
    unsigned int sec,nsec;
    GetWallTime(sec,nsec);
    return (unsigned long long)sec*1000 + (unsigned long long)nsec/1000000;
}
#endif // _WIN32
#endif // MUJIN_TIME

using namespace mujinclient;

#include <boost/program_options.hpp>
#include <boost/thread.hpp>

void TestThread(SceneResourcePtr scene, int id)
{
    try {
        //std::cout << id << " " << GetMilliTime() << std::endl;
        std::map<std::string, std::string> mAllCameraNameHardwareId; // mapping of all the cameras, even ones that are not used
        scene->GetSensorMapping(mAllCameraNameHardwareId);
        //std::cout << id << " " << GetMilliTime() << " mAllCameraNameHardwareId.size()=" << mAllCameraNameHardwareId.size() << std::endl;
        std::cout << mAllCameraNameHardwareId.size() << std::endl;
    }
    catch(const std::exception& ex) {
        std::stringstream errss;
        errss << "Caught exception " << ex.what();
        std::cerr << errss.str() << std::endl;
    }
    catch (...) {
        std::stringstream errss;
        errss << "Caught unknown exception!";
        std::cerr << errss.str() << std::endl;
    }
}


int main(int argc, char ** argv)
{
    // parse command line arguments
    namespace bpo = boost::program_options;
    bpo::options_description desc("Options");

    desc.add_options()
        ("help,h", "produce help message")
        ("controller_ip", bpo::value<std::string>()->required(), "ip of the mujin controller, e.g. controller")
        ("controller_port", bpo::value<unsigned int>()->default_value(80), "port of the mujin controller, e.g. 80")
        ("controller_username_password", bpo::value<std::string>()->required(), "username and password to the mujin controller, e.g. username:password")
        ("controller_command_timeout", bpo::value<double>()->default_value(10), "command timeout in seconds, e.g. 10")
        ("locale", bpo::value<std::string>()->default_value("en_US"), "locale to use for the mujin controller client")
        ("binpicking_task_scenepk", bpo::value<std::string>()->required(), "scene pk of the binpicking task on the mujin controller, e.g. officeboltpicking.mujin.dae")
        ("n", bpo::value<unsigned int>()->default_value(1))
    ;

    bpo::variables_map opts;
    bpo::store(bpo::parse_command_line(argc, argv, desc), opts);
    bool badargs = false;
    try {
        bpo::notify(opts);
    }
    catch(...) {
        badargs = true;
    }
    if(opts.count("help") || badargs) {
        std::cout << "Usage: " << argv[0] << " [OPTS]" << std::endl;
        std::cout << std::endl;
        std::cout << desc << std::endl;
        return (1);
    }

    const std::string controllerIp = opts["controller_ip"].as<std::string>();
    const unsigned int controllerPort = opts["controller_port"].as<unsigned int>();
    const std::string controllerUsernamePass = opts["controller_username_password"].as<std::string>();
    const double controllerCommandTimeout = opts["controller_command_timeout"].as<double>();
    const std::string binpickingTaskScenePk = opts["binpicking_task_scenepk"].as<std::string>();
    const std::string locale = opts["locale"].as<std::string>();
    const unsigned int n = opts["n"].as<unsigned int>();
    std::string tasktype = "binpicking";
    std::stringstream url_ss;
    url_ss << "http://"<< controllerIp << ":" << controllerPort;
    std::string url = url_ss.str();
    boost::thread t0, t1;
    ControllerClientPtr controllerclient = CreateControllerClient(controllerUsernamePass, url);
    SceneResourcePtr scene(new SceneResource(controllerclient, binpickingTaskScenePk));
    ControllerClientPtr controllerclient1 = CreateControllerClient(controllerUsernamePass, url);
    SceneResourcePtr scene1(new SceneResource(controllerclient, binpickingTaskScenePk));
    boost::thread_group threads;
    for (int i = 0; i < n; ++i) {
        threads.create_thread(boost::bind(&TestThread, scene, i));
    }
    threads.join_all();
}
