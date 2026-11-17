#pragma once

namespace app::player {
    class BlackboardSpeed : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardSpeed";
        float unk0; // StateGrindJump::EnterPlayerState sets it to 0.0f
                    // StateGrindJump::LeavePlayerState sets it to 10.0f
        float adjustSpeed;  // MsgAdjustPath
        float speedNormal;  // MsgLimitEdgeJump      
        float speedBoost;
        float minSpeed;
        float outOfControlTime;
        float decelerationValue;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardSpeed);
    };
}
