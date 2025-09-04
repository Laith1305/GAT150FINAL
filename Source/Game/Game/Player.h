#pragma once
#include "Framework/Actor.h"

class Player : public viper::Actor {
public:
	float timer = 0;
	float speed = 200;
	float rotationRate = 180;
	float fireTime = 0.2f;
	float fireTimer = 0.0f;
	bool isPowered = false;
public:
	Player() = default;
	Player(const viper::Transform& transform) :
		Actor{ transform }
	{}

	void PoweredUp();

	void Update(float dt) override;

	void OnCollision(Actor* other) override;
};
