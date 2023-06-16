#include "RawWithGzip.h"

#include "Utils/Logger.hpp"

MAA_CTRL_UNIT_NS_BEGIN

bool ScreencapRawWithGzip::parse(const json::value& config)
{
    return parse_argv("ScreencapRawWithGzip", config, screencap_raw_with_gzip_argv_);
}

bool ScreencapRawWithGzip::init(int w, int h)
{
    set_wh(w, h);
    return true;
}

std::optional<cv::Mat> ScreencapRawWithGzip::screencap()
{
    LogFunc;

    if (!io_ptr_) {
        LogError << "io_ptr is nullptr";
        return std::nullopt;
    }

    auto cmd_ret = command(screencap_raw_with_gzip_argv_.gen(argv_replace_));

    if (!cmd_ret) {
        return std::nullopt;
    }

    return process_data(cmd_ret.value(), std::bind(&ScreencapBase::decode_gzip, this, std::placeholders::_1));
}

MAA_CTRL_UNIT_NS_END