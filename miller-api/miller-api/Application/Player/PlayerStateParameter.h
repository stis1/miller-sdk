#pragma once

namespace app::player {
    class PlayerStateParameter : public hh::fnd::BaseObject {
        csl::ut::MoveArray<StateParameter*> stateParameters;
    public:
        StateParameter* GetByNameHash(uint32_t hash);

        template<typename T>
        T* GetByNameHash() { 
            return static_cast<T*>(GetByNameHash(T::hash)); 
        }
           
        DEFAULT_CREATE_FUNC(PlayerStateParameter)
    };
}
