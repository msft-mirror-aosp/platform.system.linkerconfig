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

#include "linkerconfig/recovery.h"
#include "configurationtest.h"
#include "linkerconfig/configwriter.h"
#include "mockenv.h"

TEST(linkerconfig_configuration_fulltest, recovery_test) {
  MockGenericVariables();
  auto legacy_config =
      android::linkerconfig::contents::CreateRecoveryConfiguration();
  android::linkerconfig::modules::ConfigWriter config_writer;

  legacy_config.WriteConfig(config_writer);

  VerifyConfiguration(config_writer.ToString());
}