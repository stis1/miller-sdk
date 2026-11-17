#pragma once

namespace app::player {
    class RelayedFlagsParameter : public StateParameter {
    public:
        static constexpr uint32_t hash = 0x40BA33D2;
        enum class Flags : uint32_t {
            HOLD_BOOST = 5
        };

        csl::ut::Bitset<Flags> flags;

        RelayedFlagsParameter();
        virtual RelayedFlagsParameter* Clone(csl::fnd::IAllocator* allocator) override;
        virtual uint32_t GetNameHash() override;
        virtual void Clear() override;
    };
}
