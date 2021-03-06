// kX WDM Audio Driver
// Copyright (c) Eugene Gavrilov, 2001-2014.
// All rights reserved

// #define USE_MULTY_WAVE 1

/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */


static KSDATARANGE PinDataRangesBridge[] =
{
    {
            sizeof(KSDATARANGE),
            0,
            0,
            0,
            STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
            STATICGUIDOF(KSDATAFORMAT_SUBTYPE_ANALOG),
            STATICGUIDOF(KSDATAFORMAT_SPECIFIER_NONE)
    }
};

static PKSDATARANGE PinDataRangePointersBridge[] =
{
    (PKSDATARANGE)&PinDataRangesBridge[0]
};

/*****************************************************************************
 * MiniportPins
 *****************************************************************************
 * List of pins.
 */
static
PCPIN_DESCRIPTOR 
MiniportPins[] =
{
    // TOPO_WAVEOUT01_SOURCE
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSCATEGORY_AUDIO,				// Category
            &TOPO_WAVEOUT01_NAME, 			// Name
            0                                           // Reserved
        }
    },

    // TOPO_SYNTH1_SOURCE
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSCATEGORY_SYNTHESIZER,                    // Category
            &TOPO_SYNTH1_NAME,                       	// Name 
            0                                           // Reserved
        }
    },

    // TOPO_SYNTH2_SOURCE
/*    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSCATEGORY_SYNTHESIZER,                    // Category
            &TOPO_SYNTH2_NAME,                       	// Name 
            0                                           // Reserved
        }
    },
*/
    // TOPO_RECIN_SOURCE = what U here :)
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),    // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_BRIDGE,                 // Communication
            &KSNODETYPE_LINE_CONNECTOR,
            &MY_KX_RECMIXER_NAME, // &TOPO_WAVEIN_NAME,	                	// Name
            0                                           // Reserved
        }
    },

    // TOPO_MASTER_MIXER_DEST = play_control
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_OUT,                         // DataFlow
            KSPIN_COMMUNICATION_BRIDGE,                 // Communication
            &KSNODETYPE_SPEAKER,                        // Category
            &TOPO_MASTER_MIXER_NAME,                  // Name (this name shows up as
            /* &TOPO_WAVEOUT01_NAME,*/
                                                        // the playback panel name in SoundVol)
            0                                           // Reserved
        }
    },
    // TOPO_WAVEIN_DEST = recording_control
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_OUT,                         // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSCATEGORY_AUDIO,
            &TOPO_WAVEIN_NAME, // &TOPO_WAVEIN_NAME or &TOPO_RECIN_NAME,      // Name
            0                                           // Reserved
        }
    },
#ifdef USE_MULTY_WAVE
    // TOPO_WAVEOUT23_SOURCE
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSNODETYPE_LINE_CONNECTOR,				// Category
            &TOPO_WAVEOUT23_NAME, 			// Name
            0                                           // Reserved
        }
    },


    // TOPO_WAVEOUT45_SOURCE
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSNODETYPE_LINE_CONNECTOR,				// Category
            &TOPO_WAVEOUT45_NAME, 			// Name
            0                                           // Reserved
        }
    },


    // TOPO_WAVEOUT67_SOURCE
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSNODETYPE_LINE_CONNECTOR,				// Category
            &TOPO_WAVEOUT67_NAME, 			// Name
            0                                           // Reserved
        }
    },

    // TOPO_WAVEOUTHQ_SOURCE
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSNODETYPE_LINE_CONNECTOR,				// Category
            &TOPO_WAVEOUTHQ_NAME, 			// Name
            0                                           // Reserved
            }
    },
#endif
#if 1
    // TOPO_LINEIN_SOURCE = line_in
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSNODETYPE_LINE_CONNECTOR,                 // Category
            &KX_LINEIN_NAME,		                // Name
            0                                           // Reserved
        }
    },
    // TOPO_MICIN_SOURCE = mic_in
    {
        0,0,0,  // InstanceCount
        NULL,   // AutomationTable
        {       // KsPinDescriptor
            0,                                          // InterfacesCount
            NULL,                                       // Interfaces
            0,                                          // MediumsCount
            NULL,                                       // Mediums
            SIZEOF_ARRAY(PinDataRangePointersBridge),   // DataRangesCount
            PinDataRangePointersBridge,                 // DataRanges
            KSPIN_DATAFLOW_IN,                          // DataFlow
            KSPIN_COMMUNICATION_NONE,                   // Communication
            &KSNODETYPE_MICROPHONE,	                // Category
            &KX_MICIN_NAME,		                // Name
            0                                           // Reserved
        }
    }
#endif
};

