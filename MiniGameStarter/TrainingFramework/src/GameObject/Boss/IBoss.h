#pragma once
#pragma once
#include "IBState.h"

class IBoss
{
public:

    virtual void SetAction(IBState::STATE_Action) = 0;
    virtual void SetState() = 0;
    virtual void SetState(IBState* StatePtr) = 0;

    virtual IBState* GetState() = 0;
    virtual IBState* GetIdleState() = 0;
    virtual IBState* GetBiteAttackState() = 0;
    virtual IBState* GetDeathState() = 0;
    virtual IBState* GetPosionState() = 0;
    virtual IBState* GetFallState() = 0;
    virtual IBState* GetHurtState() = 0;
    virtual IBState* GetJumpState() = 0;
    virtual IBState* GetJumpBiteState() = 0;

    virtual Vector2* GetPos() = 0;
    virtual bool* GetisTouch() = 0;
    virtual int* GetSpeed() = 0;
    virtual float* GetNumScale() = 0;
    virtual IBState::STATE_Action* GetCurrentAction() = 0;
    virtual BulletManager* GetBulletManager() = 0;


};