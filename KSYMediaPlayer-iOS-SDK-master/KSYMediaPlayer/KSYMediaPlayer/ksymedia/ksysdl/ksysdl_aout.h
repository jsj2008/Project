/*****************************************************************************
 * ksysdl_aout.h
 *****************************************************************************
 *
 * This file is part of ksyPlayer.
 *
 * ksyPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ksyPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ksyPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef IJKSDL__IJKSDL_AOUT_H
#define IJKSDL__IJKSDL_AOUT_H

#include "ksysdl_audio.h"
#include "ksysdl_class.h"
#include "ksysdl_mutex.h"

typedef struct SDL_Aout_Opaque SDL_Aout_Opaque;
typedef struct SDL_Aout SDL_Aout;
typedef struct SDL_Aout {
    SDL_mutex *mutex;
    double     minimal_latency_seconds;

    SDL_Class       *opaque_class;
    SDL_Aout_Opaque *opaque;
    void (*free_l)(SDL_Aout *vout);
    int (*open_audio)(SDL_Aout *aout, const SDL_AudioSpec *desired, SDL_AudioSpec *obtained);
    void (*pause_audio)(SDL_Aout *aout, int pause_on);
    void (*flush_audio)(SDL_Aout *aout);
    void (*set_volume)(SDL_Aout *aout, float left, float right);
    void (*close_audio)(SDL_Aout *aout);

    double (*func_get_latency_seconds)(SDL_Aout *aout);
    void   (*func_set_default_latency_seconds)(SDL_Aout *aout, double latency);
} SDL_Aout;

int SDL_AoutOpenAudio(SDL_Aout *aout, const SDL_AudioSpec *desired, SDL_AudioSpec *obtained);
void SDL_AoutPauseAudio(SDL_Aout *aout, int pause_on);
void SDL_AoutFlushAudio(SDL_Aout *aout);
void SDL_AoutSetStereoVolume(SDL_Aout *aout, float left_volume, float right_volume);
void SDL_AoutCloseAudio(SDL_Aout *aout);
void SDL_AoutFree(SDL_Aout *aout);
void SDL_AoutFreeP(SDL_Aout **paout);

double SDL_AoutGetLatencySeconds(SDL_Aout *aout);
void   SDL_AoutSetDefaultLatencySeconds(SDL_Aout *aout, double latency);

#endif