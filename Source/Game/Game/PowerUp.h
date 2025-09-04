#pragma once
#include "GameData.h"
#include <EngineMinimal.h>
#include "Framework/Actor.h"

namespace viper {
	class PowerUp : public viper::Actor {
	public:
		PowerUp() = default;
		PowerUp(const viper::Transform& transform) :
			Actor{ transform }
		{
		}

		void Update(float dt) override;

		void OnCollision(Actor* other) override;
	};

}