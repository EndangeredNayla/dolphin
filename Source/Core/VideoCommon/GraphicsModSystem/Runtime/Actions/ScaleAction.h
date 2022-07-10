// Copyright 2022 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>

#include <picojson.h>

#include "VideoCommon/GraphicsModSystem/Runtime/GraphicsModAction.h"

class ScaleAction final : public GraphicsModAction
{
public:
  static std::unique_ptr<ScaleAction> Create(const picojson::value& json_data);
  explicit ScaleAction(Common::Vec3 scale);
  void OnEFB(bool* skip, u32 texture_width, u32 texture_height, u32* scaled_width,
             u32* scaled_height) override;
  void OnProjection(Common::Matrix44* matrix) override;
  void OnProjectionAndTexture(Common::Matrix44* matrix) override;

private:
  Common::Vec3 m_scale;
};