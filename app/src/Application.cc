/*
 * =============================================================================
 *
 *       Filename:  Application.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/12/15 19:07:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Keivan
 *   Organization:  None
 *
 * =============================================================================
 */

#include <cassert>
#include <new>
#include <stdlib.h>
#include <vector>
#include "Logger.h"
#include "ConfigLoaderFactory.h"
#include "ConfigLoader.h"
#include "ConfigSegment.h"
#include "Config.h"
#include "RootConfig.h"
#include "ApplicationConfig.h"
#include "ClientManagerConfig.h"
#include "GeneralCommanderConfig.h"
#include "GeneralMonitorConfig.h"
#include "GeneralPositionHandlerConfig.h"
#include "ClientsConfig.h"
#include "ClientConfig.h"
#include "Application.h"
#include "GeneralCommanderConfig.h"
#include "GeneralMonitorConfig.h"
#include "GeneralPositionHandlerConfig.h"

using namespace std;

Application* Application::mInstance = 0;

Application::Application() :
    mpGeneralCommander(NULL), mpGeneralMonitor(NULL),
    mpGeneralPositionHandler(NULL), mpClientManager(NULL),
    mIsStarted(false)
{
    Logger::debug("Application::ctor");
}

Application::~Application()
{
    Logger::debug("Application::dtor");
    onTerminate();
}

Application* Application::getInstance()
{
    if(!mInstance) {
        mInstance = new Application;
    }
    return mInstance;
}

bool Application::isStarted(void)
{
    return mIsStarted;
}

void Application::onStart(void)
{
    Logger::debug("Application::onStart");
    assert(!mIsStarted); // Only once!

    // 1) Read configuration
    // 2) Create objects
    // 3) Connect Generals to Manager
    // 4) Ask Manager to create clients
    // 5) Start data acquiring

    // 1) Read configuration
    ConfigLoader* pConfigLoader = 
        ConfigLoaderFactory::create(ConfigLoaderFactory::YamlLoader);

    ConfigSegment* pRootConfigSegment = pConfigLoader->getConfig();
    delete pConfigLoader;

    if(!pRootConfigSegment) {
        // Cannot load the configuration file!
        Logger::fatal("Cannot load the configuration!");

        exit(-1);   //TODO do something based on guideline
    }

    // Create a root config object from a root config segment; e.g. a yaml node
    RootConfig rootConfig(pRootConfigSegment);
    
    ApplicationConfig applicationConfig =
        rootConfig.getConfig<ApplicationConfig>();

    ClientManagerConfig clientManagerConfig =
        rootConfig.getConfig<ClientManagerConfig>();

    GeneralCommanderConfig generalCommanderConfig =
        rootConfig.getConfig<GeneralCommanderConfig>();

    GeneralMonitorConfig generalMonitorConfig =
        rootConfig.getConfig<GeneralMonitorConfig>();

    GeneralPositionHandlerConfig generalPositionHandlerConfig  =
        rootConfig.getConfig<GeneralPositionHandlerConfig>();

    ClientsConfig clientsConfig = 
        rootConfig.getConfig<ClientsConfig>();

    // 2) Create objects
    mpGeneralCommander = new GeneralCommander(generalCommanderConfig);
    mpGeneralMonitor = new GeneralMonitor(generalMonitorConfig);
    mpGeneralPositionHandler =
        new GeneralPositionHandler(generalPositionHandlerConfig);

    mpClientManager = new ClientManager(clientManagerConfig);

    if(mpGeneralCommander == NULL || mpGeneralMonitor == NULL ||
            mpGeneralPositionHandler == NULL || mpClientManager == NULL) {
        Logger::fatal("Cannot create main components!");
        onTerminate();
        return;
    }
    
    // 3) Connect Generals to Manager
    mpClientManager->setGeneralCommander(mpGeneralCommander);
    mpClientManager->setGeneralMonitor(mpGeneralMonitor);
    mpClientManager->setGeneralPositionHandler(mpGeneralPositionHandler);

    // 4) Ask Manager to create clients
    mpClientManager->createClients(clientsConfig);

    // 5) Start data acquiring

    mIsStarted = true;
}

void Application::onTerminate(void)
{
    Logger::debug("Application::onTerminate");
    // Warning: Do not check mIsStarted before deleting allocated objects
    delete mpGeneralCommander;
    delete mpGeneralMonitor;
    delete mpGeneralPositionHandler;
    delete mpClientManager;

    //TODO: Do more work here!
    mIsStarted = false;
}

