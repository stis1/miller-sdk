#pragma once

namespace app::ut {
    class Timer {
    public:
        float target{};
        float current{};

        Timer(float time);
        Timer();

        virtual void Update(float time);
        virtual void UnkFunc();

        inline float GetTarget() const { return target; }
        inline float GetCurrent() const { return current; }
        inline float GetProgress() const 
        { 
            if (std::abs(target) > 0.0f) {
                float part = current / target;
                return std::clamp(part, 0.0f, 1.0f);
            }
            return 0.0f;
        }
        inline float GetRemaining() const { return target - current; }
        inline bool IsFinished() const { return target > 0.0f && current >= target; }
        inline bool IsActive() const { return target > 0.0f && current < target; }
        inline void Reset() { target = -1.0f; current = 0.0f; }
        inline void ResetCurrent() { current = 0.0f; }
        inline void Restart(float time) { if (time > 0.0f) { target = time; current = 0.0f; } }
        inline void Restart() { *this = Timer(); }
    };
}