enum
{
    TOPO_WAVEOUT01_SOURCE = 0,
    TOPO_SYNTH1_SOURCE,
//    TOPO_SYNTH2_SOURCE,
    TOPO_RECIN_SOURCE,
    TOPO_MASTER_MIXER_DEST,
    TOPO_WAVEIN_DEST,
#ifdef USE_MULTY_WAVE
    TOPO_WAVEOUT23_SOURCE,
    TOPO_WAVEOUT45_SOURCE,
    TOPO_WAVEOUT67_SOURCE,
    TOPO_WAVEOUTHQ_SOURCE,
#endif
    TOPO_LINEIN_SOURCE,
    TOPO_MICIN_SOURCE
};

static
PCPROPERTY_ITEM TopologyProperties[] =
{
    { // filter/pin
        &KSPROPSETID_Audio, 
        KSPROPERTY_AUDIO_VOLUMELEVEL,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        CMiniportTopology::PropertyLevel
    },
    { // filter
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_CPU_RESOURCES,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_BASICSUPPORT,
        CMiniportTopology::PropertyCpuResources
    },
    { // pin
        &KSPROPSETID_Audio, 
        KSPROPERTY_AUDIO_MUTE,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET,
        CMiniportTopology::PropertyOnOff
    }
};

static
PCPROPERTY_ITEM FilterProperties[] =
{
    { //
        &KSPROPSETID_Private,
        KSPROPERTY_PRIVATE,
        KSPROPERTY_TYPE_GET|KSPROPERTY_TYPE_SET,
        CMiniportTopology::PropertyPrivate
    },
    { // filter
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_CPU_RESOURCES,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_BASICSUPPORT,
        CMiniportTopology::PropertyCpuResources
    }
/*    ,
    { // filter/pin
        &KSPROPSETID_Audio, 
        KSPROPERTY_AUDIO_VOLUMELEVEL,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        CMiniportTopology::PropertyLevel
    },
    { // pin
        &KSPROPSETID_Audio, 
        KSPROPERTY_AUDIO_MUTE,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET,
        CMiniportTopology::PropertyOnOff
    }
*/
};


/*
static PCEVENT_ITEM NodeEvent[] =
{
    // This is a generic event for nearly every node property.
    {
        &KSEVENTSETID_AudioControlChange,   // Something changed!
        KSEVENT_CONTROL_CHANGE,             // The only event-property defined.
        KSEVENT_TYPE_ENABLE | KSEVENT_TYPE_BASICSUPPORT,
        CMiniportTopology::EventHandler
    }
};
*/
DEFINE_PCAUTOMATION_TABLE_PROP(TopologyAutomation,TopologyProperties);
DEFINE_PCAUTOMATION_TABLE_PROP(FilterAutomation,FilterProperties);
//DEFINE_PCAUTOMATION_TABLE_PROP_EVENT (AutomationWithEvent, TopologyProperties, NodeEvent);

/*****************************************************************************
 * TopologyNodes
 *****************************************************************************
 * List of node identifiers.
 */
static
PCNODE_DESCRIPTOR TopologyNodes[] =
{
    // TOPO_WAVEOUT01_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_WAVEOUT01_VOLUME_NAME//&KSAUDFNAME_WAVE_VOLUME // Name
    },
    // TOPO_WAVEOUT01_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,     // Type
        &TOPO_WAVEOUT01_MUTE_NAME//&KSAUDFNAME_WAVE_MUTE // Name
    },
    // SYNTH1_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_SYNTH1_VOLUME_NAME//&KSAUDFNAME_MIDI_VOLUME // Name
    },
    // SYNTH1_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,     // Type
        &TOPO_SYNTH1_MUTE_NAME//&KSAUDFNAME_MIDI_MUTE // Name
    },
/*
    // SYNTH2_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_SYNTH2_VOLUME_NAME//&KSAUDFNAME_MIDI_VOLUME // Name
    },
    // SYNTH2_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,     // Type
        &TOPO_SYNTH2_MUTE_NAME//&KSAUDFNAME_MIDI_MUTE // Name
    },
*/
    // MASTER_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,   // FIXME AutomationTable with event support
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_MASTER_VOLUME_NAME//&KSAUDFNAME_MASTER_VOLUME // Name
    },

    // MASTER_MUTE
    {
        0,                      // Flags
        &TopologyAutomation, 	// AutomationTable with event support
        &KSNODETYPE_MUTE,     	// Type
        &TOPO_MASTER_MUTE_NAME//&KSAUDFNAME_MASTER_MUTE // Name
    },
    // MASTER_MIX
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_SUM,        // Type
        NULL		        // Name
    },
    // RECIN_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_RECIN_VOLUME_NAME // Name
    },
    // RECIN_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_MUTE,     // Type
        &TOPO_RECIN_MUTE_NAME// Name
    },
    // RECIN_SUM
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_SUM,        // Type
        NULL		        // Name
    },
