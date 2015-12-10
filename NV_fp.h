/*
 * Copyright 2015 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __TPM2_NV_FP_H
#define __TPM2_NV_FP_H

TPM_RC NvAddEvictObject(
        TPMI_DH_OBJECT       evictHandle,         // IN: new evict handle
        OBJECT              *object              // IN: object to be added
                        );
UINT32 NvCapGetPersistentNumber(
        void
        );
void NvCheckState(void);
BOOL NvCommit(
        void
        );
TPM_RC NvDefineIndex(
        TPMS_NV_PUBLIC      *publicArea,          // IN: A template for an area to create.
        TPM2B_AUTH          *authValue            // IN: The initial authorization value
        );
void NvDeleteEntity(
        TPM_HANDLE           handle              // IN: handle of entity to be deleted
                    );
void NvFlushHierarchy(
        TPMI_RH_HIERARCHY         hierarchy          // IN: hierarchy to be flushed.
);
void NvGetIndexData(
        TPMI_RH_NV_INDEX          handle,            //   IN: handle
        NV_INDEX                 *nvIndex,           //   IN: RAM image of index header
        UINT32                    offset,            //   IN: offset of NV data
        UINT16                    size,              //   IN: size of NV data
        void                     *data               //   OUT: data buffer
        );
void NvGetIndexInfo(
        TPMI_RH_NV_INDEX          handle,              // IN: handle
        NV_INDEX                 *nvIndex              // OUT: NV index structure
                    );
void NvGetIntIndexData(
        TPMI_RH_NV_INDEX          handle,            // IN: handle
        NV_INDEX                 *nvIndex,           // IN: RAM image of NV Index header
        UINT64                   *data               // IN: UINT64 pointer for counter or bit
        );
UINT16 NvGetName(
        TPMI_RH_NV_INDEX          handle,            // IN: handle of the index
        NAME                     *name               // OUT: name of the index
                 );
TPMI_YES_NO NvCapGetIndex(
        TPMI_DH_OBJECT     handle,              // IN: start handle
        UINT32             count,               // IN: maximum number of returned handle
        TPML_HANDLE       *handleList           // OUT: list of handle
);
TPMI_YES_NO NvCapGetPersistent(
        TPMI_DH_OBJECT       handle,            // IN: start handle
        UINT32               count,             // IN: maximum number of returned handle
        TPML_HANDLE         *handleList         // OUT: list of handle
);
TPM_RC NvIndexIsAccessible(
        TPMI_RH_NV_INDEX         handle,                // IN: handle
        TPM_CC                   commandCode            // IN: the command
                           );
void NvInit(
        void
        );
TPM_RC NvIsAvailable(
        void
);
BOOL NvIsOwnerPersistentHandle(
        TPM_HANDLE           handle              // IN: handle
                               );
BOOL NvIsPlatformPersistentHandle(
        TPM_HANDLE           handle              // IN: handle
                                  );
BOOL NvIsUndefinedIndex(
        TPMI_RH_NV_INDEX         handle                 // IN: handle
        );
void NvSetGlobalLock(
        void
        );
TPM_RC NvWriteIndexData(
        TPMI_RH_NV_INDEX          handle,               //   IN: handle
        NV_INDEX                 *nvIndex,              //   IN: RAM copy of NV Index
        UINT32                    offset,               //   IN: offset of NV data
        UINT32                    size,                 //   IN: size of NV data
        void                     *data                  //   OUT: data buffer
        );
TPM_RC NvWriteIndexInfo(
        TPMI_RH_NV_INDEX            handle,                // IN: handle
        NV_INDEX                   *nvIndex                // IN: NV Index info to be written
        );
void NvWriteReserved(
        NV_RESERVE   type,              // IN: type of reserved data
        void        *buffer             // IN: data buffer
                     );

#endif // __TPM2_NV_FP_H
