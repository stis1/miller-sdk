#pragma once

namespace app::player {
    class PlayerPostureContext : public hh::fnd::BaseObject {
    public:
        //app::player::Player* player;
        //app::player::GOCPlayerKinematicParams* qword18;
        //app::player::GOCPlayerBlackboard* gocPlayerBlackboard;
        //app::player::BlackboardStatus* BlackboardStatus;
        //float dword30; // 360
        // wip

    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}