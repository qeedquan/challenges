#!/usr/bin/env python3

"""

The goal of this challenge is to implement a digital low-pass filter.

You are free to implement any type of digital filter you want, however whatever results produced must pass the validation script below.

Here's a general description of what the validation script expects:

When an FFT is taken of the filtered signal, the filtered signal amplitude at any frequency bucket:
If the input signal has a frequency bucket with a value below -80dB, then the output signal bucket needs only be at or below the -80dB level.
A decade below the cutoff frequency must not differ from the source signal amplitude by more than 3dB at the corresponding frequency bucket.
At or above the cutoff frequency must be at least 3dB below the source signal amplitude at the corresponding frequency bucket of the input signal.
The output signal must be in the time domain and have the same number of samples and sample rate as the input signal.
You need not preserve any phase information or worry about aliasing.
The output signal must consist of only finite real values (no NaN/ infinities).
Input
Your program is given the following inputs:

A time domain sampled signal consisting of real numbers representing the amplitude of the signal at the sample time. Your program will be given the entire sample data at the beginning, but this is not necessarily the same between different runs of your program. You may assume the number of samples is sufficiently small that you don't have to worry about running out of memory. You may assume any single input sample is between [-1, 1]
A positive real number representing the sample rate (in Hz)
A positive real number representing the cutoff frequency (in Hz)
You are free to dictate the exact form of the input as long as no additional information is given (ex.: passing a data pointer+length for the time domain signal is ok, but passing in FFT information is not). The input can come from any source desired (file io, stdio, function parameter, etc.)

Output
Your program should output the time domain filtered signal. The output may be written to any source desired (file io, stdio, function return value, etc.). You should not need the filtered signal sample rate since it should be the same as the input sample rate.

Validation Python function
This should work with Python 2 or 3 (requires NumPy)

from __future__ import division, print_function
import numpy as np

def validate(original, filtered, srate, cfreq):
    '''
    Validates that the filtered signal meets the minimum requirements of a low-pass filter.
    A message of the failure mode is printed to stdout

    @param original the original signal (numpy array)
    @param filtered the filtered signal (numpy array)
    @param srate the sample rate (float)
    @param cfreq the cutoff frequency (float)
    @return True if filtered signal is sufficent, else False
    '''
    # check length
    if(len(original) != len(filtered)):
        print('filtered signal wrong length')
        print('len(original): %d, len(filtered): %d'%(len(original),len(filtered)))
        return False
    # assert filtered signal is not complex
    if(np.any(np.iscomplex(filtered))):
        print('filtered contains complex values')
        return False
    # assert filtered signal is all finite floats
    if(not np.all(np.isfinite(filtered))):
        print('filtered signal contains non-finite floating point values')
        return False
    o_fft = abs(np.fft.rfft(original))
    f_fft = abs(np.fft.rfft(filtered))
    f_fft /= np.amax(o_fft)
    o_fft /= np.amax(o_fft)
    fft_freqs = np.fft.rfftfreq(len(original), 1/srate)

    orig_small_mask = (o_fft < 1e-4)
    big_mask = ~orig_small_mask
    # check small values
    if(np.any(f_fft[orig_small_mask] > 1e-4)):
        print('input signal had a bucket below -80 dB which the filtered signal did not')
        return False

    ob_fft = o_fft[big_mask]
    fb_fft = f_fft[big_mask]
    fftb_freqs = fft_freqs[big_mask]
    low_mask = (fftb_freqs < 0.1*cfreq)
    high_mask = (fftb_freqs >= cfreq)
    lows = abs(fb_fft[low_mask]/ob_fft[low_mask])
    highs = abs(fb_fft[high_mask]/ob_fft[high_mask])
    # check pass bands
    if(np.any(lows > np.sqrt(2)) or np.any(lows < 1/np.sqrt(2))):
        print('pass region is outside of +/- 3dB')
        return False
    # check filter bands
    if(np.any(highs > 1/np.sqrt(2))):
        print('filter region is not at least -3dB below original')
        return False
    # passed all tests!
    return True
Examples
Here are some Python functions which can be used to generate example datasets. Note that these scripts require NumPy. The output of each function is a tuple containing (samples, sample_rate, cutoff_freq). Note that it is very easy to get a different test case by choosing a different cutoff frequency; the example ones are just somewhat "interesting" cases.

from __future__ import division, print_function
import numpy as np
def case1():
    # simple sine wave, cutoff including primary frequency
    t = np.linspace(0, 1, 10000)
    srate = 1/(t[1]-t[0])
    return np.sin(2*pi*t),srate,1

def case2():
    # simple sine wave, cutoff above primary frequency
    t = np.linspace(0, 1, 10000)
    srate = 1/(t[1]-t[0])
    return np.sin(2*pi*t),srate,10

def case3():
    # random noise
    t = np.linspace(0, 1, 10001)
    srate = 1/(t[1]-t[0])
    return np.random.rand(t.size)*2-1,srate,10

def case4():
    # sinc function
    t = np.linspace(-1, 1, 10000)
    srate = 1/(t[1]-t[0])
    return np.sinc(2*np.pi*srate*t), srate, 10

def case5():
    n = 200000
    t = np.linspace(0, 1, n)
    y = np.zeros(t.size)
    for i in range(3):
        amp = np.random.rand(1)
        freq = i*103+101
        phase = np.random.rand(1)*2*np.pi
        tdecay = 1e-3
        decay = 1e-1
        for j in range(1,10):
            fj = freq*j
            if(fj >= 0.9*n):
                break
            y += amp*(np.sin(2*np.pi*fj*t+phase))*np.exp(-decay*(j-1)**2)*np.exp(-tdecay*t)
    y -= np.mean(y)
    y /= max(np.amax(abs(y)),1)
    srate = 1/(t[1]-t[0])
    return y,srate, 1e3

Scoring
This is code golf, shortest answer in bytes wins. Standard loop-holes apply. You may use any built-ins desired.

"""

