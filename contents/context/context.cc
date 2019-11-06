/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "linkerconfig/context.h"

namespace android {
namespace linkerconfig {
namespace contents {
bool Context::IsSystemSection() const {
  return current_section == SectionType::System;
}

bool Context::IsVendorSection() const {
  return current_section == SectionType::Vendor;
}

bool Context::IsDefaultConfig() const {
  return current_linkerconfig_type == LinkerConfigType::Default;
}

bool Context::IsLegacyConfig() const {
  return current_linkerconfig_type == LinkerConfigType::Legacy;
}

bool Context::IsVndkliteConfig() const {
  return current_linkerconfig_type == LinkerConfigType::Vndklite;
}

bool Context::IsRecoveryConfig() const {
  return current_linkerconfig_type == LinkerConfigType::Recovery;
}

void Context::SetCurrentSection(SectionType section_type) {
  current_section = section_type;
}

std::string Context::GetSystemNamespaceName() const {
  return IsVendorSection() && !IsVndkliteConfig() ? "system" : "default";
}

void Context::SetCurrentLinkerConfigType(LinkerConfigType config_type) {
  current_linkerconfig_type = config_type;
}
}  // namespace contents
}  // namespace linkerconfig
}  // namespace android
