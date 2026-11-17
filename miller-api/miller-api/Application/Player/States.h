#pragma once

namespace app::player {
    class PlayerStateActionBase : public PlayerStateBase {
    public:
        PlayerStateActionBase(csl::fnd::IAllocator* allocator);
    };
    
    class StateJumpBase : public PlayerStateActionBase {
    public:
        float addForceTimeTimer{};
        float dropDashCharge{};
        hh::snd::SoundHandle soundHandleJumpBase{};
        bool addForceActive{};
        uint8_t byteED{};
        StateJumpBase(csl::fnd::IAllocator* allocator);
    };
    
    class StateStandBase : public PlayerStateActionBase {
    public:
    };

    class StateAirBoost : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBackflip : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBallMove : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBaseJump : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBoarding : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBounceJump : public StateJumpBase {
    public:
        class Parameter : public StateParameter {
            int stompCount;

            Parameter(uint32_t unk1, int stompCount) : StateParameter(unk1), stompCount(stompCount) {}

            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) override;
            virtual uint32_t GetNameHash() override;
        };
        enum class Flags : uint8_t {
            LET_GO_INPUT = 1
        };
        int bounces{};
        hh::snd::SoundHandle soundHandle{};
        csl::ut::Bitset<Flags> flags{};

        StateBounceJump(csl::fnd::IAllocator* allocator) : StateJumpBase{ allocator } {}
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBrake : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBrakeNeutral : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateBumpJump : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateCaught : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool UpdatePlayerState(PlayerHsmContext& context, hh::fnd::UpdatingPhase phase, float deltaTime) override;
    };

    class StateChaosAttack : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateChaosWarp : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateClimbing : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateClimbingEdge : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateCloudJump : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateCollectionRoom : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDAmoeba : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDAmoebaAir : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDAmoebaChangeGround : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDAmoebaDash : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDAmoebaHoming : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDAmoebaJump : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDBlowDown : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDBlowOff : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDBlowRush : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDBlowRushFinish : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDBlowUp : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurf : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfAir : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfDamage : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfFinish : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfGround : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfJump : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfSpin : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual bool Step(PlayerHsmContext& context, float deltaTime) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfVirticalJump : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDSurfWarp : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDWingDead : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDWingFlinch : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDWingGuard : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDWingStart : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDamage : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDamageBlowOff : public PlayerStateActionBase {
    public:
        class Parameter : public StateParameter {
        public:
            csl::math::Vector4 vector10;
            uint32_t dword20;
            uint32_t dword24;
            uint8_t byte28;
            uint8_t byte29;
            uint8_t byte2A;

            Parameter(uint32_t unk) : StateParameter{ unk } {};

            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) override;
            virtual uint32_t GetNameHash() override;
        };


        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDamageLava : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDamageQuake : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDamageRoot : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateDamageRunning : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDamageTurnBack : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDead : public PlayerStateBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDestination : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDiving : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingChangeVolume : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingDamage : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingFall : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingRoot : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpecial : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpecialDamage : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpecialDashRing : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpecialFall : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpecialPush : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpecialRoot : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDivingSpring : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDoubleJump : public StateJumpBase {
    public:
        hh::snd::SoundHandle soundHandle;
        uint8_t byteF4;
        
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDrift : public PlayerStateActionBase {
    public:
        hh::snd::SoundHandle soundHandle;
        float airborneTime;
        float zeroInputTime;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDriftAir : public PlayerStateActionBase {
    public:
    };

    class StateDriftDash : public PlayerStateActionBase {
    public:
        StateDriftDash(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateDropDash : public PlayerStateActionBase {
    public:
        hh::snd::SoundHandle soundHandle;
        bool byteE4;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateFall : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateFallFlip : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateFallSlope : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateFan : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateFixedGoal : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
    };

    class StateFloat : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateGliding : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateGoal : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateGrindDamage : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateGrindDamageAir : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    //class StateGrindJump : public StateJumpBase {
    //public:
    //    virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
    //    virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
    //    virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    //    virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    //};

    class StateGrindDoubleJump : public StateJumpBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateGrindRoot : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateGrindStep : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateGuard : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateGuardedFlipBack : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateHangPole : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateHangPoleJump : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateHoldStand : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateHomingAttack : public PlayerStateActionBase {
    public:
        float dwordE0;
        uint32_t dwordE4;
        hh::eff::EffectHandle effectHandle;
        hh::snd::SoundHandle soundHandle;
        uint8_t byteFC;

        StateHomingAttack(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateHomingAttackRoot : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
    };

    class StateHomingFinish : public PlayerStateActionBase {
    public:
    };

    class StateHomingFinished : public PlayerStateActionBase {
    public:
        class Parameter : public StateParameter {
            uint8_t byte10;
            csl::math::Vector4 vector20;
            uint8_t byte30;
            csl::math::Vector4 vector40;
            uint32_t dword50;
            uint8_t byte54;
            uint8_t byte55;
            uint8_t byte56;
            uint8_t byte57;

            Parameter(uint32_t unk) : StateParameter{ unk } {};
            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) override;
            virtual uint32_t GetNameHash() override;
        };

        uint32_t dwordE0;
        uint8_t byteE4;
        uint8_t byteE5;
        uint8_t byteE6;

        StateHomingFinished(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}

        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateHomingRepelled : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateImpactGimmick : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateJump : public StateJumpBase {
    public:
        enum class Flags : uint8_t {
            SPIN = 0,
            DWINGS = 4,
            FALL = 6
        };

        hh::snd::SoundHandle soundHandle{};
        csl::ut::Bitset<Flags> flags; 
        StateJump(csl::fnd::IAllocator* allocator) : StateJumpBase{ allocator } {}
       
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateJumpDash : public PlayerStateActionBase {
    public:
        hh::snd::SoundHandle soundhandle{};
        float brakeTime{};
        float dropDashCharge{};
        bool keepVelocity{};
        uint8_t byteED{};
        bool dropDash{};

        StateJumpDash(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateLavaDead : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateLeftStep : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateLeftStepRun : public PlayerStateActionBase {
    public:

        StateLeftStepRun(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateLightDash : public PlayerStateActionBase {
    public:

        StateLightDash(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateOperateConsole : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateParalysis : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StatePhotonDash : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StatePipeMove : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StatePipeOut : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StatePlayMotion : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StatePressDead : public PlayerStateBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStep : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStepCrash : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStepDoubleJump : public StateJumpBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStepJump : public StateJumpBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStepLeft : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStepRight : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateQuickStepRoot : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateRecoil : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateRecovery : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateRecoveryJump : public StateJumpBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateRightStep : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateRightStepRun : public PlayerStateActionBase {
    public:
        StateRightStepRun(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateRun : public PlayerStateActionBase {
    public:
        hh::snd::SoundHandle soundHandle{};
        uint8_t byteE4{};
        bool shift{};
        bool shiftSideLeft{};
        uint8_t byteE7{};
        
        StateRun(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
        bool CheckShift(PlayerHsmContext& context); // L1/R1 slide
    };

    class StateRunOnWater : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateRunningStart : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSendSignal : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateShiftJump : public StateJumpBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateShiftJumpAir : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateShotChaosSpear : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateShotChaosSpearAir : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateShotChaosSpearRunning : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSlalomStep : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSleep : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateSlider : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSliderAir : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSliderJump : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSliding : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSlidingToStand : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSpin : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSpinAttack : public StateJumpBase {
    public:
        uint8_t byteF0;
        float addForceTime;
        hh::snd::SoundHandle soundHandle;
        uint8_t byteFC;

        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSpinDash : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSpringJump : public PlayerStateActionBase {
    public:
        class Parameter : public StateParameter {
            enum class Animation : int32_t {
                JUMP_RAILCANYON = 1,
                JUMP_BALL = 5,
                SPIN = 6,
                DASHRING = 7,
                POLESPIN_JUMP_START = 8,
                SELECTJUMP_F_START = 9,
                SELECTJUMP_U_START = 10,
                SELECTJUMP_MISS_START = 11,
                WATERFALL_JUMP = 12,
                GLASSBREAK_JUMP = 13,
                JUMP_ACT_CITY_START = 14,
                JUMP_CHAOSLAST = 15,
                JUMP_LOOP = 17,
                SPRING_JUMP = 29,
            };
            
            csl::math::Vector4 vector10;
            csl::math::Vector4 vector20;
            csl::math::Vector4 vector30;
            uint32_t dword40;
            uint32_t dword44;
            uint32_t dword48;
            uint32_t dword4C;
            uint32_t dword50;
            csl::ut::Bitset<Animation> requestAnimation;

            Parameter(uint32_t unk) : StateParameter{ unk } {};
            virtual Parameter* Clone(csl::fnd::IAllocator* allocator) override;
            virtual uint32_t GetNameHash() override;
        };
    
        uint32_t dwordE0;
        app::ut::Timer timerE8;
        app::ut::Timer timerF8;
        app::ut::Timer timer108;
        app::ut::Timer timer118;
        app::ut::Timer timer128;
        uint32_t dword138;
        csl::math::Vector4 vector140;
        csl::math::Vector4 vector150;
        uint32_t dword160;
        uint8_t byte164;

        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSpringJumpHeadLand : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSquat : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSquatRoot : public PlayerStateActionBase {
    public:
        virtual bool InitPlayerState(PlayerHsmContext& context) override;
    };

    class StateStand : public StateStandBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStandRoot : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateStomping : public PlayerStateActionBase {
    public:
        virtual bool Init(PlayerHsmContext& context) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateStompingAttack : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStompingBounce : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStompingDown : public PlayerStateActionBase {
    public:
        csl::math::Vector4 vectorE0{};
        int bounces{};
        uint16_t wordF4{};

        StateStompingDown(csl::fnd::IAllocator* allocator) : PlayerStateActionBase{ allocator } {}
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStompingFlip : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStompingLand : public PlayerStateActionBase {
    public:
        int stompCount{};
        float dwordE4{};
        uint8_t byteE8{};
        
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStompingPress : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateStraightJump : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateSuffocatingDead : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateTalkMode : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateTimeStopStart : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateTreadmill : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateTreeJump : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateTumble : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateTurn : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateUpDead : public PlayerStateBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWakeUp : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallActionRoot : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
    };

    class StateWallHanging : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallHoming : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallJump : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallJumpReady : public PlayerStateActionBase {
    public:
        class Parameter {
            csl::math::Vector4 vector10;
        };

        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallLanding : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallLeave : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallMove : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallReset : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallRest : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWallSlideDown : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWarpEnd : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWarpStart : public PlayerStateActionBase {
    public:
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWaterFall : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };

    class StateWaterFlow : public PlayerStateActionBase {
    public:
        virtual bool ProcessMessage(PlayerHsmContext& context, const hh::fnd::Message& message) override;
        virtual void EnterPlayerState(PlayerHsmContext& context, int previousState) override;
        virtual void LeavePlayerState(PlayerHsmContext& context, int nextState) override;
        virtual bool StepPlayerState(PlayerHsmContext& context, float deltaTime) override;
    };
}