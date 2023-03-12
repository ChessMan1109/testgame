#pragma once
#include "ICState.h"

class ICharacter
{
public:
 
    virtual void SetAction(ICState::STATE_Action) = 0;
    virtual void SetState()=0;
    virtual void SetState(ICState* StatePtr) = 0;

    virtual ICState* GetState() = 0;
    virtual ICState* GetJumpState() = 0;
    virtual ICState* GetAttackState() = 0;
    virtual ICState* GetDeathState() = 0;
    virtual ICState* GetDashState() = 0;
    virtual ICState* GetIdleState() = 0;
    virtual ICState* GetRunState() = 0;
    virtual ICState* GetFallState() = 0;

    virtual Vector2* GetPos() = 0;
    virtual bool* GetisTouch() = 0;
    virtual int* GetSpeed() = 0;
    virtual int* GetKeyPress() = 0;
    virtual ICState::STATE_Action* GetCurrentAction()=0;
    virtual BulletManager* GetBulletManager() = 0;
    virtual std::vector<SoLoud::Wav>* GetListSound() = 0;


};