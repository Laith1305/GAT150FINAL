#include "PowerUp.h"
#include "Player.h"
#include "Rocket.h"
#include "Engine.h"
#include "SpaceGame.h"
#include "GameData.h"
#include "Math/Vector3.h"
#include "Core/Random.h"
#include "Framework/Scene.h"


#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include <Components/CircleCollider2D.h>
#include <AudioClip.h>
#include <Components/SpriteRenderer.h>
#include <Components/RigidBody.h>
void viper::PowerUp::Update(float dt){

}

void viper::PowerUp::OnCollision(Actor* other){
    if (tag != other->tag) {
        destroyed = true;
       
        auto player = dynamic_cast<Player*>(other);
           if (player) {
               player->isPowered = true;
               player->PoweredUp();
           }
       
        dynamic_cast<SpaceGame*>(scene->GetGame())->PoweredUp();
        
    }
}
