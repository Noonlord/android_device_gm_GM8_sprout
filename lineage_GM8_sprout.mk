#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from GM8_sprout device
$(call inherit-product, device/gm/GM8_sprout/device.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := lineage_GM8_sprout
PRODUCT_DEVICE := GM8_sprout
PRODUCT_BRAND := GM
PRODUCT_MODEL := GM 8
PRODUCT_MANUFACTURER := General_Mobile

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="msm8937_64-user 9 OPM1.171019.011 eng.scm.20210302.164620 release-keys"

BUILD_FINGERPRINT := google/walleye/walleye:8.1.0/OPM1.171019.011/4448085:user/release-keys

TARGET_SCREEN_WIDTH := 720
TARGET_SCREEN_HEIGHT := 1440
