#!/bin/bash

./wz 1000 30 | tee -a data.txt
sleep 30s
./wz 3000 30 | tee -a data.txt
sleep 30s
./wz 5000 30 | tee -a data.txt
sleep 30s
./wz 7000 30 | tee -a data.txt
sleep 30s
