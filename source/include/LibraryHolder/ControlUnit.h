#pragma once

#include "LibraryHolder.h"

#include <memory>

#include "ControlUnit/ControlUnitAPI.h"
#include "Utils/Platform.h"

MAA_NS_BEGIN

class AdbControlUnitLibraryHolder : public LibraryHolder<AdbControlUnitLibraryHolder>
{
public:
    static std::shared_ptr<MAA_CTRL_UNIT_NS::ControlUnitAPI> create_control_unit(
        MaaStringView adb_path,
        MaaStringView adb_serial,
        MaaAdbControllerType type,
        MaaStringView config,
        MaaStringView agent_path,
        MaaControllerCallback callback,
        MaaCallbackTransparentArg callback_arg);

private:
    inline static const std::filesystem::path libname_ = MAA_NS::path("MaaAdbControlUnit");
    inline static const std::string version_func_name_ = "MaaAdbControlUnitGetVersion";
    inline static const std::string create_func_name_ = "MaaAdbControlUnitCreate";
    inline static const std::string destroy_func_name_ = "MaaAdbControlUnitDestroy";
};

class Win32ControlUnitLibraryHolder : public LibraryHolder<Win32ControlUnitLibraryHolder>
{
public:
    static std::shared_ptr<MAA_CTRL_UNIT_NS::ControlUnitAPI> create_control_unit(
        MaaWin32Hwnd hWnd,
        MaaWin32ControllerType type,
        MaaControllerCallback callback,
        MaaCallbackTransparentArg callback_arg);

private:
    inline static const std::filesystem::path libname_ = MAA_NS::path("MaaWin32ControlUnit");
    inline static const std::string version_func_name_ = "MaaWin32ControlUnitGetVersion";
    inline static const std::string create_func_name_ = "MaaWin32ControlUnitCreate";
    inline static const std::string destroy_func_name_ = "MaaWin32ControlUnitDestroy";
};

class DbgControlUnitLibraryHolder : public LibraryHolder<DbgControlUnitLibraryHolder>
{
public:
    static std::shared_ptr<MAA_CTRL_UNIT_NS::ControlUnitAPI>
        create_control_unit(MaaDbgControllerType type, MaaStringView read_path);

private:
    inline static const std::filesystem::path libname_ = MAA_NS::path("MaaDbgControlUnit");
    inline static const std::string version_func_name_ = "MaaDbgControlUnitGetVersion";
    inline static const std::string create_func_name_ = "MaaDbgControlUnitCreate";
    inline static const std::string destroy_func_name_ = "MaaDbgControlUnitDestroy";
};

class ThriftControlUnitLibraryHolder : public LibraryHolder<ThriftControlUnitLibraryHolder>
{
public:
    static std::shared_ptr<MAA_CTRL_UNIT_NS::ControlUnitAPI> create_control_unit(
        MaaThriftControllerType type,
        MaaStringView host,
        int32_t port,
        MaaStringView config);

private:
    inline static const std::filesystem::path libname_ = MAA_NS::path("MaaThriftControlUnit");
    inline static const std::string version_func_name_ = "MaaThriftControlUnitGetVersion";
    inline static const std::string create_func_name_ = "MaaThriftControlUnitCreate";
    inline static const std::string destroy_func_name_ = "MaaThriftControlUnitDestroy";
};

MAA_NS_END
