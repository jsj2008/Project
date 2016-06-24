/*
 * ff_ffpipenode.h
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

#ifndef FFPLAY__FF_FFPIPENODE_H
#define FFPLAY__FF_FFPIPENODE_H

#include "ksysdl/ksysdl_mutex.h"

typedef struct FFPlayer FFPlayer;

typedef struct KSYFF_Pipenode_Opaque KSYFF_Pipenode_Opaque;
typedef struct KSYFF_Pipenode KSYFF_Pipenode;
typedef struct KSYFF_Pipenode {
    SDL_mutex *mutex;
    void *opaque;

    void (*func_destroy) (KSYFF_Pipenode *node);
    int  (*func_run_sync)(KSYFF_Pipenode *node);
} KSYFF_Pipenode;

KSYFF_Pipenode *ffpipenode_alloc(size_t opaque_size);
void ffpipenode_free(KSYFF_Pipenode *node);
void ffpipenode_free_p(KSYFF_Pipenode **node);

int  ffpipenode_run_sync(KSYFF_Pipenode *node);

#endif