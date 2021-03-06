/*
 * Copyright (C) 2013 The Android Open Source Project
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

#ifndef ANDROID_ISYSPROPERTIESREGISTRAR_H
#define ANDROID_ISYSPROPERTIESREGISTRAR_H

#include <binder/IInterface.h>
#include <syspropservice/ISysPropertiesListener.h>

namespace android {

// must be kept in sync with interface defined in IBatteryPropertiesRegistrar.aidl
enum {
    REGISTER_LISTENER = IBinder::FIRST_CALL_TRANSACTION,
    UNREGISTER_LISTENER,
    GET_PROPERTY,
};

class ISysPropertiesRegistrar : public IInterface {
public:
    DECLARE_META_INTERFACE(SysPropertiesRegistrar);

    virtual void registerListener(const sp<ISysPropertiesListener>& listener) = 0;
    virtual void unregisterListener(const sp<ISysPropertiesListener>& listener) = 0;
    virtual status_t getProperty(int id, struct SysProperty *val) = 0;
};

class BnSysPropertiesRegistrar : public BnInterface<ISysPropertiesRegistrar> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data,
                                Parcel* reply, uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_IBATTERYPROPERTIESREGISTRAR_H