import numpy as np
from numpy.fft import *
from math import *

def validate(original, filtered, srate, cfreq):
    """
    Validates that the filtered signal meets the minimum requirements of a low-pass filter.
    A message of the failure mode is printed to stdout

    @param original the original signal (numpy array)
    @param filtered the filtered signal (numpy array)
    @param srate the sample rate (float)
    @param cfreq the cutoff frequency (float)
    @return True if filtered signal is sufficent, else False
    """
    # check length
    if len(original) != len(filtered):
        print("filtered signal wrong length")
        print("len(original): %d, len(filtered): %d" % (len(original), len(filtered)))
        return False
    # assert filtered signal is not complex
    if np.any(np.iscomplex(filtered)):
        print("filtered contains complex values")
        return False
    # assert filtered signal is all finite floats
    if not np.all(np.isfinite(filtered)):
        print("filtered signal contains non-finite floating point values")
        return False
    o_fft = abs(np.fft.rfft(original))
    f_fft = abs(np.fft.rfft(filtered))
    f_fft /= np.amax(o_fft)
    o_fft /= np.amax(o_fft)
    fft_freqs = np.fft.rfftfreq(len(original), 1 / srate)

    orig_small_mask = o_fft < 1e-4
    big_mask = ~orig_small_mask
    # check small values
    if np.any(f_fft[orig_small_mask] > 1e-4):
        print(
            "input signal had a bucket below -80 dB which the filtered signal did not"
        )
        return False

    ob_fft = o_fft[big_mask]
    fb_fft = f_fft[big_mask]
    fftb_freqs = fft_freqs[big_mask]
    low_mask = fftb_freqs < 0.1 * cfreq
    high_mask = fftb_freqs >= cfreq
    lows = abs(fb_fft[low_mask] / ob_fft[low_mask])
    highs = abs(fb_fft[high_mask] / ob_fft[high_mask])
    # check pass bands
    if np.any(lows > np.sqrt(2)) or np.any(lows < 1 / np.sqrt(2)):
        print("pass region is outside of +/- 3dB")
        return False
    # check filter bands
    if np.any(highs > 1 / np.sqrt(2)):
        print("filter region is not at least -3dB below original")
        return False
    # passed all tests!
    return True


def case1():
    # simple sine wave, cutoff including primary frequency
    t = np.linspace(0, 1, 10000)
    srate = 1 / (t[1] - t[0])
    return np.sin(2 * pi * t), srate, 1


def case2():
    # simple sine wave, cutoff above primary frequency
    t = np.linspace(0, 1, 10000)
    srate = 1 / (t[1] - t[0])
    return np.sin(2 * pi * t), srate, 10


def case3():
    # random noise
    t = np.linspace(0, 1, 10000)
    srate = 1 / (t[1] - t[0])
    return np.random.rand(t.size) * 2 - 1, srate, 10


def case4():
    # sinc function
    t = np.linspace(-1, 1, 10000)
    srate = 1 / (t[1] - t[0])
    return np.sinc(2 * np.pi * srate * t), srate, 10


def case5():
    n = 200000
    t = np.linspace(0, 1, n)
    y = np.zeros(t.size)
    for i in range(3):
        amp = np.random.rand(1)
        freq = i * 103 + 101
        phase = np.random.rand(1) * 2 * np.pi
        tdecay = 1e-3
        decay = 1e-1
        for j in range(1, 10):
            fj = freq * j
            if fj >= 0.9 * n:
                break
            y += (
                amp
                * (np.sin(2 * np.pi * fj * t + phase))
                * np.exp(-decay * (j - 1) ** 2)
                * np.exp(-tdecay * t)
            )
    y -= np.mean(y)
    y /= max(np.amax(abs(y)), 1)
    srate = 1 / (t[1] - t[0])
    return y, srate, 1e3

"""

@helloworld922
This is a very simple rectangle/brick filter. It takes the real fft of the signal, sets all components equal to or higher than the cutoff frequency to 0, then returns the inverse real fft.

"""

def brickwall(x, samplerate, cutoff):
    a = rfft(x)
    b = rfftfreq(x.size, 1 / samplerate)
    a[b >= cutoff] = 0
    return irfft(a)


def test(gen):
    x, samplerate, cutoff = gen()
    y = brickwall(x, samplerate, cutoff)
    assert(validate(x, y, samplerate, cutoff) == True)


def main():
    test(case1)
    test(case2)
    test(case3)
    test(case4)
    test(case5)

main()

