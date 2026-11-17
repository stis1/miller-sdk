#pragma once

namespace app::player {
    // technically ShadowContext, but it's the same
    class PlayerHsmContext; 
    class Shadow : public app::player::Player {
    public:
        PlayerHsmContext* shadowContext{};

        Shadow(csl::fnd::IAllocator* allocator) : Player{ allocator } {}
    };
}