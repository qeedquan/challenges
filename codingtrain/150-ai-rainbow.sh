#!/bin/sh

MODEL="v1-5-pruned-emaonly.safetensors"

sd-cli -o rainbow.png -m $MODEL -p "rainbow"

