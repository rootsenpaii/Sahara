#pragma once
#include <Windows.h>
#include <iostream>
#include <unordered_map>
#include <winternl.h>

class Engine {
public:
    static Engine* Get() noexcept {
        static Engine instance;
        return &instance;
    }

    template<typename DefaultTy = uintptr_t>
    DefaultTy GetModule() noexcept {
        return (DefaultTy)NtCurrentTeb()->ProcessEnvironmentBlock->Reserved3[1];
    };

    void SetupConsole() noexcept;

private:
    Engine() noexcept = default;

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    ~Engine() noexcept;
};

namespace Update
{
    inline const auto client = Engine::Get()->GetModule();
    inline auto retaddr = client;

    inline ptrdiff_t ViewMatrix = 0x40; //0xC0DEE58 eski offset 
    inline ptrdiff_t Name = 0x798; //0x758 eski offset 
    inline ptrdiff_t TeamID = 0x1C; //0x8562FA0 eski offset
    inline ptrdiff_t RayCast = 0xBB0FB90; //0x56B4A10 eski offset
    inline ptrdiff_t Physics = 0x15BF3F08; //0xBA06120 eski offset
    inline ptrdiff_t EffectClass = 0x160; //0xBA5B3C0; eski offset (0x160 yeni offset gamemanager'in içinden çekildi)

    inline ptrdiff_t JumpingFunction = 0x25B616; //0x1A02B0 eski offset bulana kadar götüm dü?tü sabah 6 oldu amk
    inline ptrdiff_t JumpingComponent = 0x23E;

    inline ptrdiff_t MovementFunction = 0x66B88E0;
    inline ptrdiff_t MovementComponent = 0x21D;

    inline ptrdiff_t ChatFunction = 0x34D9A0;


    inline ptrdiff_t SkeletonComponent = 0x20C;
}

using Update::client, Update::retaddr;