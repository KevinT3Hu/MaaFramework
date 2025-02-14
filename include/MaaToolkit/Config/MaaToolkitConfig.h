/**
 * @file MaaToolkitConfig.h
 * @author
 * @brief Init and uninit the toolkit.
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "../MaaToolkitDef.h"

#ifdef __cplusplus
extern "C"
{
#endif

    MAA_TOOLKIT_API MaaBool MaaToolkitInit();
    MAA_TOOLKIT_API MaaBool MaaToolkitUninit();

#ifdef __cplusplus
}
#endif
