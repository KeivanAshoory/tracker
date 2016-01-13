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
#include "Config.h"
#include "ConfigLoaderFactory.h"
#include "ConfigLoader.h"
#include "ConfigSegment.h"
#include "RootConfig.h"
#include "ClientManagerConfig.h"
#include "Application.h"

Application* Application::mInstance = 0;

Application::Application() :
    mpGeneralCommander(NULL), mpGeneralMonitor(NULL),
    mpGeneralPositionHandler(NULL), mpClientManager(NULL),
    mIsStarted(false)
{
    Logger::info("Application::ctor");
}

Application::~Application()
{
    Logger::info("Application::dtor");
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
    Logger::info("Application::onStart");
    assert(!mIsStarted); // Only once!

    // 1) Read configuration
    // 2) Create objects
    // 3) Connect Generals to Manager
    // 4) Ask Manager to create clients
    // 5) Start data acquiring

    // 1) Read configuration
    ConfigLoader* pConfigLoader = 
        ConfigLoaderFactory::create(ConfigLoaderFactory::YAML_CONFIG_LOADER);

    ConfigSegment* pRootConfigSegment = pConfigLoader->getConfig();
    delete pConfigLoader;

    if(!pRootConfigSegment) {
        // Cannot load the configuration file!
        // TODO Log something!
        exit(-1);   //TODO do something based on guideline
    }

    RootConfig rootConfig(pRootConfigSegment);

    ClientManagerConfig clientManagerConfig =
        rootConfig.getConfig<ClientManagerConfig>();



    // 2) Create objects
    mpGeneralCommander = new GeneralCommander("c");
    mpGeneralMonitor = new GeneralMonitor("c");
    mpGeneralPositionHandler = new GeneralPositionHandler("c");
    mpClientManager = new ClientManager("c");

    if(mpGeneralCommander == NULL || mpGeneralMonitor == NULL ||
            mpGeneralPositionHandler == NULL || mpClientManager == NULL) {
        // TODO Log something
        onTerminate();
        return;
    }
    
    // 3) Connect Generals to Manager
    mpClientManager->setGeneralCommander(mpGeneralCommander);
    mpClientManager->setGeneralMonitor(mpGeneralMonitor);
    mpClientManager->setGeneralPositionHandler(mpGeneralPositionHandler);

    // 4) Ask Manager to create clients
    mpClientManager->createClients("c");

    // 5) Start data acquiring

    mIsStarted = true;
}

void Application::onTerminate(void)
{
    Logger::info("Application::onTerminate");
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
        ConfigLoaderFactory::create(ConfigLoaderFactory::YAML_CONFIG_LOADER);

    ConfigSegment* pRootConfigSegment = pConfigLoader->getConfig();
    delete pConfigLoader;


    puut = pRootConfigSegment;

    assert(puut);


    assert(puut->hasSegment("Application"));
    assert(puut->hasSegment("ClientManager"));
    assert(puut->hasSegment("Clients"));
    assert(puut->hasProperty("ConfigVersion"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasSegment("ClientsAAAA"));
    
    std::string confVersion;
    confVersion =
        puut->getProperty<std::string>("ConfigVersion", "www");
    assert(confVersion=="0.1");

    confVersion =
        puut->getProperty<std::string>("ConfigVersionsss", "www");
    assert(confVersion=="www");

////////////////////////////////////////////////////////////////
    puut = pRootConfigSegment->getSegment("Application");
    
    assert(!puut->hasSegment("Name"));
    assert(!puut->hasSegment("Version"));
    assert(puut->hasProperty("Name"));
    assert(puut->hasProperty("Version"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("Versioniiiii"));
    
    std::string name;
    name =
        puut->getProperty<std::string>("Name", "www");
    assert(name=="tracker");

    name =
        puut->getProperty<std::string>("Nameii", "www");
    assert(name=="www");

    int version;
    version = puut->getProperty<int>("Version", 55);
    assert(version==12);

    version = puut->getProperty<int>("Versioniiii", 55);
    assert(version==55);

////////////////////////////////////////////////////////////////
    puut = pRootConfigSegment->getSegment("ClientManager");
    
    assert(!puut->hasSegment("maximumClientNumber"));
    assert(!puut->hasSegment("minimumClientNumber"));
    assert(puut->hasProperty("maximumClientNumber"));
    assert(puut->hasProperty("minimumClientNumber"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("wwwwwww"));
    
    int num;
    num = puut->getProperty<int>("maximumClientNumber", 66);
    assert(num==10);
    num = puut->getProperty<int>("minimumClientNumber", 77);
    assert(num==1);

////////////////////////////////////////////////////////////////
    puut = pRootConfigSegment->getSegment("Clients");
    
    assert(!puut->hasSegment("type"));
    assert(!puut->hasSegment("capabilities"));
    assert(!puut->hasProperty("type"));
    assert(!puut->hasProperty("capabilities"));
    assert(puut->hasSegmentArray());
    
    std::vector<ConfigSegment*> psegments;
    psegments = puut->getSegmentArray();

////////////////////////////////////////////////////////////////
    puut = psegments[0];

    assert(!puut->hasSegment("type"));
    assert(puut->hasProperty("type"));
    assert(puut->hasProperty("capabilities"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("wwwwwww"));
    
    assert(puut->getProperty<std::string>("type") == "console");
    assert(puut->getProperty<std::vector<std::string> >("capabilities")[0]
            == "monitor");
    assert(puut->getProperty<std::vector<std::string> >("capabilities")[1]
            == "commander");


////////////////////////////////////////////////////////////////
    puut = psegments[1];

    assert(!puut->hasSegment("type"));
    assert(puut->hasProperty("type"));
    assert(puut->hasProperty("capabilities"));
    assert(puut->hasProperty("remote"));
    assert(!puut->hasSegmentArray());
    assert(!puut->hasProperty("wwwwwww"));
    
    assert(puut->getProperty<std::string>("type") == "push button");
    assert(puut->getProperty<std::vector<std::string> >("capabilities")[0]
            == "commander");
    assert(puut->getProperty<std::vector<std::string> >("capabilities")[1]
            == "position handler");
    assert(puut->getProperty<std::vector<std::string> >("capabilities")[2]
            == "monitor");



}
