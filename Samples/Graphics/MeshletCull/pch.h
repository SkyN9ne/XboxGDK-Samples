//--------------------------------------------------------------------------------------
// pch.h
//
// Header for standard system include files.
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include <winsdkver.h>
#define _WIN32_WINNT 0x0A00
#include <sdkddkver.h>

// Use the C++ standard templated min/max
#define NOMINMAX

// DirectX apps don't need GDI
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// Include <mcx.h> if you need this
#define NOMCX

// Include <winsvc.h> if you need this
#define NOSERVICE

// WinHelp is deprecated
#define NOHELP

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <wrl/client.h>
#include <wrl/event.h>

#include <grdk.h>

#if _GRDK_VER < 0x4A610D2B /* GXDK Edition 200600 */
#error This sample requires the June 2020 GDK or later
#endif

#ifdef _GAMING_XBOX_SCARLETT
#include <d3d12_xs.h>
#include <d3dx12_xs.h>
#elif defined(_GAMING_XBOX)
#error This sample does not support Xbox One
#else
#include <d3d12.h>
#include <dxgi1_6.h>

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include "d3dx12.h"
#endif

#define _XM_NO_XMVECTOR_OVERLOADS_

#include <DirectXMath.h>
#include <DirectXColors.h>

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <exception>
#include <memory>
#include <stdexcept>

#include <assert.h>
#include <stdio.h>

#ifdef _GAMING_XBOX
#include <pix3.h>
#else
// To use graphics markup events with the latest version of PIX, change this to include <pix3.h>
// then add the NuGet package WinPixEventRuntime to the project.
#include <pix.h>
#endif
#include <XGame.h>
#include <XSystem.h>

#include "CommonStates.h"
#include "ControllerFont.h"
#include "ControllerHelp.h"
#include "DescriptorHeap.h"
#include "DirectXHelpers.h"
#include "GamePad.h"
#include "GraphicsMemory.h"
#include "Keyboard.h"
#include "Meshlet.h"
#include "Model.h"
#include "Mouse.h"
#include "OrbitCamera.h"
#ifdef _GAMING_XBOX_SCARLETT
#include "PerformanceTimersXbox.h"
#else
#include "PerformanceTimers.h"
#endif
#include "ReadData.h"
#include "RenderTargetState.h"
#include "ResourceUploadBatch.h"
#include "SimpleMath.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"

struct VQS
{
    DirectX::XMFLOAT4 Rotation;
    DirectX::XMFLOAT3 Position;
    float             Scale;

    inline DirectX::XMMATRIX ToMatrix() const
    {
        return DirectX::XMMatrixAffineTransformation(
            DirectX::XMVectorReplicate(Scale),
            DirectX::g_XMZero,
            DirectX::XMLoadFloat4(&Rotation),
            DirectX::XMLoadFloat3(&Position)
        );
    }

    inline VQS& operator=(DirectX::FXMMATRIX mat)
    {
        DirectX::XMVECTOR scale, position, rotation;
        DirectX::XMMatrixDecompose(&scale, &rotation, &position, mat);

        DirectX::XMStoreFloat3(&Position, position);
        DirectX::XMStoreFloat4(&Rotation, rotation);
        DirectX::XMStoreFloat(&Scale, scale);

        return *this;
    }

    inline static VQS Identity() { return CreateScale(1.0f); }
    inline static VQS CreateScale(float scale)
    {
        VQS r;
        DirectX::XMStoreFloat4(&r.Rotation, DirectX::XMQuaternionIdentity());
        DirectX::XMStoreFloat3(&r.Position, DirectX::XMVectorZero());
        r.Scale = scale;

        return r;
    }

    DirectX::XMMATRIX ToInverseMatrix() const { return DirectX::XMMatrixInverse(nullptr, ToMatrix()); }
};

namespace DX
{
    // Helper class for COM exceptions
    class com_exception : public std::exception
    {
    public:
        com_exception(HRESULT hr) : result(hr) {}

        virtual const char* what() const override
        {
            static char s_str[64] = {};
            sprintf_s(s_str, "Failure with HRESULT of %08X", static_cast<unsigned int>(result));
            return s_str;
        }

    private:
        HRESULT result;
    };

    // Helper utility converts D3D API failures into exceptions.
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            throw com_exception(hr);
        }
    }
}

// Enable off by default warnings to improve code conformance
#pragma warning(default : 4061 4062 4191 4242 4263 4264 4265 4266 4289 4365 4826 4841 4986 4987 5029 5038 5042)