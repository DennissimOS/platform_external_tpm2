/*
 * Copyright 2015 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __TPM2_MARSHAL_FP_H
#define __TPM2_MARSHAL_FP_H

UINT16 Common_Marshal(void *source, BYTE **buffer, INT32 *size,
                      UINT16 type_size);
TPM_RC  Common_Unmarshal(void *source, BYTE **buffer, INT32 *size,
                         UINT16 type_size);

#define MARSHAL_WRAPPER(name)   \
        static inline UINT16 name##_Marshal(void *x, BYTE **y, INT32 *z) { \
        return Common_Marshal(x, y, z, sizeof(name)); \
        }\
        static inline TPM_RC name##_Unmarshal(void *x, BYTE **y, INT32 *z) { \
        return Common_Unmarshal(x, y, z, sizeof(name)); \
        }

MARSHAL_WRAPPER(TPMS_ATTEST)
MARSHAL_WRAPPER(TPMS_ECC_POINT)
MARSHAL_WRAPPER(TPM_HANDLE)

#endif // __TPM2_MARSHAL_FP_H
