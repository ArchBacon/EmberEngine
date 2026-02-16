#include "Engine.hpp"

#include <chrono>
#include <thread>

#include <SDL3/SDL_events.h>

#include "Ember.hpp"

EE::EmberEngine Engine;

void EE::EmberEngine::Initialize()
{
    LogEngine->Trace("Initializing Engine...");
}

void EE::EmberEngine::Run()
{
    auto previousTime = std::chrono::high_resolution_clock::now();
    SDL_Event event;
    
    LogEngine->Trace("Engine Started...");
    
    while (isRunning)
    {
        const auto currentTime = std::chrono::high_resolution_clock::now();
        const float elapsed = static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(currentTime - previousTime).count());
        deltaTime = elapsed / 1000000.0f; // time in seconds
        uptime += deltaTime;
        const float frameTime = elapsed / 1000.0f; // time in milliseconds
        previousTime = currentTime;

        while (SDL_PollEvent(&event))
        {
            // Handle events
        }

        // Do not draw if we are minimized
        if (stopRendering)
        {
            // Throttle the speed to avoid the endless spinning
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        
        frameNumber++;
    }
}

void EE::EmberEngine::Shutdown()
{
    LogEngine->Trace("Shutting Down Engine...");
    LogEngine->Info("Engine uptime: {}s", Uptime());
}
