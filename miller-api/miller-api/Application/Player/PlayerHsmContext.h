#pragma once

namespace app::player {
    class Player;
    class GOCPlayerHsm;
    class GOCPlayerPosture;
    class GOCPlayerKinematicParams;
    class GOCPlayerBlackboard;
    class BlackboardStatus;
    class BlackboardItem;
    class PlayerHsmContext : public hh::fnd::ReferencedObject, public app::save::SaveManagerListener {
        class OutOfControlTimerList : public PlayerCounterTimer {
            PlayerHsmContext* pPlayerHsmContext;
        public:
            OutOfControlTimerList(csl::fnd::IAllocator* pAllocator);
        };

        class DamagedObjects : public hh::fnd::BaseObject {
            csl::ut::MoveArray<void*> objects;
        public:
            DamagedObjects(csl::fnd::IAllocator* pAllocator);
        };

    public:
        Player* playerObject;
        BlackboardStatus* blackboardStatus;
        BlackboardItem* blackboardItem;
        GOCPlayerHsm* gocPlayerHsm;
        GOCPlayerPosture* gocPlayerPosture;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        csl::ut::MoveArray<void*> unk8;
        OutOfControlTimerList* pOutOfControlTimerList;
        DamagedObjects* pDamagedObjects;

        PlayerHsmContext(csl::fnd::IAllocator* pAllocator);
        ~PlayerHsmContext();

        void Setup(GOCPlayerHsm* gocPlayerHsm);

        void ChangeHsmState(int32_t stateId, uint32_t priority);
        int GetCurrentState();

        bool isGrounded() const;
        bool isOutOfControl() const;
        
        bool GetCombatFlag(BlackboardStatus::CombatFlag combatFlag) const;
        bool GetStateFlag(BlackboardStatus::StateFlag stateFlag) const; 
        bool GetWorldFlag(BlackboardStatus::WorldFlag worldFlag) const;
        void SetCombatFlag(BlackboardStatus::CombatFlag combatFlag, bool enabled);
        void SetStateFlag(BlackboardStatus::StateFlag stateFlag, bool enabled);
        void SetWorldFlag(BlackboardStatus::WorldFlag worldFlag, bool enabled);
        void ResetCombatFlag(BlackboardStatus::CombatFlag combatFlag);
        void ResetStateFlag(BlackboardStatus::StateFlag stateFlag);
        void ResetWorldFlag(BlackboardStatus::WorldFlag worldFlag);

        void ChangeVisualState(const char* stateName, bool unk); // unk goes into app::player::ComponentCollector::unk4, usually is 1
        void StopEffects();        
        
        bool CheckHoming(bool unk, float priorityInputTimeOverrider); // returns True if switched to Homing, bool have some todo with jumpDash
        bool CheckDSurf(bool unk); // returns True if switched to Surf, not sure about the argument
        bool CheckShiftJumpAir();
        bool CheckDropDash(float charge);
        bool CheckQuickStep();
        bool CheckRunOnWater();
    };
}
