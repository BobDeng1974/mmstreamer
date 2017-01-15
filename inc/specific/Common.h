//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                              //
//              Copyright © 2016, 2017 Boubacar DIENE                                           //
//                                                                                              //
//              This file is part of mmstreamer project.                                        //
//                                                                                              //
//              mmstreamer is free software: you can redistribute it and/or modify              //
//              it under the terms of the GNU General Public License as published by            //
//              the Free Software Foundation, either version 3 of the License, or               //
//              (at your option) any later version.                                             //
//                                                                                              //
//              mmstreamer is distributed in the hope that it will be useful,                   //
//              but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
//              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   //
//              GNU General Public License for more details.                                    //
//                                                                                              //
//              You should have received a copy of the GNU General Public License               //
//              along with mmstreamer.  If not, see <http://www.gnu.org/licenses/>.             //
//                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
* \file   Common.h
* \author Boubacar DIENE
*/

#ifndef __SPECIFIC_COMMON_H__
#define __SPECIFIC_COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------------------------- */
/*                                           INCLUDE                                            */
/* -------------------------------------------------------------------------------------------- */

#include "graphics/Graphics.h"
#include "network/Client.h"
#include "network/Server.h"
#include "video/Video.h"

#include "utils/Common.h"
#include "utils/Log.h"
#include "utils/Parser.h"

/* -------------------------------------------------------------------------------------------- */
/*                                           DEFINE                                             */
/* -------------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------------------- */
/*                                           TYPEDEFS                                           */
/* -------------------------------------------------------------------------------------------- */

typedef struct GRAPHICS_INFOS_S GRAPHICS_INFOS_S;
typedef struct VIDEO_INFOS_S    VIDEO_INFOS_S;
typedef struct SERVERS_INFOS_S  SERVERS_INFOS_S;
typedef struct CLIENTS_INFOS_S  CLIENTS_INFOS_S;

typedef struct PARAMS_S         PARAMS_S;
typedef struct MODULES_S        MODULES_S;
typedef struct INPUT_S          INPUT_S;
typedef struct CONTEXT_S        CONTEXT_S;

struct GRAPHICS_INFOS_S {
    char              *currentLanguage;
    uint32_t          nbGfxElements;
    GFX_ELEMENT_S     **gfxElements;
    GRAPHICS_PARAMS_S graphicsParams;
};

struct VIDEO_INFOS_S {
    uint8_t           nbVideoListeners;
    VIDEO_LISTENER_S  **videoListeners;
    VIDEO_PARAMS_S    videoParams;
    
    char              *graphicsDest;
    int8_t            graphicsIndex;
    
    char              *serverDest;
    int8_t            serverIndex;
};

struct SERVERS_INFOS_S {
    uint8_t           nbServers;
    SERVER_PARAMS_S   **serverParams;
};

struct CLIENTS_INFOS_S {
    uint8_t           nbClients;
    CLIENT_PARAMS_S   **clientParams;
    
    char              **graphicsDest;
    int8_t            *graphicsIndex;
    
    char              **serverDest;
    int8_t            *serverIndex;
};

struct PARAMS_S {
    GRAPHICS_INFOS_S graphicsInfos;
    VIDEO_INFOS_S    videoInfos;
    SERVERS_INFOS_S  serversInfos;
    CLIENTS_INFOS_S  clientsInfos;
};

struct MODULES_S {
    GRAPHICS_S *graphicsObj;
    VIDEO_S    *videoObj;
    SERVER_S   *serverObj;
    CLIENT_S   *clientObj;
    PARSER_S   *parserObj;
};

struct INPUT_S {
    char       *appDataDir;
    char       *xmlRootDir;
    
    uint8_t    keepAliveMethod;
    uint32_t   timeout_s;
    
    uint8_t    graphicsEnabled;
    uint8_t    autoStartGraphics;
    char       *graphicsXml;
    
    uint8_t    videoEnabled;
    uint8_t    autoStartVideo;
    char       *videoXml;
    
    uint8_t    serverEnabled;
    uint8_t    autoStartServer;
    char       *serversXml;
    
    uint8_t    clientEnabled;
    uint8_t    autoStartClient;
    char       *clientsXml;
};

struct CONTEXT_S {
    PARAMS_S   params;
    MODULES_S  modules;
    INPUT_S    input;
    
    sem_t      keepAliveSem;
};

/* -------------------------------------------------------------------------------------------- */
/*                                           VARIABLES                                          */
/* -------------------------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif //__SPECIFIC_COMMON_H__
