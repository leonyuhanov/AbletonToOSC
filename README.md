# AbletonToOSC
Grab MIDI Data from any instrument from Ableton Live and send that data via OSC to an ESP8266 to use as a control/sequencing mechanism

The Max module is based on the "OSC MIDI Send" module fomr the Ableton Connection Kit https://github.com/Ableton/m4l-connection-kit

# How it Works
Drop the module into any device in Ableton:
![Insert the Module](https://github.com/leonyuhanov/AbletonToOSC/blob/master/media/screen1.JPG)

In the modules fields, change the host port and instrument id to:
Host: The IP address of your ESP8266
Port: 2000
Instrument ID: your choice, assign each module a different instument ID

Upload the code to your ESP and make sure its on the same network as the machine running Ableton Live

All MIDI data on that instrument will now be routed to the ESP
