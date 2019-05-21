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
Namespace BuildSystemNamespace([[maybe_unused]] const Context& ctx) {
  Namespace ns("system", /*is_isolated=*/false, /*is_visible=*/false);
  ns.AddSearchPath("/system/${LIB}", /*also_in_asan=*/true,
                   /*with_data_asan=*/true);
  ns.AddSearchPath("/@{PRODUCT:product}/${LIB}", /*also_in_asan=*/true,
                   /*with_data_asan=*/true);
  ns.AddSearchPath("/@{PRODUCT_SERVICES}/${LIB}", /*also_in_asan=*/true,
                   /*with_data_asan=*/true);

  ns.CreateLink("runtime").AddSharedLib(
      {"libdexfile_external.so", "libnativebridge.so", "libnativehelper.so",
       "libnativeloader.so", "libandroidicu.so"});

  return ns;
}
}  // namespace contents
}  // namespace linkerconfig
}  // namespace android