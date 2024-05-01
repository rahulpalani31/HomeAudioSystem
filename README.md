# HomeAudioSystem

This project entails the development of a basic home audio system intended for personal use. The complete system includes a graphic equalizer, a class-D amplifier, and an OLED display featuring a user interface and a Spectrogram. 

# Graphic Equalizer
The graphic equalizer will be constructed using 3 BPF’s in order to boost/attenuate the bass region, mid region and treble region. 

Consists Of:
- Bandpass Filters for Bass, Treble, and Mid-Range
- Potentiometer Cluster

# Class-D Amplifier
The class-D amplifier, distinguished for its efficiency in signal processing, achieves levels exceeding 90%, presenting a notable improvement compared to the maximum efficiency of 78.5% attained by class A or class B amplifiers. This efficiency factor underscores the amplifier's widespread adoption in signal processing applications.

Consists of:
- Pulse Width Modulator
- Switching Output Stage Transistor Pair
- RLC Low-Pass Filter

# OLED Display
Finally, the OLED display and Arduino are used for waveform generation, and as a visual representation for the signal strength of each of the three frequency bands at any given time while the audio is playing.

Consists Of:
- Spectrogram
- Welcome Screen