#ifdef USE_MULTY_WAVE
    // TOPO_WAVEOUT23_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_WAVEOUT23_VOLUME_NAME//&KSAUDFNAME_WAVE_VOLUME // Name
    },
    // TOPO_WAVEOUT23_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,     // Type
        &TOPO_WAVEOUT23_MUTE_NAME//&KSAUDFNAME_WAVE_MUTE // Name
    },
    // TOPO_WAVEOUT45_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_WAVEOUT45_VOLUME_NAME//&KSAUDFNAME_WAVE_VOLUME // Name
    },
    // TOPO_WAVEOUT45_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,     // Type
        &TOPO_WAVEOUT45_MUTE_NAME//&KSAUDFNAME_WAVE_MUTE // Name
    },
    // TOPO_WAVEOUT67_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_WAVEOUT67_VOLUME_NAME//&KSAUDFNAME_WAVE_VOLUME // Name
    },
    // TOPO_WAVEOUT67_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,     // Type
        &TOPO_WAVEOUT67_MUTE_NAME//&KSAUDFNAME_WAVE_MUTE // Name
    },
    // TOPO_WAVEOUTHQ_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &TOPO_WAVEOUTHQ_VOLUME_NAME //&KSAUDFNAME_WAVE_VOLUME // Name
    },
    // TOPO_WAVEOUTHQ_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable with event support
        &KSNODETYPE_MUTE,       // Type
        &TOPO_WAVEOUTHQ_MUTE_NAME //&KSAUDFNAME_WAVE_MUTE // Name
    },
#endif
    // TOPO_LINEIN_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,      // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &KX_LINEIN_NAME		// Name
    },
    // TOPO_LINEIN_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_MUTE,     	// Type
        &KX_LINEIN_MUTE_NAME	// Name
    },
    // TOPO_MICIN_VOLUME
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_VOLUME,     // Type
        &KX_MICIN_NAME		// Name
    },
    // TOPO_MICIN_MUTE
    {
        0,                      // Flags
        &TopologyAutomation,    // AutomationTable
        &KSNODETYPE_MUTE,     	// Type
        &KX_MICIN_MUTE_NAME	// Name
    }
};

enum
{
 TOPO_WAVEOUT01_VOLUME  ,
 TOPO_WAVEOUT01_MUTE    ,
 TOPO_SYNTH1_VOLUME     ,	// note: '2' is also WAVE_VOLUME1
 TOPO_SYNTH1_MUTE       ,
/* TOPO_SYNTH2_VOLUME     ,
 TOPO_SYNTH2_MUTE       ,
*/
 TOPO_MASTER_VOLUME     ,	// NOTE: TOPO_MASTER_VOLUME is used in p16v driver
 				// note: '4' is also WAVE_VOLUME2
 TOPO_MASTER_MUTE       ,
 TOPO_MASTER_MIX	    ,
 TOPO_RECIN_VOLUME      ,
 TOPO_RECIN_MUTE        ,
 TOPO_RECIN_SUM         ,
#ifdef USE_MULTY_WAVE
 TOPO_WAVEOUT23_VOLUME  ,
 TOPO_WAVEOUT23_MUTE    ,
 TOPO_WAVEOUT45_VOLUME  ,
 TOPO_WAVEOUT45_MUTE    ,
 TOPO_WAVEOUT67_VOLUME  ,
 TOPO_WAVEOUT67_MUTE    ,
#endif
 TOPO_LINEIN_VOLUME	,
 TOPO_LINEIN_MUTE	,
 TOPO_MICIN_VOLUME	,
 TOPO_MICIN_MUTE	
};

static char *mixer_data_names[MAX_TOPOLOGY_ITEMS]=
{
 "WaveOut01 Volume",
 "WaveOut01 Mute",
 "Synth1 Volume",
 "Synth1 Mute",
/* "Synth2 Volume",
 "Synth2 Mute",
*/
 "Master Volume",
 "Master Mute",
 "Master Mix",
 "RecIn Volume",
 "Recin Mux",
#ifdef USE_MULTY_WAVE
 "WaveOut23 Volume",
 "WaveOut23 Mute",
 "WaveOut45 Volume",
 "WaveOut45 Mute",
 "WaveOut67 Volume",
 "WaveOut67 Mute",
#endif
 "LineIn Volume",
 "LineIn Mute",
 "MicIn Volume",
 "MicIn Mute"
 };

static dword default_mixer_data[MAX_TOPOLOGY_ITEMS][MAX_TOPOLOGY_CHANNELS]=
{
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, },
 { 0, }
};

static char *mixer_data_ch_names[MAX_TOPOLOGY_CHANNELS]=
{
 "Left",
 "Center",
 "Right",
 "SurLeft",
 "SurRight",
 "SubWoofer"
 };

