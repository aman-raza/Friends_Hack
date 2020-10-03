# -*- coding: utf-8 -*-
"""
Created on Tue Apr 21 16:09:02 2020

@author: sandip
"""
# =============================================================================
#  Program that checks data processed
# =============================================================================

import psutil
import time


def Download_Speed():
    prevByteCounter = psutil.net_io_counters()[1]
    while(True):
        newByteCounter = psutil.net_io_counters()[1]
        downloadSpeed = (newByteCounter - prevByteCounter) / 1024 
        print("Download Speed : %3.2f Kbps " % downloadSpeed, end = '\r')
        prevByteCounter = newByteCounter
        time.sleep(1)
        
Download_Speed()

    

