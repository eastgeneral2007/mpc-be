/*  Copyright (c) MediaArea.net SARL. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Information about PCM files
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
#ifndef MediaInfo_File_PcmH
#define MediaInfo_File_PcmH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "MediaInfo/File__Analyze.h"
//---------------------------------------------------------------------------

namespace MediaInfoLib
{

//***************************************************************************
// Class File_Pcm
//***************************************************************************

class File_Pcm : public File__Analyze
{
public :
    //In
    int64u          Frame_Count_Valid;
    ZenLib::Ztring  Codec;
    int32u          SamplingRate;
    int8u           BitDepth;
    int8u           Channels;
    int8u           Endianness;
    int8u           Sign;

    //Constructor/Destructor
    File_Pcm();

private :
    //Streams management
    void Streams_Fill();
    void Streams_Finish();

    //Buffer - File header
    bool FileHeader_Begin();

    //Buffer - Per element
    void Header_Parse();
    void Data_Parse();
};

} //NameSpace

#endif
