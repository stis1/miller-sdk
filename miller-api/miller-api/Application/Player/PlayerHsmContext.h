#pragma once

namespace app::player {
    class Player;
    class GOCPlayerHsm;
    class GOCPlayerPosture;
    class GOCPlayerKinematicParams;
    class GOCPlayerBlackboard;
    class BlackboardStatus;
    class BlackboardItem;
    class StateParameter;
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

        bool ChangeHsmState(int32_t stateId, uint32_t priority);
        bool ChangeHsmStateRestart(int32_t stateId, uint32_t priority);
        int GetCurrentState();
        bool AddParam(StateParameter& parameter);
        
        // vo_sd_005+index
        hh::snd::SoundHandle PlayVoice(int index); 

        bool isGrounded() const;
        bool isOutOfControl() const;
        bool isAutoRun() const;
        
        bool GetCombatFlag(BlackboardStatus::CombatFlag combatFlag) const;
        bool GetStateFlag(BlackboardStatus::StateFlag stateFlag) const;
        bool GetWorldFlag(BlackboardStatus::WorldFlag worldFlag) const;
        void SetCombatFlag(BlackboardStatus::CombatFlag combatFlag, bool enable);
        void SetStateFlag(BlackboardStatus::StateFlag stateFlag, bool enable);
        void SetWorldFlag(BlackboardStatus::WorldFlag worldFlag, bool enable);
        void ResetCombatFlag(BlackboardStatus::CombatFlag combatFlag);
        void ResetStateFlag(BlackboardStatus::StateFlag stateFlag);
        void ResetWorldFlag(BlackboardStatus::WorldFlag worldFlag);
        // unk goes into app::player::ComponentCollector::unk4, usually True
        void ChangeVisualState(const char* stateName, bool unk); 
        void AdjustMovieShadowLooks(bool enable);
        void StopEffects(); // maybe more appropriate name is resetvisuals         
        
        // check state methods return true if conditions met and switched
        // HomingAttack/ChaosWarp/DAmoebaHoming
        bool CheckHoming(bool doubleJumpOrDashIfFail, float priorityInputTimeOverride); 
        // unk usualy is False (except DSurfSpin)
        bool CheckDSurf(bool unk);
        bool CheckShiftJumpAir();
        bool CheckDropDash(float charge);
        bool CheckQuickStep();
        bool CheckRunOnWater();

        // useless without reintegrating StatePluginAirTrick
        bool CheckAirTricks();

        inline bool IsMovieShadow() {
            return blackboardStatus->dword28 == 3;
        }
    };
}