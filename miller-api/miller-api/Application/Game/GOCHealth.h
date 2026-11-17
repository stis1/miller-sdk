#pragma once

namespace app::game {
    class GOCHealth : public hh::game::GOComponent {
        GOCHealth(csl::fnd::IAllocator* allocator);
        GOCOMPONENT_CLASS_DECLARATION(GOCHealth);
    };
}