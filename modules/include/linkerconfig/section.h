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
#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

#include "linkerconfig/configwriter.h"
#include "linkerconfig/namespace.h"

namespace android {
namespace linkerconfig {
namespace modules {

using BinaryPathMap = std::map<std::string, std::string>;

class Section {
 public:
  Section(std::string name, std::vector<std::string> binary_paths,
          std::vector<Namespace> namespaces)
      : name_(std::move(name)),
        binary_paths_(std::move(binary_paths)),
        namespaces_(std::move(namespaces)) {
  }

  Section(const Section&) = delete;
  Section(Section&&) = default;

  void WriteConfig(ConfigWriter& writer);
  void CollectBinaryPaths(BinaryPathMap& binary_paths);

  // For test usage
  Namespace* GetNamespace(const std::string& namespace_name);
  std::string GetName();

 private:
  const std::string name_;
  std::vector<std::string> binary_paths_;
  std::vector<Namespace> namespaces_;
};
}  // namespace modules
}  // namespace linkerconfig
}  // namespace android