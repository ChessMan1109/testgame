#pragma once
#pragma once
#include "ISBState.h"

class ISecretBoss
{
public:

    virtual void SetAction(ISBState::STATE_Action) = 0;
    virtual void SetState() = 0;
    virtual void SetState(ISBState* StatePtr) = 0;

    virtual ISBState* GetState() = 0;
    virtual ISBState* GetMoveLeftState() = 0;
    virtual ISBState* GetMoveRightState() = 0;
    virtual ISBState* GetLazeAttackState() = 0;
    virtual ISBState* GetBulletAttackState() = 0;

    virtual Vector2* GetPos() = 0;
    virtual int* GetSpeed() = 0;
    virtual float* GetNumScale() = 0;
    virtual ISBState::STATE_Action* GetCurrentAction() = 0;
    virtual FlameManager* GetFlameManager()=0;

};