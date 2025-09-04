#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Core/File.h"
#include "Engine.h"
#include "Texture.h"
#include "Game/Player.h"
#include "Game/SpaceGame.h"
#include "Resources/ResourceManager.h"
#include "Logger.h"
#include <iostream>
#include <vector>
#include <memory>
//#include <Renderer/Texture.h>

int main(int argc, char* argv[]) {

    
    viper::Logger::SetEnabledLevels(viper::LogLevel::Error);


    viper::file::SetCurrentDirectory("Assets");
    
    // initialize engine
    viper::GetEngine().Initialize();
    //viper::ResourceManager resourceManager;
    // initialize game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();

    // initialize sounds
    viper::GetEngine().GetAudio().AddSound("bass.wav", "bass");
    viper::GetEngine().GetAudio().AddSound("snare.wav", "snare");
    viper::GetEngine().GetAudio().AddSound("clap.wav", "clap");
    viper::GetEngine().GetAudio().AddSound("close-hat.wav", "close-hat");
    viper::GetEngine().GetAudio().AddSound("open-hat.wav", "open-hat");
    
    auto texture = viper::ResourceManager::Instance().Get<viper::Texture>("textures/blue_05.PNG", viper::GetEngine().GetRenderer());




    // create stars
    std::vector<viper::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(viper::vec2{ viper::random::getReal() * 1280 , viper::random::getReal() * 1024 });
    }

    SDL_Event e;
    bool quit = false;
    float rotate = 0;

    // create texture, using shared_ptr so texture can be shared
    /*std::shared_ptr<viper::Texture> texture = std::make_shared<viper::Texture>();
    texture->Load("pixel-art-drawing-art-game-character-animation-png-favpng-4kk0ZkiGxyz1XXT8FpHiKJ4qy.JPG", viper::GetEngine().GetRenderer());*/


    // MAIN LOOP
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        viper::GetEngine().Update();
        game->Update(viper::GetEngine().GetTime().GetDeltaTime());
       
        if (viper::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        // draw
        viper::vec3 color{ 0, 0, 0 };
        viper::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        viper::GetEngine().GetRenderer().Clear();

        game->Draw(viper::GetEngine().GetRenderer());
        rotate += 90 * viper::GetEngine().GetTime().GetDeltaTime();
        viper::GetEngine().GetRenderer().DrawTexture(*texture.get(), 30, 30, 45, 3);

        viper::GetEngine().GetRenderer().Present();
    }

    game->Shutdown();
    game.release();
    viper::GetEngine().Shutdown();

    return 0;
}

/*
    viper::vec2 speedz{ -140.0f, 0.0f };
    float length = speedz.Length();

    for (auto& star : stars) {
        star += speedz * viper::GetEngine().GetTime().GetDeltaTime();

        if (star[0] > 1280) star[0] = 0;
        if (star[0] < 0) star[0] = 1280;

        viper::GetEngine().GetRenderer().SetColor((uint8_t)viper::random::getRandomInt(256), viper::random::getRandomInt(256), viper::random::getRandomInt(256));
        viper::GetEngine().GetRenderer().DrawPoint(star.x, star.y);
    }
*/