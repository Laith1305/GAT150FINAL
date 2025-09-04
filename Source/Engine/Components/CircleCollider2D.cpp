#include "CircleCollider2D.h"


namespace viper{

    void CircleCollider2D::Update(float dt){


    }

    bool CircleCollider2D::CheckCollission(ColliderComponent& other){
        float distance = (owner->transform.position - other.owner->transform.position).Length();
        auto circleCollider = dynamic_cast<CircleCollider2D*>(&other);


        //check circle to circle collision
        if (circleCollider) {
            float radii = radius + circleCollider->radius;
            if (distance <= radii) return true;
        }

        return false;
    }

}