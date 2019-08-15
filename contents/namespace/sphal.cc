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

#include "linkerconfig/namespacebuilder.h"

using android::linkerconfig::modules::Namespace;

namespace android {
namespace linkerconfig {
namespace contents {
Namespace BuildSphalNamespace([[maybe_unused]] const Context& ctx) {
  Namespace ns("sphal", /*is_isolated=*/true, /*is_visible=*/true);
  ns.AddSearchPath("/odm/${LIB}", /*also_in_asan=*/true,
                   /*with_data_asan=*/true);
  ns.AddSearchPath("/vendor/${LIB}", /*also_in_asan=*/true,
                   /*with_data_asan=*/true);
  ns.AddSearchPath("/vendor/${LIB}/hw", /*also_in_asan=*/false,
                   /*with_data_asan=*/false);

  ns.AddPermittedPath("/odm/${LIB}", /*also_in_asan=*/true,
                      /*with_data_asan=*/true);
  ns.AddPermittedPath("/vendor/${LIB}", /*also_in_asan=*/true,
                      /*with_data_asan=*/true);
  ns.AddPermittedPath("/system/vendor/${LIB}", /*also_in_asan=*/false,
                      /*with_data_asan=*/false);

  ns.CreateLink("rs").AddSharedLib("libRS_internal.so");
  ns.CreateLink("default").AddSharedLib(
      {"@{LLNDK_LIBRARIES:}", "@{SANITIZER_RUNTIME_LIBRARIES:}"});
  ns.CreateLink("vndk").AddSharedLib("@{VNDK_SAMEPROCESS_LIBRARIES:}");
  ns.CreateLink("neuralnetworks").AddSharedLib("libneuralnetworks.so");

  return ns;
}
}  // namespace contents
}  // namespace linkerconfig
}  // namespace android