void Application::configTest(void)
{
    ConfigSegment* puut;

    ConfigLoader* pConfigLoader = 
        ConfigLoaderFactory::create(ConfigLoaderFactory::YamlLoader);

    ConfigSegment* pRootConfigSegment = pConfigLoader->getConfig();
    delete pConfigLoader;


    puut = pRootConfigSegment;

    assert(puut);


    assert(puut->hasSegment("Application"));
    assert(puut->hasSegment("ClientManager"));
    assert(puut->hasSegment("Clients"));
    assert(puut->hasProperty("configVersion"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasSegment("ClientsAAAA"));
    
    std::string confVersion;
    confVersion =
        puut->getProperty<std::string>("configVersion", "www");
    assert(confVersion=="0.1");

    confVersion =
        puut->getProperty<std::string>("configVersionsss", "www");
    assert(confVersion=="www");

////////////////////////////////////////////////////////////////
    puut = pRootConfigSegment->getSegment("Application");
    
    assert(!puut->hasSegment("name"));
    assert(!puut->hasSegment("version"));
    assert(puut->hasProperty("name"));
    assert(puut->hasProperty("version"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("versioniiiii"));
    
    std::string name;
    name =
        puut->getProperty<std::string>("name", "www");
    assert(name=="tracker");

    name =
        puut->getProperty<std::string>("nameii", "www");
    assert(name=="www");

    int version;
    version = puut->getProperty<int>("version", 55);
    assert(version==12);

    version = puut->getProperty<int>("versioniiii", 55);
    assert(version==55);

////////////////////////////////////////////////////////////////
    puut = pRootConfigSegment->getSegment("ClientManager");
    
    assert(!puut->hasSegment("maximumClientNumber"));
    assert(puut->hasProperty("maximumClientNumber"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("wwwwwww"));
    
    int num;
    num = puut->getProperty<int>("maximumClientNumber", 66);
    assert(num==10);

////////////////////////////////////////////////////////////////
    puut = pRootConfigSegment->getSegment("Clients");
    
    assert(!puut->hasSegment("type"));
    assert(!puut->hasSegment("role"));
    assert(!puut->hasProperty("type"));
    assert(!puut->hasProperty("role"));
    assert(puut->hasSegmentArray());
    
    std::vector<ConfigSegment*> psegments;
    psegments = puut->getSegmentArray();

////////////////////////////////////////////////////////////////
    puut = psegments[0];

    assert(!puut->hasSegment("type"));
    assert(puut->hasProperty("type"));
    assert(puut->hasProperty("role"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("wwwwwww"));
    
    assert(puut->getProperty<std::string>("type") == "console");
    assert(puut->getProperty<std::vector<std::string> >("role")[0]
            == "monitor");
    assert(puut->getProperty<std::vector<std::string> >("role")[1]
            == "commander");


////////////////////////////////////////////////////////////////
    puut = psegments[1];

    assert(!puut->hasSegment("type"));
    assert(puut->hasProperty("type"));
    assert(puut->hasProperty("role"));
    assert(puut->hasProperty("remote"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("wwwwwww"));
    
    assert(puut->getProperty<std::string>("type") == "push button");
    assert(puut->getProperty<std::vector<std::string> >("role")[0]
            == "commander");
    assert(puut->getProperty<std::vector<std::string> >("role")[1]
            == "position handler");
    assert(puut->getProperty<std::vector<std::string> >("role")[2]
            == "monitor");

    std::vector<std::string> jjj = puut->getProperty<std::vector<std::string> >(
            "typei");
    std::cout << std::endl << jjj[0] << std::endl;

}

void Application::configTest2(void)
{
    ConfigLoader* pConfigLoader = 
        ConfigLoaderFactory::create(ConfigLoaderFactory::YamlLoader);

    ConfigSegment* pRootConfigSegment = pConfigLoader->getConfig();
    delete pConfigLoader;

    if(!pRootConfigSegment) {
        // Cannot load the configuration file!
        // TODO Log something!
        exit(-1);   //TODO do something based on guideline
    }

    RootConfig rootConfig(pRootConfigSegment);

    ApplicationConfig appConfig =
        rootConfig.getConfig<ApplicationConfig>();

    ClientManagerConfig clientManagerConfig =
        rootConfig.getConfig<ClientManagerConfig>();

    ClientsConfig clientsConfig =
        rootConfig.getConfig<ClientsConfig>();


    string configVersion = rootConfig.getConfigVersion();
    cout << configVersion << endl;

    string appName = appConfig.getName();
    cout << appName << endl;

    string appVersion = appConfig.getVersion();
    cout << appVersion << endl;

    int clientManagerMaxClient = clientManagerConfig.getMaximumClientNumber();
    cout << clientManagerMaxClient << endl;
    
    cout << "1==>" << endl;
    vector<ClientConfig> clientConfigs = clientsConfig.getClientConfigs();

    cout << "2==>" << endl;
    Client::Type c0Type = clientConfigs[0].getType();
    cout << c0Type << endl;

    cout << "3==>" << endl;
    Client::Type c1Type = clientConfigs[1].getType();
    cout << c1Type << endl;


    cout << "4==>" << endl;
    vector<Client::Role> c0Roles = clientConfigs[0].getRoles();
    cout << c0Roles[0] << endl;
    cout << c0Roles[1] << endl;




    cout << "5==>" << endl;
    vector<Client::Role> c1Roles = clientConfigs[1].getRoles();
    cout << c1Roles[0] << endl;
    cout << c1Roles[1] << endl;
    cout << c1Roles[2] << endl;





}
