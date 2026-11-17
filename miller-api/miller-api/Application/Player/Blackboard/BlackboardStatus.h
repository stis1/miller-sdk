#pragma once

namespace app::player {
    class BlackboardStatus : public BlackboardContent {
    public:
        enum class StateFlag : unsigned int
        {
            BOOST = 0x00,
            AIR_BOOST = 0x03,
            QUICK_STEP = 0x04,
            GRIND_STEP = 0x05,
            GRIND_JUMP = 0x06,
            GRIND = 0x07,
            JUMP = 0x08,
            DOUBLE_JUMP = 0x09,
            BOUNCE_JUMP = 0x0A,
            FALL = 0x0B,
            STOMP = 0x0C,
            DIVING = 0x0D,
            DIVING_BOOST = 0x0E,
            CURVE_MOVE = 0x0F,
            DRIFT = 0x11,
            DRIFT_DASH = 0x12,
            HOMING = 0x13, // also jumpdash for no reason...
            TURN = 0x16,
            SEVENTEEN = 0x17,
            STAND_ROOT_AFK = 0x18,
            WALL_CLIMB = 0x19,
            IDLE = 0x1A,
            BOARDING = 0x1B,
            WALL_CLIMB_IDLE = 0x1C,
            BOARDINGTWO = 0x1E,
            SLIDER = 0x20,
            DSURF = 0x21,
            CHAOS_SPEAR = 0x22,
            DAMOEBA = 0x23,
            DAMOBEA_RELATED = 0x24,
            DBLOW_OFF = 0x25,
            DBLOW_OFF_2nd = 0x26,
            DBLOW_DOWN = 0x27,
            DBLOW_UP = 0x29,
            WARP_ATTACK = 0x2A,
            DWING_FLY = 0x2B,
            RUN_ON_WATER = 0x2E,
            DAMAGE_RUNNING = 0x31,
        };
        enum class CombatFlag : unsigned int
        {
            JUMP = 0x00,
            DOUBLE_JUMP = 0x01,
            BOOST = 0x02,
            AIR_BOOST = 0x03,
            HOMING_ATTACK = 0x04,
            SIDE_STEP = 0x05,
            SLALOM_STEP = 0x06,
            CROUCH = 0x0D,
            STOMP = 0x0E,
            SLIDE = 0x10,
            BRAKE = 0x11,
            DROP_DASH = 0x19,
            AIR_TRICK = 0x1A,
            BOARDING = 0x1B,
            PHOTON_DASH = 0x1F,
            CAMERA_MOVEMENT = 0x20,
            MOVEMENT = 0x21,
            RAIL_GRINDING = 0x2A,
            CORRUPTION_WEAK = 0x30,
            CORRUPTOIN_STRONG = 0x31,
            DBLOW = 0x32,
            DSURF = 0x33,
            DAMOEBA = 0x34,
            DWING = 0x35,
            DSPEAR = 0x36,
        };
        enum class WorldFlag : unsigned int
        {
            KILLED = 0x01,
            DAMAGED_OR_REPELLED = 0x02,
            UNDER_WATER = 0x06,
            OUT_OF_CONTROL = 0x07,
            AUTO_RUN = 0x0A,
            BATTLE = 0x14,
            WALL_JUMP = 0x1A,
            LOCAL_JUMP = 0x1B,
            AIR_TRICK = 0x1D,
            LIMIT_EDGE_JUMP = 0x2C,
            TIME_STOP_BAN = 0x2E,
            TIME_STOP_LOCK = 0x2F,
            SKATING_MOTION = 0x31, 
            HAS_RINGS = 0x32,
            GRIND = 0x33,
            DSURF_ON_GROUND = 0x35,
            HEIGHT_MAP_COLLISION = 0x37,
            DWING = 0x38,
            DWING_GLIDING_BAN = 0x3C,
            DWING_CONSUMPTION_BAN = 0x3D,
        };
        
        enum class Dimension : unsigned int {

        };

        struct Description {
            char playerId;
            float unk8;
        };

        enum class LimitedAction : uint8_t {
            JUMP = 0,
            DOUBLE_JUMP = 2,
            AIR_BOOST = 3,
            STOMP = 4,
        };

        static constexpr const char* name = "BlackboardStatus";
        char playerId;
        uint32_t dword24;
        uint32_t dword28; // equals to 3 if Movie Shadow
        csl::ut::Bitset<CombatFlag, uint64_t> combatFlags;
        csl::ut::Bitset<StateFlag, uint64_t> stateFlags;
        csl::ut::Bitset<WorldFlag, uint64_t> worldFlags;
        float airborneTime;
        float groundedTime;
        float outOfControlTime;
        float inControlTime;
        float float58;
        uint32_t dword5C;
        uint64_t qword60;
        ut::PriorityList<bool, hh::fnd::Handle<hh::fnd::Messenger>> qword68;
        csl::ut::InplaceMoveArray<uint32_t, 4> qword90;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordC0;
        csl::ut::InplaceMoveArray<uint32_t, 4> qwordF0;
        uint32_t dword120;
        uint32_t dword124;
        ut::PriorityList<Dimension, hh::fnd::Handle<hh::fnd::Messenger>> qword128;
        csl::math::Vector4 oword150;
        uint64_t qword160;
        csl::ut::Bitset<LimitedAction> usedLimitedAction; 
        csl::ut::Bitset<LimitedAction> ignoreLimitedAction; // 0x1499543B0
        uint8_t byte16A;
        uint32_t dword16C;

        virtual unsigned int GetNameHash() const override;


        void SetCombatFlag(CombatFlag combatFlag, bool enabled);
        void SetStateFlag(StateFlag stateFlag, bool enabled);
        void SetWorldFlag(WorldFlag worldFlag, bool enabled);
        bool GetCombatFlag(CombatFlag combatFlag);
        bool GetStateFlag(StateFlag stateFlag);
        bool GetWorldFlag(WorldFlag worldFlag);

        void Setup(const Description& desc);

        DEFAULT_CREATE_FUNC(BlackboardStatus);
    };
}
