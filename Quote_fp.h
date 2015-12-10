// Copyright 2015 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// THIS CODE IS GENERATED - DO NOT MODIFY!

#ifndef TPM2_QUOTE_FP_H_
#define TPM2_QUOTE_FP_H_

#include "tpm_generated.h"

typedef struct {
  TPMI_DH_OBJECT signHandle;
  TPM2B_DATA qualifyingData;
  TPMT_SIG_SCHEME inScheme;
  TPML_PCR_SELECTION PCRselect;
} Quote_In;

typedef struct {
  TPM2B_ATTEST quoted;
  TPMT_SIGNATURE signature;
} Quote_Out;

// Executes Quote with request handles and parameters from
// |in| and computes response handles and parameters to |out|.
TPM_RC TPM2_Quote(Quote_In* in, Quote_Out* out);

// Initializes handle fields in |target| from |request_handles|. Unmarshals
// parameter fields in |target| from |buffer|.
TPM_RC Quote_In_Unmarshal(Quote_In* target,
                          TPM_HANDLE request_handles[],
                          BYTE** buffer,
                          INT32* size);

// Marshals response handles and parameters from |source| to |buffer|. Computes
// and marshals the size of the parameter area (parameter_size) if |tag| ==
// TPM_ST_SESSIONS. Returns size of (parameter area + handle area) in bytes.
// Return value does not include parameter_size field.
UINT16 Quote_Out_Marshal(Quote_Out* source,
                         TPMI_ST_COMMAND_TAG tag,
                         BYTE** buffer,
                         INT32* size);

// Unmarshals any request parameters starting at |request_parameter_buffer|.
// Executes command. Marshals any response handles and parameters to the
// global response buffer and computes |*response_handle_buffer_size| and
// |*response_parameter_buffer_size|. If |tag| == TPM_ST_SESSIONS, marshals
// parameter_size indicating the size of the parameter area. parameter_size
// field is located between the handle area and parameter area.
TPM_RC Exec_Quote(TPMI_ST_COMMAND_TAG tag,
                  BYTE** request_parameter_buffer,
                  INT32* request_parameter_buffer_size,
                  TPM_HANDLE request_handles[],
                  UINT32* response_handle_buffer_size,
                  UINT32* response_parameter_buffer_size);

#endif  // TPM2_QUOTE_FP_H
