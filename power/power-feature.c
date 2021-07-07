/*
 * Copyright (C) 2020 The LineageOS Project
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
#include <fcntl.h>
#include <unistd.h>

#include "power-feature.h"

#include <hardware/power.h>
#include <log/log.h>

#define TAP_TO_WAKE_HIMAX "/proc/android_touch/SMWP"
#define TAP_TO_WAKE_FTS "/sys/android_touch/wakeup_gesture_enable"

void set_device_specific_feature(struct power_module *module __unused,
    feature_t feature, int state)
{
    if (feature == POWER_FEATURE_DOUBLE_TAP_TO_WAKE) {
        char value = state ? '1' : '0';
        int fd = open(TAP_TO_WAKE_FTS, O_WRONLY);
        if (fd < 0){
            ALOGD("Opening TAP_TO_WAKE_FTS failed, trying HIMAX");
            fd = open(TAP_TO_WAKE_HIMAX, O_WRONLY);
            if (fd < 0){
                ALOGE("Opening TAP_TO_WAKE_HIMAX failed!");                }
            else
                ALOGD("Success");
        }
        int len = write(fd, &value, sizeof(value));
        if (len < 0){
            ALOGE("Writing failed!");
        }
    }
}