static
PCCONNECTION_DESCRIPTOR MiniportConnections[] =
{   //  FromNode,               FromPin,          ToNode,                 ToPin
    {   PCFILTER_NODE,          TOPO_WAVEOUT01_SOURCE, TOPO_WAVEOUT01_VOLUME,         1             },
    {   TOPO_WAVEOUT01_VOLUME,         0,                   TOPO_WAVEOUT01_MUTE,	     1,		   },
    {   TOPO_WAVEOUT01_MUTE,		0,		     TOPO_MASTER_MIX,             1             },
#ifdef USE_MULTY_WAVE
    {   PCFILTER_NODE,          TOPO_WAVEOUT23_SOURCE, TOPO_WAVEOUT23_VOLUME,         1             },
    {   TOPO_WAVEOUT23_VOLUME,         0,                   TOPO_WAVEOUT23_MUTE,	     1,		   },
    {   TOPO_WAVEOUT23_MUTE,		0,		     TOPO_MASTER_MIX,             1             },

    {   PCFILTER_NODE,          TOPO_WAVEOUT45_SOURCE, TOPO_WAVEOUT45_VOLUME,         1             },
    {   TOPO_WAVEOUT45_VOLUME,         0,                   TOPO_WAVEOUT45_MUTE,	     1,		   },
    {   TOPO_WAVEOUT45_MUTE,		0,		     TOPO_MASTER_MIX,             1             },

    {   PCFILTER_NODE,          TOPO_WAVEOUT67_SOURCE, TOPO_WAVEOUT67_VOLUME,         1             },
    {   TOPO_WAVEOUT67_VOLUME,         0,                   TOPO_WAVEOUT67_MUTE,	     1,		   },
    {   TOPO_WAVEOUT67_MUTE,		0,		     TOPO_MASTER_MIX,             1             },
#endif
    {   PCFILTER_NODE,          TOPO_SYNTH1_SOURCE,  TOPO_SYNTH1_VOLUME,           1             },
    {   TOPO_SYNTH1_VOLUME,           0,             TOPO_SYNTH1_MUTE,	     1,		   },
    {   TOPO_SYNTH1_MUTE,		0,	TOPO_MASTER_MIX,             1             },

/*    {   PCFILTER_NODE,          TOPO_SYNTH2_SOURCE,  TOPO_SYNTH2_VOLUME,           1             },
    {   TOPO_SYNTH2_VOLUME,           0,                   TOPO_SYNTH2_MUTE,	     1,		   },
    {   TOPO_SYNTH2_MUTE,		0,		     TOPO_MASTER_MIX,             1             },
*/

    {   PCFILTER_NODE,          TOPO_LINEIN_SOURCE,    TOPO_LINEIN_VOLUME,          1             },
    {   TOPO_LINEIN_VOLUME,          0,                TOPO_LINEIN_MUTE,	1	},
    {	TOPO_LINEIN_MUTE,	     0, 	       TOPO_MASTER_MIX,		1             		  },

    {   PCFILTER_NODE,          TOPO_MICIN_SOURCE,    TOPO_MICIN_VOLUME,          1             },
    {   TOPO_MICIN_VOLUME,          0,                TOPO_MICIN_MUTE,	1	},
    {	TOPO_MICIN_MUTE,	     0, 	       TOPO_MASTER_MIX,		1             		  },

    {   TOPO_MASTER_MIX,             0,                   TOPO_MASTER_VOLUME,          1             },
    {   TOPO_MASTER_VOLUME,          0,                   TOPO_MASTER_MUTE,            1,		   },
    {   TOPO_MASTER_MUTE,		0,		     PCFILTER_NODE,          TOPO_MASTER_MIXER_DEST },

    {   PCFILTER_NODE,          TOPO_RECIN_SOURCE,   TOPO_RECIN_VOLUME,           1             },
    {   TOPO_RECIN_VOLUME,           0,                   TOPO_RECIN_MUTE,              1             },
    {   TOPO_RECIN_MUTE,              0,                   TOPO_RECIN_SUM,              1             },
    {   TOPO_RECIN_SUM,              0,                   PCFILTER_NODE,          TOPO_WAVEIN_DEST   }
};

// MiniportFilterDescription
static
PCFILTER_DESCRIPTOR MiniportFilterDescriptor =
{
    0,                                  // Version
    &FilterAutomation,       		// AutomationTable
    sizeof(PCPIN_DESCRIPTOR),           // PinSize
    SIZEOF_ARRAY(MiniportPins),         // PinCount
    MiniportPins,                       // Pins
    sizeof(PCNODE_DESCRIPTOR),          // NodeSize
    SIZEOF_ARRAY(TopologyNodes),        // NodeCount
    TopologyNodes,                      // Nodes
    SIZEOF_ARRAY(MiniportConnections),  // ConnectionCount
    MiniportConnections,                // Connections
    0,                                  // CategoryCount
    NULL                                // Categories
};
