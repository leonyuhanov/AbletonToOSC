# AbletonToOSC
Grab MIDI Data from any instrument from Ableton Live and send that data via OSC to an ESP8266 to use as a control/sequencing mechanism

The Max module is based on the "OSC MIDI Send" module fomr the Ableton Connection Kit https://github.com/Ableton/m4l-connection-kit

Packet form Ableton
      "/N10,iii0000000<000d000255"
Drop the module into any device in Ableton:
![Insert the Module](https://github.com/leonyuhanov/AbletonToOSC/blob/master/media/screen1.JPG)

In the modules fields, change the host port and instrument id to:

Host: The IP address of your ESP8266

Port: 2000

Instrument ID: your choice, assign each module a different instument ID

Upload the code to your ESP and make sure its on the same network as the machine running Ableton Live

All MIDI data on that instrument will now be routed to the ESP

# What the Module transmits fomr Ableton

Each time a MIDI message is made within an instrument, the module will create a packet that looks like this

      "/N10,iii0000000100000001"

The following is a breakdown of the above example:

Byte 0:7   -  OSC Note Command with 3 x Integer identifiers                             "/N10,iii"

Byte 8:11  -  Value of the MIDI Device(always 0)                                        "0000"

Byte 12:15 -  Value of the Note playd                                                   "0001"

Byte 16:19 -  Value of the Velocity (100 is Note ON / 0 is note OFF)                    "0000" 

Byte 20:23 -  The manualy set Device ID(TO identify what device sent this midi signal)  "0001"
