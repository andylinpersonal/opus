/* Copyright (c) 2022 Amazon
   Written by Jan Buethe */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _DRED_ENCODER_H
#define _DRED_ENCODER_H

#include "lpcnet.h"
#include "dred_config.h"
#include "dred_rdovae.h"
#include "entcode.h"



typedef struct {
    opus_int16 input_buffer[DRED_DFRAME_SIZE + DRED_SILK_ENCODER_DELAY];
    float feature_buffer[2 * 36];
    float latents_buffer[DRED_MAX_FRAMES * DRED_LATENT_DIM];
    float state_buffer[24];
    unsigned char ec_buffer[DRED_MAX_DATA_SIZE];
    ec_enc ec_encoder;
    LPCNetEncState *lpcnet_enc_state;
    RDOVAEEnc *rdovae_enc;
} DREDEnc;


void init_dred_encoder(DREDEnc* enc);

void dred_deinit_encoder(DREDEnc *enc);

void dred_encode_silk_frame(DREDEnc *enc, const opus_int16 *silk_frame);

#endif