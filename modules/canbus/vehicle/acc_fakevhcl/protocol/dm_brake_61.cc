/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/acc_fakevhcl/protocol/dm_brake_61.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acc_fakevhcl {

using ::apollo::drivers::canbus::Byte;

Dmbrake61::Dmbrake61() {}
const int32_t Dmbrake61::ID = 0x61;

void Dmbrake61::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acc_fakevhcl()->mutable_dm_brake_61()->set_dm_brake(dm_brake(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'dm_brake', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 0.1, 'type': 'double'}
double Dmbrake61::dm_brake(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}
}  // namespace acc_fakevhcl
}  // namespace canbus
}  // namespace apollo